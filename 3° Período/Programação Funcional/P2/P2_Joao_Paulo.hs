------------------------------------------------------------------- EX 6 -------------------------------------------------------------------

--Usei a função concatena para melhor visualização, poderia ser usado o : para inserir, seria mais otimizado, mas optei por uma melhor visualização

--Collatz com cauda
colCauda n xs |n==1 = xs ++ [1]
              |even n = colCauda (div n 2) (xs  ++ [n])
              |odd  n = colCauda (3*n +1 ) (xs ++ [n])
--Collatz sem cauda              
col n |n==1   = [1]
      |even n = n:(col (div n 2))
      |odd  n = n:(col (3*n +1 ))
      
      
      
------------------------------------------------------------------- EX 7 -------------------------------------------------------------------
{--


explode x = map ().takeWhile (>0) (iterate (rem 10) x))

--}
teste x = takeWhile (>1) (iterate (`div` 10 ) x)
--teste2 x = take 4 (iterate (/10) )
--teste x = take 4 (iterate (/10) x)