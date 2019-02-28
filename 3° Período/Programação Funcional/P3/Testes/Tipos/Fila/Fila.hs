module Fila (Fila, inicializa, ehVazia, entra, sai
        ) where

        data Fila a = F [a]
        
        inicializa :: Fila a
        inicializa = F []
        
        ehVazia :: Fila a -> Bool
        ehVazia (F []) = True
        ehVazia _ = False
        
        entra :: a -> Fila a -> Fila a
        entra x (F (xs)) = F (xs ++ [x])
        
        sai :: Fila a -> Fila a
        sai (F []) = error "Fila Vazia"
        sai (F (x:xs)) = F (xs)
