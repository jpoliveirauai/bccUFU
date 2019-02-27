#include "lista_adjacencias.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include<limits.h>
typedef struct no no;
typedef struct node node;

struct graf{
    int qte_vertices;
    int qte_arestas;
    int* grau;
    lista **aresta;
};
int indice,in = 0;

int retorna_peso_la(grafo_la *g,int v1,int v2,int tipopeso){
    //0 - custo
    //1 - delay
    //2 - capacidade
    //3 - trafego
    int j=0;
    int x,cap, cus, trafego, delay;
    while(x!=v2){
        elemento_n(g->aresta[v1],j,&x,&cap,&cus,&trafego,&delay);
        j++;
    }
    if(tipopeso==0){
        return cus;
    }
    if(tipopeso==1){
        return delay;
    }
    if(tipopeso==2){
        return cap;
    }
    if(tipopeso==3){
        return trafego;
    }
    return 0;
}

int menorDist_la(int* dist,int* visitado, int nv){
    int i, menor = -1, primeiro = 1;
    for(i=0;i < nv; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i]) menor = i;
            }
        }
    }
return menor;
}

void profundidade_la(grafo_la *g,int v, int *visitado,int* ant,int v2){
    visitado[v] = 1;

    if(v2 == v){
        ant[v] = -1;
    }else{
        ant[v] = v2;
        v2 = v;

    }
    int lixo,i;
    for(i=0;i<n_elementos(g->aresta[v]);i++){
        if(elemento_n(g->aresta[v],i,&v,&lixo,&lixo,&lixo,&lixo)==1){
            if(visitado[v]==0){
                profundidade_la(g,v,visitado,ant,v2);
            }
        }
    }
    /*
    no *aux;
    aux = g->aresta[v]->
    while(aux!=NULL){
        if(visitado[aux->vertice] == 0){
            ant[aux->vertice]=v;
            busca_profundidade_la(g,aux->vertice,visitado,ant,tamanho,destino);
        }
        aux = aux->prox;
    }
    */

}


float busca_profundidade_la(grafo_la *g,int *destinos,int tamDestinos, int v,int metrica,int tamanhomsg){
    //0 - custo total da arvore
    //1 - delay fim a fim maximo
    //2 - utilização maxima do enlace
    int *visitados = (int*) calloc(sizeof(int),g->qte_vertices);
    int *ant = (int*) calloc(sizeof(int),g->qte_arestas);
    int x,i=0;
    float soma=0,max=0,soma2 = 0;
    indice=v;
    profundidade_la(g,v,visitados,ant,v);
    if(metrica==0){

        for(i=0;i<g->qte_vertices;i++)printf("%d   ",ant[i]);
        int **percorridos = (int**) calloc(g->qte_vertices,sizeof(int));
        for(i=0;i<g->qte_vertices;i++) percorridos[i] = (int*) calloc(g->qte_vertices,sizeof(int));
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];

            while(x!=v){
                if(percorridos[x][ant[x]]==0){
                    soma += retorna_peso_la(g,x,ant[x],0);
                    percorridos[x][ant[x]] = 1;
                    percorridos[ant[x]][x] = 1;
                }
                x = ant[x];
            }
        }
        return soma;
    }
    if(metrica==1){
        for(i=0;i<g->qte_vertices;i++)printf("%d   ",ant[i]);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=v){
                soma += retorna_peso_la(g,x,ant[x],1);
                x = ant[x];
            }
            if(soma>max) max = soma;
        }
        return max;
    }
    if(metrica==2){
        for(i=0;i<g->qte_vertices;i++)printf("%d   ",ant[i]);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=v){
                soma += retorna_peso_la(g,x,ant[x],3);
                soma2 += retorna_peso_la(g,x,ant[x],2);
                x = ant[x];
            }
            if((soma + tamanhomsg)/soma2)
                max = soma;
        }
        return(max);
    }
    return 0;
}









void Djk_la(grafo_la *g, int p, int* an, int* dist,int peso){
    //0 - custo
    //1 - delay
    //2 - capacidade
    //3 - trafego
    int i,cont, nv, ind, *visitado,u;
    cont = nv = g->qte_vertices;
    visitado = (int*) malloc(nv*sizeof(int));
    for (i=0;i<nv;i++){
        an[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[p] = 0;
    while(cont > 0){
        u = menorDist_la(dist,visitado,nv);
        if(u == -1) break;
        visitado[u] = 1;
        cont--;
        for(i=0;i<nv;i++){
            if(ehAdjacente_la(g,i,u) != 1) continue;
            ind = i;
            //colocar demais pesos
            if(dist[ind] < 0){
                dist[ind] = dist[u]+retorna_peso_la(g,u,ind,peso);
                an[ind] = u;
            }else{
                if(dist[ind] > dist[u]+retorna_peso_la(g,u,ind,peso)){
                    dist[ind] = dist[u]+retorna_peso_la(g,u,ind,peso);
                    //tratamento de pesos
                    an[ind] = u;
                }
            }
        }
    }
    free(visitado);
}

float Dijkstra_la (grafo_la *g,int metrica,int origem, int *destinos,int tamDestinos, int tamanhomsg){
    //0 - custo total da arvore
    //1 - delay fim a fim maximo
    //2 - utilização maxima do enlace
    int i,max = 0;
    int *ant = (int*) malloc(sizeof(int)*g->qte_vertices),soma = 0,min = 0;
    int *dist = (int*) malloc(sizeof(int)*g->qte_vertices),x=-1;

    //0 - custo
    //1 - delay
    //2 - capacidade
    //3 - trafego
    if(metrica == 0){
        Djk_la(g,origem,ant,dist,0);
        int **percorridos = (int**) calloc(g->qte_vertices,sizeof(int));
        for(i=0;i<g->qte_vertices;i++) percorridos[i] = (int*) calloc(g->qte_vertices,sizeof(int));
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=origem){
                if(percorridos[x][ant[x]]==0){
                    soma += retorna_peso_la(g,x,ant[x],0);
                    percorridos[x][ant[x]] = 1;
                    percorridos[ant[x]][x] = 1;
                }
                x = ant[x];
            }
        }
        return soma;
    }
    if(metrica == 1){
        Djk_la(g,origem,ant,dist,1);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=origem){
                soma += retorna_peso_la(g,x,ant[x],1);
                x = ant[x];
            }
            if(soma>max) max = soma;
        }
        return max;
    }
    if(metrica == 2){
        Djk_la(g,origem,ant,dist,3);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=origem){
                soma += retorna_peso_la(g,x,ant[x],3);
                x = ant[x];
            }
            if(soma>max) max = soma;
        }
        Djk_la(g,origem,ant,dist,2);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=origem){
                soma += retorna_peso_la(g,x,ant[x],2);
                x = ant[x];
            }
            if(soma<min) min = soma;
        }
        return((max + tamanhomsg)/min);
    }
    return 0;
}

int grava_arquivo_la(grafo_la *g, char* cm){
    FILE* arq;
    if((arq = fopen(cm,"w")) == NULL) printf("Nao foi possivel abrir o arquivo\n");
    else{
        int i,j,capacidade,delay,trafego_atual,custo,x;
        for(i=0;i<(g->qte_vertices);i++){
            for(j=0;j<n_elementos(g->aresta[i]);j++){
                if(elemento_n(g->aresta[i],j,&x,&capacidade,&custo,&trafego_atual,&delay)){
                    fprintf(arq,"%d - %d: %d %d %d %d\n",i,x,custo,capacidade,delay,trafego_atual);
                    printf("%d - %d: %d %d %d %d\n",i,x,capacidade,delay,custo,trafego_atual);
                }
            }
        }
    }
    fclose(arq);
    return 1;
}

grafo_la* lerArquivo_la(char n[]){
    FILE* arq;
    puts(n);
    if((arq = fopen(n,"r"))==NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return NULL;
    }else{
        char caracter;
        int numLinhas = 0;
        while ((caracter = fgetc(arq))!=EOF)            if (caracter=='\n') numLinhas++;

        grafo_la *g = cria_grafo_la(numLinhas);
        int custo,delay,capac,trafego,v1,v2;
        fclose(arq);
        arq = fopen(n,"r");
        while((fscanf(arq,"%d - %d: %d %d %d %d",&v1,&v2,&capac,&delay,&custo,&trafego))!=EOF){
            if(insere_aresta_la(g,v1,v2,capac,delay,custo,trafego))
                printf("Inserindo: %d - %d: %d %d %d %d\n",v1,v2,capac,delay,custo,trafego);
        }
        return g;
    }
    fclose(arq);
}

int ehAdjacente_la(grafo_la* g, int v1,int v2){
    if(jaexiste(g->aresta[v1],v2))return 1;
    return 0;
}

int numVertices_la(grafo_la* g){
    return (g->qte_vertices);
}

int grauVertice_la(grafo_la *g,int v){
    return (g->grau[v]);
}

grafo_la* cria_grafo_la(int quantidade){
    if(quantidade<1) return NULL;
    grafo_la *g = (grafo_la*) malloc(sizeof(grafo_la));
    if(g == NULL) return NULL;
    g->qte_arestas = 0;
    g->qte_vertices = quantidade;
    g->grau = (int*) calloc(sizeof(int),quantidade);
    if(g->grau == NULL) return NULL;
    g->aresta = (lista**) calloc(sizeof(lista*),quantidade);
    if(g->aresta == NULL) return NULL;
    int i;
    for(i=0;i<quantidade;i++)
        g->aresta[i] = cria_lista();

    return g;
}


int insere_aresta_la(grafo_la* g,int vertice1, int vertice2,int capacidade,int delay,int custo, int trafego_atual){
    if(vertice1<0||vertice2<0||g==NULL||delay<=0||capacidade<=0||custo<=0||trafego_atual<=0) return -1;
    if(vertice1==vertice2) return 0;
    if(!jaexiste(g->aresta[vertice1],vertice2) && !jaexiste(g->aresta[vertice2],vertice1)){
        insere_lista(g->aresta[vertice1],vertice2,custo,capacidade,delay,trafego_atual);
        g->grau[vertice1]++;
        if(vertice1!=vertice2){
            insere_lista(g->aresta[vertice2],vertice1,custo,capacidade,delay,trafego_atual);
            g->grau[vertice2]++;
        } else g->grau[vertice1]++;
    }else return 0;

    return 1;
}


int remove_aresta_la(grafo_la* g,int vertice1,int vertice2){
    if(vertice1<0||vertice2<0||g==NULL) return -1;
    if(vertice1 == vertice2){
        if(remove_lista(g->aresta[vertice1],vertice1)==1){
                g->grau[vertice1] -=2;
                return 1;
        }
    }else{
        if (remove_lista(g->aresta[vertice1],vertice2)==1 && remove_lista(g->aresta[vertice2],vertice1)==1){
            g->grau[vertice1]--;
            g->grau[vertice2]--;
            return 1;
        }
    }
    return 0;
}

void libera_grafo_la(grafo_la *g){
    free(g->grau);
    int i;
    for(i=0;i<g->qte_vertices;i++){
        libera_lista(g->aresta[i]);
    }
    free(g);
}
