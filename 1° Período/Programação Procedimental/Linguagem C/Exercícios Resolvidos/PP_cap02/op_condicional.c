#include <stdio.h>

int main(){
    int a, b, c, x;
    a = 1; 
    b = 2; 
    c = 3; 
    x = 0; 
    x = a < b ? a < c ? a : c : b < c ? b : c; 
    printf("a < b ? a < c ? a : c : b < c ? b : c\n");
    printf("a < b ? -- %d < %d = %d\n", a,b, a<b);
    printf("a < c ? -- %d < %d = %d\n", a,c, a<c);
    printf("b < c ? -- %d < %d = %d\n", b,c, b<c);
    printf("x = %d\n",x);
    system("PAUSE");
    return 0;
}

