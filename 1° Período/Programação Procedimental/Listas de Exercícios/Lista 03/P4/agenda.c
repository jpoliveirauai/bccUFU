#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct horario
{
    int hora;
    int minuto;
} Hora;

typedef struct agenda
{
    Data data;
    Hora hora_a;
    char descricao[100];

} Agenda;

/*Prototipos de Funcoes*/
int cadastrar_agenda(Agenda *, int );
Agenda pegar_data(char *);
Agenda pegar_hora(char *);
void ordenar_agenda(Agenda *,int);
int compara(Agenda inicial, Agenda outro);

int main ()
{
    int i, n = 1, teste = 0;
    char op[10];
    Agenda agenda[100];
    FILE *fd;
    /*-----------------------*/

    printf("Construo um cadastro de eventos em um arquivo de texto (.txt).\n\n");

    if((fd = fopen("agenda.txt","w+")) == NULL)
    {
        printf("Erro na criacao do arquivo!\n\n");
        exit(1);
    }
    else
    {
        do
        {
            teste = cadastrar_agenda(agenda, n - 1);

            printf("Deseja cadastrar um compromisso? (Digite SIM ou NAO)\n");
            fflush(stdin);
            gets(op);
            fflush(stdin);
            printf("\n");

            for(i = 0; i < strlen(op); i++)
            {
                op[i] = toupper(op[i]);
            }

            while((strcmp(op,"NAO") != 0) && (strcmp(op,"SIM") != 0)||(strlen(op) > 3))
            {
                printf("Opcao desconhecida.\n\n");
                printf("Deseja cadastrar um compromisso? (Digite SIM ou NAO )\n");
                fflush(stdin);
                gets(op);
                fflush(stdin);
                printf("\n");

                for(i = 0; i < strlen(op); i++)
                {
                    op[i] = toupper(op[i]);
                }
            }

            n++;

        }
        while(strcmp(op,"NAO") != 0);

        n--;

        printf("Agenda desordenada:\n");
        for(i = 0; i < n; i++)
        {
            printf("%02d/%02d/%04d\n",agenda[i].data.dia,agenda[i].data.mes,agenda[i].data.ano);
            printf("%02d:%02d\n",agenda[i].hora_a.hora,agenda[i].hora_a.minuto);
            printf("%s\n\n",agenda[i].descricao);
        }
        printf("\n");

        ordenar_agenda(agenda,n);

        printf("Agenda ordenada:\n");
        for(i = 0; i < n; i++)
        {
            printf("%02d/%02d/%04d\n",agenda[i].data.dia,agenda[i].data.mes,agenda[i].data.ano);
            printf("%02d:%02d\n",agenda[i].hora_a.hora,agenda[i].hora_a.minuto);
            printf("%s\n\n",agenda[i].descricao);
        }
        printf("\n");


        fprintf(fd,"Agenda ordenados:\n");

        for(i = 0; i < n; i++)
        {
            fprintf(fd,"%02d/%02d/%04d-",agenda[i].data.dia,agenda[i].data.mes,agenda[i].data.ano);
            fprintf(fd,"%02d:%02d-",agenda[i].hora_a.hora,agenda[i].hora_a.minuto);
            fprintf(fd,"%s",agenda[i].descricao);
            fprintf(fd,"\n\n");
        }
    }
    fclose(fd);

    return 0;
}

int cadastrar_agenda(Agenda *agenda, int n)
{
    Agenda compr;
    char data[11], horario[6];

    do
    {
        printf("Digite a data do compromisso com formato dd/mm/aaaa :\n");
        fflush(stdin);
        gets(data);
        fflush(stdin);
        printf("\n");

        if((data[2] != '/')||(data[5] != '/')||(strlen(data) > 10))
        {
            printf("Formato Incorreto da Data!\n\n");
            exit(1);
        }

        compr.data = pegar_data(data).data;

        if(((compr.data.dia <= 0)||(compr.data.dia > 31))||((compr.data.mes <= 0)||(compr.data.mes > 12))||(compr.data.ano <= 0))
        {
            printf("Digitou uma data invalida.\n\n");
        }

    }
    while(((compr.data.dia <= 0)||(compr.data.dia > 31))||((compr.data.mes <= 0)||(compr.data.mes > 12))||(compr.data.ano <= 0));

    do
    {
        printf("Digite o horario do compromisso com formato hh:mm :\n");
        fflush(stdin);
        gets(horario);
        fflush(stdin);
        printf("\n");

        if((horario[2] != ':')||(strlen(horario) > 5))
        {
            printf("Formato Incorreto do Horario!\n\n");
            exit(1);
        }
        compr.hora_a = pegar_hora(horario).hora_a;

        if(((compr.hora_a.hora < 0)||(compr.hora_a.hora > 23))||((compr.hora_a.minuto < 0)||(compr.hora_a.minuto > 59)))
        {
            printf("Digitou um horario errado.\n\n");
        }
    }
    while(((compr.hora_a.hora < 0)||(compr.hora_a.hora > 23))||((compr.hora_a.minuto < 0)||(compr.hora_a.minuto > 59)));


    printf("Digite a descricao do compromisso:\n");
    fflush(stdin);
    gets(compr.descricao);
    fflush(stdin);
    printf("\n");

    system("CLS");

    agenda[n] = compr;

    return 0;
}

Agenda pegar_data(char *data)
{
    int i;
    char dia[3], mes[3], ano[5];
    Agenda data_compr;

    for(i = 0; i < 2; i++)
    {
        dia[i] = data[i];
    }
    for(i = 0; i < 2; i++)
    {
        mes[i] = data[i+3];
    }
    for(i = 0; i < 4; i++)
    {
        ano[i] = data[i+6];
    }
    dia[2] = '\0';
    mes[2] = '\0';
    ano[4] = '\0';

    data_compr.data.dia = atoi(dia);
    data_compr.data.mes = atoi(mes);
    data_compr.data.ano = atoi(ano);

    return data_compr;
}

Agenda pegar_hora(char *horario)
{
    int i;
    char hora[3], minuto[3];
    Agenda hora_compr;

    for(i = 0; i < 2; i++)
    {
        hora[i] = horario[i];
    }
    for(i = 0; i < 2; i++)
    {
        minuto[i] = horario[i+3];
    }

    hora[2] = '\0';
    minuto[2] = '\0';

    hora_compr.hora_a.hora = atoi(hora);
    hora_compr.hora_a.minuto = atoi(minuto);

    return hora_compr;
}

void ordenar_agenda(Agenda *agenda, int n)
{
    int i, j;
    Agenda aux;

    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            if(compara(agenda[i],agenda[j]) == 1)
            {
                aux = agenda[j];
                agenda[j] = agenda[i];
                agenda[i] = aux;
            }
        }
    }
}

int compara(Agenda inicial, Agenda outro)
{
    if(inicial.data.ano < outro.data.ano) return 0;
    if(inicial.data.ano > outro.data.ano) return 1;
    if(inicial.data.ano == outro.data.ano)
    {
        if(inicial.data.mes < outro.data.mes) return 0;
        if(inicial.data.mes > outro.data.mes) return 1;
        if(inicial.data.mes == outro.data.mes)
        {
            if(inicial.data.dia < outro.data.dia) return 0;
            if(inicial.data.dia > outro.data.dia) return 1;
            if(inicial.data.dia == outro.data.dia)
            {
                if(inicial.hora_a.hora < outro.hora_a.hora) return 0;
                if(inicial.hora_a.hora > outro.hora_a.hora) return 1;
                if(inicial.hora_a.hora == outro.hora_a.hora)
                {
                    if(inicial.hora_a.minuto < outro.hora_a.minuto) return 0;
                    if(inicial.hora_a.minuto > outro.hora_a.minuto) return 1;
                    if(inicial.hora_a.minuto == outro.hora_a.minuto) return 0;
                }
            }
        }
    }
return 0;
}


