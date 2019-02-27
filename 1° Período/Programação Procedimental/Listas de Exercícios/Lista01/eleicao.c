'#include <stdio.h>
#include <stdlib.h>

int main (){
    unsigned int voto[5]={0,0,0,0,0}, i=0;
    puts("Para Fulano digite 1\nPara Sicrano digite 2 \nPara Beltrano digite 3\nVoto nulo digite 4\nVoto em branco digite 5:");
    do {
        do{
        puts("Voto:");
        scanf("%d",&i);
        } while (i>6 && i<0);
        switch (i){
            case 1:
                voto[i-1]++;
            break;
            case 2:
                voto[i-1]++;
            break;
            case 3:
                voto[i-1]++;
            break;
            case 4:
                voto[i-1]++;
            break;
            case 5:
                voto[i-1]++;
            break;
        }
    }while(i!=99);
    printf("Resultados:\nFulano: %d\nSicrano: %d\nBeltrano: %d\nNulos: %d\nVotos em branco: %d\n",voto[0],voto[1],voto[2],voto[3],voto[4]);

}
