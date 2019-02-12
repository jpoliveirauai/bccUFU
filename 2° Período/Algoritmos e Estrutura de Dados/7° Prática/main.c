#include <stdio.h>
#include <stdlib.h>

typedef struct item_Lista {
	char letra;
	struct item_Lista *prox;
	struct item_Lista *ant;
}item_Lista;


int main(){
    int i;
    item_Lista* atual;
    item_Lista* primeiro = (item_Lista*)malloc(sizeof(item_Lista));
    atual = primeiro;
    for (i=0;i<2;i++){
        atual -> letra = 97+i;
        atual -> prox = (item_Lista*)malloc(sizeof(item_Lista));
        atual->prox->ant = atual;
        atual = atual -> prox;
    }
    atual ->letra = 'c';
    atual -> prox = primeiro;
    atual -> prox -> ant = atual;
    primeiro -> ant = atual;
    atual=primeiro;
    int escolha;
    printf("Elemento atual: %c\n",atual -> letra);
    while(1){
        printf("Digite:\n[1] Para frente\n[2] Para trás\n[3] Sair:\n");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
                atual = atual ->prox;
                printf("Elemento atual: %c\n",atual -> letra);
            break;
            case 2:
                atual = atual -> ant;
                printf("Elemento atual: %c\n",atual -> letra);
            break;
            case 3:
                printf("Elemento atual: %c\n",atual -> letra);
                exit(0);
            break;
            default:
                printf("Elemento atual: %c\n",atual -> letra);
                continue;
            break;
        }
    }
    return 0;
}
