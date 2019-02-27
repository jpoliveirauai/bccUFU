#include <stdio.h>
#include "pilha.h"
#include<stdlib.h>
#include <string.h>
void push ( struct node **s, char* item ) {
    struct node *q ;
    q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    strcpy ( q -> plate, item) ;
    q -> link = NULL ;
    *s = q ;
}

/* removes an element from top of stack */
void pop ( struct node **s ) {
    struct node *q ;
    /* if stack is empty */
    if ( *s == NULL ){
        puts("erro\n");
        return;
    }
    else {
        q = *s ;
        *s = q -> link ;
        free ( q ) ;
    }
}
