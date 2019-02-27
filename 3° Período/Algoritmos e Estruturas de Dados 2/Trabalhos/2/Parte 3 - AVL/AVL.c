#include <stdlib.h>
#include <stdio.h>
#include "AVL.h"

struct info
{
    int id, localx,localy,capacidade;
    int trafego;
};
struct avl
{
    struct avl *SAE;
    struct avl * SAD;
    struct info raiz;
    int fb;
};

int insere_AVL_interno(AVL *a, info* elemento,int *bal);

int remove_AVL_interno(AVL *a, int trafego, int* bal);

int meu_balanceamento_esq(AVL *a);

int meu_balanceamento_dir(AVL * a);

AVL busca_binaria_interno(AVL a, int trafego);

int rot_esq(AVL *a);

int rot_dir(AVL *a);

int rot_esq_dir(AVL *a);

int rot_dir_esq(AVL *a);

AVL cria_arvore()
{
    return (AVL) null;
}

int arvore_vazia(AVL a)
{
    return a==null;
}
info * busca_binaria(AVL a, int trafego)
{
    AVL b = busca_binaria_interno(a, trafego);
    if(b) return &(b->raiz);
    else return null;
}
AVL busca_binaria_interno(AVL a, int trafego)
{
    if(arvore_vazia(a)) return null;
    if(trafego==a->raiz.trafego) return a;
    if(trafego>a->raiz.trafego) return busca_binaria_interno(a->SAD,trafego);
    else return busca_binaria_interno(a->SAE, trafego);
}
void exibe_arvore_ordenada(AVL a)
{
    if(a!=null)
    {
        exibe_arvore_ordenada(a->SAE);
        printf("%d: \(%d,%d\) %d %d\n",a->raiz.trafego, a->raiz.localx, a->raiz.localy, a->raiz.id, a->raiz.capacidade);
        exibe_arvore_ordenada(a->SAD);
    }
    return;
}

void exibe_arvore(AVL a)
{
    printf("< ");
    if(a)
    {
        exibe_raiz(&(a->raiz));
        exibe_arvore(a->SAE);
        exibe_arvore(a->SAD);
    }
    printf(" >");
}

void exibe_raiz(info *raiz)
{
    if(raiz)
        printf("%d: \(%d,%d\) %d %d",raiz->trafego, raiz->localx, raiz->localy, raiz->id, raiz->capacidade);
    return;
}
void libera_arvore(AVL *a)
{
    if(a&&*a)
    {
        libera_arvore(&(*a)->SAE);
        libera_arvore(&(*a)->SAD);
        free(*a);
        *a=null;
    }
}
int insere_AVL(AVL *a,int id, int localx, int localy, int capacidade, int trafego )
{
    if(a==null) return failure;

    info * elemento = (info*) malloc(sizeof(info));
    if(!elemento) return failure;

    elemento->capacidade = capacidade;
    elemento->id = id;
    elemento->localx = localx;
    elemento->localy = localy;
    elemento->trafego = trafego;
    int bal=1;
    return insere_AVL_interno(a,elemento,&bal);
}

int insere_AVL_interno(AVL *a, info* elemento,int *bal)
{
    if(*a==NULL)
    {
        AVL novo = (AVL) calloc(1,sizeof(struct avl));
        if(!novo) return failure;
        novo->raiz = *elemento;
        *a = novo;
        *bal = 1;
        return sucess;
    }
    int watchdog;
    if((*a)->raiz.trafego<elemento->trafego)
    {
        watchdog = insere_AVL_interno(&((*a)->SAD),elemento,bal);
        if(watchdog!=sucess) return watchdog;

        if(*bal==1)
        {
            if((*a)->fb==-1)
            {
                *bal = 0;
                return balancea_direita(a);

            }
            if((*a)->fb==0)
            {
                (*a)->fb=-1;
                return sucess;
            }
            (*a)->fb=0;
            *bal = 0;
            return sucess;
        }
    }
    else
    {
        watchdog = insere_AVL_interno(&((*a)->SAE), elemento,bal);
        if(watchdog!=sucess) return watchdog;
        if(*bal==1)
        {
            if((*a)->fb==1)
            {
                *bal = 0;
                return balancea_esquerda(a);
            }
            if((*a)->fb==0)
            {
                (*a)->fb=1;
                return sucess;
            }
            (*a)->fb=0;
            *bal = 0;
            return sucess;
        }
    }
    return sucess;
}
int remove_AVL(AVL *a, int trafego )
{
    if(a==null) return failure;

    int bal=0;
    return remove_AVL_interno(a,trafego,&bal);
}

int remove_AVL_interno(AVL *a, int trafego, int* bal)
{

    int watchdog=sucess;
    if(*a==null) return failure;
    if(trafego==(*a)->raiz.trafego)
    {
        if((!(*a)->SAD)&&(!(*a)->SAE)) //verifica se é folha
        {
            free(*a);
            *a=null;
            *bal=1;
            return sucess;
        }
        else if(((*a)->SAD&&(!(*a)->SAE))||((!(*a)->SAD)&&(*a)->SAE))//verifica se só tem um filho
        {
            AVL temp =*a;
            *a = (*a)->SAD ?(*a)->SAD :(*a)->SAE;
            free(temp);
            *bal=1;
            return sucess;
        }
        else
        {
            //entao o no a excluir tem dois filhos
            //exibe_arvore(*a);
            info troca;
            AVL maiorfilho = (*a)->SAE;
            while(maiorfilho->SAD)maiorfilho=maiorfilho->SAD;
            troca = maiorfilho->raiz;
            maiorfilho->raiz = (*a)->raiz;
            (*a)->raiz = troca;
            watchdog = remove_AVL_interno(&(*a)->SAE,trafego,bal);
            if(watchdog!=sucess) return watchdog;
            if(*bal)
            {
                switch ((*a)->fb)
                {
                case 0:
                    (*a)->fb = -1;
                    break;
                case 1:
                    (*a)->fb =0;
                    break;
                case -1:
                    *bal = 0;
                    return balancea_direita(a);
                }
            }
        }
    }
    if(trafego>(*a)->raiz.trafego)
    {
        watchdog = remove_AVL_interno(&((*a)->SAD),trafego,bal);
        if(watchdog!=sucess) return watchdog;
        if(*bal)
        {
            switch ((*a)->fb)
            {
            case 0:
                (*a)->fb = 1;
                break;
            case -1:
                (*a)->fb =0;
                break;
            case 1:
                *bal = 0;
                return balancea_esquerda(a);
            }
        }
    }
    else
    {
        watchdog = remove_AVL_interno(&((*a)->SAE),trafego,bal);
        if(watchdog!=sucess) return watchdog;
        if(*bal)
        {
            switch ((*a)->fb)
            {
            case 0:
                (*a)->fb = -1;
                break;
            case 1:
                (*a)->fb =0;
                break;
            case -1:
                *bal = 0;
                return balancea_direita(a);
            }
        }

    }
    return sucess;
}

int balancea_esquerda(AVL *a)
{
    if(!a||!*a) return failure;
    if((*a)->fb==1)
    {
        switch ((*a)->SAE->fb)
        {
        case -1:
            return rot_dir_esq(a);
        case 1:
            return rot_dir(a);
        case 0:
            return meu_balanceamento_dir(a);
        }
    }
    return failure;
}

int meu_balanceamento_dir(AVL *a)
{
    AVL novaraiz = (*a)->SAE;
    (*a)->SAE =  novaraiz->SAD->SAD;
    novaraiz->SAD->SAD = (*a);
    novaraiz->fb=-1;
    novaraiz->SAD->fb=-1;
    (*a)->fb = 0;
    *a = novaraiz;
    return sucess;
}
int balancea_direita(AVL *a)//balencea_direita balancea a sub-arvore a direita
{
    if(!a||!*a) return failure;
    if((*a)->fb==-1)
    {
        switch((*a)->SAD->fb)
        {
        case 1:
            return rot_esq_dir(a);
            break;
        case -1:
            return rot_esq(a);
            break;
        case 0:
            return meu_balanceamento_esq(a);
        }
    }
    return failure;
}

int meu_balanceamento_esq(AVL *a)
{
    AVL novaraiz = (*a)->SAD;
    (*a)->SAD =  novaraiz->SAE->SAE;
    novaraiz->SAE->SAE = (*a);
    novaraiz->fb=1;
    novaraiz->SAE->fb=1;
    (*a)->fb = 0;
    *a = novaraiz;
    return sucess;
}
int rot_esq(AVL *a)
{
    AVL temp = (*a)->SAD;
    AVL dir = (*a)->SAD->SAE;
    (*a)->SAD = temp->SAE;
    temp->SAE = (*a);
    (*a)->fb = 0;
    temp->fb = 0;
    *a = temp;
    return sucess;

}
int rot_dir(AVL *a)
{

    AVL temp = (*a)->SAE;
    (*a)->SAE = temp->SAD;
    temp->SAD = *a;
    temp->fb = 0;
    (*a)->fb = 0;
    *a = temp;
    return sucess;

}
int rot_dir_esq(AVL *a)
{
    AVL esq = (*a)->SAE;
    AVL b = esq->SAD;
    (*a)->SAE = b->SAD;
    esq->SAD = b->SAE;
    b->SAE = esq;
    b->SAD = *a;
    switch(b->fb)
    {
    case -1:
        esq->fb = 0;
        (*a)->fb = 1;
        break;
    case 0:
        esq->fb = 0;
        (*a)->fb = 0;
        break;
    case +1:
        esq->fb = -1;
        (*a)->fb = 0;
        break;
    }
    b->fb = 0;
    *a = b;
    return sucess;
}

int rot_esq_dir(AVL *a)
{

    AVL c = (*a)->SAD;
    AVL b = c->SAE;
    c->SAE = b->SAD;
    (*a)->SAD = b->SAE;
    b->SAE = *a;
    b->SAD = c;
    switch(b->fb)
    {
    case -1:
        (*a)->fb = 0;
        c->fb = 1;
        break;
    case 0:
        (*a)->fb = 0;
        c->fb = 0;
        break;
    case +1:
        (*a)->fb = -1;
        c->fb = 0;
        break;
    }
    b->fb = 0;
    *a = b;
    return sucess;
}

info* menor_trafego(AVL a)
{
    if(!a) return null;
    AVL menor = a;
    while(menor->SAE) menor = menor->SAE;
    return &(menor->raiz);
}
int qtde_ocioso(AVL a)
{
    if(a==null) return 0;
    int t=0;
    if((a->raiz.trafego/a->raiz.capacidade)<0.5) ++t;
    return t+qtde_ocioso(a->SAE)+qtde_ocioso(a->SAD);
}

int nro_folha(AVL a)
{
    if(!a) return 0;
    if((!a->SAD)&&(!a->SAE)) return 1;
    return nro_folha(a->SAE)+nro_folha(a->SAD);
}

int cheia(AVL a)
{
    if(a==null) return sucess;
    if((a->SAD&&(!a->SAE))||(a->SAE&&(!a->SAD))) return failure;
    return cheia(a->SAD)&&cheia(a->SAE);
}

int nivel_no(AVL a, info * elemento)
{

    AVL buscador = busca_binaria_interno(a,elemento->trafego);
    return altura(buscador);
}

int altura(AVL a)
{
    if(!a) return -1;
    int hsad,hsae;
    hsad = altura(a->SAD);
    hsae = altura(a->SAE);
    if(hsad>hsae) return ++hsad;
    else return ++hsae;
}
int iguais(AVL a, AVL b)
{
    if((!a&&b)||(a&&!b)) return failure;
    if(!(a||b)) return sucess;
    if(a->raiz.capacidade==b->raiz.capacidade&&a->raiz.id ==b->raiz.id)
        if(a->raiz.localx==b->raiz.localx&&a->raiz.localy==b->raiz.localy)
            if(a->raiz.trafego==a->raiz.trafego)
                return iguais(a->SAE,b->SAE)&&iguais(a->SAD,b->SAD);
    return failure;
}

