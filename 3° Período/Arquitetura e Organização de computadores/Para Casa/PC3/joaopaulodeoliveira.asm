#Nome: João Paulo de Oliveira
#Matricula: 11611BCC046

.data
	separador: .asciiz ",  "
	
.text
	
	addi $t3, $zero, 2

	
	tratamento:
		
		beq $t0, 1, exit
		
		div $t0, $t3
		mfhi $t2
		beq $t2, 1, impar
		beq $t2, 0, par

	print:
		li $v0, 1
		add $a0, $t0, $zero
		syscall
		
		li $v0, 4
		la $a0, separador
		syscall
		
		jal tratamento	


	par:
	
		div $t0, $t0, $t3
		jal print
	
	impar:
		
		mul $t0, $t0, 3
		addi $t0, $t0, 1
	 	jal print	
	main:
		li $v0, 5
		syscall
		
		move $t0, $v0
		
		jal tratamento
		
		exit:
			li $v0, 10
			syscall
					
		li $v0, 10
		syscall
			
