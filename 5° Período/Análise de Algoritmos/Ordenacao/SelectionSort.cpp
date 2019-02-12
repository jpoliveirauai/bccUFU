#include <iostream>

using namespace std;

void SelectionSort(int v[], int max){
   int aux, j, count=0;
   for (int i=0;i<max-1;i++){
      j = i+1;
      aux = v[j];
      while(j!=0 && v[j-1]>aux){
         count ++;
         v[j] = v[j-1];
         j--;
      }
      v[j] = aux;
   }
   for (int i=0;i<max;i++) cout << v[i]<< " "; cout <<endl;		//Printa o vetor
   cout << count << " = " ;//<< max*(max-1)/2;
}

int main(){
   int vetor[5]={7,5,2,1,0},aux;
      for (int i=0;i<5;i++) cout << vetor[i]<< " "; cout <<endl;		//Printa o vetor
   //BubbleSort(vetor,5);
   //CountingSort(vetor,5,400);
   SelectionSort(vetor, 5);

   return 0;
}




