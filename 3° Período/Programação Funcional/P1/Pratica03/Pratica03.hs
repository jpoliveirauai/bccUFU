import Data.Char
eita =  case 3-2+1 of
        0->"zero"
        1->"um"
        2->"dois"
        3->"tres"
        
eita2 = case 23>10 of
        True -> "beleza!"
        False-> "fudeu!!"
        
eita3 = case (head "Masculino") of
        'F' -> 10.2
        'M' -> 20.0
        
eita4 = case (toUpper (head "masculino")) of
        'F' -> "muié"
        'M' -> "homi"

{-        
eita5 = case head "Masculino"  of                           --vai dar merda
        True   ->  "mulher"
        False  ->  "homem"
-}
{-
eita6 = case toUpper (head "masculino")  of                 --MERDA
        'F' -> 10.0
        'M'-> 20.0
-}
eita7 = case 9-1 of{-fsadkjfhksajfhósadfouiasd bgi´b´rioe ugb e-}
        x ->11+x
{-
eita8 = case head "Masculino"=='F'of                        --Essa parte aki esta certa, o == serve para comparação
        True  -> "mulher"
        1     -> "homem"                                    --haskell é diferente de C
-}


eita9 = case 20-16 of
        0 -> "zero"
        1 -> "UM"
        2 -> "dois"
        3 -> "treis"
        _ -> "maior que 3"
        
eita10 = case (3+2,3-2) of
        (0,0) -> 10
        (_,3) -> 20
        (x,2) -> x^2
        (x,y) ->x*y-1