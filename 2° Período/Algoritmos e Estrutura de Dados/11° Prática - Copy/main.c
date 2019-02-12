#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include <string.h>
static void print_stack(const Stack *stack) {

	ListElmt           *element;

	int                *data, size,i;
	fprintf(stdout, "Stack size is %d\n", size = stack_size(stack));
	i = 0;
	element = list_head(stack);
	while (i < size) {

	   data = list_data(element);
	   fprintf(stdout, "stack[%03d]=%03d\n", i, *data);
	   element = list_next(element);
	   i++;

	}
	return;
}

int Prioridade(char c, char t){
    int pc,pt;
    if(c == '*' || c == '/')
        pc = 2;
    if(c == '+' || c == '-')
        pc = 1;
    if(c == '(')
        pc = 4;
    if(t == '*' || t == '/')
        pt = 2;
    if(t == '+' || t == '-')
        pt = 1;
    if(t == '(')
        pt = 0;
    return (pc > pt);
}

int main()
{
    int i;
    char texto[30];
    char *data,t;
    Stack stack;
    stack_init(&stack,free);
    printf("Digite sua expressao:\n");
    fflush(stdin);
    gets(texto);
      fflush(stdin);
    data = (char*)malloc(sizeof(char));
    for(i=0; i<strlen(texto); i++)
    {
        if(texto[i]>= 'a' && texto[i]<= 'z')
        {
            printf("%c", texto[i]);
        }
        if(texto[i]== '+' || texto[i]== '-' ||texto[i]== '*' || texto[i]== '/')
        {
           if(stack.head==NULL){
               stack_push(&stack,(void*)&texto[i]);
           }


            }
       }
       data = stack_peek(&stack);
printf("%c\n",*data);
stack_pop(&stack,data);
    print_stack(&stack);

            printf("\n");
                printf("\n");
return 0;
}
