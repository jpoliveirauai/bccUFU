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


void insere(List* lista,int dat){
    ListElmt *novo_no;
    novo_no = (ListElmt*) malloc(sizeof(ListElmt));
    novo_no->data = dat;
    novo_no->next = lista->head;
    lista->head = novo_no;
    if(lista->size==0) lista->tail = novo_no;
    lista->size++;
}
List inversa(List lista){
    List inver;
    inver.size = 0;
    ListElmt *no;
    no = lista.head;
    int i;
    for (i=0;i<lista.size;i++){
        insere(&inver,no->data);
        no = no->next;
    }
    return inver;
}

List sub(List lista, int inicio, int fim){
    if(inicio>fim||fim>lista.size||inicio<1){
        printf("Parametros Incorreto\n");
        exit(1);
    }
    List sub;
    sub.size = 0;
    int i;
    ListElmt *no;
    no = lista.head;
    for(i=1;i<=lista.size;i++){
        if(i>=inicio)
            insere(&sub,no->data);
        no = no->next;
    }
    return sub;
}


int main(){
    List lista,inv,subli;
    lista.size = 0;
    int i;
    for(i=30;i>1;i-=10){
        insere(&lista,i);
    }
    ListElmt* no;
    no = lista.head;
    for(i=0;i<lista.size;i++){
        printf("%d  ",no->data);
        no = no->next;
    }
    inv = inversa(lista);
    subli = sub(lista,2,3);
    puts("\n");
    no = inv.head;
    for(i=0;i<inv.size;i++){
        printf("%d  ",no->data);
        no = no->next;
    }
    puts("\n");
    no = subli.head;
    for(i=0;i<subli.size;i++){
        printf("%d  ",no->data);
        no = no->next;
    }
    return 0;
}
