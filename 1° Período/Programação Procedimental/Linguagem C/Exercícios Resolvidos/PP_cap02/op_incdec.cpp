#include <stdio.h>
#include <stdlib.h>

int main(){
    int x,y,z;
    x = y = 10;
    z = ++x;
    x = -x;
    y++;
    x = x+y-(z--);


    printf("x = %d - y = %d - z = %d\n",x,y,z);
    system("PAUSE");
    return 0;
}

