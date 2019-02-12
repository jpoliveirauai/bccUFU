#include <stdio.h>
#include <stdlib.h>

int seg(int horas,int minutos, int segundos){
  int total=0;
  total=segundos+(60*minutos)+(3600*horas);
  return total;
}

main (){
  int h,m,s;
  do {
    printf("horas:");
    scanf("%d",&h);
    printf("minutos:");
    scanf("%d",&m);
    printf("segundos:");
    scanf("%d",&s);
  }while (h<0&&m<0&&s<0);
  printf("\neh igual a %d segundos\n",seg(h,m,s));
}
