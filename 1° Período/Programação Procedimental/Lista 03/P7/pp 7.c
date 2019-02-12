#include <stdio.h>
#include <stdlib.h>


enum Naipe {Paus, Copas, Ouros, Espadas };
enum Face { As=1, Dois, Tres, Quatro, Cinco, Seis, Sete, Oito, Nove, Dez, Valete,
            Dama, Rei
          };

typedef struct carta
{
    enum Naipe naipe;
    enum Face face;
} Carta ;

void showCarta(Carta c);
void lerCarta(Carta *c);
int lerCartaArq(Carta *col);
void escreveCartaArq(Carta *col, int n);
void ordenaCarta(Carta *col, int n);
int ComparaCartas(Carta c1, Carta c2);

int main(int argc, char *argv[])
{
    Carta c1[100],c2[100];
    int n;


    lerCarta(c1);
    showCarta(*c1);

return 0;
}

void showCarta(Carta c)
{
    char* faces[] = {"", "As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete",
                     "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"
                    };
    char* naipes[] = {"Paus","Copas", "Ouros","Espadas"};
    printf("%s de %s\n",faces[c.face],naipes[c.naipe]);
}

void lerCarta(Carta *c)
{
    printf("Definir carta:\n");
    printf("Digite o valor de face(As=1, Dois, Tres, Quatro, Cinco, Seis, Sete, Oito, Nove, Dez, Valete=11,Dama=12, Rei=13):");
    scanf("%d",&c->face);
    printf("Digite o valor do naipe(Paus=1, Copas=2, Ouros=3, Espadas=4): ");
    scanf("%d",&c->naipe);
}

int lerCartaArq(Carta *col)
{
    FILE *fd;

    if ((fd= fopen("baralho","r")) == NULL)
    {
        puts("Não posso abrir o Arquivo teste.\n");
        exit(1); /* força o término da execução da rotina */
    }else
    {
        char* faces[] = {"", "As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete",
                         "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"
                        };
        char* naipes[] = {"Paus","Copas", "Ouros","Espadas"};
        printf("%s de %s\n",faces[col->face],naipes[col->naipe]);
    }

    fclose(fd);
}
void escreveCartaArq(Carta *col, int n)
{
    FILE *fd;
    int i=0;
    if ((fd= fopen("baralho","w")) == NULL)
    {
        puts("Não posso abrir o Arquivo teste.\n");
        exit(1); /* força o término da execução da rotina */
    }
    else
    {
        do{
        fprintf(fd,"Definir carta:\n");
        fprintf(fd,"Digite o valor de face: ");
        fscanf(fd,"%d",&col->face);
        fprintf(fd,"Digite o valor do naipe: ");
        fscanf(fd,"%d",&col->naipe);
        i++;
    }while(i<n);
    }
    fclose(fd);
}
