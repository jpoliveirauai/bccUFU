module Main (main) where
main :: IO()
{-
main = do putStrLn "Qual é o seu nome?"
          nome <- getLine
          putStr nome
          putStrLn " , seja bem fodido"
          
-}

main = do putStr "n1: "
          n1 <- getLine
          putStr "n2: "
          n2          <- getLine
          putStr "n1 + n2 = "
          putStrLn (show ((read n1 :: Float) + (read n2 :: Float)))