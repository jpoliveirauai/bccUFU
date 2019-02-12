#include <stdio.h>

int main(){
    int v[5] = { 3, 2, 4, 1, 5 },i,j;
    for(i=0;i<5;i++){
        printf("%d :",v[i]);
        for(j=0;j<v[i];j++){
            putchar('*');
        }
        puts("\n");
    }
}
