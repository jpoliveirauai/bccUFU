#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>
#include <chrono>
using namespace std;


class Space{
    public:
    int espaco[3][3];
    int vazio[2];
    //Zero é a posição em branco
    void init(){
        srand(time(NULL));
        int aux = rand() % 9, count=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                espaco[i][j]=-1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                while(pertence(aux)){
                    aux = rand() % 9;
                }
                espaco[i][j] = aux;
                count++;
            }
        }

    }
    bool pertence (int x){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(espaco[i][j]==x) return true;
        return false;
    }

    void print(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(espaco[i][j]!= 0)
                    cout << espaco[i][j] << "   ";
                else cout << "    ";
            }
            cout<< endl;
        }

    }
    void achaBranco(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(espaco[i][j] == 0){ vazio[0] = i; vazio[1] = j;}
    }
    void moveAcima(){
        if(vazio[0] > 0){
            espaco[vazio[0]][vazio[1]] = espaco[vazio[0] - 1][vazio[1]];
            espaco[vazio[0] - 1][vazio[1]] = 0;
            achaBranco();
        }
    }

    void moveAbaixo(){
        if(vazio[0] < 2){
            espaco[vazio[0]][vazio[1]] = espaco[vazio[0] + 1][vazio[1]];
            espaco[vazio[0] + 1][vazio[1]] = 0;
            achaBranco();
        }
    }

    void moveDireita(){
        if(vazio[1] < 2){
            espaco[vazio[0]][vazio[1]] = espaco[vazio[0]][vazio[1] + 1];
            espaco[vazio[0]][vazio[1] + 1] = 0;
            achaBranco();
        }
    }
    void moveEsquerda(){
        if(vazio[1] > 0){
            espaco[vazio[0]][vazio[1]] = espaco[vazio[0]][vazio[1] - 1];
            espaco[vazio[0]][vazio[1] - 1] = 0;
            achaBranco();
        }
    }
    int calculaH1(){
        //Calcula o número de peças na posição correta
        int count=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(espaco[i][j] != i*3 +j ){
                    count++;
                }
            }
        }
        return count;
    }
    int calculaH2(){
        //Calcula a distância de Manhatan
        int distancia=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(espaco[i][j] != i*3 +j ){
                    distancia += abs(i - (espaco[i][j] / 3)) + abs(j - (espaco[i][j]%3));
                }
            }
        }
        return distancia;
    }
    bool brancoBordaSuperior(){
        if(vazio[0]==0) return true;
        else return false;
    }
    bool brancoBordaInferior(){
        if(vazio[0]==2) return true;
        else return false;
    }
    bool brancoBordaEsquerda(){
        if(vazio[1]==0) return true;
        else return false;
    }
    bool brancoBordaDireita(){
        if(vazio[1]==2) return true;
        else return false;
    }
    bool ganhou(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                if(espaco[i][j] != i*3 +j )
                    return false;
            }
        return true;
    }
    int multiplica(){
        int resultado = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                resultado += espaco[i][j] * pow(10,3*i+j);
        return resultado;
    }

};

class No{
    public:
    Space espaco;
    int custo;
    int g;
    int h;
    int f;
    vector<No*> filhos;

    //Ações
    No* acima(){
        if(espaco.brancoBordaSuperior()) return NULL;
        No* node = new No;

        node->espaco = this->espaco;
        node->espaco.moveAcima();
        node->custo = 1;
        node->g = g + node->custo;              //Calcula-se a g(n)
        node->calculaHeuristica();
        return node;
    }
    No* abaixo(){
        if(espaco.brancoBordaInferior()) return NULL;
        No* node = new No;
        
        node->espaco = this->espaco;
        node->espaco.moveAbaixo();
        node->custo = 1;
        node->g = g + node->custo;              //Calcula-se a g(n)
        node->calculaHeuristica();
        return node;
    }
    No* esquerda(){
        if(espaco.brancoBordaEsquerda()) return NULL;
        No* node = new No;
        
        node->espaco = this->espaco;
        node->espaco.moveEsquerda();
        node->custo = 1;
        node->g = g + node->custo;              //Calcula-se a g(n)
        node->calculaHeuristica();
        return node;
    }
    No* direita(){
        if(espaco.brancoBordaDireita()) return NULL;
        No* node = new No;
        
        node->espaco = this->espaco;
        node->espaco.moveDireita();
        node->custo = 1;
        node->g = g + node->custo;              //Calcula-se a g(n)
        node->calculaHeuristica();
        return node;
    }

    int calculaHash(){
        return espaco.multiplica();
    }
    bool ehObjetivo(){
        return espaco.ganhou();
    }

    void calculaHeuristica(){
        // h = espaco.calculaH1();
        h = espaco.calculaH2();                           //Função para escolher a Heurística
    }
    int calculaf(){
        f = g+h;
        return f;
    }
    bool operator < (No* b) const{
		return this->f > b->f ? true : false;
	}
    void print(){
        espaco.print();
    }

};


class Borda{
    map<int,No*> visitados;
    priority_queue<No*> * borda = new priority_queue<No*>();
    public:
    void expandir(No* root){
        int nNos = 1;
        No *dir,*esq, *ac,*ab;
        // cout<<"ROOT:"<<endl;
        // root->print();
        borda->push(root);
        visitados.insert(make_pair(root->calculaHash(),root));
        while(!root->ehObjetivo()&&borda->size() > 0){
            dir = root -> direita();
            esq = root -> esquerda();
            ab  = root -> abaixo();
            ac  = root -> acima();
            // cout<<dir<<endl;
            if(dir!=0){
                if(visitados.find(dir->calculaHash()) == visitados.end()){
                    borda->push(dir);
                    nNos++;
                }
            }
            if(esq!=0){
                if(visitados.find(esq->calculaHash()) == visitados.end()){
                    borda->push(esq);
                    nNos++;
                }
            }
            if(ac!=0){
                if(visitados.find(ac->calculaHash()) == visitados.end()){
                    borda->push(ac);
                    nNos++;
                }
            }
            if(ab!=0){
                if(visitados.find(ab->calculaHash()) == visitados.end()){
                    borda->push(ab);
                    nNos++;
                }
                
            }
            
            borda->top()->print();
            cout << endl;
            //cout<<borda->top()<<endl<<endl;
            root = borda->top();
            visitados.insert(make_pair(root->calculaHash(),root));
            borda->pop();
        }
        cout<<"Número de nós gerados: "<<nNos<<endl;
    }
    
    
};