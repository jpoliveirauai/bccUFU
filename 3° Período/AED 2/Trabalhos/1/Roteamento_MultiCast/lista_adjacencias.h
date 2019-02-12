#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct graf grafo_la;

grafo_la* cria_grafo_la(int quantidade);
int insere_aresta_la(grafo_la* g,int vertice1, int vertice2,int capacidade,int delay,int custo, int trafego_atual);
int remove_aresta_la(grafo_la* g,int vertice1,int vertice2);
void libera_grafo_la(grafo_la *g);
int numVertices_la(grafo_la *g);
int grauVertice_la(grafo_la *g,int v);
int ehAdjacente_la(grafo_la* g, int v1,int v2);
grafo_la* lerArquivo_la(char n[]);
int grava_arquivo_la(grafo_la* g, char* cm);
float Dijkstra_la (grafo_la *g,int metrica,int origem, int *destinos,int tamDestinos, int tamanhomsg);
float busca_profundidade_la(grafo_la *g,int *destinos,int tamDestinos, int v,int metrica,int tamanhomsg);

#endif // GRAFO_H_INCLUDED
