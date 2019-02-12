#include "func.h"
int erro(double i, double ik1){
    return (  (int)  (pow(10,precisao)   *   fabs((ik1-i)/ik1)));
}
float arrendonda(float x){

      printf("\n");

    //Armazena x em resultado.
    float resultado = x;

    //Arrendondando conforme a formula: s+B^(-t).
    resultado += 0.5*pow(10,-precisao);

    //Pegando os digitos significativos.
    resultado *= (pow(10,precisao));

    //Truncando
    int valor = (int)resultado;

    //Voltando eles ao normal.
    resultado = valor*(pow(10,-precisao));

    //Retornando resultado.
    return resultado;


}

void newtonRapson(double i,double t,double d,double n){
    double ik1=i;
    int j=1;
    while(erro(i,ik1)||j){
        i=ik1;
        ik1 = arrendonda(i -(arrendonda(funcao)/arrendonda(derivada)));
        j=0;


        printf("i = %f\ni(k+1) = %f\nerro: %f\n",i,ik1,erro(i,ik1));
        setbuf(stdin,NULL);
        getchar();
    }
}
