removeNegtivo xs | xs==[] = []
                 |(head xs)<0 = removeNegtivo (tail xs)
                 |otherwise = [(head xs)] ++ removeNegtivo (tail xs)

removePares xs |xs ==[] = []
               |even (head xs) = (removePares (tail xs))
               |otherwise = [(head xs)] ++ removePares (tail xs)
               
removeParesC xs = [a | a <-xs, (even a)]

elimina_negativos l = filter negativo l
negativo x = x>0

eliminaPares xs = filter odd xs
