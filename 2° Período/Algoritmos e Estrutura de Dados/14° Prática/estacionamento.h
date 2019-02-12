#ifndef ESTACIONAMENTO_H_INCLUDED
#define ESTACIONAMENTO_H_INCLUDED
#define CAPACITY 10
#include "tipo.h"
int count ( struct node *q );
int search ( struct node *q, char *p );
void insere_inicio( struct node **f, struct node **r, char *p );
void insere_final(struct node **f, struct node **r, char *p );
void q_display ( struct node *q );
void del_dq ( struct node **f, struct node **r, int n );
#endif // ESTACIONAMENTO_H_INCLUDED
