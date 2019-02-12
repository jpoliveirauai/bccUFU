#include <stdio.h>

int main(){
	float km_inicial, km_final, abastece, consumo, distancia, quant_litros;
	
	printf("Calcula o cosumo medio\n");
	printf("Digite a KM inicial: ");
	scanf("%f",&km_inicial);   
	distancia = 0.0;
	quant_litros = 0.0;
	while(km_inicial != 0.0){
		printf("Digite a kmetragem: ");
		scanf("%f",&km_final);
		printf("Digite o abastecimento: ");
		scanf("%f",&abastece);
		if (km_final != 0.0){
		   distancia += (km_final - km_inicial);
		   quant_litros += abastece;
	}
	km_inicial = km_final;
	
	}
	consumo = quant_litros/distancia;
	printf("O consumo médio foi : %f km/l\n",consumo);
	
	system("PAUSE");
	return 0;
}
