verTodas [] = 0
verTodas ((_,_,dur,_):xs) = dur + verTodas xs

estrenos [] = []
estrenos (x:xs) 
    | año x == 2016 = x : estrenos xs
    | otherwise = estrenos xs
    where
    año (_,a,_,_) = a

filmografia [] _ = []
filmografia (x:xs) director 
    |direc x == director = x : filmografia xs director
    |otherwise = filmografia xs director
    where
    direc (_,_,_,d) = d

duracion ((nom,_,dur,_):xs) nombre
    |nom == nombre = dur
    |otherwise = duracion xs nombre
-- [("nombre", 1999, 2, "capo"), ("nombre2", 1990, 5, "capo2")]
