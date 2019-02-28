module Main 
        where main = do l <- getLine
                        putStr l
                        putStrLn " Xupa"
                        
        abc 0 xs = putStrLn xs
        abc n xs = abc (n-1) xs
