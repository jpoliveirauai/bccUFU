#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "estacionamento.h"
int main() {
    char plate[15];
    char ad ;
    int s, lane = -1, min, i ;
    while ( 1 ) {
        for ( i = 0 ; i < LANES ; i++ ) {
            printf( "lane %d: ", i ) ;
            q_display ( front[i] ) ;
            puts("");
        }
        printf( "\nArrival/Departure/Quit? ( A/D/Q ): " ) ;
        ad = getchar();
        setbuf(stdin,NULL);
        if ( toupper ( ad ) == 'Q' ) exit ( 1 ) ;

        printf ( "\nEnter license plate num:" ) ;
        gets ( plate ) ;
        ad = toupper ( ad ) ;

        if ( ad == 'A' )  { /* arrival of car */
            lane = -1 ;  /* assume no lane is available */
            min = CAPACITY ;
            for ( i = 0 ; i < LANES ; i++ ) {
                s = count ( front[i] ) ;
                if ( s < min ) {
                    min = s ;
                    lane = i ;
                }
            }
            if ( lane == -1 )
                printf ( "\nNo room available" ) ;
            else {
                insere_final( &front[ lane ], &rear[ lane ],plate ) ;
                printf ( "\npark car at lane %d slot %d\n", lane, s ) ;
            }
        }
        else {
            if ( ad == 'D' ) {  /* departure of car */
                for ( i = 0 ; i < LANES ; ++i ) {
                    s = search ( front[i], plate ) ;
                    if ( s != -1 ) {
                        lane = i ;
                        break ;
                    }
                }
                if ( i == LANES )
                    printf ( "\nno such car!!\n" ) ;
                else  {
                    printf ( "\ncar found at lane %d slot %d\n", lane, s ) ;
                    del_dq ( &front[ lane ], &rear[ lane ], s ) ;
                }
            }
            else if( ad == 'Q')
                    exit (1) ;
        }
    }
    return 0;
}
