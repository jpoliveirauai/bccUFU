/* ========================================================================== */
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define INICIOARRANJO   1
#define MAXTAM          1000

int main(int argc, char *argv[])
{ struct timeval t;

  TipoLista lista;
  TipoItem item;
  int vetor[MAXTAM];
  int i, j, k, n, max;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  max = 10;
  FLVazia(&lista);

  /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
  for(i = 0; i < max; i++) vetor[i] = i + 1;
  for(i = 0; i < max; i++)
    { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*Insere cada chave na lista */
  for (i = 0; i < max; i++)
    { item.Chave = vetor[i];
      Insere(item, &lista);
      printf("Inseriu: %d \n", item.Chave);
    }
  Imprime(lista);

  /*Retira cada chave da lista */
  for(i = 0; i < max; i++)
    { /*escolhe uma chave aleatoriamente */
      j = (int) ((lista.Ultimo - 1) * rand() / (RAND_MAX + 1.0));
      /*retira chave apontada */
      Retira(j, &lista, &item);
      printf("Retirou: %d\n", item.Chave);
    }
  Imprime (lista);
  return(0);
}
