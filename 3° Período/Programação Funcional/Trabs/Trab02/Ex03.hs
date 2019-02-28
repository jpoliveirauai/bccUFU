--João Paulo de Oliveira
--11611BCC046

type Tempo = Int                        
type TempoQChegou = Int                 --Cliente chegou
type TempoPAtend = Int                  --Tempo para atender
type TempoDEsp = Int                    --Tempo de espera
type TempoDeAtend = Int                 --Tempo de atendimento

--Clienque que chega ao banco, armazena tempo que chegou e tempo para atender o cliente
data ClienteQChega = Nao | Sim TempoQChegou TempoPAtend
   deriving(Show, Eq)


--Cliente que sai do banco. Guarda tmepo de espera e tempo para atender
data ClienteQSai = Nenhum |Liberado TempoQChegou TempoDEsp TempoPAtend
   deriving(Show, Eq)

--Implementação do TAD Fila

--      Consiste no tempo atual, tempo que demora para o atendimento e na fila de ClienteQChega (tempo que chegou e tempo para atender o cliente)
type EstadoDaFila = (Tempo,TempoDeAtend,[ClienteQChega])

--Adiciona um cliente que chega, e mantem os demais atributos
adicionaCliente :: ClienteQChega -> EstadoDaFila -> EstadoDaFila
adicionaCliente m (tempo,tempDeAtend,ml) = (tempo,tempDeAtend, ml++[m])

--ClienteQSai é gerado, ou continua o processamento da fila
--incrementa o tempo caso não seja possivel tratar a solicitação do cliente
--Quando concluido, o tempo da fila aumenta + 1
--Se não há nada a ser processado, avança o tempo
processaFila :: EstadoDaFila -> (EstadoDaFila, [ClienteQSai])
processaFila (tempo,tempDeAtend,[]) = ((tempo+1,tempDeAtend,[]),[])
processaFila (tempo,tempDeAtend,(Sim a tempNecDAtend:resto))
       | tempDeAtend < tempNecDAtend = (((tempo+1),(tempDeAtend+1),(Sim a tempNecDAtend:resto)),[])
       | otherwise = ((tempo+1,0,resto), [Liberado a (tempo-tempNecDAtend-a) tempNecDAtend])

--Estado inicial da fila
filaDeInicio :: EstadoDaFila
filaDeInicio = (0,0,[])

--Verifica o tamanho da fila
tamanhoDaFila :: EstadoDaFila -> Int
tamanhoDaFila (tempo,tempoDeAtend,l) = length l


--Testa se a fila está vazia
filaVazia :: EstadoDaFila -> Bool
filaVazia (t,s,q) = (q == [])

-- Estado do Servidor: Filas indexadas em uma lista
type EstadoDoServidor = [EstadoDaFila]


--insere um Cliente na fila n
colocaNaFila :: Int -> ClienteQChega -> EstadoDoServidor -> EstadoDoServidor
colocaNaFila n im st = take n st ++ [novoEstadoDaFila] ++ drop (n+1) st
                       where novoEstadoDaFila = adicionaCliente im (st!!n)

--avalia cada fila e retorna uma lista de ClienteQSai
processaServidor :: EstadoDoServidor -> (EstadoDoServidor, [ClienteQSai])
processaServidor [] = ([],[])
processaServidor (q:qs) = ((nq:nqs), mess ++ messes)
                          where (nq,mess) = processaFila q
                                (nqs,messes) = processaServidor qs

--processa o servidor(retornando a lista de ClienteQSai) e adiciona os clientes que cheguem à menor fila
processaSimulacao :: Int -> EstadoDoServidor -> ClienteQChega -> (EstadoDoServidor,[ClienteQSai])
processaSimulacao n estServ im = (adicionaNovoObjeto n im estServ1,clientQSai)
                               where (estServ1,clientQSai) = processaServidor estServ


--adiciona um cliente na menor fila
adicionaNovoObjeto :: Int -> ClienteQChega -> EstadoDoServidor -> EstadoDoServidor
adicionaNovoObjeto _ Nao estServ = estServ
adicionaNovoObjeto n (Sim tempoDeChegada tempoNecAtend) estServ = colocaNaFila (n `mod` (tamanhoDoServidor estServ)) (Sim tempoDeChegada tempoNecAtend) estServ
--Inicia um servidor com n filas recursivamente concatenando várias filas no estado inicial. Foi modificado para n filas para que possa ser realizado os experimentos


estadoInicialDoServidor :: Int -> EstadoDoServidor
estadoInicialDoServidor n
                        |n == 0 = []
                        |otherwise = (estadoInicialDoServidor (n-1)) ++ [filaDeInicio]

tamanhoDoServidor :: EstadoDoServidor -> Int
tamanhoDoServidor = length

-- Geracao de Numeros Aleatorios 

--Explique: a remoção dos parênteses colocados no tipo da função seqAleatoria  altera a definição da função?
--Sim, se removessemos os parênteses, a função rem (que deveria estar entre aspas) seria associada apenas à incremento
semente :: Integer
semente = 17489

multiplicador :: Integer
multiplicador = 25173

incremento :: Integer
incremento = 13849

modulo :: Integer
modulo = 65536

dist :: Num t => [(t, Float)]
dist = [(1, 0.2), (2, 0.25), (3, 0.25), (4, 0.15), (5, 0.1), (6, 0.05)]

proxNumAleat :: Integer -> Integer
proxNumAleat n = ((multiplicador*n) + incremento) `rem` modulo

seqAleatoria :: (Integer -> [Integer])
seqAleatoria = iterate proxNumAleat

geraFuncao :: [(t,Float)] -> (Float -> t)
geraFuncao dist = geraFun dist 0.0
geraFun ((ob,p):dist) nUlt aleat
          | nProx >= aleat && aleat > nUlt = ob
          |otherwise = geraFun dist nProx aleat
                       where nProx = (p * (fromInteger modulo)) + nUlt

-- Simulação

--Entra uma série de Clientes e saem vários Clientes
simule :: Int -> EstadoDoServidor -> ([ClienteQChega] -> [ClienteQSai])
simule n estDoServ (im:messes) = outmesses ++ simule (n+1)proxEstDoServ messes
                               where (proxEstDoServ,outmesses) = processaSimulacao n estDoServ im

seqDeTempos :: [TempoPAtend]
seqDeTempos = map (geraFuncao dist.fromInteger) (seqAleatoria semente)

--gera n° infinito de entradas, que gera num n° infinito de saídas
entradaDaSimulacao :: [ClienteQChega]
entradaDaSimulacao = zipWith Sim [ 1..] seqDeTempos

--gera apenas 50 entradas
entradaDaSimulacao2 :: [ClienteQChega]
entradaDaSimulacao2 = take 50 entradaDaSimulacao ++ naos

naos :: [ClienteQChega]
naos = (Nao:naos)

tempoDeEsperaTotal :: ([ClienteQSai] -> Int)
tempoDeEsperaTotal = sum . map tempoDEsp
                     where tempoDEsp (Liberado _ w _) = w
{-
Nesse exercício, eu alterei o simule, processaSimulacao e adicionaNovoObjeto utilizando um n. N começa inicialmente com 0, quando ele estoura o limite do número de filas, é usado a operação mod na função adicionaNovoObjeto fazendo com que não estoure o n° de filas
-}




--Experimento 1
{-
        Utilizando o comando:
                tempoDeEsperaTotal (take 50 (simule 0 (estadoInicialDoServidor 1) entradaDaSimulacao2))
        com uma fila, obtive o tempo 3358
-}

--Experimento 2
{-
        Obtive tempo 0 com n° de filas >= 7, usando o comando:
                tempoDeEsperaTotal (take 50 (simule 0 (estadoInicialDoServidor 7) entradaDaSimulacao2))
-}
