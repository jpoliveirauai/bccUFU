type Dia = Int
type Mes = Int
type Ano = Int
type Data = (Dia,Mes,Ano)

bissexto :: Ano -> Bool
bissexto n | ((n `mod` 100/=0)&&(n `mod` 4==0))||(n `mod` 400==0) = True
           |otherwise = False

--diaDaSemana
numDeDiasEmCadaMesDeUmAno :: Ano ->[Int]
numDeDiasEmCadaMesDeUmAno ano = [31,feb,31,30,31,30,31,31,30,31,30,31] 
    where feb
            |bissexto ano = 29
            |otherwise = 28

numDeDias :: Data -> Int
numDeDias (dia,mes,ano) = dia + sum (take (mes-1) (numDeDiasEmCadaMesDeUmAno ano))
                          +(ano-2001)*365 + (ano-2001) `div` 4
nomeDoDia :: Int ->String
nomeDoDia n | n==0 = "Domingo"
            | n==1 = "Segunda"
            | n==2 = "Terca"
            | n==3 = "Quarta"
            | n==4 = "Quinta"
            | n==5 = "Sexta"
            | n==6 = "Sabado"
diaDaSemana :: Data -> String
diaDaSemana dataS = nomeDoDia(rem (numDeDias dataS) 7)