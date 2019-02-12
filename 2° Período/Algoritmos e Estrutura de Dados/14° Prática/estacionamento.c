#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamento.h"
#include "pilha.h"
/* adds a new element at the end of queue */
int search ( struct node *q, char *p ){
    int s = -1, c = 0 ;
    while ( q != NULL ) {
        if ( strcmp ( p, q -> plate ) == 0 ) {
            s = c ;
            break ;
        }
        else {
            q = q -> link ;
            c++ ;
        }
    }
    return ( s ) ;
}
void insere_final(struct node **f, struct node **r, char *p ){
    struct node *q ;
    q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    strcpy ( q -> plate, p ) ;
    q -> link = NULL ;
    if ( *f == NULL ){    /* if the queue is empty */
        *f = q ;
    }
    else {
        (*r) -> link = q ;
    }
    *r = q ;
}
void insere_inicio( struct node **f, struct node **r, char *p ){
    struct node *q ;
    /* create new node */
    q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    strcpy ( q -> plate, p ) ;
    q -> link = NULL ;
    if ( *f == NULL )    /* if the queue is empty */
        *f = q ;
    else {
        q -> link = *f ;
        *f = q ;
        return ;
    }
    *r = q ;
}
int count ( struct node *q ){
    int c = 0 ;
    while ( q!= NULL ) {     /* traverse the entire linked list */

        q = q -> link ;
        c++ ;
    }
    return c ;
}
void q_display ( struct node *q ) {
    while( q != NULL )    {
        printf ( "%s ", q -> plate ) ;
        q = q -> link ;
    }
}
void del_dq ( struct node **f, struct node **r, int n ) {
    if ( *f == NULL )
        printf ( "queue is empty" ) ;
    else {
        if ( n == 0 ){
            pop(f);
        }
    }
}
