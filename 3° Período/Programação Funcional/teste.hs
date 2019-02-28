module Main (main) where

import System.IO
import Data.Char

main ::IO()











main8= do pares 30

pares :: Integer -> IO ()
pares 0 = putStrLn (show 0)
pares x = do putStr ((show x)++", ")
             pares (x-2)

main7= do putStrLn("--------------------------------\nOpções:\n--------------------------------\n1. Imposto\n2. Novo salário\n3.Classificação\n--------------------------------\nDigite a opção desejada:")
          o <- readLn :: IO Integer
          putStr"Digite o salário do funcionário: "
          salario <- readLn :: IO Double
          case o of
                1 -> print (op1 salario)
                2 -> print (op2 salario)
                3 -> print (op3 salario)
op1 :: Double -> Double
op1 salario |salario<500 = salario*0.05
            |salario>500&&salario<850 = salario*0.15
            |otherwise   = salario*0.10

op2 :: Double -> Double
op2 salario |salario>1500 = salario+25.0
            |salario>=750&&salario<=1500 = salario+50.0
            |salario>=450&&salario<=750 = salario+75.0
            |otherwise = salario+100

op3 :: Double -> String
op3 salario |salario>=750 = "Mal remunerado"
           |otherwise    = "Bem remunerado"

main6 = do salario   <- readLn::IO Double
           prestacao <- readLn::IO Double
           putStrLn (testaPrestacao salario prestacao)


testaPrestacao :: Double -> Double -> String
testaPrestacao sal pre |pre <= 0.3*sal = "Pode ser concedido"
                       |otherwise = "Não pode ser concedido"




main5= do n1 <- readLn:: IO Double
          n2 <- readLn:: IO Double
          n3 <- readLn:: IO Double
          let media = (n1+n2+n3)/3
          putStrLn ("Situação: "++ show media)
          if media<3
                then putStrLn "Reprovado"
                else if media<7
                        then putStrLn "Exame especial"
                        else putStrLn "Aprovado"
main4 = do putStr "Sexo (f ou m): "
           sexo <- getChar
           putStr "Altura: "
           altura <- readLn:: IO Double
           putStrLn (pesoIdeal sexo altura)

pesoIdeal :: Char -> Double -> String
pesoIdeal s h |(toLower s)=='m' = show (72.7*h - 58)
              |(toLower s)=='f'  = show (62.1*h - 44.7)
              |otherwise      = "Sexo indefinido"



main3 = do a<-getLine
           let f = read a::Double
           putStrLn (show (celsius f))

celsius :: Double -> Double
celsius f = (5/9)*(f-32)
             



main2= do hSetBuffering stdout NoBuffering      --não precisa de hflush
          hFlush stdout
          a<-getLine
          b<-getLine
          let c = read a::Double
              d = read b::Double 
          print (c+d)
