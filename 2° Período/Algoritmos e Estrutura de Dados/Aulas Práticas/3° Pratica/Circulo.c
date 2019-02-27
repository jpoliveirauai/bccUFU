#include <stdlib.h>
#include "Ponto.h"
#include <math.h>
#define pi 3.14159
typedef struct circulo{
    Ponto* p;
    float r;

}Circulo;

void transladaCirculoX (Circulo* c, float n){
    transladaPontoX(c->p,n);
}

void transladaCirculoY(Circulo* c, float n){
    transladaPontoY(c->p,n);
}

Circulo* circ_cria (float x, float y, float r){
    Circulo* c= (Circulo*)malloc(sizeof(Circulo));
    c->p = cria_Ponto(x,y);
    c->r = r;
    return c;
}

void circ_libera(Circulo* c){
    libera_Ponto(c->p);
    free(c);
}

float circ_area (Circulo* c){
    return c->r*c->r*pi;
}

int circ_interior (Circulo* c, Ponto* p){
    float d = distancia_Pontos(c->p,p);
    return (d<c->r);
}
