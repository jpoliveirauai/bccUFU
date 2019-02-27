#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#define funcao  -t + d*(pow(1+i,n)-1)/i
#define derivada (d/i*i)*(i*n*pow(1+i,n-1) -pow(1+i,n) +1)
#define precisao 30


#include "func.c"
int erro(double i, double ik1);
float arrendonda(float x);

void newtonRapson(double i,double t,double d,double n);

#endif // FUNC_H_INCLUDED
