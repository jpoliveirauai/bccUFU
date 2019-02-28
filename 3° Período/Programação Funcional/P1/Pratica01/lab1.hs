--null: 	verifica se uma lista é vazia
--head: 	seleciona o primeiro elemento de uma lista
--tail: 	remove o primeiro elemento de uma lista
--lenght: 	calcula o tamanho de uma lista
--(!!): 	seleciona on-ésimo elemento de uma lista (pos operando)
--take:		seleciona os primeiros n elementos de uma lista
--sum:		calcula a soma dos elementos de uma lista de números
--product:	calcula o produto dos elementos de uma lista de números
--drop:		remove os primeiros n elementos de uma lista
--(++):		concatena duas listas
--reverse:	inverte uma lista
--Double :: x ->Int
double x = 2*x
quadruple x = double(double x)
--take (double 2) [1,2,3,4,5,6]
fatorial n = product [1..n]
--average lista  = sum lista `div` lista
n = a `div`(length xs)
    where
       a=10
       xs=[1,2,3,4,5]

ultimo ns = (reverse ns) !! 0

ultimo2 ns = ns !! (length(ns)-1)

init1 ns = reverse(tail (reverse(ns)))

init2 ns = reverse(drop 1 (reverse(ns)))

