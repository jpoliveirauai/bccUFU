#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"
#include "Circulo.h"
int main(){
    Ponto* p= cria_Ponto(0,0);
    float x,y;
    acessa_Ponto(p,&x,&y);
    printf("Criado o ponto P=(%.3f,%.3f)\n",x,y);
    transladaPontoX(p,1);
    transladaPontoY(p,1);
    acessa_Ponto(p,&x,&y);
    printf("P transladado para: P=(%.3f,%.3f)",x,y);
    puts("\nDigite um novo ponto Q:");
    printf("X:");
    scanf("%f",&x);
    printf("Y:");
    scanf("%f",&y);
    Ponto* q= cria_Ponto(x,y);
    atribui_Ponto(q,x,y);
    printf("Criado o ponto P=(%.3f,%.3f)\n",p->x,p->y);
    printf("Criado o ponto Q=(%.3f,%.3f)\n",q->x,q->y);
    printf("Distancia entre P e Q: %.3f\n",distancia_Pontos(p,q));
    float raio;
    printf("Digite um raio:");
    scanf("%f",&raio);
    Circulo* c=circ_cria(p->x,p->y,raio);
    printf("Criado circulo com centro no ponto P e raio %.3f\n",raio);
    transladaCirculoX(c,1);
    transladaCirculoY(c,1);
    acessa_Ponto(p,&x,&y);
    printf("Circulo transladadado para: centro=(%.3f,%.3f)\n",x,y);
    printf("Area do cirulo: %f\n",circ_area(c));
    if (circ_interior(c,q)) printf("O ponto Q=(%.3f,%.3f) esta dentro do cirulo",q->x,q->y);
    else printf("O ponto Q=(%.3f,%.3f) nao esta dentro do cirulo\n\n",q->x,q->y);
    libera_Ponto(p);
    libera_Ponto(q);
    return 0;
}
