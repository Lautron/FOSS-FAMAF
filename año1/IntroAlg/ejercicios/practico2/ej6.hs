repartir  [] ys = []
repartir (x:xs) (y:ys) = [(x,y)] ++ repartir xs ys
