#include <stdio.h>
#define ln 4
#define cl 5
int main(){
    float mat[ln][cl],x;
    int i,j,im,jm;
    for(i=0;i<ln;i++){
        for(j=0;j<cl;j++){
            scanf("%f",&mat[i][j]);
            if ((i==0&&j==0)||mat[i][j]<x){
                x=mat[i][j];
                im=i;
                jm=j;
            }
        }
    }
    for(i=0;i<ln;i++){
        for(j=0;j<cl;j++){
            printf("%10.2f",mat[i][j]);
        }
        printf("\n");
    }

    puts("\n\n\n");
    printf("\n\nx: %.2f i:%d j: %d\n\n",x,im,jm);
    for (j=0;j<cl;j++){
        if (mat[im][j]>x) x=mat[im][j];
    }
    printf("\nMINMAX da matriz: %.3f",x);

}
