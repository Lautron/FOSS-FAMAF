---- 1) a)
--data Moneda = Uno | Dos | Cinco | Diez deriving (Show, Enum)
--type Cantidad = Int
---- b)
--titulo:: Moneda -> String
--titulo m = case m of
--    Uno -> "Un peso"
--    Dos -> "Dos pesos"
--    Cinco -> "Cinco pesos"
--    Diez -> "Diez pesos"
--
---- 2)
---- a)
--data ContadoraMonedas = SinPlata | Agregar Moneda ContadoraMonedas
--
--entregarMonedas :: ContadoraMonedas -> Moneda -> [Moneda]
--entregarMonedas (Agregar Uno SinPlata) Uno = Uno : [] 
--entregarMonedas (Agregar Dos SinPlata) Dos = Dos : []
--entregarMonedas (Agregar Cinco SinPlata) Cinco = Cinco : []
--entregarMonedas (Agregar Diez SinPlata) Diez = Diez : []
--entregarMonedas (Agregar Uno cm) Uno = Uno : entregarMonedas cm Uno
--entregarMonedas (Agregar Dos cm) Dos = Dos : entregarMonedas cm Dos
--entregarMonedas (Agregar Cinco cm) Cinco = Cinco : entregarMonedas cm Cinco
--entregarMonedas (Agregar Diez cm) Diez = Diez : entregarMonedas cm Diez
--entregarMonedas (Agregar _ SinPlata) _ = [] 
--entregarMonedas (Agregar mon cm) m = entregarMonedas cm m
--
---- test = Agregar Diez (Agregar Dos (Agregar Dos (Agregar Uno SinPlata)))
--
--data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show
--type ContadoraMonedas' = ListaAsoc Moneda Cantidad 
--
--masDeCinco :: ContadoraMonedas' -> [Moneda]
--masDeCinco Vacia = []
--masDeCinco (Nodo mon cant ls) 
--    | cant >= 5 = mon : masDeCinco ls
--    | otherwise = masDeCinco ls
--
---- test = Nodo Uno 10 (Nodo Dos 3 ( Nodo Cinco 6 ( Nodo Diez 2 Vacia))) 
--
---- Tema b:
---- 1)a)
--data Medalla = Bronce | Plata | Oro deriving (Show)
--type Medallero = [Medalla]
--valorMedalla:: Medalla -> Int
--valorMedalla Bronce = 1
--valorMedalla Plata = 2
--valorMedalla Oro = 4
--
---- 2)
--data Disciplina = Boxeo | Judo | Vela | Jockey | Tenis
--data Resultado = Res Disciplina Medalla
--medalleroVela:: [Resultado] -> Medallero
--medalleroVela [] = []
--medalleroVela ((Res Vela m):xs) = m : medalleroVela xs
--medalleroVela ((Res _ m):xs) = medalleroVela xs
---- test = [Res Vela Oro, Res Vela Plata, Res Vela Bronce, Res Boxeo Oro] 
--
---- 3)
--laExiste :: (Eq a) => ListaAsoc a b -> a -> Bool
--laExiste Vacia _ = False
--laExiste (Nodo a b ls) k
--    | a == k = True
--    | otherwise = laExiste ls k
---- test = Nodo "Uno" 10 (Nodo "Dos" 3 ( Nodo "Cinco" 6 ( Nodo "Diez" 2 Vacia))) 
---- b)
--laBusca:: Eq a => ListaAsoc a b -> a -> Maybe b
--laBusca Vacia _ = Nothing
--laBusca (Nodo a b ls) c
--  |a == c = Just b
--  |otherwise = laBusca ls c
--
--laExiste' :: (Eq a) => ListaAsoc a b -> a -> Bool
--laExiste' la k = auxiliar (laBusca la k)
--  where 
--    auxiliar Nothing = False
--    auxiliar (Just a) = True
--
-- Tema c
-- 1)a)
data Verdura = Papa | Batata | Calabacin | Cebolla deriving Show
type Unidades = Int

titulo:: Verdura -> String
titulo v = case v of 
    Papa -> "Papa Blanca"
    Batata -> "Batata Colorada"
    Calabacin -> "Calabacin coreanito"
    Cebolla -> "Cebolla morada"

-- 2)
data Verduleria = NoQuedaNada | Agregar Verdura Verduleria
hayVerdura:: Verduleria -> Verdura -> Bool
hayVerdura NoQuedaNada _ = False
hayVerdura (Agregar ver vs) v 
  | aux ver v = True
  | otherwise = hayVerdura vs v
    where
      aux Papa Papa = True
      aux Batata Batata = True
      aux Calabacin Calabacin = True
      aux Cebolla Cebolla = True
      aux _ _ = False

-- test = Agregar Papa (Agregar Batata ( Agregar Cebolla NoQuedaNada))
-- 3)
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show
type Verduleria' = ListaAsoc Verdura Unidades
verdurasEnStock:: Verduleria' -> [Verdura]
verdurasEnStock Vacia = []
verdurasEnStock (Nodo a b ls)
  | b > 0 = a: verdurasEnStock ls
  | otherwise = verdurasEnStock ls


-- test = Nodo Papa 0 (Nodo Calabacin 0 ( Nodo Batata 6 ( Nodo Cebolla 2 Vacia))) 
-- Tema d
data NotaMusical = Do | Re | Mi | Fa | Sol | La | Si deriving Show
type Melodia = [NotaMusical]

cifradoAmericano :: NotaMusical -> Char
cifradoAmericano nota = case nota of
    Do -> "C"
    Re -> "D"
    Mi -> "E"
    Fa -> "F"
    Sol -> "G"
    La -> "A"
    Si -> "B"
