#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
#define LANES 5
struct node {
    char plate [15] ;
    struct node *link ;
} *front[LANES], *rear[LANES] ;


#endif // TIPO_H_INCLUDED
