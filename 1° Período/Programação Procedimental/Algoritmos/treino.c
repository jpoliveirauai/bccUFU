#include <stdio.h>
int main(){
    float treino[5][6],media[5]={0,0,0,0,0},mt[5]={0,0,0,0,0};
    int i,j;
    for (i=0;i<5;i++){
        for(j=0;j<6;j++){
            do{
                printf("%sAtleta %2d:\nTreino%2d:\t",i==0&&j==0?"\0":"\n",i+1,j+1);
                scanf("%f",&treino[i][j]);
            }while(treino[i][j]<=0);
        }
    }
    for (i=0;i<5;i++){
        for(j=0;j<6;j++){
            media[i]+=treino[i][j];
            if(j==0||(treino[i][j]<mt[i])){
                mt[i]=treino[i][j];
            }
        }
    }
    for (i=0;i<5;i++)
    printf("\nAtleta %2d:Media:   %3.3f \tMelhor tempo: %3.3f",i+1,media[i]/6,mt[i]);
}
