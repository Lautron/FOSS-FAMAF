soloPares :: [Int] -> [Int]
soloPares [] = []
soloPares (x:xs)
    | even x = [x] ++ soloPares xs
    | otherwise = soloPares xs

mayoresQue10 :: [Int] -> [Int]
mayoresQue10 [] = []
mayoresQue10 (x:xs)
    | x > 10 = [x] ++ mayoresQue10 xs
    | otherwise = mayoresQue10 xs

mayoresQue :: Int -> [Int] -> [Int]
mayoresQue _ [] = []
mayoresQue n (x:xs)
    | x > n = [x] ++ mayoresQue n xs
    | otherwise = mayoresQue n xs
