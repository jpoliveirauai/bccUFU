#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED
#include "Circulo.c"
#include <math.h>

Circulo* circ_cria (float x, float y, float r);
void circ_libera(Circulo* c);
float circ_area (Circulo* c);
int circ_interior (Circulo* c, Ponto* p);
void transladaCirculoX (Circulo* c, float n);
void transladaCirculoY (Circulo* c, float n);
#endif // CIRCULO_H_INCLUDED
