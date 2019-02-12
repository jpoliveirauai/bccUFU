#include <stdio.h>
#include <stdlib.h>
#include"heap.h"
void PQinsert(int elem, int pri, que* Q){
    int i;       /* Function for Insert operation */
    if( Qfull(*Q)) printf("\n\nOverflow!!!!\n\n");
    else{
        i=Q->costa;
        Q->costa++;
        while(Q->filaP[i].pr >= pri && i >= 0){
            Q->filaP[i+1]=Q->filaP[i];
            i--;
        }
        Q->filaP[i+1].ele=elem;
        Q->filaP[i+1].pr=pri;
    }
}

int Qfull(que Q){
    if(Q.costa==SIZE-1) {
            return 1;
    }
    return 0;
}
int Qempty(que Q){
    if(Q.frente > Q.costa) return 1;
    return 0;
}
que Criafila(){
    que* Q;
    Q = (que*)malloc(5*sizeof(que));
    Q->costa=0;
    Q->frente = 0;
    Q->costa = -1;
    return *Q;
}
void display(que Q){
    /* Function to display status of Queue */
    int i;
    if(Qempty(Q)) printf(" \n Empty Queue\n");
    else{
        printf("Front->");
        for(i=Q.frente; i<=Q.costa; i++)
            printf("[%d,%d] ",Q.filaP[i].ele,Q.filaP[i].pr);
        printf("<-Rear");
    }
}
PriorityQ Qdelete(que *Q){
    PriorityQ p;
    if(Qempty(*Q)){
        printf("\n\nUnderflow!!!!\n\n");
        p.ele=-1;
        p.pr=-1;
        return(p);
    }
    else{
        p.ele=Q->filaP[Q->frente].ele;
        p.pr=Q->filaP[Q->frente].pr;
        int i;
        for(i=0;i<SIZE;i++){
            Q->filaP[i] = Q->filaP[i+1];
        }
        Q->costa--;
        return(p);
    }
}
