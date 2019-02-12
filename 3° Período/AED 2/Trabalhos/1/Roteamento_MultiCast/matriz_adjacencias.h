#ifndef MATRIZ_ADJACENCIAS_H_INCLUDED
#define MATRIZ_ADJACENCIAS_H_INCLUDED

typedef struct Grafo grafo_ma;

grafo_ma* cria_grafo_ma(int quantidade);
void libera_grafo_ma(grafo_ma* g);
int insere_aresta_ma(grafo_ma** g,int vertice1, int vertice2,int capacidade,int delay,int custo, int trafego_atual);
int remove_aresta_ma(grafo_ma **g, int vertice1, int vertice2);
int numVertices_ma(grafo_ma* g);
int ehAdjacente_ma(grafo_ma* g, int v1,int v2);
int grauVertice_ma(grafo_ma *g,int v);
grafo_ma* leArquivo_ma(grafo_ma* g, char arq[]);
float busca_profundidade_ma(grafo_ma *g,int *destinos,int tamDestinos, int v,int metrica,int tamanhomsg);
float Dijkstra_ma (grafo_ma *g,int metrica,int origem, int *destinos,int tamDestinos, int tamanhomsg);
void busca_largura(grafo_ma *g,int v, int *visitados);
int gravaArquivo_ma(grafo_ma* g, char arq[]);
#endif // MATRIZ_ADJACENCIAS_H_INCLUDED
