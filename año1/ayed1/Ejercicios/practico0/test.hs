
g [] = 0
g (0:xs) = 0
g (x:xs) = x * (1+ g xs)

g' [] = 0
g' (x:xs) = x * (1+ g xs)
