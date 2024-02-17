sumar1 [] = [] 
sumar1 (x:xs) = (1 + x) : sumar1 xs

duplica [] = [] 
duplica (x:xs) = (2 * x) : duplica xs

multiplica n [] = [] 
multiplica n (x:xs) = [n * x] ++ multiplica n xs

