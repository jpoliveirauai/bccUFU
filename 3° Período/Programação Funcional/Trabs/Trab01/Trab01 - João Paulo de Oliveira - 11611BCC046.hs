{-
João Paulo de Oliveira
11611BCC046
-}
type Nome = String
type Preco = Int
type CodBar = Int
type BaseDeDados = [(CodBar,Nome,Preco)]
type ListaDeCodigos = [CodBar]
type Recibo = [(Nome,Preco)]
    
listaDeProdutos :: BaseDeDados
listaDeProdutos = [(1234, "Oleo DoBom, 1l" , 195),(4756, "Chocolate Cazzeiro, 250g" , 180),(3216, "Arroz DoBom, 5Kg", 213),(5823, "Balas Pedregulho, 1Kg" , 379),(4719, "Queijo Mineirim, 1Kg" , 449),(6832, "Iogurte Maravilha, 1Kg" , 499),(1112, "Rapadura QuebraDente, 1Kg", 80),(1111, "Sal Donorte, 1Kg", 221),(1113, "Cafe DoBom, 1Kg", 285),(1115, "Biscoito Bibi, 1Kg", 80),(3814, "Sorvete QGelo, 1l", 695)] 

tamLinha :: Int
tamLinha = 30
formataCentavos :: Preco -> String
formataCentavos x = (show(quot x 100))++ "."++(show (rem x 100))

formataLinha :: (Nome,Preco)-> String
formataLinha (n,p) = n ++ (replicate (50-(length n)) '.') ++(formataCentavos p)++ "\n"

formataLinhas :: [(Nome,Preco)] -> String
formataLinhas xs |xs == [] = ""
                 |otherwise = formataLinha (head xs)++ formataLinhas (tail xs)

geraTotal :: Recibo -> Preco
geraTotal r |r ==[] = 0
            |otherwise = snd(head r)+ geraTotal (tail r)
formataTotal :: Preco -> String
formataTotal x = "Total = " ++(replicate (50 -length("Total = $")) '.') ++ "$"++ (show x)

formataRecibo :: Recibo -> IO()
formataRecibo rs = putStrLn(formataLinhas rs ++ formataTotal (geraTotal rs))

fst3 (a,b,c) = a
rt2  (a,b,c) = (b,c)


acha :: BaseDeDados -> CodBar -> (Nome,Preco)
acha bs x |bs==[] = ("item desconhecido", 0)
          |fst3 (head bs) == x = rt2 (head bs)
          |otherwise = acha (tail bs) x


achaItem :: CodBar -> (Nome,Preco)
achaItem x = acha listaDeProdutos x

fazRecibo :: ListaDeCodigos -> Recibo
fazRecibo ps |ps==[] = []
             |otherwise = [achaItem (head ps)] ++ fazRecibo (tail ps)

geraRecibo :: ListaDeCodigos -> IO()
geraRecibo ps = formataRecibo (fazRecibo ps)


