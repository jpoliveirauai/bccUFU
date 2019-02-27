#include <stdio.h>
#include <stdlib.h>

void mostrar_lugares(char L[4][12])
{
    int i,j;
    printf("\nl/c| ");
    for(j=1; j<13; j++)
    {
        printf("%3d ",j);
    }
    printf("\n----------------------------------------------------\n");

    for(i=0; i<2; i++)
    {
        printf(" %d | ",i+1);
        for(j=0; j<12; j++)
        {
            printf("%3c ", L[i][j]);
        }
        printf("\n");
    }
    printf("   |    Corredor        Corredor        Corredor\n");
    for(i=2; i<4; i++)
    {
        printf(" %d | ",i+1);
        for(j=0; j<12; j++)
        {
            printf("%3c ", L[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j,t=48;
    char L[4][12];
    for(i=0; i<4; i++)
    {
        for(j=0; j<12; j++)
        {
            L[i][j]='0';
        }
    }

    int l, c, k, q=0;
    while(1==1)
    {
        mostrar_lugares(L);
        do
        {
            printf("\n\nQuantas poltronas o cliente deseja: ");
            do
            {
                scanf("%d", &q);
            }

            while(q<=0);
            if(q>t)
            {
                printf("\nNao ha essa quantidade de poltronas. Numero de poltronas disponivel: %d",t);
            }
        }
        while(q>t);
        for(k=0; k<q; k++)
        {
            while(1==1)
            {
                printf("\nQual o numero da linha da poltrona: ");
                do
                {
                    scanf("%d",&l);
                    --l;
                }
                while(l<0 || l>=4);
                printf("\nQual o numero da coluna da poltrona: ");
                do
                {
                    scanf("%d",&c);
                    --c;
                }
                while(c<0 || c>=12);
                if(L[l][c]=='X')
                {
                    printf("\nPoltrona ocupada! Por favor, escolha outra:\n");
                }
                else
                {
                    printf("\nPoltrona Reservada!\n");
                    L[l][c]='X';
                    t--;
                    break;
                }
            }
        }
        if(t==0)
        {
            printf("Nenhuma poltrona disponivel!");
            break;

        }
    }
    return 0;
}

