estaEnDNI :: Int -> Bool
estaEnDNI num = num `elem` [4,4,3,9,0,1,6,7]

cuentaDNI:: [Int] -> Int
cuentaDNI [] = 0
cuentaDNI (4:xs) = 1 + cuentaDNI xs
cuentaDNI (3:xs) = 1 + cuentaDNI xs
cuentaDNI (9:xs) = 1 + cuentaDNI xs
cuentaDNI (0:xs) = 1 + cuentaDNI xs
cuentaDNI (1:xs) = 1 + cuentaDNI xs
cuentaDNI (6:xs) = 1 + cuentaDNI xs
cuentaDNI (7:xs) = 1 + cuentaDNI xs
cuentaDNI (_:xs) = cuentaDNI xs

sumatoria' _ [] = 0
sumatoria' f (x:xs) = f x + sumatoria' f xs

aux x 
  | estaEnDNI x = 1 
  | otherwise = 0

cuentaDNI':: [Int] -> Int
cuentaDNI' xs = sumatoria' aux xs

separar :: [a] -> (a -> Bool) -> ([a], [a])
separar [] _ = ([], [])
separar (x:xs) pred
  | pred x = (x:fst tupla,snd tupla)
  | otherwise = (fst tupla, x:snd tupla)
  where 
    tupla = separar xs pred

-- Tema c
cuentaNoDNI:: [Int] -> Int
cuentaNoDNI [] = 0
cuentaNoDNI (4:xs) = cuentaNoDNI xs
cuentaNoDNI (3:xs) = cuentaNoDNI xs
cuentaNoDNI (9:xs) = cuentaNoDNI xs
cuentaNoDNI (0:xs) = cuentaNoDNI xs
cuentaNoDNI (1:xs) = cuentaNoDNI xs
cuentaNoDNI (6:xs) = cuentaNoDNI xs
cuentaNoDNI (7:xs) = cuentaNoDNI xs
cuentaNoDNI (x:xs) = 1 + cuentaNoDNI xs

aux' x 
  | estaEnDNI x = 0
  | otherwise = 1

cuentaNoDNI':: [Int] -> Int
cuentaNoDNI' xs = sumatoria' aux' xs

aplicaSegun :: [Int] -> Int -> (Int -> a) -> (Int -> a) -> [a]
aplicaSegun [] _ _ _ = []
aplicaSegun (x:xs) n f g 
  | x >= n = f x : aplicaSegun xs n f g 
  | otherwise = g x : aplicaSegun xs n f g 

-- tema d

letraEnApellido :: Char -> Bool
letraEnApellido letra = letra `elem` "bachmann"

cuentaEnApellido:: [Char] -> Int
cuentaEnApellido [] = 0
cuentaEnApellido ('b':xs) = 1 + cuentaEnApellido xs
cuentaEnApellido ('a':xs) = 1 + cuentaEnApellido xs
cuentaEnApellido ('c':xs) = 1 + cuentaEnApellido xs
cuentaEnApellido ('h':xs) = 1 + cuentaEnApellido xs
cuentaEnApellido ('m':xs) = 1 + cuentaEnApellido xs
cuentaEnApellido ('n':xs) = 1 + cuentaEnApellido xs
cuentaEnApellido (_:xs) = cuentaEnApellido xs
