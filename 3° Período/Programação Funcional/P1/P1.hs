--João Paulo de Oliveira - 11611BCC046

transformaR :: [Int] ->[String]
transformaR [] = []
transformaR (x:xs) = (show (div x 100) ++ "." ++show (mod x 100)):(transformaR xs)

transformaC :: [Int] ->[String]
transformaC xs = [(show (div a 100) ++ "." ++show (mod a 100)) |a<-xs  ]




espacoBranco ::[Char]
espacoBranco = ['\n','\t',' ']

pertence :: Char -> [Char]->Bool
pertence c [] = False
pertence c (x:xs) | c==x = True
                  |otherwise = pertence c xs

devolvePalavra :: String->String
devolvePalavra [] = []
devolvePalavra (x:xs) |x ==' ' = []
                      |otherwise = x:(devolvePalavra xs)
                      
                      
                      
removePalavra :: String->String
removePalavra [] = []
removePalavra (x:xs) |pertence x espacoBranco = (x:xs)
                     |otherwise = removePalavra xs
                     
removaEspaco :: String->String
removaEspaco [] =[]
removaEspaco (x:xs) |not(pertence x espacoBranco) =  (x:xs)
                    |otherwise = removaEspaco xs