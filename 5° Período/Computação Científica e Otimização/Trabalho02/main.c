#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"


//João Paulo
//Gabriel Haddad


int main(){
    double t=750000,d=1500,n=240,x0;
    printf("Digite X0:");
    scanf("%f",&x0);
    newtonRapson(x0,t,d,n);

    return 0;
}



