#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

typedef struct ponto{
    float x;
    float y;
}Ponto;

Ponto* cria_Ponto (float x,float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p==NULL){
        puts("Memória insuficiente!\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

void libera_Ponto (Ponto* p){
    free(p);
}

void acessa_Ponto(Ponto* p, float* x, float* y){
    *x = p->x;
    *y = p->y;
}

void atribui_Ponto (Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

float distancia_Pontos (Ponto* p1, Ponto* p2){
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy);
}

void transladaPontoX (Ponto* p,float n){
    p->x+=n;
}
void transladaPontoY (Ponto* p, float n){
    p->y+=n;
}
