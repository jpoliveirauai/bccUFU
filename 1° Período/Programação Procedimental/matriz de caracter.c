#include <stdio.h>
#include <stdlib.h>
#define Nl 4
//#define Nc
int main (){
    int i,j;
    char Mar[Nl][30];
    float Notas [Nl][4],Soma=0;
    for(i=0;i<Nl;i++){
        puts("\nNome: ");
        scanf("%s",&Mar[i]);
        Soma=0;
        for(j=0;j<3;j++){
            printf("nota%d:  ",j+1);
            scanf("%f",&Notas[i][j]);
            Soma+=Notas[i][j];
        }
        Notas[3][i]=Soma/3.0;
    }



}
