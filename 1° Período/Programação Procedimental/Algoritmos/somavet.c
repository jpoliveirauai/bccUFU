#include <stdio.h>

int main(){
    float a[5],b[5],c[5];
    int i;
    puts("vetor a: ");
    for (i=0;i<5;i++){
        scanf("%f",&a[i]);
    }
    puts("vetor b: ");
    for (i=0;i<5;i++){
        scanf("%f",&b[i]);
    }
    printf("vetor a+b: ");
    for (i=0;i<5;i++){
        c[i]=a[i]+b[i];
        printf("%.2f%c",c[i],i==4?',':' ');
    }
}
