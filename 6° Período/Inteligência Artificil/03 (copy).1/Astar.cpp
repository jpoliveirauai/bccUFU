#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <algorithm>
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
        srand(time(NULL));
        int aux = rand() % 9;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                m[i][j]=-1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                while(pertence(aux)){
                    aux = rand() % 9;
                }
                m[i][j] = aux;
                if(aux==0){
                    brancoI = i;
                    brancoJ = j;
                }
            }
        }
    }

    void print(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(m[i][j]!= 0)
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
            m[brancoI-1][brancoJ] = 0;
            brancoI--;
            return 1;
        }else return 0;
    }
    int moveAbaixo(){
        if(brancoI < 2){
            m[brancoI][brancoJ] = m[brancoI+1][brancoJ];
            m[brancoI+1][brancoJ] = 0;
            brancoI++;
            return 1;
        }else return 0;
    }
    int moveEsquerda(){
        if(brancoJ > 0){
            m[brancoI][brancoJ] = m[brancoI][brancoJ-1];
            m[brancoI][brancoJ-1] = 0;
            brancoJ--;
            return 1;
        }else return 0;
    }
    int moveDireita(){
        if(brancoJ < 2){
            m[brancoI][brancoJ] = m[brancoI][brancoJ+1];
            m[brancoI][brancoJ+1] = 0;
            brancoJ++;
            return 1;
        }else return 0;
    }
    int h1(){
        //Calcula o número de peças na posição incorreta
        int count=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(m[i][j] != i*3 +j )
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
                if(m[i][j] != i*3 +j )
                    distancia += abs(i - (m[i][j] / 3)) + abs(j - (m[i][j]%3));
            }
        }
        return distancia;
    }
    bool ordenado(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                if(m[i][j] != i*3 +j )
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
    Node(Space *s){
        espaco = s;
        calcHeuristicas();
        custo = 1;
        hash = espaco->multiplica();
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
	bool operator()(const Node& a,const Node& b){
		return a.f > b.f;
	}
};

bool wayToSort(Node i, Node j) { return i.f > j.f; }

class FilaPrioridades{
    //push
    //pop
    //top
    private:
    vector<Node> fila;

    public:
    
    
    void push(Node n){
        fila.push_back(n);
        sort(fila.begin(), fila.end(), wayToSort);
    }
    void pop(){
        fila.erase (fila.begin());
    }
    Node* top(){
        return &fila.front();
    }
    int size(){
        return fila.size();
    }
};

class Borda{
    private:
    int nNos1;
    int nNos2;
    map<unsigned int, Node*> visitadosH1;
    map<unsigned int, Node*> visitadosH2;
    FilaPrioridades borda1;
    FilaPrioridades  borda2;
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
        borda1.push(*root1);

        root2->calculaF(2);
        borda2.push(*root2);
    }
    
    void expandir(){
        while(!root1->ehObjetivo() || !root2->ehObjetivo()){
            if(!root1->ehObjetivo()){
                if(vazio1){
                    memcpy(root1,borda1.top(),sizeof(Node));
                    borda1.pop();
                    nNos1++;
                    root1->print();
                    cout<<endl;
                    visitadosH1.insert(make_pair(root1->getHash(),root1));
                    ac1  = root1->Acima();
                    ab1  = root1->Abaixo();
                    esq1 = root1 ->Esquerda();
                    dir1  = root1->Direita();
                    if(ac1!=NULL){
                        if(visitadosH1.find(ac1->getHash())==visitadosH1.end()){
                            ac1->calculaF(1);
                            visitadosH1.insert(make_pair(ac1->getHash(),ac1));
                            borda1.push(*ac1);
                            // nNos1++;
                        }
                    }
                    if(ab1!=NULL){
                        if(visitadosH1.find(ab1->getHash())==visitadosH1.end()){
                            ab1->calculaF(1);
                            visitadosH1.insert(make_pair(ab1->getHash(),ab1));
                            borda1.push(*ab1);
                            // nNos1++;
                        }
                    }
                    if(esq1!=NULL){
                        if(visitadosH1.find(esq1->getHash())==visitadosH1.end()){
                            esq1->calculaF(1);
                            visitadosH1.insert(make_pair(esq1->getHash(),esq1));
                            borda1.push(*esq1);
                            // nNos1++;
                        }
                    }
                    if(dir1!=NULL){
                        if(visitadosH1.find(dir1->getHash())==visitadosH1.end()){
                            dir1->calculaF(1);
                            visitadosH1.insert(make_pair(dir1->getHash(),dir1));
                            borda1.push(*dir1);
                            // nNos1++;
                        }
                    }
                    if(borda1.size()==0)vazio1 = false;
                }
            }


            if(!root2->ehObjetivo()){
                if(vazio2){
                    memcpy(root2,borda2.top(),sizeof(Node));
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
                            borda2.push(*ac2);
                            // nNos2++;
                        }
                    }
                    if(ab2!=NULL){
                        if(visitadosH2.find(ab2->getHash())==visitadosH2.end()){
                            ab2->calculaF(2);
                            visitadosH2.insert(make_pair(ab2->getHash(),ab2));
                            borda2.push(*ab2);
                            // nNos2++;
                        }
                    }
                    if(esq2!=NULL){
                        if(visitadosH2.find(esq2->getHash())==visitadosH2.end()){
                            esq2->calculaF(2);
                            visitadosH2.insert(make_pair(esq2->getHash(),esq2));
                            borda2.push(*esq2);
                            // nNos2++;
                        }
                    }
                    if(dir2!=NULL){
                        if(visitadosH2.find(dir2->getHash())==visitadosH2.end()){
                            dir2->calculaF(2);
                            visitadosH2.insert(make_pair(dir2->getHash(),dir2));
                            borda2.push(*dir2);
                            // nNos2++;
                        }
                    }
                    if(borda2.size()==0)vazio2=false;
                }
            }
        }
        cout<<"H1: "<<endl;
        root1->print();
        cout<<"Número de nós gerados por H1: "<<nNos1<<endl;
        cout<<endl;
        cout<<"H2: "<<endl;
        root2->print();
        cout<<"Número de nós gerados por: "<<nNos1<<endl;
    }
};

