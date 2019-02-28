--Recursividade de calda: a recursão de calda evita a volta. Deve haver uma variável auxiliar
--Lembra programação procedimental

soma ::[Int]->Int
soma xs |xs==[] = 0
        |otherwise = head(xs) +soma (tail xs)

somaCauda :: [Int]->Int->Int
somaCauda xs s|xs==[] = s
              |otherwise = somaCauda (tail(xs)) (s+head(xs))
              
fatorial :: Int->Int
fatorial x |x==1 = 1
           |otherwise = x * fatorial (x-1)
           
fatorialCauda :: Int->Int->Int
fatorialCauda x r |x==1 = r
                  |otherwise = fatorialCauda (x-1) (r*x)