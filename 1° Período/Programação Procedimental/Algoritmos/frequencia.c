#include <stdio.h>
#include <string.h>
#define s 100
int main(){
    char str[s];
    do{
        gets(str);
    }while(strlen(str)>100);
    int vog[5]={0,0,0,0,0},i,j;
    for(i=0;i<s;i++){
        switch(str[i]){
            case 'a':
                vog[0]++;
            break;
            case 'e':
                vog[1]++;
            break;
            case 'i':
                vog[2]++;
            break;
            case 'o':
                vog[3]++;
            break;
            case 'u':
                vog[4]++;
            break;
        }
    }
    puts("Histograma:");
    for (i=0;i<5;i++){
        printf("%d ",vog[i]);
        switch(i){
            case 0:
                printf("a ");
            break;
            case 1:
                printf("e ");
            break;
            case 2:
                printf("i ");
            break;
            case 3:
                printf("o ");
            break;
            case 4:
                printf("u ");
            break;
        }
        for(j=0;j<vog[i];j++) printf("*");
        printf("\n");
    }
}
