#include "operacoes.hpp"
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <ctgmath>
#include <cstring>

using namespace std;

double** criaMatriz(int n){
    double **m = (double**) malloc (sizeof(double*) * n);
    for(int i=0;i<n;i++){
        m[i] = (double*) malloc (sizeof(double) * n);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            m[i][j]=0;
    return m;
}

int liberaMatriz (double** m,int n){
    for(int i=0;i<n;i++){
        free(m[i]);
    }
    free(m);
    return 0;
}

int printaMatriz(double** m, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

int decompoeMatriz (double **m,int n, double ***l,double ***u){
    cout.precision(5);
    *l = criaMatriz(n);
    *u = criaMatriz(n);
    double soma;
    for(int i=0;i<n;i++){
        //matriz U
        //i faz papel de linha -> i =i
        //coluna é quem varia  -> coluna = j
        for(int coluna=0;coluna<n;coluna++){
            if(i==0) (*u)[i][coluna] = m[i][coluna];
            else if (i<=coluna){
                soma =0;
                for(int k=0;k<i;k++) soma += (*l)[i][k] * (*u)[k][coluna];
                (*u)[i][coluna] = m[i][coluna] - soma;
            }
        }
        //matriz L
        //i faz papel de coluna
        //linha faz papel de linha kkkk
        for(int linha=0;linha<n;linha++){
            if(i==linha) (*l)[linha][i] = 1;
            else if (linha>i) {
                soma=0;
                for(int k=0;k<i;k++) soma += (*l)[linha][k] * (*u)[k][i];
                (*l)[linha][i] = (m[linha][i] - soma)/(*u)[i][i];

            }
        }


    }

    return 0;

}

int resolveMatriz  (int n, double **l,double **u, double **x, double *b){
    double *y = (double *) malloc (n*sizeof(double));
    //Faz o somatório para o vetor dos Y
    for (int i=0;i<n;i++) y[i]=b[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                y[i] -= (double) (l[i][j] * (y[j]));
            }
        }
        y[i] /= l[i][i];
    }
    //Faz o somatório para o vetor do X
    for (int i=0;i<n;i++) (*x)[i]=y[i];
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++)
            if(i!=j)(*x)[i] -= u[i][j] * (*x)[j];
        (*x)[i] /= u[i][i];
    }
    return 0;
}
