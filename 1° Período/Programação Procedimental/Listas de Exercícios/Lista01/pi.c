#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float result;
    int i;
    for (i=0;;i++){
        result += pow(-1,i)/((2*i)+1);
        printf ("%f\n",result);
        if (fabs(result)<0.00001) break; else continue;
    }
    return 0;
}
