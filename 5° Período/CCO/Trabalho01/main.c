#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CCO-1.h"

/*
João Paulo de Oliveira   - 11611BCC046
Gabriel Haddad           - 11611BCC057
*/
int main()
{
    double x,y,soma,subtracao;
    int t,escolha,enquanto;

    while(1){

    enquanto=1;

    printf("Digite 2 valores x e y: \n");
    printf("X: ");
    setbuf(stdin,NULL);scanf("%lf",&x);setbuf(stdin,NULL);

    printf("\n");

    printf("Y: ");scanf("%lf",&y);

    printf("\n");

    printf("Agora escolha a quantidade de numeros significativos t: \n");
    printf("T: ");scanf("%d",&t);

    printf("\n");

    //printf("Pressione qualquer tecla...\n");setbuf(stdin,NULL);getchar();setbuf(stdin,NULL);


    while(enquanto){

    //-----MENU-----
    printf("------MENU----- \n");
    printf("Escolha a operacao: \n\n");
    printf("1- Soma\n");
    printf("2- Subtracao\n");
    printf("3- Multiplicacao\n");
    printf("4- Divisao\n");
    printf("5- Potenciacao\n");
    printf("6- Voltar\n");
    printf("7- Sair\n\n");

    scanf("%d",&escolha);

    switch(escolha){

     case 1:
         //Chamando função para soma:
         soma = add(x,y,t);
         printf("Arredondado = %lf\n\n",soma);
         //printf("Pressione qualquer tecla...\n");setbuf(stdin,NULL);getchar();setbuf(stdin,NULL);
         break;

     case 2:
         //Chamando função para subtração.
          subtracao = sub(x,y,t);
          printf("Arrendondado = %lf\n\n",subtracao);
          //printf("Pressione qualquer tecla...\n");setbuf(stdin,NULL);getchar();setbuf(stdin,NULL);
          break;

     case 3:
         //Chamando função para subtração.

          printf("Arrendondado = %lf\n\n",mult(x,y,t));
          //printf("Pressione qualquer tecla...\n");setbuf(stdin,NULL);getchar();setbuf(stdin,NULL);
          break;

     case 4:
          printf("Arrendondado = %lf\n\n",divi(x,y,t));
          //printf("Pressione qualquer tecla...\n");setbuf(stdin,NULL);getchar();setbuf(stdin,NULL);
      break;
     case 5:
          printf("Arrendondado = %lf\n\n",pot(x,y,t));
          //printf("Pressione qualquer tecla...\n");setbuf(stdin,NULL);getchar();setbuf(stdin,NULL);
        break;
     case 6: enquanto=0;
             break;

     case 7: exit(0);
     default: break;

    }

    printf("Pressione qualquer tecla...\n");setbuf(stdin,NULL);getchar();setbuf(stdin,NULL);
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif // _WIN32
  }

}
    return 0;
}
