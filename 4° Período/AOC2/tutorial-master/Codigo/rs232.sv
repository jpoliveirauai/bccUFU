/* Modulo de transmissao UART na placa DE2-115 da Altera*/
module rs232(input CLOCK_50, 
		input  [1:0] KEY,
		input  [7:0] SW,
		output reg UART_TXD);
		
	reg[4:0] bitCounter; 			// conta o numero de bits que foram sendo enviados

	reg[31:0] counter; 				// conta o numero de pulsos de clock, usado para dividir o clock interno(115200)
	
	reg state, nextState;			// estado atual e proximo estado
	
	reg[9:0] rightShiftReg;			// regtistrador usado para armazenar o valor que esta sendo atualmente enviado
	
	reg shift, load, clear;			// determina as operacoes que dever ser terminadas no estado atual
	always @ (posedge CLOCK_50)
	begin
		if (KEY[1]) begin
			state <= 0;
			counter <= 0;
			bitCounter <= 0;
		end
		else begin
			counter <= counter+1;
			if (counter >= 5208) begin 						// divide o colock para uma taxa de transferencia de 9600
				state <= nextState;							// se o valor foi alcancado, vai para o proximo estado
				counter <= 0;								// da reset no contador e efetua a operacao do estado atual
				if (load) 									// preparam o bit nas chaves incluindo o start bit (0), e o stop bit (1)
					rightShiftReg <= {1'b1, SW[7:0], 1'b0};
				if (clear)
					bitCounter <= 0;
				if (shift) begin
					rightShiftReg <= rightShiftReg>>1;
					bitCounter <= bitCounter+1;
				end
			end
		end
	end
	
	always @(state or bitCounter or KEY[0]) // maquina de estados do transmissor
	begin
		 load <= 0;
		 shift <= 0;
		 clear <= 0;
		 UART_TXD <= 1;
		 case (state)
			0: begin						// Estado inicial, se KEY0 esta pressionada, inicializa a transmissao das chaves (SW)
				if (KEY[0] == 1) begin
					nextState <= 1;
					load <= 1;
					shift <= 0;
					clear <= 0;
				end
				else begin
					nextState <= 0;
					UART_TXD <= 1;
				end
			end
			 
			1: begin						// faz as operacoes para o estado e mantem nesse estado ate todos os bits serem enviados
					if (bitCounter >= 9) begin
						nextState <= 0;
						clear <= 1;
					end
					else begin
						nextState <= 1;
						shift <= 1;
						UART_TXD <= rightShiftReg[0];
				end
			end
		endcase
	end
endmodule