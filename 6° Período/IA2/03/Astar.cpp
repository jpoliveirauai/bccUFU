#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;


class Space{
    int m[3][3];
    int brancoI, brancoJ;

    bool pertence (int x){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(m[i][j]==x) return true;
        return false;
    }

    public:

    Space(){

        m[0][0] = 1;
        m[0][1] = 2;
        m[0][2] = 3;
        m[1][0] = 4;
        m[1][1] = 7;
        m[1][2] = 6;
        m[2][0] = 8;
        m[2][1] = 5;
        m[2][2] = 9;    //Branco

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(m[i][j]==9){
                    brancoI = i;
                    brancoJ = j;
                }
            }
        }
    }

    void print(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(m[i][j]!= 9)
                    cout << m[i][j] << "   ";
                else cout << "    ";
            }
            cout<< endl;
        }

    }
    //FUNÇÕES QUE MOVEM O BRANCO PARA AS DIREÇÕES
    int moveAcima(){
        if(brancoI > 0){
            m[brancoI][brancoJ] = m[brancoI-1][brancoJ];
            m[brancoI-1][brancoJ] = 9;
            brancoI--;
            return 1;
        }else return 0;
    }
    int moveAbaixo(){
        if(brancoI < 2){
            m[brancoI][brancoJ] = m[brancoI+1][brancoJ];
            m[brancoI+1][brancoJ] = 9;
            brancoI++;
            return 1;
        }else return 0;
    }
    int moveEsquerda(){
        if(brancoJ > 0){
            m[brancoI][brancoJ] = m[brancoI][brancoJ-1];
            m[brancoI][brancoJ-1] = 9;
            brancoJ--;
            return 1;
        }else return 0;
    }
    int moveDireita(){
        if(brancoJ < 2){
            m[brancoI][brancoJ] = m[brancoI][brancoJ+1];
            m[brancoI][brancoJ+1] = 9;
            brancoJ++;
            return 1;
        }else return 0;
    }
    int h1(){
        //Calcula o número de peças na posição incorreta
        int count=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(m[i][j] != 1+i*3 +j )
                    count++;
            }
        }
        return count;
    }
    int h2(){
        //Calcula a distância de Manhatan
        int distancia=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(m[i][j] != 1+i*3 +j )
                    distancia += abs(i - (m[i][j] / 3)) + abs(j - (m[i][j]%3));
            }
        }
        return distancia;
    }
    bool ordenado(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                if(m[i][j] != 1+i*3 +j )
                    return false;
            }
        return true;
    }
    unsigned int multiplica(){
        unsigned int resultado = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                resultado += m[i][j] * pow(9,3*i+j);
        return resultado;
    }
};

class Node{
    private:
    int g,custo,h1,h2;
    Space *espaco;
    vector<Node*> filhos;
    unsigned int hash;

    public:
    int f;
    Node* pai;
    Node(Space *s){
        espaco = s;
        calcHeuristicas();
        custo = 1;
        hash = espaco->multiplica();
    }
    void printTudo(int n){
        cout<<"Profundidade: "<<g<<endl;
        //cout<< calcHeuristicas(1) <<endl

        // cout<<"Custo: "<<g;
    }
    int calculaF(int n){
        if(n==1){
            f = g+h1;
            // cout<<"H1: "<<h1<<"   H2: "<<h2<<endl<<"   G: "<<g<<endl;
            return f;
        } 
        else{
            if(n==2) {
                f = g+h2;
                return f;
            }else {
                cout<<"Heurística não setada!!!"<<endl;
                return -1;
            }
        }
    }
    
    void setG(int n){
        g = n;
    }
    void print(){
        espaco->print();
    }
    unsigned int getHash(){
        return hash;
    }
    bool ehObjetivo(){
        return espaco->ordenado();
    }
    void calcHeuristicas(){
        h1 = espaco->h1();
        h2 = espaco->h2();
    }
    //Ações de movimentação
    Node* Acima(){
        Space *s = new Space();                         
        memcpy(s,this->espaco,sizeof(*espaco));         //Copia o conteúdo de espaco para s
        if(s->moveAcima()){                             //Se for possível ir para cima
            Node *n = new Node(s);
            n->pai = this;
            filhos.push_back(n);                        //Insere no vetor de filhos
            n->setG(g+1);                               //Abstraído para economizar getters/setters
            return n;
        }else return NULL;
    }

    Node* Abaixo(){
        Space *s = new Space();                         
        memcpy(s,this->espaco,sizeof(*espaco));         //Copia o conteúdo de espaco para s
        if(s->moveAbaixo()){                             //Se for possível ir para baixo
            Node *n = new Node(s);
            n->pai = this;
            filhos.push_back(n);                        //Insere no vetor de filhos
            n->setG(g+1);                               //Abstraído para economizar getters/setters
            return n;
        }else return NULL;
    }

    Node* Esquerda(){
        Space *s = new Space();                         
        memcpy(s,this->espaco,sizeof(*espaco));         //Copia o conteúdo de espaco para s
        if(s->moveEsquerda()){                         //Se for possível ir para a esquerda
            Node *n = new Node(s);
            n->pai = this;
            filhos.push_back(n);                        //Insere no vetor de filhos
            n->setG(g+1);                               //Abstraído para economizar getters/setters
            return n;
        }else return NULL;
    }
    Node* Direita(){
        Space *s = new Space();                         
        memcpy(s,this->espaco,sizeof(*espaco));         //Copia o conteúdo de espaco para s
        if(s->moveDireita()){                             //Se for possível ir para baixo
            Node *n = new Node(s);
            n->pai = this;
            filhos.push_back(n);                        //Insere no vetor de filhos
            n->setG(g+1);                               //Abstraído para economizar getters/setters
            return n;
        }else return NULL;
    }

    Node* copia(){
        Space *s = new Space();                         
        memcpy(s,this->espaco,sizeof(*espaco));
        Node *n = new Node(s);
        n->setG(g);
        return n;
    }
};

struct comp{
    bool operator()( Node *a, Node *b){
		return a->f > b->f;
	}
};



class Borda{
    private:
    int nNos1,nNosG1;
    int nNos2,nNosG2;
    map<unsigned int, Node*> visitadosH1;
    map<unsigned int, Node*> visitadosH2;
    priority_queue <Node*, vector<Node*>,comp> borda1;
    priority_queue <Node*, vector<Node*>,comp> borda2;
    Node *root1, *root2;
    Node *ac1,*ab1,*dir1,*esq1;
    Node *ac2,*ab2,*dir2,*esq2;
    bool vazio1,vazio2;
    public:
    
    Borda(Node *root){
        nNos1=1;
        nNos2=1;
        vazio1=vazio2=true;
        root1 = root->copia();
        root2 = root->copia();
        root1->calculaF(1);
        borda1.push(root1);

        root2->calculaF(2);
        borda2.push(root2);
    }
    
    void expandir(){
        while(!root1->ehObjetivo() || !root2->ehObjetivo()){
            if(!root1->ehObjetivo()){
                if(vazio1){
                    root1 = borda1.top();
                    borda1.pop();
                    nNos1++;
                    // root1->print();
                    // cout<<endl;
                    visitadosH1.insert(make_pair(root1->getHash(),root1));
                    ac1  = root1->Acima();
                    ab1  = root1->Abaixo();
                    esq1 = root1 ->Esquerda();
                    dir1  = root1->Direita();
                    if(ac1!=NULL){
                        if(visitadosH1.find(ac1->getHash())==visitadosH1.end()){
                            ac1->calculaF(1);
                            visitadosH1.insert(make_pair(ac1->getHash(),ac1));
                            borda1.push(ac1);
                            nNosG1++;
                        }
                    }
                    if(ab1!=NULL){
                        if(visitadosH1.find(ab1->getHash())==visitadosH1.end()){
                            ab1->calculaF(1);
                            visitadosH1.insert(make_pair(ab1->getHash(),ab1));
                            borda1.push(ab1);
                            nNosG1++;
                        }
                    }
                    if(esq1!=NULL){
                        if(visitadosH1.find(esq1->getHash())==visitadosH1.end()){
                            esq1->calculaF(1);
                            visitadosH1.insert(make_pair(esq1->getHash(),esq1));
                            borda1.push(esq1);
                            nNosG1++;
                        }
                    }
                    if(dir1!=NULL){
                        if(visitadosH1.find(dir1->getHash())==visitadosH1.end()){
                            dir1->calculaF(1);
                            visitadosH1.insert(make_pair(dir1->getHash(),dir1));
                            borda1.push(dir1);
                            nNosG1++;
                        }
                    }
                    if(borda1.size()==0)vazio1 = false;
                }
            }


            if(!root2->ehObjetivo()){
                if(vazio2){
                    root2 = borda2.top();
                    borda2.pop();
                    nNos2++;
                    // root2->print();
                    visitadosH2.insert(make_pair(root2->getHash(),root2));
                    ac2  = root2->Acima();
                    ab2  = root2->Abaixo();
                    esq2 = root2 ->Esquerda();
                    dir2  = root2->Direita();
                    if(ac2!=NULL){
                        if(visitadosH2.find(ac2->getHash())==visitadosH2.end()){
                            ac2->calculaF(2);
                            visitadosH2.insert(make_pair(ac2->getHash(),ac2));
                            borda2.push(ac2);
                            nNosG2++;
                        }
                    }
                    if(ab2!=NULL){
                        if(visitadosH2.find(ab2->getHash())==visitadosH2.end()){
                            ab2->calculaF(2);
                            visitadosH2.insert(make_pair(ab2->getHash(),ab2));
                            borda2.push(ab2);
                            nNosG2++;
                        }
                    }
                    if(esq2!=NULL){
                        if(visitadosH2.find(esq2->getHash())==visitadosH2.end()){
                            esq2->calculaF(2);
                            visitadosH2.insert(make_pair(esq2->getHash(),esq2));
                            borda2.push(esq2);
                            nNosG2++;
                        }
                    }
                    if(dir2!=NULL){
                        if(visitadosH2.find(dir2->getHash())==visitadosH2.end()){
                            dir2->calculaF(2);
                            visitadosH2.insert(make_pair(dir2->getHash(),dir2));
                            borda2.push(dir2);
                            nNosG2++;
                        }
                    }
                    if(borda2.size()==0)vazio2=false;
                }
            }
        }
        cout<<"H1: "<<endl;
        root1->print();
        cout<<"Número de nós explorados por H1: "<<nNos1<<endl;
        cout<<"Número de nós gerados por H1: "<<nNosG1<<endl;
        root1->printTudo(1);
        cout<<endl;

        cout<<endl;
        cout<<"H2: "<<endl;
        root2->print();
        cout<<"Número de nós explorados por H2: "<<nNos2<<endl;
        cout<<"Número de nós gerados por H2: "<<nNosG2<<endl;
        root2->printTudo(2);
        cout<<endl;
    }
};