/* programa: advinha.c */
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    int num,segredo;
    
    srand(time(NULL));
    segredo=rand()%10;
    printf("Digite um numero: ");
    scanf("%d",&num);
    printf("segredo: %d\n",segredo);
    if (segredo==num)
    {
        printf("Acertou!");
        printf("\nO numero e %d\n",segredo);
    }
    else if (segredo<num)
        printf("Errado, muito alto!\n");
        else printf("Errado, muito baixo!\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}


