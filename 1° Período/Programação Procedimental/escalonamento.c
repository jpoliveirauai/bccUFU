#include <stdio.h>

int main()
{
int i,j,k,N;

printf("Qual e a ordem do sistema?\n");
scanf("%d", &N);
float B[N][N+1];
for(i=1;i<N+1;i++)
{
for(j=1;j<N+2;j++)
{
printf("Digite o valor do coeficiente A[%d", i);
printf("][%d",j);
printf("] da matriz gaussiana:");
scanf("%f*", &B[i][j]);
}
}
for(i=1;i<=N;i++)
{
for(j=i+1;j<=N;j++)
{
for(k=N+1;k>=i;i--)
{
B[j][k]=B[i][k]*B[j][i]/B[i][i]-B[i][k]; -B[i][k];
}
}
}
for(i=1;i<N+1;i++)
{
for(j=1;j<N+1;j++)
{
printf("O elemento de A[%d", i);
printf("][%d",j);
printf("] escalonado é%f*", B[i][j]);
}
}

return 0;
}
