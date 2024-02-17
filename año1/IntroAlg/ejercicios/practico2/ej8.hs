largo [] = 0
largo (x:xs) = 1 + largo xs

indice 0 (x:xs) = x
indice n (x:xs) = indice (n-1) xs

--indice n ls
--    | length xs == n = x
--    | otherwise = indice n xs
--    where 
--    x = last ls
--    xs = init ls

concatenar [] elem = [elem]
concatenar (x:xs) elem = [x] ++ concatenar xs elem

masmas [] ls = ls
masmas (x:xs) ls = x : masmas xs ls  

tomar 0 (x:xs) = []
tomar n [] = []
tomar n (x:xs) = x: tomar (n-1) xs 

soltar 0 ls = ls
soltar n [] = []
soltar n (x:xs) = soltar (n-1) xs 

--soltar n [] = []
--soltar n ls
--    | length xs < n = soltar n xs
--    | otherwise = soltar n xs ++ [x]
--    where
--    x = last ls
--    xs = init ls
