#include <stdio.h>

int main(){
    int dia1,dia2,mes1,mes2,ano1,ano2;
    do{
        printf("primeira data:");
        scanf("%d %d %d",&dia1,&mes1,&ano1);
        printf("\nSegunda data:");
        scanf("%d %d %d",&dia2,&mes2,&ano2);
    } while (dia1==23&&dia2==23&&mes1==4&&mes2==4&&ano1==2016&&ano2==2016);
}
