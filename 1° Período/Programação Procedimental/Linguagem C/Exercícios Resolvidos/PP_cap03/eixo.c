#include <stdio.h>

int main(void)
{
    int i;
    for (i = -1; i <= 3; i++) printf("%9c%c", ' ', '+');
    printf("\n");
    for (i = -1; i <= 3; i = i + 1) printf("%10d", i*10);
    printf("\n");
    getchar();
    return 0;
}
