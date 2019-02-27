#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,h,j,k;
    do{
        scanf("%d", &h);
    } while(h<1);
    //j=h;
    for (i=1;i<=h;i++){
        for (j=h-i;j>0;j--){
            printf("  ");
        }
        for (k=0;k<=i;k++){
            printf("%d",k);
        }

    }
    return 0;
}
