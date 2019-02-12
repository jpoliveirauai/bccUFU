#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED
#include "Ponto.c"

Ponto* cria_Ponto (float x,float y);

void libera_Ponto (Ponto* p);

void acessa_Ponto(Ponto* p, float* x, float* y);

void atribui_Ponto (Ponto* p, float x, float y);

float distancia_Pontos (Ponto* p1, Ponto* p2);

void transladaPontoX (Ponto* p, float n);
void transladaPontoY (Ponto* p, float n);
#endif // PONTO_H_INCLUDED
