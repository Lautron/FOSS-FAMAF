listasIguales [] [] = True
listasIguales [] ys = False
listasIguales xs [] = False
listasIguales (x:xs) (y:ys) = x == y && listasIguales xs ys

mejorNota [] = []
mejorNota ((nom,a,b,c):xs) = (nom, maximum [a,b,c]): mejorNota xs 

incPrim [] = []
incPrim ((a,b):xs) = (a+1,b) : incPrim xs

expandir [x] = [x]
expandir (x:xs) = x:" " ++ expandir xs
