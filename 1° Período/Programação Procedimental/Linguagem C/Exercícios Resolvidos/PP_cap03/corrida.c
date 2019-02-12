
// Programa CorridaMaluca.
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int N, melhorVolta, volta;
    double tempoMedio, tempoVolta, tempoTotal, melhorTempo;
    printf("Programa Corrida Maluca\n");
//    printf("\n Digite um número: ");
    do{
       printf("Digite o número de voltas (N): ");
       scanf("%u",&N);
    }while(N<0);    
    melhorVolta = 0;
    melhorTempo = 999999999.9999999;
    tempoMedio = 0.0;
    tempoTotal = 0.0;
    volta = 1;
    while( volta <= N ) {
        do{
           printf("Digite o tempo da volta %d : ",volta);
           scanf("%lf",&tempoVolta);
        }while(tempoVolta<0.0); 
        tempoTotal += tempoVolta;
        if (tempoVolta < melhorTempo){
           melhorVolta = volta;
           melhorTempo = tempoVolta;
        }
        volta++;
    }
    if(N > 0){
         tempoMedio = tempoTotal/N;
         printf("Fim da corrida: Schumi venceu mais uma vez...\n");
         printf("Numero de Voltas: %d\n",N);
         printf("Tempo médio: %lf\n",tempoMedio);
         printf("Melhor tempo: %lf na volta %d\n",melhorTempo,melhorVolta);
    }
    printf("Ate a proxima...\n");
    system("PAUSE");
    return 0;
}
