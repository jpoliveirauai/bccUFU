#include <stdio.h>

int main(){
    int dd, mm, aaaa, aux1, aux2, op;
    printf("Descubra o seu Perfil Psicologico!\n");
    printf("Digite a sua data de nascimento:\n");
    printf("Uso: dd mm aaaa\n");
    scanf("%d %d %d",&dd,&mm,&aaaa);
    aux1 = dd*100+ mm + aaaa;
    aux2 = aux1/100 + aux1%100;
    op = aux2%5;
    
    
    
    switch(op){
       case 0: printf("Voce eh timido...\n"); break;
       case 1: printf("Voce eh sonhador...\n"); break;
       case 2: printf("Voce eh paquerador...\n"); break;
       case 3: printf("Voce eh atraente...\n"); break;
       case 4: printf("Voce eh irresistivel...\n"); break;
    }
/*    
    if(op==0)  printf("Voce eh timido...\n");
    else if(op==1)  printf("Voce eh sonhador...\n");
    else if(op==2)  printf("Voce eh paquerador...\n");
    
*/    
    system("PAUSE");
    return 0;
}
