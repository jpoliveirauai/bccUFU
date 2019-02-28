#include <iostream>
#include "Astar.cpp"
#include <cmath>
#include <queue>
using namespace std;

/* struct comp1{
    bool operator()( Node *a, Node *b){
		return a->f > b->f;
	}
};
 */
int main(int argc, char const *argv[]){
    /* Space *s = new Space();
    Node *n = new Node(s);
    n->setG(0);                             //Seta-se g para o nó inicial, os demais são acrescidos de 1
    cout<< "N: "<<endl;
    n->print();

    priority_queue <Node*, vector<Node*>,comp> borda1;
    n->calculaF(2);
    borda1.push(n);
    cout<<endl;
    Node *n1 = n->Direita();
    cout<< "N1: "<<endl;
    n1->print();
    n1->calculaF(2);
    borda1.push(n1);
    cout<<endl<<endl<<endl<<endl;
    // while(!borda1.empty()){
    //     borda1.top()->print();
    //     cout<<endl;
    //     borda1.pop();
    // }
    n->calculaF(1);
    cout<<endl<<"F1: "<<n->f<<endl;
    n->calculaF(2);
    cout<<endl<<"F2: "<<n->f<<endl;
    borda1.push(n1);
    cout<<endl<<endl<<endl<<endl;
    n1->calculaF(1);
    cout<<endl<<"F1: "<<n1->f<<endl;
    n->calculaF(2);
    cout<<endl<<"F2: "<<n1->f<<endl;
    borda1.push(n1);
    // while(!borda1.empty()){
    //     borda1.top()->print();
    //     cout<<endl;
    //     borda1.pop();
    // } */
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