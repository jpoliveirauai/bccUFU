#include <stdio.h>
#include <stdlib.h>
#define Nl 3
#define Nc 3

int main (){
    int a [Nl][Nc],i,j;
    /*for(i=0;i<Nl;i++){
        for(j=0;j<Nc;j++){
            scanf("%d",&a[i][j]);
        }
    }*/
    for(i=0;i<Nl;i++){
        for(j=0;j<Nc;j++){
            a[i][j]=0;
        }
    }

    for(i=0;i<Nl;i++){
        for(j=0;j<Nc;j++){
            if (i==j) a[i][j]=2;
        }
    }

    for(i=0;i<Nl;i++){
        for(j=0;j<Nc;j++){
            printf("%3d",a[i][j]);
        }
        puts("\n");
    }
}
