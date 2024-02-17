
queHace b a [] = 0
queHace b a (x:xs) = queHace2 b a xs `max` queHace b a xs
  where
    queHace2 b a [] = 0
    queHace2 b a (x:[]) = 0
    queHace2 b a (x:xs)
      | b < x && x < a = 0 `max` (queHace2 b a xs + 1)
      | otherwise = 0

queHace' b a [] = 0
queHace' b a (x:xs) = queHace2 b a (x:xs) `max` queHace' b a xs
  where
    queHace2 b a [] = 0
    queHace2 b a (x:xs)
      | b < x && x < a = 0 `max` (queHace2 b a xs + 1)
      | otherwise = 0



--queHace'' b a [] = -10
--queHace'' b a (x:xs) = 0 `max` (queHace2 b a xs + 1) `max` queHace'' b a xs
--  where
--    queHace2 b a [] = 1
--    queHace2 b a (x:xs) = 0 `max` (queHace2 b a xs )
