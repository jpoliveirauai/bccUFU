<<<<<<< HEAD
﻿import System.IO

escreveDados :: String -> IO ()
escreveDados f = 
     do
        putStrLn "Escrevendo em arquivo ..."
        h <- openFile f WriteMode
        hFlush h
        escreveDadosDeArquivo 5 h
        hClose h

escreveDadosDeArquivo :: Int -> Handle -> IO ()
escreveDadosDeArquivo n h
  | n == 0 = return ()
  | otherwise =
       do
          putStr "Digite um valor:"
          l <- getLine
          hPutStrLn h l
          escreveDadosDeArquivo (n-1) h

leDados :: String -> IO ()
leDados f = 
     do
        h <- openFile f ReadMode
        hFlush stdout
        leDadosDeArquivo h
        hClose h

leDadosDeArquivo :: Handle -> IO ()
leDadosDeArquivo h =
   do
     x <- hIsEOF h
     if x
     then return ()
     else
       do
        y <- hGetLine h
        putStrLn y
        leDadosDeArquivo
=======
data Expr = Lit Int |
    Add Expr Expr |
    Sub Expr Expr

f :: Expr
f = Lit 2

eval :: Expr-Int
eval (Lit n) = n
eval (Add e1 e2) = (eval e1) + (eval e2)
eval (Sub e1 e2) = (eval e1) + (eval e2)

data Lista = Nil | Cons Int List
>>>>>>> 889dd43bf0b4f7a4b3e367079d6856ac8b64f527
