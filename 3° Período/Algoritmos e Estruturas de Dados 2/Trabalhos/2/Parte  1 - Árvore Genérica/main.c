#include <stdio.h>
#include <stdlib.h>
#include "arvore_generica.h"

int main(){
    int escolha=0,vertice;
    Arv arvore;
    while(1){
            while(escolha<1||escolha>14){
            printf("Digite o numero da operacao:\n");
            printf("1  - Cria arvore\n");
            printf("2  - Exibe arvore\n");
            printf("3  - Insere\n");
            printf("4  - Cria arvore Vazia\n");
            printf("5  - Libera Arvore\n");
            printf("6  - Busca\n");
            printf("7  - Percorrimento por Pos-ordem\n");
            printf("8  - Percorrimento por Pre-ordem\n");
            printf("9  - Percorre por nivel\n");
            printf("10 - Numero de nos de derivacao\n");
            printf("11 - Grau da arvore\n");
            printf("12 - Altura do No\n");
            printf("13 - Quantidade de Nos\n");
            printf("14 - Sair\n");
            scanf("%d",&escolha);
        }
        if(escolha==1){
            arvore = cria_vazia();
            printf("Digite o valor do vertice:");
            scanf("%d",&vertice);
            arvore = cria_arvore_generica(vertice);
        }
        if(escolha==2){
            exibe_arvore(arvore);
            printf("\n");
        }
        if(escolha==3){
            printf("Digite o valor do vertice a ser inserido:");
            scanf("%d",&vertice);
            insere(arvore,cria_arvore_generica(vertice));
        }
        if(escolha==4){
            arvore = cria_vazia();
        }
        if(escolha==5){
            libera_arvore_generica(&arvore);
        }
        if(escolha==6){
            printf("Digite o valor do vertice a ser buscado:");
            scanf("%d",&vertice);
            if(busca_arv_generica(arvore,vertice)) printf("Existe!!!\n");
            else printf("Nao Existe na arvore :(");
        }
        if(escolha==7){
            printf("Pos-Ordem:  ");
            postorder(arvore);
            printf("\n");
        }
         if(escolha==8){
            printf("Pre-Ordem:  ");
            busca_preorder(arvore);
            printf("\n");
        }
        if(escolha==9){
            printf("Percorrimento por nivel:  ");
            percorre_nivel(arvore);
            printf("\n");
        }
        if(escolha==10){
            printf("Numero de nos de derivacao:  %d\n",nro_derivacao(arvore));
        }
        if(escolha==11){
            printf("Grau da Arvore:  %d\n", grau_arv(arvore));
        }
        if(escolha==12){
            printf("Digite o valor do No a ser consultada a altura:");
            scanf("%d",&vertice);
            printf("Altura do no %d:  %d\n",vertice,altura_no(arvore,vertice));
        }
        if(escolha==13){
            printf("Quantidade de nos:  %d\n", qtde_nos(arvore));
        }
        if(escolha==14)break;
        escolha = 0;

        system("pause");
        system("cls");
    }
    return 1;
}
