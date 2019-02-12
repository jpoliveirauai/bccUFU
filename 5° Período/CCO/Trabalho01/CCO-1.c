#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CCO-1.h"

int numAntesVirgula(double x){

int resul = (int)x;
int count = 0;

if(resul == 0){
    count = 1;
    return count;
}else{
while(resul != 0){
    resul = resul/10;
    count++;
}
return count;

}

}

double arrendonda(double x,int t){

      int tam = numAntesVirgula(x);
      int tfinal = t - tam;
      char str[tfinal];
      char str2[tam];

      printf("\n");

    double resultado = x;
    double resultadoFinal=0;

    resultado += 0.5*pow(10,-tfinal);

    int inteiro = (int)resultado;
    double resto=0;

    if(inteiro !=0){
    resto = fmod(resultado,inteiro);
    resto = fabs(resto);
    }else{
    resto = fabs(resultado);
    }

    resto = (int)(resto * pow(10,tfinal));

    sprintf(str, "%lf", resto);

    sprintf(str2, "%d", inteiro);

    strcat(str2,".");

    strcat(str2,str);

    resultadoFinal = atof(str2);

    return resultadoFinal;

}

double add(double x,double y,int t){
    /*Função soma
//Recebe 2 numeros x e y como parametro para serem somados. O t é a variavel que indica o numero de digitos significativos que
devem ser representados.
*/
    printf("\n");

    //Soma de x e y e armazenamento em resultado.
    double resultado = arrendonda(x,t) + arrendonda(y,t);
    resultado = arrendonda(resultado,t);

    return resultado;

}

double sub(double x,double y,int t){

    printf("\n");

    //Subtração de x e y e armazenamento em resultado.
    x = arrendonda(x,t);
    y = arrendonda(y,t);

    return (arrendonda(x-y,t));
}

double mult(double x,double y,int t){
    x = arrendonda(x,t);
    y = arrendonda(y,t);
    double resul = x*y;
    return (arrendonda(resul, t));
}

double divi(double x,double y,int t){
    x = arrendonda(x,t);
    y = arrendonda(y,t);
    double resul = x/y;
    return (arrendonda(resul,t));

}

double pot(double x,double y,int t){
    x = arrendonda(x,t);
    y = arrendonda(y,t);
    double resul = pow(x,y);
    return arrendonda(resul,t);
}
