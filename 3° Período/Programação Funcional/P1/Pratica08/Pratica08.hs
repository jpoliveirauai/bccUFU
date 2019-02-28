fatorial ::Integer->Integer
fatorial n |n==0 = 1
           |n<0 = error "Fatorial não pode ser negativo" 1
           |otherwise = n * (fatorial (n-1))
           
fibonacci :: Integer -> Integer
fibonacci n |n ==0 = 0
            |n ==1 = 1
            |otherwise = fibonacci (n-1) + fibonacci (n-2)

            
fatorialC  ::Integer->Integer->Integer
fatorialC 0 r = r
fatorialC n r = fatorialC (n-1) (n*r)




--Não consegui usar  fibonacci por cauda





{-
int fatorial( int n){
    int i;
    for (i=1;i<n;i++)
        n *=i;
    return n;
}

int fibonacci( int n){
    int *vet = (int*) malloc (n*sizeof(int));
    vet[0] = 0;
    vet[1] = 1;
    

}



-}