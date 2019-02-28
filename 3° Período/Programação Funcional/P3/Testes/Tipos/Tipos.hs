--import Prelude hiding (Bool)

        --data Bool = False | True
        data Point = Point Float Float deriving (Show)
        data Forma = Circulo Point Float | Retangulo Point Point  Float deriving (Show)
        
        area :: Forma -> Float
        area (Circulo _ r) = pi * r ^ 2
        
        data Pessoa= Pessoa {
                nome            ::String,
                sobrenome       ::String,
                altura          ::Float
        } deriving (Show)

        data Expr = Lit Int | Add Expr Expr | Sub Expr Expr deriving (Show)
        eval :: Expr->Int
        eval (Lit n) = n
        eval (Add a b) = (eval a) + (eval b)
        eval (Sub a b) = (eval a) - (eval b)
        

