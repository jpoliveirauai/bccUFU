#include <stdio.h>
#define ld 10
int main(){
    int a,i,j,flag=0;
	do{
        printf("Digite a ordem da matriz quadrada(<=10): ");
        scanf("%d",&a);
	}while(a<1||a>ld);
	float mat[a][a];
	int linhas[2][a],colunas[a][2];
	for (i=0;i<2;i++){
        for(j=0;j<a;j++){
            linhas[i][j]=0;
        }
	}
	for (i=0;i<a;i++){
        for(j=0;j<2;j++){
            colunas[i][j]=0;
        }
	}
	for(i=0;i<a;i++){
        for(j=0;j<a;j++){
            scanf("%f",&mat[i][j]);
            if (mat[i][j]!=0&&mat[i][j]!=1)flag=1;
            if (mat[i][j]==0){
                linhas[0][j]++;
                colunas[i][0]++;
            }
            if(mat[i][j]==1){
                linhas[1][j]++;
                colunas[i][1]++;
            }
        }
	}
	for (i=0;i<2;i++){
        for(j=0;j<a;j++){
            if (i==0&&linhas[i][j]!=a-1){
                flag=1;
            }
            if (i==1&&linhas[i][j]!=1){
                flag=1;
            }
        }
	}
	for (i=0;i<a;i++){
        for(j=0;j<2;j++){
            if (j==0&&colunas[i][j]!=a-1){
                flag=1;
            }
            if (j==1&&colunas[i][j]!=1){
                flag=1;
            }
        }
	}
    if(flag==1)printf("\n nao eh matriz de permutacao!");else puts("\neh matriz permutacao!");

}
