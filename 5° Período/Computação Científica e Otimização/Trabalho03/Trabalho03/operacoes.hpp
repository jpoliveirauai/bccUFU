#ifndef OPERACOES_HPP_INCLUDED
#define OPERACOES_HPP_INCLUDED

double** criaMatriz(int n);
int liberaMatriz (double** m,int n);
int printaMatriz(double** m, int n);
int decompoeMatriz (double **m,int n, double ***l,double ***u);
int resolveMatriz  (int n, double **l,double **u, double **x, double *b);
#endif // OPERACOES_HPP_INCLUDED
