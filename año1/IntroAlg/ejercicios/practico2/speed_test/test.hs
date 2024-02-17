sumar1Arriba :: Num a => [a] -> [a]
sumar1Arriba [] = []
sumar1Arriba (x:xs) = x+1 : (sumar1Arriba xs)

sumar1Abajo :: Num a => [a] -> [a]
sumar1Abajo (x:xs) = x+1 : (sumar1Abajo xs)
sumar1Abajo [] = [] 
