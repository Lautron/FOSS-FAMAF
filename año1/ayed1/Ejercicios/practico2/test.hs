csum n 0 = 0
csum n y = n+ csum n (y-1)

cubeSum 0 = 0
cubeSum n = csum n n + cubeSum (n-1)

iguales [] = True
iguales [x] = True
iguales (x:y:xs) = x==y && iguales (y:xs)

creciente [] = True
creciente [x] = True
creciente (x:y:xs) = x < y && creciente (y:xs)

