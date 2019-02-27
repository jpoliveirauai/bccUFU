#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#define SIZE 5
typedef struct PRQ{
    int ele;
    int pr;
} PriorityQ;

typedef struct Queue{
    PriorityQ filaP[SIZE];
    int frente, costa;
}que;

void PQinsert(int elem, int pri, que* Q);
void display(que Q);
int Qfull(que Q);
int Qempty(que Q);
que Criafila();
PriorityQ Qdelete(que *Q);
#endif // HEAP_H_INCLUDED
