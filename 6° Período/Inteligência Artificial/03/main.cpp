#include <iostream>
#include "Astar.cpp"
#include <cmath>
#include <queue>
using namespace std;


int main(int argc, char const *argv[]){
    Space *s = new Space();
    Node *n = new Node(s);
    n->setG(0);                             //Seta-se g para o nó inicial, os demais são acrescidos de 1
    cout<< "ROOT: "<<endl;
    n->print();
    cout<<endl;
    Borda *b = new Borda(n);
    b->expandir();
    return 0;
}