#include <stdio.h>
#include <stdlib.h>
typedef struct ListElmt_{
    int data;
    struct ListElmt_ *next;
} ListElmt;
typedef struct List_ {
    int size;
    ListElmt *head;
    ListElmt *tail;
} List;
void insere(List* lista, ListElmt* elemento){
    elemento -> next = lista -> head;
    lista->head = elemento;
    if(lista->size==0)lista->tail = elemento;
    lista->size++;
}
List inversa(List lista){
    if(lista.size==0)return lista;
    List inver;
    inver.size = 0;
    ListElmt* no;
    no = lista.head;
    int i,s;
    for(i=0;i<lista.size;i++){
        s = lista.size;
        insere(&lista,no);
        no = no->next;
    }
    return (inver);
}

List sub(List lista, int i, int j){
    List sub;
    int p;
    ListElmt* no;
    no = lista.head;
    for(p=0;p<=j;p++){
        if(p>=i){
            insere(&sub,no);
        }
        no = no -> next;
    }
    return (inversa(sub));
}

int main(){
    List lista;
    lista.size = 0;
    ListElmt* no;
    no = malloc(sizeof(ListElmt));
    int i=0;
    for(i=30;i>9;i-=10){
        no -> data= i;
        insere(&lista,no);
    }
    lista = inversa(lista);
    //lista = sub(lista,2,3);
    return 0;
}
