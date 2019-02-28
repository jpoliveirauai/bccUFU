module Tad (Pilha, push, pop, top, empty, isEmpty) where
        data Pilha a = Stk[a]
        
        push :: a -> Pilha a -> Pilha a
        push x (Stk xs) = Stk (x:xs)
        
        pop :: Pilha a -> Pilha a
        pop (Stk (_:xs)) = Stk xs
        pop _            = error "Pilha vazia"
        
        top :: Pilha a -> a
        top (Stk (x:_)) = x
        top _ = error "Pilha vazia"
        
        empty :: Pilha a
        empty = Stk []
        
        isEmpty :: Pilha a -> Bool
        isEmpty (Stk ([])) = True
        isEmpty (Stk _) = False
        

        
      
        
