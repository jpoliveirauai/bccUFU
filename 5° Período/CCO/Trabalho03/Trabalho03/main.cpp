#include <iostream>
#include <vector>
#include <stdlib.h>
#include "operacoes.hpp"

//João Paulo de Oliveira      11611BCC046
//Gabriel Prudêncio Haddad    11611BCC057

using namespace std;

int main(){
    double **m, **l, **u;
    int n=-1;
    cout << "Ordem da matriz (quadrada):";
    while (n<0) cin >> n;
    m = criaMatriz(n);
    cout << "Digite a matriz:" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> m[i][j];
        }
    }
    cout << "Digite o vetor de resultados:" << endl;
    double *b = (double *) malloc (n*sizeof(double));
    for(int i=0;i<n;i++) cin >> b[i];

    double *x = (double *) malloc (n*sizeof(double));

    decompoeMatriz (m,n,&l,&u);

    cout << endl<< "Matriz M:"<<endl ; printaMatriz(m, n);                                         //Imprime a matriz original
    cout <<endl << "Matriz L:"<< endl; printaMatriz(l, n);                                         //Imprime a matriz L
    cout <<endl<< "Matriz U:"<<endl;   printaMatriz(u, n);                                         //Imprime a matriz U
    cout <<endl << endl;resolveMatriz(n,l,u,&x,b);                                                 //Resolve a matriz

    cout << "Vetor X:"<<endl;for(int i=0;i<n;i++) cout << x[i]<<endl;                              //Imprime o resultado, que é o vetor dos resultados

    liberaMatriz(m,n); liberaMatriz(l,n); liberaMatriz(u,n);                                       //Libera todas as matrizes utilizadas
    return 0;
}
