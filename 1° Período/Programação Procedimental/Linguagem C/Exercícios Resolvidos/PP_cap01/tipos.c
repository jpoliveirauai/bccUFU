#include <stdio.h>


int main()
{
    char c;
    unsigned char uc;
    int i;
    unsigned int ui;
    float f;
    double d;
    long double ld;
    short s;
    printf("char %ld\n",&c);
    printf("unsigned char %ld\n",&uc);
    printf("int %ld\n",&i);
    printf("unsigned int %ld\n",&ui);
    printf("float %ld\n",&f);
    printf("double %ld\n",&d);
    
    printf("char %d\n",sizeof(c));
    printf("unsigned char %d\n",sizeof(uc));
    printf("int %d\n",sizeof(i));
    printf("unsigned int %d\n",sizeof(ui));
    printf("float %d\n",sizeof(f));
    printf("double %d\n",sizeof(d));
    printf("short %d\n",sizeof(s));
    printf("long double %d\n",sizeof(ld));
   
    system("PAUSE");
    return 0;
}
