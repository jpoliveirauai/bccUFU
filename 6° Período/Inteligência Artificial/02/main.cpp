#include <queue>
#include <iostream>
#include <stack>
#include "classes.hpp"
using namespace std;


int main() {
    //Criando e sujando o espaço
    Space espaco;
    espaco.init();

    espaco.sujar('D');
//    espaco.sujar('E');
    
    //Criando e setando a raiz
    No root;
    root.setEspaco(espaco);
    root.setCusto(0);
    root.setEstado('E');												//Começando pela esquerda
    root.setProfundidade(0);
    Borda b;

//    cout<< "DFS"<< endl;
//    b.expandirDFS(&root,100);
    
    
    cout<< endl<< "BFS"<< endl;
    root.printaEstado();
    b.expandirBFS(&root,1000);

    return 0;
}
