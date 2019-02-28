{-
Toda lista tem um cabeça e uma cauda
-}

linlistaQuad=[x^2|x<-[1..30]] 
listaQuadIn f=[x^2|x<-[1..]]


listaQuadPares = [x^2 | x<-[1..20], even x]

teste0 = [(x,y) | x<-[1,3,5],y<-[2,4,6],x<y]

dobraPos   :: [Int]->[Int]
dobraPos xs = [2*x |x<-xs, x>0]

dobraPosR xs |xs==[] = []
             |head(xs)<=0 = dobraPosR(tail(xs))
             |otherwise = (2*head(xs)):dobraPosR(tail(xs))

pertence :: Int->[Int]-> Bool
pertence x xs |xs==[] = False
              |x == head(xs) = True
              |otherwise = pertence x (tail(xs))

inverso ::[Int] -> [Int]
inverso xs |xs == [] = []
           |otherwise = (inverso (tail xs) )++[head(xs)]

comprimento::[Int] -> Int
comprimento xs | xs==[] = 0
               |otherwise = 1 + comprimento (tail xs)
