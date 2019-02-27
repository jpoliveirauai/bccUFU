#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAXTAM 4


typedef int TipoApontador;
typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* --- outros componentes --- */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Topo;
} TipoPilha;

void FPVazia(TipoPilha *Pilha)
{ Pilha -> Topo = 0; }

int Vazia(TipoPilha Pilha)
{ return (Pilha.Topo == 0); }

void Empilha(TipoItem x, TipoPilha *Pilha)
{ if (Pilha -> Topo == MAXTAM)
  printf(" Erro   pilha esta  cheia\n");
  else { Pilha->Topo++; Pilha->Item[Pilha->Topo - 1] = x; }
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ if (Vazia(*Pilha))
  printf(" Erro   pilha esta  vazia\n");
  else { *Item = Pilha->Item[Pilha->Topo - 1]; Pilha->Topo--; }
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Topo); }

int  main(int argc, char *argv[])
{ struct timeval t;
  TipoPilha pilha;
  TipoItem item;
  int vetor[10];
  int i, j, k, n, max;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);

  max = 4;
  FPVazia(&pilha);

  /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
  for(i = 0; i < 10; i++) vetor[i] = i + 1;
  for(i = 0; i < max; i++)
    { k =  (int) (10.0*rand()/(RAND_MAX + 1.0));

      j =  (int) (10.0*rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*Insere cada chave na lista */
  for (i = 0; i < max; i++)
    { item.Chave = vetor[i];
      Empilha(item, &pilha);
      printf("Empilhou: %d \n", item.Chave);
    }
  printf("Tamanho da pilha: %d\n", Tamanho(pilha));

  /*Desempilha cada chave */
  for(i = 0; i < max; i++)
    { Desempilha(&pilha, &item);
      printf ("Desempilhou: %d\n", item.Chave);
    }
  printf ("Tamanho da pilha: %d \n", Tamanho(pilha));
  return(0);
} /* pilha */
