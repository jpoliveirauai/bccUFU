#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  4

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[10];
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % 10 + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % 10 + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % 10 + 1;
       }
}

void Imprime(TipoFila Fila)
{ int Aux;
  for (Aux = Fila.Frente - 1; Aux <= (Fila.Tras - 2); Aux++)
    printf("%12d\n", Fila.Item[Aux].Chave);
}  /* Imprime */



int main(int argc, char *argv[])
{ struct timeval t;

  TipoFila fila;
  TipoItem item;
  int vetor[10];
  int i, j, k, n, max;

  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  max = 9;
  FFVazia(&fila);

  /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
  for(i = 0; i < max+1; i++) vetor[i] = i + 1;
  for(i = 0; i < max; i++){
    k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
    j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
    n = vetor[k];
    vetor[k] = vetor[j];
    vetor[j] = n;
  }
  /*Enfileira  cada chave  */
  for (i = 0; i < max; i++){
    item.Chave = vetor[i];
    Enfileira(item, &fila);
    printf("Enfileirou: %d \n", item.Chave);
  }
  /*Desenfileira cada chave */
  for(i = 0; i < max; i++)
  { Desenfileira(&fila, &item);
    printf("Desenfileirou: %d\n", item.Chave);
  }
  return(0);
}
