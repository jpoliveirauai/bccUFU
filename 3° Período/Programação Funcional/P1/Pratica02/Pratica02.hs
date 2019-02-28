import Prelude hiding (even,odd)

even n = mod n 2==0
odd n = not(even n)

zeroto    ::Int->[Int]
zeroto n = [0..n]

isDigit ::Char->Bool
isDigit c = c>='0' && c<='9'
maior10 :: Int ->Bool
maior10 m = m>=10

media3 :: Float->Float->Float->Float
media3 a b c = (a+b+c)/3

maior2  :: Int->Int->Int
maior2 a b| a>b = a
          | a<b = b

maior2'  :: Int->Int->Int
maior2' a b = if a>b then a else b
