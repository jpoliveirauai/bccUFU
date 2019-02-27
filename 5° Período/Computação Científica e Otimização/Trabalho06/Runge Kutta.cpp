//Integrantes
//João Paulo de Oliveira       11611BCC046
//Gabriel Prudêncio Haddad     11611BCC057

//O algoritmo referente ao 1° exercício do T5, vai imprimir todos os passos para 10000 e logo em seguida 100000000 passos

#include <iostream>
#include <cmath>
using namespace std;


double funcao (double t, double q){
        return (-q*cos(t)+2*t*exp(q))/(sin(t)+t*t*exp(q)+2);                    //Equanção dada no problema
}
main(){
        int n, i;                                                               //n é o número de passos
        double x=1;                                                             //valor inicial de x
        double y=0;                                                             //Valor inicial de y
        double  h;                                                              //valor de passo
        double  k1;                                                             //passo 1 do método
        double  k2;                                                             //passo 2 do método
        double  k3;                                                             //passo 3 do método
        double  k4;                                                             //passo 4 do método
        double  k=x;                                                            //Variável auxiliar para x (n-1)
        double  a=1;                                                            //Intervalo superior
        double  b=2;                                                            //Intervalo inferior

        
        
        
        h=0.0001;                                                               //Definindo 10000 passos
        cout<<fixed<<"Comecando com h = "<< h <<", ";
        n = ceil((b-a)/h);                                                      //usando ceil para evitar truncamento
        cout<<fixed<<"o valor aproximado de f para "<< n <<" passos eh "<<endl;
        fflush(stdin);
        getchar();
        cout<<"     "<< "xn\t\t\tyn"<<endl;                                     //Print para criar a tabela
        cout << "PVI: ";
        cout<< x <<"\t\t"<<y<<endl;                                             //Imprimindo o PVI
        for(i=1;i<=n;i++){
            //Feito o laço dos passos de runge Kutta
            x=k+i*h;
            k1=funcao(x,y);
            k2=funcao(x+(h/2),y+(h/2)*k1);
            k3=funcao(x+(h/2), y+ (h/2)*k2);
            k4=funcao(x+h,y+h*k3);
            y=y+(h/6)*(k1+2*k2+2*k3+k4);
            cout<<"     " <<x <<"\t\t"<<y<<endl;
        }




        //Repete-se o passo acima com um h diferente
        h=0.000001;                                                           //Definindo 1000000 passos
        cout<<fixed<<endl<<"Agora com h = "<< h <<", ";
        n = ceil((b-a)/h);
        cout<<fixed<<"o valor aproximado de f para "<< n <<" passos eh "<<endl;
        cout << "Pressione enter para continuar";
        fflush(stdin);
        getchar();
        cout<<"     "<< "xn\t\t\tyn"<<endl;
        x=1;
        y=0;
        k=x;
        cout << "PVI: ";
        cout<< x <<"\t\t"<<y<<endl;
        for(i=1;i<=n;i++){
            //Feito o laço dos passos de runge Kutta
            x=k+i*h;
            k1=funcao(x,y);
            k2=funcao(x+(h/2),y+(h/2)*k1);
            k3=funcao(x+(h/2), y+ (h/2)*k2);
            k4=funcao(x+h,y+h*k3);
            y=y+(h/6)*(k1+2*k2+2*k3+k4);
            cout<<"     " <<x <<"\t\t"<<y<<endl;
        }

                
        cout << endl << "Com isso, conclui-se que quanto menor o h, e consequentemente mais passos, mais preciso eh o resultado" << endl;
}       
