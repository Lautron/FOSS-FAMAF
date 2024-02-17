mayoresQue _ [] = []
mayoresQue num (x:xs) 
  | x > num = x: mayoresQue num xs 
  | otherwise = mayoresQue num xs

tamaños [] = []
tamaños (xs:xss) = length xs : tamaños xss

multiplica n [] = []
multiplica n (x:xs) = n * x : multiplica n xs

ultimo [] = Nothing
ultimo (x:[]) = x
ultimo (x:xs) = ultimo xs

repetir 0 n = []
repetir v n = n : repetir (v-1) n

--elemento _ [] = False
--elemento e (x:xs) = e == x || elemento e xs

hacerA [] = []
hacerA (x:xs) 
  | elem x ['e','i','o','u'] = 'a' : (hacerA xs)
  | elem x ['E','I','O','U'] = 'A' : (hacerA xs)
  | otherwise = x : (hacerA xs)

siguientes [] = []
siguientes (x:xs) = (x, x+1) : siguientes xs

sum' [] = 0
sum' (x:xs) = x + sum' xs

