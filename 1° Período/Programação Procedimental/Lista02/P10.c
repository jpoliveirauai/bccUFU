#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Funcoes
void imprimir_campo(int n, int p, char M[n][p]);
void tamanho_campo(int *n, int *p);
void sorteio_mina(int *k, int n, int p, char C[n][p]);
void abrir_quad(int n, int p, int l, int c, char M[n][p]);
void escolher_quadrado(int n, int p, int *l, int *c, char M[n][p]);
void arrumando_matrizM(int n, int p, char M[n][p]);
int revelar(int n, int p, int l, int c, char C[n][p]);
void marcar(int *h, int *w, int n, int p, int *l, int *c, char M[n][p], char C[n][p]);
//Final Funcoes

void tamanho_campo(int *n, int *p)
{

    printf("Digite quantas linhas o campo minado tera: ");
    scanf("%d", *&n);
    printf("Digite quantas colunas o campo minado tera: ");
    scanf("%d", *&p);
}
void imprimir_campo(int n, int p, char M[n][p])
{
    int i, j;
    system("cls");
    printf("l/c|");
    for(i=0; i<p; i++)
    {
        printf("%2d",(i+1));
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%3d|",(i+1));
        for(j=0; j<p; j++)
        {
            printf("%2c",M[i][j]);
        }
        printf("\n");
    }
}
void sorteio_mina(int *k, int n, int p, char C[n][p])
{
    int i, j;
    srand( (unsigned)time(NULL));
    for(i=0; i<n; i++)
    {
        for(j=0; j<p; j++)
        {
            C[i][j]=rand()%3;
            if(C[i][j]==0)
            {
                C[i][j]='M';
                ++*k;
            }
            else
            {
                C[i][j]='S';
            }
        }
    }
}
void escolher_quadrado(int n, int p, int *l, int *c, char M[n][p])
{
    do
    {
        printf("\nEscolha a linha: ");
        do
        {
            scanf("%d", *&l );
            --*l;
        }
        while((*l<0) || (*l>=n));
        printf("\nEscolha a coluna: ");
        do
        {
            scanf("%d",*&c);
            --*c;
        }
        while((*c<0) || (*c>=p));
    }
    while(M[*l][*c]!='*' && M[*l][*c]!='M');
}
void arrumando_matrizM(int n, int p, char M[n][p])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<p; j++)
        {
            M[i][j]='*';
        }
    }
}
int revelar(int n, int p, int l, int c, char C[n][p])
{
    int i, j, q=0;
    n=n-1;
    p=p-1;
    if(l==-1)
    {
        return(-2);
    }
    if(C[l][c]=='S')
    {
        if(l==0)
        {
            if(c==0)
            {
                if(C[0][1]=='M') q++;
                if(C[1][1]=='M') q++;
                if(C[1][0]=='M') q++;
                return(q);
            }
            if(c==p)
            {
                if(C[0][(p-1)]=='M') q++;
                if(C[1][(p-1)]=='M') q++;
                if(C[1][p]=='M') q++;
                return(q);
            }
            for(i=(c-1); i<=(c+1); i++)
            {
                if(C[0][i]=='M') q++;
                if(C[1][i]=='M') q++;
            }
            return(q);
        }
        if(l==n)
        {
            if(c==0)
            {
                if(C[(n-1)][0]=='M') q++;
                if(C[(n-1)][1]=='M') q++;
                if(C[n][1]=='M') q++;
                return(q);
            }
            if(c==p)
            {
                if(C[(n-1)][p]=='M') q++;
                if(C[(n-1)][(p-1)]=='M') q++;
                if(C[n][(p-1)]=='M') q++;
                return(q);
            }
            for(i=(c-1); i<=(c+1); i++)
            {
                if(C[n][i]=='M') q++;
                if(C[(n-1)][i]=='M') q++;
            }
            return(q);
        }
        if(c==0)
        {
            for(i=(l-1); i<=(l+1); i++)
            {
                if(C[i][0]=='M') q++;
                if(C[i][1]=='M') q++;
            }
            return(q);
        }
        if(c==n)
        {
            for(i=(l-1); i<=(l+1); i++)
            {
                if(C[i][(p-1)]=='M') q++;
                if(C[i][p]=='M') q++;
            }
            return(q);
        }
        for(i=(l-1); i<=(l+1); i++)
        {
            for(j=(c-1); j<=(c+1); j++)
            {
                if(C[i][j]=='M')
                {
                    q++;
                }
            }
        }
        return(q);
    }
    else
    {
        return(-1);
    }
}
void abrir_quad(int n, int p, int l, int c, char M[n][p])
{
    int i, j;
    n=n-1;
    p=p-1;
    if(l==0)
    {
        if(c==0)
        {
            M[0][1]=' ';
            M[1][1]=' ';
            M[1][0]=' ';
        }
        if(c==p)
        {
            M[0][(p-1)]=' ';
            M[1][(p-1)]=' ';
            M[1][p]=' ';
        }
        if(c!=0)
        {
            if(c!=p)
            {
                for(i=(c-1); i<=(c+1); i++)
                {
                    M[0][i]=' ';
                    M[1][i]=' ';
                }
            }
        }
    }
    if(l==n)
    {
        if(c==0)
        {
            M[(n-1)][0]=' ';
            M[(n-1)][1]=' ';
            M[n][1]=' ';
        }
        if(c==p)
        {
            M[(n-1)][p]=' ';
            M[(n-1)][(p-1)]=' ';
            M[n][(p-1)]=' ';
        }
        if(c!=0)
        {
            if(c!=p)
            {
                for(i=(c-1); i<=(c+1); i++)
                {
                    M[n][i]=' ';
                    M[(n-1)][i]=' ';
                }
            }
        }
    }
    if(l!=0)
    {
        if(l!=n)
        {
            if(c==0)
            {
                for(i=(l-1); i<=(l+1); i++)
                {
                    M[i][0]=' ';
                    M[i][1]=' ';
                }
            }
            if(c==n)
            {
                for(i=(l-1); i<=(l+1); i++)
                {
                    M[i][(p-1)]=' ';
                    M[i][p]=' ';
                }
            }
            if(c!=0)
            {
                if(c!=n)
                {
                    for(i=(l-1); i<=(l+1); i++)
                    {
                        for(j=(c-1); j<=(c+1); j++)
                        {
                            M[i][j]=' ';
                        }
                    }
                }
            }
        }
    }
}
void marcar(int *h, int *w, int n, int p, int *l, int *c, char M[n][p], char C[n][p])
{
    int m;
    printf("\nDigite 0 para marcar e 1 para desmarcar o local\n");
    scanf("%d",&m);
    if(m==0)
    {
        if(M[*l][*c]=='*')
        {
            M[*l][*c]='M';
            if(M[*l][*c]==C[*l][*c])
            {
                ++*w;
            }
            *l=-1;
            *c=-1;
            ++*h;
        }
    }
    if(m==1)
    {
        if(M[*l][*c]=='M')
        {
            if(M[*l][*c]==C[*l][*c])
            {
                --*w;
            }
            M[*l][*c]='*';
            *l=-1;
            *c=-1;
            --*h;
        }
    }
}
int main(int argc, char* argrv)
{
    int n=0, p=0, i, j, k=0, l=-1, c=-1, w=0, h=0;
    tamanho_campo(&n,&p);
    char C[n][p], M[n][p];
    sorteio_mina(&k,n,p,C);
    //printf("\n\n%d",k);
    arrumando_matrizM(n,p,M);
    while(1==1)
    {
        imprimir_campo(n,p,M);
        escolher_quadrado(n,p,&l,&c,M);
        marcar(&h,&w,n,p,&l,&c,M,C);
        if(revelar(n,p,l,c,C)==-1)
        {
            printf("\nGame Over!");
            break;
            break;
        }
        if(revelar(n,p,l,c,C)==0)
        {
            abrir_quad(n,p,l,c,M);
        }
        if(revelar(n,p,l,c,C)!=-2)
        {
            M[l][c]=(revelar(n,p,l,c,C)+48);

        }

        if(k==w)
        {
            if(h==w)
            {
                printf("\nYou Win!");
                break;
                break;
                break;
            }
        }
//HACK
/*
        printf("\n\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j<p; j++)
            {
                printf("%2c",C[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
*/
//HACK
    }
    return 0;
}
