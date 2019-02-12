#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* alocar_vetor(int n)
{
    int *v;
    v = (int *) malloc (n * sizeof(int));
    if(v == NULL)
    {
        printf ("Erro na alocacao do vetor tente novamente!\n");
        exit(EXIT_FAILURE);
    }


    return v;
}
int** alocar_matriz(int col, int lin)
{
    int i, **m;
    m = (int **) malloc (lin * sizeof(int*));
    if (m == NULL)
    {
        printf ("Erro na alocacao da matriz tente novamente!\n");
        exit(EXIT_FAILURE);

    }
    for (i = 0; i < lin; i++)
    {
        m[i] = (int *) malloc (col * sizeof (int));

    }
    for (i = 0; i < lin; i++)
    {
        if (m[i] == NULL)
        {
            printf ("Erro na alocacao da matriz tente novamente!\n");
            exit(EXIT_FAILURE);
        }
    }
    return m;
}

void preencher_vetor(int *vet, int a, int b, int n)
{
    int j, aux;
    srand(time(NULL));
    for (j = 0; j < n; j++)
    {
        do
        {
            aux = rand() %b;
        }
        while(aux < a);
        vet[j] = aux;

    }

}

void preencher_matriz (int **mat, int a, int b, int n, int lin)
{

    int i, j, aux;
    srand(time(NULL));
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < n; j++)
        {
            do
            {
                aux = rand() %b+1;
            }
            while(aux < a);
            mat[i][j] = aux;
        }
    }
}
int main()
{
    int col, *v, **m, lin;
    int a, b,troca;
    int i, j;

    FILE *fd;

    printf ("Esse algorismo gera valores para uma matriz e um vetor com um intervalo[a,b]\n");

    printf ("Digite o tamanho do vetor e as colunas da matriz:\n");
    do
    {
        scanf("%d", &col);
    }
    while(col <= 0);

    printf ("Digite o numero de linhas da matriz:\n");
    do
    {
        scanf ("%d", &lin);
    }
    while(lin <= 0);


    v = alocar_vetor(col);
    m = alocar_matriz(col, lin);
    printf ("Alocado\n\n");

    printf("Digite os valores para definir o intervalo [a,b]:\n");
    scanf ("%d %d" , &a, &b);
    if (a > b)
    {
        troca=a;
        a=b;
        b=troca;
    }

    preencher_vetor (v, a, b, col);
    preencher_matriz (m,a,b,col,lin);

    if ((fd= fopen("dados","w+")) == NULL)
    {
        puts("Não posso abrir o Arquivo dados.\n");
        exit(1);
    }
else
{
    fprintf (fd,"o vetor gerado eh com dimencao [%d]:\n\n",col);
    printf ("o vetor gerado eh:\n\n");
    for (i = 0; i < col; i++)
    {
        fprintf(fd,"%3d\t", v[i]);
        printf("%3d\t", v[i]);
    }
    fprintf (fd,"\n\n");
    fprintf (fd,"a matriz gerada eh com [%d][%d]:\n",lin,col);
    printf ("\n\n");
    printf ("a matriz gerada eh:\n");
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            fprintf (fd,"%3d\t",m[i][j]);
            printf ("%3d\t",m[i][j]);
        }
        fprintf (fd,"\n");
        printf ("\n");
    }
free(v);
free(m);
}
fclose(fd);

return 0;
}
