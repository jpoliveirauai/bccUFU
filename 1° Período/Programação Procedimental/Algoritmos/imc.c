#include<stdio.h>
#include <math.h>

int main(){
    float peso, altura,imc;
    printf("Digite o peso:");
    scanf("%f", &peso);
    printf("Digite a altura:");
    scanf("%f",&altura);
    imc=peso/(pow(altura,2));
    if (imc <18.5){
        puts("Peso abaixo do recomendado");
    }
    if (imc >25){
        puts("Peso acima do recomendado");
    }
    if (imc >18.5&& imc <25){
            puts("Peso OK");
    }
}
