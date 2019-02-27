#include <stdio.h>
#include <stdlib.h>
#include "matriz_adjacencias.h"

struct Grafo{
    int qte_arestas;
    int* grau;
    int** aresta_custo;
    int** aresta_delay;
    int** aresta_capacidade;
    int** aresta_trafego_atual;
    int qte_vertices;
};


int retorna_peso_ma(grafo_ma *g,int v1,int v2,int tipopeso){
    //0 - custo
    //1 - delay
    //2 - capacidade
    //3 - trafego
    if(tipopeso==0){
        return g->aresta_custo[v1][v2];
    }
    if(tipopeso==1){
        return g->aresta_delay[v1][v2];
    }
    if(tipopeso==2){
        return g->aresta_capacidade[v1][v2];
    }
    if(tipopeso==3){
        return g->aresta_trafego_atual[v1][v2];
    }
    return 0;
}

int menorDist_ma (int* dist,int* visitado, int nv){
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

void busca_largura(grafo_ma *g,int v, int *visitados){
    int i, vert, *fila, ini = 0, fim = 0;
    for( i=0;i<g->qte_vertices;i++)
        visitados[i]=0;
    fila = (int*) malloc(g->qte_vertices* sizeof(int));
    fim++;
    fila[fim] = v;
    visitados[v] = 1;
    while(ini != fim){
        ini = (ini +1)% g->qte_vertices;
        vert = fila[ini];
        for(i=0;i<g->grau[vert];i++){
            if(!visitados[g->aresta_custo[vert][i]]){
                fim = (fim +1)% g->qte_vertices;
                fila[fim] = g->aresta_custo[vert][i];
                visitados[g->aresta_custo[vert][i]] = 1;
            }
        }
    }
}

void Djk_ma(grafo_ma *g, int p, int* an, int* dist,int peso){
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
        u = menorDist_ma(dist,visitado,nv);
        if(u == -1) break;
        visitado[u] = 1;
        cont--;
        for(i=0;i<nv;i++){
            if(ehAdjacente_ma(g,i,u) != 1) continue;
            ind = i;
            //colocar demais pesos
            if(dist[ind] < 0){
                dist[ind] = dist[u]+retorna_peso_ma(g,u,ind,peso);
                an[ind] = u;
            }else{
                if(dist[ind] > dist[u]+retorna_peso_ma(g,u,ind,peso)){
                    dist[ind] = dist[u]+retorna_peso_ma(g,u,ind,peso);
                    //tratamento de pesos
                    an[ind] = u;
                }
            }
        }
    }
    free(visitado);
}

int indice;

void profundidade_ma(grafo_ma *g,int v, int *visitado,int* ant,int destino){
    //0 - custo
    //1 - delay
    //2 - capacidade
    //3 - trafego
    visitado[v] = 1;
    if(indice == v){
        ant[v] = -1;
    }else{
        ant[v] = indice;
        indice = v;
        if(v==destino) return;
    }
    int i;
    for(i=0;i<g->qte_vertices;i++){
        if(ehAdjacente_ma(g,v,i) && visitado[i]==0){
            profundidade_ma(g, i,visitado,ant,destino);
        }
    }
}


float busca_profundidade_ma(grafo_ma *g,int *destinos,int tamDestinos, int v,int metrica,int tamanhomsg){
    //0 - custo total da arvore
    //1 - delay fim a fim maximo
    //2 - utilização maxima do enlace
    int *visitados = (int*) calloc(sizeof(int),g->qte_vertices);
    int *ant = (int*) calloc(sizeof(int),g->qte_arestas);
    int x,i=0;
    float soma=0,min=0,max=0,soma2 = 0;
    if(metrica==0){
        indice=v;
        profundidade_ma(g,v,visitados,ant,destinos[i]);
        int **percorridos = (int**) calloc(g->qte_vertices,sizeof(int));
        for(i=0;i<g->qte_vertices;i++) percorridos[i] = (int*) calloc(g->qte_vertices,sizeof(int));
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=v){
                if(percorridos[x][ant[x]]==0){
                    soma += retorna_peso_ma(g,x,ant[x],0);
                    percorridos[x][ant[x]] = 1;
                    percorridos[ant[x]][x] = 1;
                }
                x = ant[x];
            }
        }
        return soma;
    }
    if(metrica==1){
        indice=v;
        profundidade_ma(g,v,visitados,ant,destinos[i]);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=v){
                soma += retorna_peso_ma(g,x,ant[x],1);
                x = ant[x];
            }
            if(soma>max) max = soma;
        }
        return max;
    }
    if(metrica==2){
        indice=v;
        profundidade_ma(g,v,visitados,ant,destinos[i]);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=v){
                soma += retorna_peso_ma(g,x,ant[x],3);
                soma2 += retorna_peso_ma(g,x,ant[x],2);
                x = ant[x];
            }
            if((soma + tamanhomsg)/soma2)
                max = soma;
        }
        return(max);
    }
    return 0;
}

grafo_ma* leArquivo_ma(grafo_ma* g, char n[]){
    FILE* arq;
    puts(n);
    if((arq = fopen(n,"r"))==NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return NULL;
    }else{
        char caracter;
        int numLinhas = 0;
        while ((caracter = fgetc(arq))!=EOF)            if (caracter=='\n') numLinhas++;
        grafo_ma *g = cria_grafo_ma(numLinhas);
        int custo,delay,capac,trafego,v1,v2;
        fclose(arq);
        arq = fopen(n,"r");
        while((fscanf(arq,"%d - %d: %d %d %d %d",&v1,&v2,&capac,&delay,&custo,&trafego))!=EOF){
            if(insere_aresta_ma(&g,v1,v2,capac,delay,custo,trafego))
                printf("Inserindo: %d - %d: %d %d %d %d\n",v1,v2,capac,delay,custo,trafego);
        }
        return g;
    }
    fclose(arq);
}


int gravaArquivo_ma(grafo_ma* g, char arq[]){
    FILE* f;
    int i,j;
    if((f = fopen(arq,"w"))!=NULL){
        for(i=0;i<g->qte_vertices;i++){
            for(j=0;j<g->qte_vertices;j++){
                if(g->aresta_custo[i][j]!= 0){
                    fprintf(f,"%d - %d: %d %d %d %d\n",i,j,g->aresta_custo[i][j],g->aresta_capacidade[i][j],g->aresta_delay[i][j],g->aresta_trafego_atual[i][j]);
                }
            }
        }
    }else {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }
    fclose(f);
    return 1;
}

int ehAdjacente_ma(grafo_ma* g, int v1,int v2){
    if(g->aresta_custo[v1][v2]>0&&
       g->aresta_delay[v1][v2]>0&&
       g->aresta_capacidade[v1][v2]>0&&
       g->aresta_trafego_atual[v1][v2]>0) return 1;
    return 0;
}


float Dijkstra_ma (grafo_ma *g,int metrica,int origem, int *destinos,int tamDestinos, int tamanhomsg){
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
        Djk_ma(g,origem,ant,dist,0);
        int **percorridos = (int**) calloc(g->qte_vertices,sizeof(int));
        for(i=0;i<g->qte_vertices;i++) percorridos[i] = (int*) calloc(g->qte_vertices,sizeof(int));
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=origem){
                if(percorridos[x][ant[x]]==0){
                    soma += retorna_peso_ma(g,x,ant[x],0);
                    percorridos[x][ant[x]] = 1;
                    percorridos[ant[x]][x] = 1;
                }
                x = ant[x];
            }
        }
        return soma;
    }
    if(metrica == 1){
        Djk_ma(g,origem,ant,dist,1);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=origem){
                soma += retorna_peso_ma(g,x,ant[x],1);
                x = ant[x];
            }
            if(soma>max) max = soma;
        }
        return max;
    }
    if(metrica == 2){
        Djk_ma(g,origem,ant,dist,3);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=origem){
                soma += retorna_peso_ma(g,x,ant[x],3);
                x = ant[x];
            }
            if(soma>max) max = soma;
        }
        Djk_ma(g,origem,ant,dist,2);
        for(i=0;i<tamDestinos;i++){
            x = destinos[i];
            while(x!=origem){
                soma += retorna_peso_ma(g,x,ant[x],2);
                x = ant[x];
            }
            if(soma<min) min = soma;
        }
        return((max + tamanhomsg)/min);
    }
    return 0;
}

int numVertices_ma(grafo_ma* g){
    return (g->qte_vertices);
}
int grauVertice_ma(grafo_ma *g,int v){
    return (g->grau[v]);
}
grafo_ma* cria_grafo_ma(int quantidade){
    int i;
    if(quantidade<1) return NULL;
    grafo_ma *g = (grafo_ma*) malloc(sizeof(grafo_ma));
    if(g != NULL){
        g->qte_arestas = 0;
        g->qte_vertices = quantidade;
        g->grau = (int*) calloc(sizeof(int),quantidade);

            //aresta de custo

        g->aresta_custo = (int**) calloc(sizeof(int*),quantidade);
        if(g->aresta_custo == NULL) return NULL;
        for(i=0;i<quantidade;i++){
            g->aresta_custo[i] = (int*) calloc(sizeof(int),quantidade);
            if(g->aresta_custo[i]==NULL) return NULL;
        }

                    //aresta de delay

        g->aresta_delay = (int**) calloc(sizeof(int*),quantidade);
        if(g->aresta_delay == NULL) return NULL;
        for(i=0;i<quantidade;i++){
            g->aresta_delay[i] = (int*) calloc(sizeof(int),quantidade);
            if(g->aresta_delay[i]==NULL) return NULL;
        }

        //aresta de capacidade
        g->aresta_capacidade = (int**) calloc(sizeof(int*),quantidade);
        if(g->aresta_capacidade == NULL) return NULL;
        for(i=0;i<quantidade;i++){
            g->aresta_capacidade[i] = (int*) calloc(sizeof(int),quantidade);
            if(g->aresta_capacidade[i]==NULL) return NULL;
        }

        //aresta de trafego atual
        g->aresta_trafego_atual = (int**) calloc(sizeof(int*),quantidade);
        if(g->aresta_trafego_atual == NULL) return NULL;
        for(i=0;i<quantidade;i++){
            g->aresta_trafego_atual[i] = (int*) calloc(sizeof(int),quantidade);
            if(g->aresta_trafego_atual[i]==NULL) return NULL;
        }

    }
    return g;
}

int insere_aresta_ma(grafo_ma** g,int vertice1, int vertice2,int capacidade,int delay,int custo, int trafego_atual){
    if(g==NULL||vertice1<0||vertice2<0||vertice1>(*g)->qte_vertices||vertice2>(*g)->qte_vertices) return -1;
    if(vertice1==vertice2) return 0;
    if((*g)->aresta_custo[vertice1][vertice2]== custo||(*g)->aresta_custo[vertice2][vertice1]== custo)return 0;
    if(vertice1==vertice2)
        (*g)->grau[vertice1]+=2;
    else{
        (*g)->grau[vertice1]++;
        (*g)->grau[vertice2]++;
    }
    (*g)->qte_arestas++;
    //custo
    (*g)->aresta_custo[vertice1][vertice2] = custo;
    (*g)->aresta_custo[vertice2][vertice1] = custo;
    //delay
    (*g)->aresta_delay[vertice1][vertice2] = delay;
    (*g)->aresta_delay[vertice2][vertice1] = delay;
    //capacidade
    (*g)->aresta_capacidade[vertice1][vertice2] = capacidade;
    (*g)->aresta_capacidade[vertice2][vertice1] = capacidade;
    //trafego_total
    (*g)->aresta_trafego_atual[vertice1][vertice2] = trafego_atual;
    (*g)->aresta_trafego_atual[vertice2][vertice1] = trafego_atual;
    return 1;
}

int remove_aresta_ma(grafo_ma **g, int vertice1, int vertice2){
    if(g==NULL||vertice1<0||vertice2<0||vertice1>(*g)->qte_vertices||vertice2>(*g)->qte_vertices)return -1;
    //if(!verifica_aresta_ma((*g),vertice1,vertice2)) return 0;
    if(vertice1==vertice2)(*g)->grau[vertice1]--;
    else{
        (*g)->grau[vertice1]--;
        (*g)->grau[vertice2]--;
    }
    (*g)->qte_arestas--;

    (*g)->aresta_capacidade[vertice1][vertice2] = 0;
    (*g)->aresta_capacidade[vertice2][vertice1] = 0;
    //custo
    (*g)->aresta_custo[vertice1][vertice2] = 0;
    (*g)->aresta_custo[vertice2][vertice1] = 0;
    //trafego_atual
    (*g)->aresta_trafego_atual[vertice1][vertice2] = 0;
    (*g)->aresta_trafego_atual[vertice2][vertice1] = 0;
    //delay
    (*g)->aresta_delay[vertice1][vertice2] = 0;
    (*g)->aresta_delay[vertice2][vertice1] = 0;
    return 1;
}

void libera_grafo_ma(grafo_ma* g){
    int i;
    if(g!=NULL){
        //custo
        if((g->aresta_custo)!=NULL){
            for(i=0;i<(g->qte_vertices);i++){
                free(g->aresta_custo[i]);
            }
            free(g->aresta_custo);
        }
        //delay
        if((g->aresta_delay)!=NULL){
            for(i=0;i<(g->qte_vertices);i++){
                free(g->aresta_delay[i]);
            }
            free(g->aresta_delay);
        }
        //capacidade
        if((g->aresta_capacidade)!=NULL){
            for(i=0;i<(g->qte_vertices);i++){
                free(g->aresta_capacidade[i]);
            }
            free(g->aresta_capacidade);
        }
            free(g->grau);
        //trafego_atual
        if((g->aresta_trafego_atual)!=NULL){
            for(i=0;i<(g->qte_vertices);i++){
                free(g->aresta_trafego_atual[i]);
            }
            free(g->aresta_trafego_atual);
        }
            free(g->grau);
        }
         free(g);
}
