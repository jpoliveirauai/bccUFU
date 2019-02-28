import Stack

x = empty
p = push 10 (push 1 x)

size :: Stack a -> Int
size s |isEmpty s = 0
       |otherwise = 1 + size (pop s)