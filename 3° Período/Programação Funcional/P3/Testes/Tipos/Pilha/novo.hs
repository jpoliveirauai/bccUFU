import Tad

a = empty
b = push 1 a
c = push 2 b
d = push 3 c


size :: Pilha p-> Int
size p |isEmpty p = 0
       |otherwise = 1 + (size (pop p))
