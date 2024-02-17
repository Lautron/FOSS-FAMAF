maximo [] = 0
maximo (x:xs) = max x (maximo xs)

sumaPares [] = 0
sumaPares (x:xs) = sumPar x + sumaPares xs 
    where
    sumPar (a,b) = a + b

todo0y1 [] = True
todo0y1 (x:xs) = (x == 1 || x == 0) && todo0y1 xs

quitar0s [] = []
quitar0s (x:xs) 
    | x == 0 = quitar0s xs
    | otherwise = [x] ++ quitar0s xs

ultimo (x:[]) = x
ultimo (x:xs) = ultimo xs

repetir 0 k = []
repetir n k = [k] ++ repetir (n-1) k

concat' [] = []
concat' (x:xs) = x ++ concat' xs

rev [] = []
rev (x:xs) = rev xs ++ [x]
