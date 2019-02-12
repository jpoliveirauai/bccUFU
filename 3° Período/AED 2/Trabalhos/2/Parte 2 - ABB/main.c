#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"
#include <string.h>



void display_menu();





int main()
{
    Arv arvore, no;                     // a arvore sera utilizada para manter o endereco da arvore
    reg elemento, *verificador;         // elemento servira para inserir novos dados a arvore, e verificador como recebimento de funcoes de busca
    int laco=1, retorno, acao, acao_aux, ini, fim, arv_max=0;
    arvore = NULL;
    no = NULL;


    strcpy(elemento.curso,"bcc");
    strcpy(elemento.nome,"lucas");
    elemento.idade = 330;
    no = cria_arvore_binaria();
    insere_ordenado(&no,elemento);
    elemento.idade = 220;
    insere_ordenado(&no,elemento);
    elemento.idade= 550;
    insere_ordenado(&no,elemento);

    strcpy(elemento.curso,"");
    strcpy(elemento.nome,"");
    elemento.idade = 0;
    while(laco){

        display_menu();
        scanf("%d", &acao);

        switch(acao){

        case 1:
            if(arvore_binaria_vazia(arvore)){
                arvore = cria_arvore_binaria();
                printf("CRIADA COM SUCESSO\n");
            }
            /*else if(arvore_binaria_vazia(no)){
                no = cria_arvore_binaria();
                arv_max = 1;
            }*/
            else{
                printf("EXISTE UMA ARVORE, PARA CRIAR UMA NOVA LIBERE A ATUAL!\n");
            }
            break;

        case 2:
            libera_arvore_binaria(arvore);
            printf("LIBERADA COM SUCESSO\n");
            break;

        case 3:
            printf("1 - pre ordem\n");
            printf("2 - em ordem \n");
            printf("opcao: ");
            scanf("%d",&acao_aux);
            if(acao_aux == 1){
                exibe_arvore_binaria(arvore);
            }
            else if(acao_aux == 2){
                exibe_ordenado(arvore);
            }
            else{
                printf("opcao invalida, tentar novamente!\n");
            }
            break;

        case 4:

            printf("Digite o nome do aluno: ");
            scanf("%s", elemento.nome);
            fflush(stdin);
            printf("Digite a idade do aluno: ");
            scanf("%d", &elemento.idade);
            fflush(stdin);
            printf("Digite o curso do aluno: ");
            scanf("%s", elemento.curso);

            if(insere_ordenado(&arvore,elemento)){

                printf("\nINSERIDO COM SUCESSO\n");
            }
            else printf("\nNAO FOI POSSIVEL INSERIR\n");
            break;

        case 5:
            acao_aux = 0;
            printf("Digite a idade do aluno que deseja remover: ");
            scanf("%d", &acao_aux);
            if(remove_arv_binaria_ordenado(&arvore,acao_aux)){
                printf("\nREMOVIDO COM SUCESSO\n");
            }
            else printf("\nERRO NA REMOCAO\n");
            break;

        case 6:
            acao_aux = -1;
            printf("Digite a chave que deseja buscar: ");
            scanf("%d", &acao_aux);

            verificador = busca_binaria(arvore,acao_aux);

            if(verificador){
                printf("Nome do aluno: %s \n", verificador->nome);
                printf("Idade do aluno: %d \n", verificador->idade);
                printf("Curso do aluno: %s \n", verificador->curso);
            }
            else{
                printf("REGISTRO NAO ENCONTRADO\n");
            }
            break;


        case 7:
            acao_aux = 0;
            printf("1 - aluno mais velho\n");
            printf("2 - quantidade de alunos maiores de idade\n");
            printf("3 - quantidade de alunos em determinada faixa etaria\n");
            printf("4 - quantidade de nos que possui apenas 1 filho\n");
            printf("5 - Eh uma arvore completa?\n");
            printf("6 - Altura da arvore\n");
            printf("Opcao: ");
            scanf("%d", &acao_aux);

                if(acao_aux == 1){
                    verificador = maior(arvore);
                    printf("Nome do aluno: %s \n", verificador->nome);
                    printf("Idade do aluno: %d \n", verificador->idade);
                    printf("Curso do aluno: %s \n", verificador->curso);
                }
                else if(acao_aux == 2){
                    printf("Qntd : %d \n", de_maior(arvore));
                }
                else if(acao_aux == 3){
                        printf("Digite a faixa etaria minima: ");
                        scanf("%d", &ini);
                        printf("Digite a faixa etaria maxima: ");
                        scanf("%d", &fim);
                        printf("\nQuantidade de alunos entre %d e %d : %d \n" ,ini , fim, qnt_nos(arvore,ini,fim));
                }
                else if(acao_aux == 4){
                    printf("Qnt : %d\n", um_filho(arvore));
                }
                else if(acao_aux == 5){
                    if(completa(arvore)){
                        printf("EH UMA ARVORE COMPLETA\n");
                    }else printf("NAO EH UMA ARVORE COMPLETA\n");
                }
                else if(acao_aux == 6){
                    printf("Altura da arvore: %d \n", altura_arvore_binaria(arvore));
                }
                else{
                    printf("\nOPCAO INVALIDA!!!\n");
                }

                break;

        case 8:
            printf("NAO DISPONIVEL AINDA, SOMENTE SE VOCE COMPRAR O APP\n");
            arvore = juntar(arvore,no);
            break;

        case 9:
            laco = 0;
            break;

        }
        printf("\n");
        system("pause");
        system("cls");
    }
    printf("fechando...\n\n");


    return 0;
}






void display_menu(){

    printf("\t\t\t MENU ARVORE BINARIA DE BUSCA \t\t\t\n");
    printf("1 - cria arvore \n");
    printf("2 - libera arvore \n");
    printf("3 - exibe arvore \n");
    printf("4 - insere elemento \n");
    printf("5 - remove elemento \n");
    printf("6 - busca por registro \n");
    printf("7 - dados da arvore \n");
    printf("8 - juntar duas arvores \n");
    printf("9 - sair\n");
    printf("Digite a operacao desejada: ");

}
