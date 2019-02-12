#include <stdio.h>
#include <stdlib.h>
#include "matriz_adjacencias.h"
#include "lista_adjacencias.h"
int main(){
    int escolha_tipo=30,escolha,tamanho,i;
    char arquivo[200];
    while(escolha_tipo<1||escolha_tipo>10){
        system("cls");
        printf("Integrante: Joao Paulo de Oliveira       11611BCC046\n\n");
        printf("/**************************************************\\\n");
        printf("/*              Criar grafo com:                  *\\\n");
        printf("/*1 - Lista  de adjacencias                       *\\\n");
        printf("/*2 - Matriz de adjacencias                       *\\\n");
        printf("/*3 - Lista  de adjacencias apartir de arquivo    *\\\n");
        printf("/*4 - Matriz de adjacencias apartir de arquivo    *\\\n");
        printf("/*9 - Sair                                        *\\\n");
        printf("/**************************************************\\\n");
        scanf("%d",&escolha_tipo);
    }
    grafo_la* g_la=NULL;
    grafo_ma* g_ma=NULL;
    switch(escolha_tipo){
    case (1):
        printf("Digite o numero de vertices: ");
        scanf("%d",&tamanho);
        g_la = cria_grafo_la(tamanho);
        break;
    case (2):
        printf("Digite o numero de vertices: ");
        scanf("%d",&tamanho);
        g_ma = cria_grafo_ma(tamanho);
        break;
    case (3):
        printf("Digite o nome do arquivo: ");
        setbuf(stdin,NULL);
        gets(arquivo);
        g_la = lerArquivo_la(arquivo);
        printf("Arquivo carregado com sucesso\n");
        system("pause");
        break;
    case (4):
        printf("Digite o nome do arquivo: ");
        setbuf(stdin,NULL);
        gets(arquivo);
        g_ma = leArquivo_ma(g_ma,arquivo);
        printf("Arquivo carregado com sucesso\n");
        system("pause");
        break;
    case (9):
        exit(1);
        break;
    }
    system("cls");
    int custo,delay,capacidade,trafego_atual,v1,v2,v;
    int tamsg,tamdestinos,*destinos,metrica,origem;
    while(1){
        printf("/*************************************************\\\n");
        printf("/*              Digite uma opcao:                *\\\n");
        printf("/*0 - Criar grafo da Figura 1                    *\\\n");
        printf("/*1 - Inserir aresta                             *\\\n");
        printf("/*2 - Remove aresta                              *\\\n");
        printf("/*3 - Gravar em arquivo                          *\\\n");
        printf("/*4 - Numero de vertices                         *\\\n");
        printf("/*5 - Grau do vertice                            *\\\n");
        printf("/*6 - Verificar Adjacencia                       *\\\n");
        printf("/*7 - Menor caminho com Dijkstra                 *\\\n");
        printf("/*10 - Sair                                       *\\\n");
        printf("/*************************************************\\\n");
        scanf("%d",&escolha);
        switch(escolha){
        case (0):
            if(escolha_tipo==2||escolha_tipo==4){
                grafo_ma *g = cria_grafo_ma(15);
                insere_aresta_ma(&g,0,1,1,1,1,1);
                insere_aresta_ma(&g,0,2,5,5,5,5);
                insere_aresta_ma(&g,0,3,10,10,10,10);
                insere_aresta_ma(&g,1,4,3,3,3,3);
                insere_aresta_ma(&g,2,6,7,7,7,7);
                insere_aresta_ma(&g,3,7,3,3,3,3);
                insere_aresta_ma(&g,3,8,1,1,1,1);
                insere_aresta_ma(&g,2,5,1,1,1,1);
                insere_aresta_ma(&g,6,10,15,15,15,15);
                insere_aresta_ma(&g,7,10,2,2,2,2);
                insere_aresta_ma(&g,8,10,12,12,12,12);
                insere_aresta_ma(&g,6,10,15,15,15,15);
                insere_aresta_ma(&g,10,5,2,2,2,2);
                insere_aresta_ma(&g,10,12,21,21,21,21);
                insere_aresta_ma(&g,6,10,15,15,15,15);
                insere_aresta_ma(&g,4,9,8,8,8,8);
                insere_aresta_ma(&g,4,9,8,8,8,8);
                insere_aresta_ma(&g,5,9,5,5,5,5);
                insere_aresta_ma(&g,9,12,3,3,3,3);
                insere_aresta_ma(&g,4,9,8,8,8,8);
                insere_aresta_ma(&g,9,11,9,9,9,9);
                insere_aresta_ma(&g,12,14,10,10,10,10);
                insere_aresta_ma(&g,11,13,4,4,4,4);
                insere_aresta_ma(&g,14,13,1,1,1,1);
                gravaArquivo_ma(g,"Figura1.txt");
                libera_grafo_ma(g);
            }else{
                grafo_la *g = cria_grafo_la(15);
                insere_aresta_la(g,0,1,1,1,1,1);
                insere_aresta_la(g,0,2,5,5,5,5);
                insere_aresta_la(g,0,3,10,10,10,10);
                insere_aresta_la(g,1,4,3,3,3,3);
                insere_aresta_la(g,2,6,7,7,7,7);
                insere_aresta_la(g,3,7,3,3,3,3);
                insere_aresta_la(g,3,8,1,1,1,1);
                insere_aresta_la(g,2,5,1,1,1,1);
                insere_aresta_la(g,6,10,15,15,15,15);
                insere_aresta_la(g,7,10,2,2,2,2);
                insere_aresta_la(g,8,10,12,12,12,12);
                insere_aresta_la(g,6,10,15,15,15,15);
                insere_aresta_la(g,10,5,2,2,2,2);
                insere_aresta_la(g,10,12,21,21,21,21);
                insere_aresta_la(g,6,10,15,15,15,15);
                insere_aresta_la(g,4,9,8,8,8,8);
                insere_aresta_la(g,4,9,8,8,8,8);
                insere_aresta_la(g,5,9,5,5,5,5);
                insere_aresta_la(g,9,12,3,3,3,3);
                insere_aresta_la(g,4,9,8,8,8,8);
                insere_aresta_la(g,9,11,9,9,9,9);
                insere_aresta_la(g,12,14,10,10,10,10);
                insere_aresta_la(g,11,13,4,4,4,4);
                insere_aresta_la(g,14,13,1,1,1,1);
                grava_arquivo_la(g,"Figura1.txt");
                libera_grafo_la(g);
            }
            printf("Arquivo gravado no arquivo Figura1.txt\n");
            system("pause");
        break;
        case (1):
            printf("Digite o Vertice 1:");
            scanf("%d",&v1);
            printf("Digite o Vertice 2:");
            scanf("%d",&v2);
            printf("Digite o custo:");
            scanf("%d",&custo);
            printf("Digite o delay:");
            scanf("%d",&delay);
            printf("Digite o capacidade:");
            scanf("%d",&capacidade);
            printf("Digite o trafego_atual:");
            scanf("%d",&trafego_atual);

            if(escolha_tipo==1||escolha_tipo==3)insere_aresta_la(g_la,v1,v2,capacidade,delay,custo,trafego_atual);
            else               insere_aresta_ma(&g_ma,v1,v2,capacidade,delay,custo,trafego_atual);

            break;


        case (2):
            printf("Digite o Vertice 1:");
            scanf("%d",&v1);
            printf("Digite o Vertice 2:");
            scanf("%d",&v2);
            if(escolha_tipo==1||escolha_tipo==3)remove_aresta_la (g_la,v1,v2);
            else               remove_aresta_ma(&g_ma,v1,v2);

            break;

        case (3):
            setbuf(stdin,NULL);
            gets(arquivo);
            if(escolha_tipo==1||escolha_tipo==3) grava_arquivo_la(g_la,arquivo);
            else gravaArquivo_ma(g_ma,arquivo);
            break;
        case (4):
            if(escolha_tipo==1||escolha_tipo==3)printf("%d\n",numVertices_la(g_la));
            else               printf("%d\n",numVertices_ma(g_ma));
            system("pause");
            break;
        case (5):
            printf("Digite o vertice a ser consultado:");
            scanf("%d",&v);
            if(escolha_tipo==1||escolha_tipo==3) printf("%d\n",grauVertice_la(g_la,v));
            else                printf("%d\n",grauVertice_ma(g_ma,v));
            system("pause");
            break;
        case(6):
            printf("Digite o Vertice 1:");
            scanf("%d",&v1);
            printf("Digite o Vertice 2:");
            scanf("%d",&v2);
            if(escolha_tipo==1||escolha_tipo==3)
                if(ehAdjacente_la(g_la,v1,v2))
                    printf("eh Adjacente\n");
                else
                    printf("nao eh Adjacente\n");
            else
                if(ehAdjacente_ma(g_ma,v1,v2))
                    printf("eh Adjacente\n");
                else
                    printf("nao eh Adjacente\n");
            system("pause");
            break;

        case (7):
            printf("Digite o tamanho da mensagem:");
            scanf("%d",&tamsg);
            printf("Digite o numero de Destinatarios:");
            scanf("%d",&tamdestinos);
            printf("Digite os Destinatarios:");
            destinos = (int*) malloc(sizeof(int) * tamdestinos);
            for(i=0;i<tamdestinos;i++)
                scanf("%d",&destinos[i]);
            printf("Escolha a metrica:\n\n0 - custo total da arvore\n1 - delay fim a fim maximo\n2 - utilização maxima do enlace\n");
            scanf("%d",&metrica);
            printf("Digite a origem:");
            scanf("%d",&origem);
            if(escolha_tipo==1||escolha_tipo==3){
                printf("%f\n",Dijkstra_la(g_la,metrica,origem,destinos,tamdestinos,tamsg));
            }else{
                printf("%f\n",Dijkstra_ma(g_ma,metrica,origem,destinos,tamdestinos,tamsg));
            }
            system("pause");
            break;

        default:
            if(g_la!=NULL)libera_grafo_la(g_la);
            if(g_ma!=NULL)libera_grafo_ma(g_ma);

            exit(1);
            break;
        }
        system("cls");
    }


    return 1;
}

