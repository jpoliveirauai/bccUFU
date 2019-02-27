#include <stdio.h>
#include <string.h>
void sta (int mahoe){
    mahoe=10;
}

int main(){
    register signed short a=10;
    static unsigned int mahoe=1000;
    -a;
    sta(mahoe);
    printf("%d",mahoe);
}
