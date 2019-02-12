#include <iostream>

using namespace std;
int BubbleSort(int* vetor, int n){
   /*
      O bubble sort compara com o adjacente até colocar o maior elemento no final, se crescente
   
   */
   int aux;
   for (int j =0;j<(n-1);j++){
      for (int i=0;i<(n-1);i++){
         if(vetor[i]>vetor[i+1]){                  //faz a troca das posições
            aux = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = aux;
         }
         for (int i=0;i<n;i++)
            cout << vetor[i]<< " ";
         cout <<endl;
      }
      cout << "-------------"<<endl;
   }
   return 0;
}

int CountingSort(int* v, int n, int max){
   max++;
   int count[max];
   for (int i=0;i<max;i++) count[i]=0;
   int j=0;
   for (int i=0;i<n;i++)
	   (count[v[i]])++;
   for (int i=0;i<max;i++){
	   while (count[i]>0){
		   v[j] = i;
		   j++;
		   (count[i])--;
	   }
   }

   for (int i=0;i<n;i++) cout << v[i]<< " "; cout <<endl;		//Printa o vetor
   return 0;
}
int main(){
   int vetor[5]={400,6,8,43,1},aux;
   //BubbleSort(vetor,5);
   CountingSort(vetor,5,400);

   return 0;
}


