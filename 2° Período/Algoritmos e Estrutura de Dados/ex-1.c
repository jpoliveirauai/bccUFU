#include <stdio.h>
#include <stdlib.h>
#include"list"
#include"stack"

int main(int argc, char **argv){
    Stack stack;
    int *data,i;
    stack_init(&stack, free);
    fprintf(stdout, "Pushing 10 elements\n");
    for (i = 0; i < 10; i++){
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = i + 1;
        if (stack_push(&stack, data) != 0)
            return 1;

    }
    print_stack(&stack);

    fprintf(stdout, "Popping 5 elements\n");

    for (i = 0; i < 5; i++)
    {

        if (stack_pop(&stack, (void **)&data) == 0)
            free(data);
        else
            return 1;

    }

    print_stack(&stack);

    fprintf(stdout, "Pushing 100 and 200\n");

    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;

    *data = 100;

    if (stack_push(&stack, data) != 0)
        return 1;

    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;

    *data = 200;

    if (stack_push(&stack, data) != 0)
        return 1;

    print_stack(&stack);

    if ((data = stack_peek(&stack)) != NULL)
        fprintf(stdout, "Peeking at the top element...Value=%03d\n", *data);
    else
        fprintf(stdout, "Peeking at the top element...Value=NULL\n");

    print_stack(&stack);

    fprintf(stdout, "Popping all elements\n");

    while (stack_size(&stack) > 0)
    {

        if (stack_pop(&stack, (void **)&data) == 0)
            free(data);

    }

    if ((data = stack_peek(&stack)) != NULL)
        fprintf(stdout, "Peeking at an empty stack...Value=%03d\n", *data);
    else
        fprintf(stdout, "Peeking at an empty stack...Value=NULL\n");

    print_stack(&stack);

    /*****************************************************************************
    *           *
    *  Destroy the stack.    *
    *           *
    *****************************************************************************/

    fprintf(stdout, "Destroying the stack\n");
    stack_destroy(&stack);

    return 0;

}
