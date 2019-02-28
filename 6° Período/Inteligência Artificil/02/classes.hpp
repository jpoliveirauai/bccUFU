#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
 * A profundidade, deve descer até o nó n e fazer a recursão
 * Faltou printar o número de nós gerados
 */

class Space{
		//True é limpo
		bool esquerdaLimpa;
		bool direitaLimpa;
		//False é sujo
		
	public:
	
		void aspira(char lugar){
			//muda o espaço. Ela recebe um char e aspira a posição atual
			if(lugar=='E')
				esquerdaLimpa = true;
			if(lugar=='D')
				direitaLimpa = true;
		}
		
		void sujar(char lugar){
			//Ela recebe um char e sujaa posição atual, para inicializar o programa
			if(lugar=='E')
				esquerdaLimpa = false;
			if(lugar=='D')
				direitaLimpa = false;
		}
		
		void init(){
			//Essa função inicializa o espaço como limpo
			esquerdaLimpa = true;
			direitaLimpa = true;
		}
                bool limpo(){
                    if (esquerdaLimpa == true && direitaLimpa == true)
                        return true;
                    else return false;
                }
                void printaEspaco(){
                    //  _ -> limpo
                    //  * -> sujo
                    if(esquerdaLimpa)cout << "_";
                    else cout << "*";
                    
                    cout << "   ";
                    if(direitaLimpa)cout << "_";
                    else cout << "*";
                    cout << endl;
                }
	};
	

class No{
		Space espacoDoAspirador;
		int custo=0, profundidade;
                string caminho;
		char estadoAtual;
		/* 'E' se os aspirador estiver na esquerda 
		 * 'D' se os aspirador estiver na direita
		 * */
		No* pai;
		vector<No*> filhos;
    
	public:
		void setFilho(No* filho){
			filhos.push_back(filho)			;
		}
		
		void setCusto(int cost){
			custo = cost;
		}
		
		void setEstado(char state){
			estadoAtual = state;
		}
		void setProfundidade(int depth){
			profundidade = depth;
		}
		void setEspaco(Space space){
			espacoDoAspirador = space;
		}
		int getProfundidade(){
			return profundidade;
		}
                void catCaminho(string s){
                    caminho += s;
                }
				
		//Ações
		No* esqueda(){
                        No* node = new No;
                        Space nspace = espacoDoAspirador;
                        node->catCaminho(caminho);
                        node->catCaminho("E->");
			node->setEspaco(nspace);
                        node->setCusto(1);
                        node->setEstado('E');												//Começando pela esquerda
                        node->setProfundidade(profundidade+1);
                        filhos.push_back(node);
			return node;
		}
		
		No* direita(){
			No* node = new No;
                        Space nspace = espacoDoAspirador;
                        node->catCaminho(caminho);
                        node->catCaminho("D->");
			node->setEspaco(nspace);
                        node->setCusto(1);
                        node->setEstado('D');												//Começando pela esquerda
                        node->setProfundidade(profundidade+1);
                        filhos.push_back(node);
			return node;
		}
		No* Aspirar(){
			No* node = new No;
                        Space nspace = espacoDoAspirador;
                        node->setEstado(estadoAtual);                        
                        nspace.aspira(node->estadoAtual);
                        node->catCaminho(caminho);
                        node->catCaminho("A->");
			node->setEspaco(nspace);
                        node->setCusto(1);
                        node->setProfundidade(profundidade);
                        filhos.push_back(node);
			return node;
		}
                bool objetivo(){
                    return espacoDoAspirador.limpo();
                }
		void printaEstado(){
                    cout << endl;
                    cout << estadoAtual<<endl;
                    espacoDoAspirador.printaEspaco();
                }
                void printaCaminho(){
                    cout<<caminho;
                }
			
};

class Borda{
	stack<No*> bordaDFS;
        queue<No*> bordaBFS;
   public:
      void expandirBFS(No (*root), int n){
        bordaBFS.push((root));
          for(int i =0;i<n;i++){
                //root->printaEstado();
                if(root->objetivo()){
                    root->printaCaminho();
                    cout << "FIM";
                    break;
                }
                else{
                    bordaBFS.pop();
                    bordaBFS.push(root->Aspirar());
                    bordaBFS.push(root->esqueda());
                    bordaBFS.push(root->direita());
//                    cout<<"-------------------------------------------------"<<i<<endl;
                }
                root = (No*) bordaBFS.front();
          }
      }
      
      void expandirDFS(No *root, int n){
          bordaDFS.push((root));
          for(int i =0;i<n;i++){
              root->printaEstado();
                if(root->objetivo()){
                    root->printaCaminho();
                    cout << "FIM";
                    break;
                }
                else{
                    bordaDFS.pop();
                    
                    bordaDFS.push(root->esqueda());
                    bordaDFS.push(root->direita());
                    bordaDFS.push(root->Aspirar());
                }
                root = (No*) bordaDFS.top();
          }
        
      }
      
};