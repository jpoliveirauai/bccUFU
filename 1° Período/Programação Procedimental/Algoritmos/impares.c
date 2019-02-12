#include <stdio.h>

int main(){
    int x,cont=0,i;
    for (i=0;i<10;i++){
        scanf("%d",&x);
        cont+=x&1;
    }
    printf("%d impares",cont);
}
