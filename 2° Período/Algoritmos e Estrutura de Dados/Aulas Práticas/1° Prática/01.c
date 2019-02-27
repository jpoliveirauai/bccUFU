#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main (){
    int nalunos,i,j;
    printf("Digite o numero de alunos:\n");
    scanf("%d",&nalunos);
    float notas [50][3],medias[3]={0,0,0},maior=FLT_MIN,coef;
    for (i=0;i<nalunos;i++)
        for (j=0;j<3;j++){
            printf("Digite a nota da P%d do aluno %d:",j+1,i+1);
            scanf ("%f",&notas[i][j]);
            medias[j]+=notas[i][j];
            if (notas[i][2]>maior) maior=notas[i][2];
        }
    printf("medias:\n");
    for (i=0;i<3;i++){
        medias[i]/=nalunos;
        printf("P%d: %.2f\n",i+1,medias[i]);
    }
    coef= 10/maior;
    printf("Aluno\tNota P1\t   Nota P2\t   Nota P3\n");
    for (i=0;i<nalunos;i++){
        notas[i][2]*=coef;
        printf("%5d %7.2f\t %7.2f\t %7.2f\n",i+1,notas[i][0],notas[i][1],notas[i][2]);
    }
    float total[nalunos];
    for(i=0;i<nalunos;i++) total[i]=0;
    printf("Aluno\tTotal\n");
    for (i=0;i<nalunos;i++)
        for (j=0;j<3;j++)
            total[i]+=notas[i][j];
    for (i=0;i<nalunos;i++)
        printf("%5d %5.2f\n",i+1,total[i]);
    return 0;
}
