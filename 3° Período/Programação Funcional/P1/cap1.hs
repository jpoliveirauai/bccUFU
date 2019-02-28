iguais a b c | a == b && b==c = 3
             | (a==b && b/=c)||(a/=b && b==c)||(a==c &&b/=a) = 2
             | a/=b && a/=c = 0

media_3 a b c = (a+b+c)/3

n_maior_media a b c     | a > (media_3 a b c) && b > (media_3 a b c) && c > (media_3 a b c) = 3
                        | a > (media_3 a b c) && b > (media_3 a b c) && c < (media_3 a b c) = 2
                        | a > (media_3 a b c) && b < (media_3 a b c) && c > (media_3 a b c) = 2
                        | a < (media_3 a b c) && b > (media_3 a b c) && c > (media_3 a b c) = 2
                        | a > (media_3 a b c) && b < (media_3 a b c) && c < (media_3 a b c) = 1
                        | a < (media_3 a b c) && b > (media_3 a b c) && c < (media_3 a b c) = 1
                        | a < (media_3 a b c) && b < (media_3 a b c) && c > (media_3 a b c) = 1
                        | a < (media_3 a b c) && b < (media_3 a b c) && c < (media_3 a b c) = 0

potencia_2 x = x*x

potencia_4 x = (potencia_2 x) * (potencia_2 x)

xor a b = (a||b) && not(a &&b)


x_maior a b c   |(-b +sqrt(b^2 - 4*a*c))/2*a > (-b-sqrt(b^2 - 4*a*c))/2*a = (-b +sqrt(b^2 - 4*a*c))/(2*a)
                |otherwise = (-1*b-sqrt(b^2 - 4*a*c))/(2*a)

x_menor a b c   |(-b +sqrt(b^2 - 4*a*c))/(2*a) < (-b-sqrt(b^2 - 4*a*c))/(2*a) = (-1*b +sqrt(b^2 - 4*a*c))/(2*a)
                |otherwise = (-b-sqrt(b^2 - 4*a*c))/(2*a)
