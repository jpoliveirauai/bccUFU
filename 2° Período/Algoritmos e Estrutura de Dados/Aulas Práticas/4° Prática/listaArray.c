#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "listaArray.h"


void FLVazia(TipoLista *Lista)
{
  Lista -> Ultimo = INICIOARRANJO;
}  /* FLVazia */

int Vazia(TipoLista Lista)
{ return (Lista.Ultimo == -1);
}  /* Vazia */

void Insere(TipoItem x, TipoLista *Lista)
{ if (Lista -> Ultimo == MAXTAM-1) printf("Lista esta cheia\n");
  else {
         Lista -> Ultimo++;
	Lista -> Item[Lista->Ultimo] = x;
       }
}  /* Insere */

void InsereItem(TipoItem x, TipoLista *Lista, int n){
int i = 0;
if (Lista -> Ultimo == MAXTAM-1){
    printf ("Lista esta cheia\n");
} else{
        Lista -> Ultimo++;
        for (i = Lista -> Ultimo; i > n; i--){
            Lista -> Item[i] = Lista -> Item[i-1];


        }
        Lista -> Item[n] = x;

}




}



void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ int Aux;

  if (Vazia(*Lista) || p > Lista -> Ultimo)
  {
	printf(" Erro   Posicao nao existe\n");
    return;
  }
  *Item = Lista -> Item[p];

  for (Aux = p; Aux <= Lista -> Ultimo; Aux++)
    Lista -> Item[Aux] = Lista -> Item[Aux + 1];

Lista -> Ultimo--;
}  /* Retira */

void Imprime(TipoLista Lista)
{
	int Aux;

  for (Aux = 0; Aux < Lista.Ultimo; Aux++)
    printf("%d\n", Lista.Item[Aux].Chave);
}
