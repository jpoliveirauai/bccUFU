#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
           /* Size of Queue */

int main(){
      /* Main Program */
    int opn;
    PriorityQ p;
    que Q = Criafila();
    do
    {
        printf("\n ### Priority Queue Operations(DSC order) ### \n\n");
        printf(" Press 1-Insert, 2-Delete,3-Display,4-Exit\n");
        printf(" Your option ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1:
            printf("\n\nRead the element and its Priority?");
            scanf("%d%d",&p.ele,&p.pr);
            PQinsert(p.ele,p.pr,&Q);
            break;
        case 2:
            p = Qdelete(&Q);
            if( p.ele != -1)
                printf("\n\nDeleted Element is %d \n",p.ele);
            break;
        case 3:
            printf("\n\nStatus of Queue\n\n");
            display(Q);
            break;
        case 4:
            printf("\n\nTerminating \n\n");
            break;
        default:
            printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
        getch();
    }
    while(opn != 4);
    return 0;
}
