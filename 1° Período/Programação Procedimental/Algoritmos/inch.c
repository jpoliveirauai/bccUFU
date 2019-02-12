#include <stdio.h>

int main(){
    float i;
    for (i=1.0;i<=20;i+=0.5) printf("%4.1f polegadas = %4.2f cm\n",i,i*2.54);
}
