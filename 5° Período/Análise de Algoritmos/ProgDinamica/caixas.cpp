#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int> >pilhas;
int alt1;
int pilha1;
int total;

int get_next(int value){
   return ++value;
}

int get_back(int value){
   return --value;
}

int exists_pos (int pos){
   int size  = pilhas[pos].size();
   if (pos == 0)return 0;
   if (pos == -1) return 0;
   return -1;
}


void calculate_min_box (int pos, int (*getfunction)(int)){
    int aux;
    
    if (pos == pilha1){
       aux =  pilhas[pos].size()-(alt1+1);
      //  se for a pilha da caixa1, tira todas as caixas acima dela
    }else{
       aux =  pilhas[pos].size()-alt1;
       if (aux <= 0) return;
       //  se não for a pilha da caixa1, de altura >=  a da caixa1
    }

    total+= aux;
    
    if (exists_pos(pos)){
    		int next = getfunction(pos);
    	   calculate_min_box(next,getfunction);	
    }
}

int main (){
  
  int nCaixas, nPilhas;  
  int tamPilha;
  while (1){
     scanf ("%d%d",&nCaixas,&nPilhas);
     if (nCaixas == 0 && nPilhas == 0) break;


     for (int i = 0; i < nPilhas; i++){
         scanf ("%d",&tamPilha);
         vector<int>pilha;
         
         for (int j = 0; j < tamPilha; j++){
              int caixa;
              scanf ("%d",&caixa);
              pilha.push_back(caixa);
              if (caixa == 1){
                 alt1 = j;
                 pilha1 = i;
              }
         }
         pilhas.push_back(pilha);
         // insere uma pilha no montante de pilhas
     }
       
	  if (pilha1 == 0 || pilha1 == nPilhas-1){
		  total += pilhas[pilha1].size() - (alt1+1);
                  //N° de objetos acima da caixa1
	  }else{
		  calculate_min_box(pilha1,&get_next);
		  int next  = total;
		  total = 0;
		  calculate_min_box(pilha1,&get_back);
		  int back = total;
		  total = std::min(back,next);		  
	  }
	   printf ("%d\n",total);
	   pilhas.clear();
	   total = 0;
  }
  
  return 0;
}