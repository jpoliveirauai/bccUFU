#include <stdio.h>
int main(){
    int a,b,mat[100][100],i,j,p=1;
    do{
        do {
        puts("Digite o numero de linhas e colunas da matriz: ");
        scanf("%d %d",&a,&b);
        } while (a>100||b>100);
        for (i=0;i<a;i++){
            for(j=0;j<b;j++,p++) {
                mat[i][j]=p;
                printf("%2d%c",mat[i][j],j==b-1?'\n':' ');
            }
        }

    } while(i!=0&&j!=0);
    return  0;
}
