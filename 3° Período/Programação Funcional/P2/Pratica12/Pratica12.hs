data Dia = Dom | Seg | Ter | Qua

data Est = Verao | Outono | Inverno | Primavera           


funk d = True


instance Eq Est where (==) Verao        Verao          = True
                      (==) Primavera    Primavera  = True
                      (==) Outono       Outono        = True
                      (==) Inverno      Inverno      = True
                      (==) _            _                  = False

