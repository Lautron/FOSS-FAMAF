-- Ejercicio 1
-- a)
esCero :: Int -> Bool
esCero x = x == 0

-- b)
esPositivo :: Int -> Bool
esPositivo x = x > 0

-- c)
esVocal :: Char -> Bool
esVocal x = elem x "aeiou"

-- 2
-- a)
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x && paratodo xs

-- b)
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

-- c)
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

-- d)
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * (factorial (n-1))

-- e)
promedio :: [Int] -> Int
promedio xs = div (sumatoria xs) (length xs)

-- 3
pertenece :: Int -> [Int] -> Bool
pertenece _ [] = False
pertenece n (x:xs) = (n == x) || pertenece n xs

-- 4
-- a)
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] _ = True
paratodo' (x:xs) f = f x && paratodo' xs f

-- b)
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] _ = False
existe' (x:xs) f = f x || existe' xs f

-- c)
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] _ = 0
sumatoria' (x:xs) f = f x + sumatoria' xs f

-- d)
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] _ = 1
productoria' (x:xs) f = f x * productoria' xs f

-- 5)
paratodo2 :: [Bool] -> Bool
paratodo2 [] = True
paratodo2 xs = paratodo' xs (id)

-- 6)
-- a) 

todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even

-- b)
hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs esMultiplo
  where
    esMultiplo x = mod x n == 0

-- c
sumaCuadrados :: Int -> Int
sumaCuadrados n = sumatoria' [1..n] (^2)

-- d)
factorial' :: Int -> Int
factorial' n = productoria' [1..n] id

-- e)

-- (funcion auxiliar)
-- Si x es par, devuelve x, si x es impar devuelve 1.
esPar :: Int -> Int
esPar x = x^ex
  where
    ex = 1 - (mod x 2) -- Si x es par es igual a 1, si no, es igual a 0

multiplicaPares :: [Int] -> Int
multiplicaPares xs = productoria' xs esPar

-- 7)
-- a)
-- filter: Toma un predicado (una funcion que devuelve un booleano) y una lista, y devuelve otra lista con los elementos de la primer lista que cumplan con el predicado.
-- map: Toma una funcion y una lista y devuelve otra lista que es el resultado de aplicar la funcion a cada uno de los elementos de la primer lista.

-- b)
-- map succ [1, -4, 6, 2, -8] == [2, -3, 7, 3, -7]
-- c) 
-- filter esPositivo [1, -4, 6, 2, -8] == [1, 6, 2]

-- 8)
-- a)
duplica:: [Int] -> [Int]
duplica [] = []
duplica (x:xs) = 2*x : duplica xs

-- b)
duplica':: [Int] -> [Int]
duplica' xs = map (*2) xs

-- 9)
-- a)
soloPares:: [Int] -> [Int]
soloPares [] = []
soloPares (x:xs) 
  | mod x 2 == 0 = x : soloPares xs
  | otherwise = soloPares xs

-- b)
soloPares':: [Int] -> [Int]
soloPares' xs = filter even xs

--c
multiplicaPares':: [Int] -> Int
multiplicaPares' xs = productoria' (filter even xs) id

-- 10)
-- a)
primIgualesA :: Eq t => t -> [t] -> [t]
primIgualesA _ [] = []
primIgualesA item (x:xs) 
  | x == item = x: primIgualesA item xs
  | otherwise = []

-- b)
primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' item xs = takeWhile (==item) xs

-- 11)
-- a)
primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales (x:xs) 
  | x == head xs = x: primIguales xs
  | otherwise = [x]

-- b)
primIguales' :: Eq t => [t] -> [t]
primIguales' xs = primIgualesA (head xs) xs
