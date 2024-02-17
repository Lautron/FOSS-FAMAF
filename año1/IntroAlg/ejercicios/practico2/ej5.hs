todosMenores10 [] = True
todosMenores10 (x:xs) = (x < 10) && todosMenores10 xs

hay0 [] = False
hay0 (x:xs) = (x == 0) || hay0 xs

suma [] = 0
suma (x:xs) = x + (sum xs)

