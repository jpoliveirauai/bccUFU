import Data.Char
type Ponto = (Float,Float)
type Reta  = (Float,Float)
triplo    :: Int->Int
triplo x  = 3*x

maior  :: Int->Int->Int
maior x y |x>y = x
          |otherwise = y

maiorDeTres :: Int->Int->Int->Int
maiorDeTres x y z = maior(maior x y) z

menor  :: Int->Int->Int
menor x y |x<y = x
          |otherwise = y

menorDeTres :: Int->Int->Int->Int
menorDeTres x y z = menor z (menor x y)

somatorio   :: Int->Int
somatorio x = sum [1..x]


nEsimoTermoPA   :: Int->Int->Int->Int
nEsimoTermoPA p r n |n==1 = p
                    |otherwise = r +(nEsimoTermoPA p r (n-1))

nEsimoTermoPG   :: Int->Int->Int->Int
nEsimoTermoPG p r n |n==1 = p
                    |otherwise = r *(nEsimoTermoPG p r (n-1))

sPA   :: Int->Int->Int->Int
sPA p r n |n ==1 = nEsimoTermoPA p r 1
          |otherwise = nEsimoTermoPA p r n + sPA p r (n-1)

sPG   :: Int->Int->Int->Int
sPG p r n |n ==1 = nEsimoTermoPG p r 1
          |otherwise = nEsimoTermoPG p r n + sPG p r (n-1)

fibonacci   :: Int -> Int
fibonacci n | n==1||n==2 = 1
            | otherwise = fibonacci (n-1) + fibonacci (n-2)

            
bissexto ::  Int-> Bool
bissexto n | ((n `mod` 100/=0)&&(n `mod` 4==0))||(n `mod` 400==0) = True
           |otherwise = False

divAntecessor   :: Int->Int->Bool           
divAntecessor x n |n==1 = True
                  |mod x n == 0 = False
                  |otherwise = divAntecessor x (n-1)

primo     :: Int -> Bool
primo x |x==1 = True
        |otherwise = divAntecessor x (x-1)


maiuscula :: Char -> Bool
maiuscula c | ord c>=ord 'A' && ord c<=ord 'Z' = True
            |otherwise = False


minuscula :: Char -> Bool
minuscula c |ord c>=ord 'a' && ord c<=ord 'z' = True
            |otherwise = False

digito :: Char -> Bool
digito c |ord c>=ord '0' && ord c<=ord '9' = True
         |otherwise = False

repete :: String->Int->String
repete s x |x==0 = ""
           |x==1 = s
           |otherwise = s ++ repete s (x-1)


brancos :: Int -> String
brancos n = repete " " n

maimen   ::  Int->Int->Int->(Int,Int)
maimen x y z = (maiorDeTres x y z, menorDeTres x y z)

mdc    :: Int->Int->Int
mdc a b |a==b = a
        |a<b  = mdc b a
        |a>b  = mdc (a-b) b

crescente    :: Int->Int->Int->(Int,Int,Int)
crescente a b c |a>(menorDeTres a b c)&&a<(maiorDeTres a b c) =  (menorDeTres a b c, a ,maiorDeTres a b c)
                |b>(menorDeTres a b c)&&b<(maiorDeTres a b c) =  (menorDeTres a b c, b ,maiorDeTres a b c)
                |c>(menorDeTres a b c)&&c<(maiorDeTres a b c) =  (menorDeTres a b c, c ,maiorDeTres a b c)


achaReta   :: Ponto->Ponto->Reta
achaReta p q  = ((snd(p)-snd(q))/(fst(p)-fst(q)),snd(p) - (snd(p)-snd(q))/(fst(p)-fst(q))*fst(p))


retaHorizontal :: Ponto->Ponto->Bool
retaHorizontal p q |fst(achaReta p q)==0 = True
                   |otherwise = False


retaVertical :: Ponto->Ponto->Bool
retaVertical p q  |snd(achaReta p q)== -fst(achaReta p q)*fst(p) && snd(achaReta p q)== -fst(achaReta p q)*snd(p) = True
                  |otherwise = False

pInterseccao :: Reta->Reta->Ponto
pInterseccao r s =(x,y)
                  where x=(snd(s)-snd(r))/(fst(r)-fst(s))
                        y=fst(r)*x+snd(r)









