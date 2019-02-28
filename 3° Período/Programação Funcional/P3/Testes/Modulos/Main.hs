module Main (main) where
        import System.IO (stdout, hFlush)

        main = do multFlutuante
        
        
        multFlutuante = do s1 <- getLine
                           hFlush stdout
                           s2 <- getLine
                           hFlush stdout
                           s3 <- getLine
                           putStrLn (show (read s1 * read s2 * read s3))
        
        
        soma = do s1 <- getLine
                  s2 <- getLine
                  putStr "Soma: "
                  putStrLn (show (read s1 + read s2))
                  
        saudacao = do putStrLn "Qual seu nome?"
                      --hFlush
                      nome <- getLine
                      putStr nome
                      putStrLn ", seja bem vindo"
        
        ehPalindromo :: String -> String
        ehPalindromo [] = "eh palindromo"
        ehPalindromo [_] = "eh palindromo"
        ehPalindromo xs | xs == (reverse xs) = "eh palindromo"
                        |otherwise = "não eh palindromo"
                        
        
