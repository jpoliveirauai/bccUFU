--{-# LANGUAGE ParallelListComp #-}
import Data.List (tails)    
--ex03
divisores x = [a| a<-[1..x], (mod x a)==0]
--ex04
qsort xs |xs==[] = []
         |otherwise = qsort ([a| a<-(tail xs), a<(head xs)])++ [(head xs)] ++ qsort ([a| a<-(tail xs), a>=(head xs)])


--ex05
qsortTupla xs |xs==[] = []
              |otherwise = qsortTupla ([a| a<-(tail xs), (fst a) < (fst (head xs))])++ [(head xs)] ++ qsortTupla ([a| a<-(tail xs), (fst a) >= (fst (head xs))])

--ex06
paresImpares xs = [[a|a<-xs,even a],[a|a<-xs,odd a]]

--ex07
uni xs ys |ys==[] && xs==[] = []
          |ys==[] = [head xs] ++ (uni (tail xs) ys)
          |xs==[] = [head ys] ++ (uni xs (tail ys))
          |(min (head xs) (head ys))==head xs || ys==[]= [head xs] ++ (uni (tail xs) ys)
          |otherwise = [head ys] ++ (uni xs (tail ys))
uni2 [] [] = []
uni2 (x:xs) (y:ys) |(y:ys)==[] && (x:xs)==[] = []
                   |(y:ys)==[] = x:(uni xs (y:ys))
                   |(x:xs)==[] = y:(uni (x:xs) ys)
                   |(min x y)== x || (y:ys)==[]= x:(uni xs (y:ys))
                   |otherwise = y:(uni (x:xs) ys)
                   
--ex08
--ex09
--ex10
--A lista [1,2,1] não serve como representação para um conjunto porque em conjuntos os elementos
--aparecem uma única vez. Construa a função que recebe uma lista de valores inteiros e devolve o
--conjunto correspondente, eliminado as múltiplas ocorrências de cada elemento.
--Exemplo de uso: listaParaConjunto [1,2,1,1] => [1,2]
listaConjunto [] = []
listaConjunto (x:xs) = x:(listaConjunto (eliminaTudo x xs))

eliminaTudo _ [] = []
eliminaTudo a (x:xs) | a==x = eliminaTudo a xs
                     |otherwise = x:(eliminaTudo a xs)


