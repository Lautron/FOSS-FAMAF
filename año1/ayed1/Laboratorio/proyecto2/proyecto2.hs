--1
--a)
data Carrera = Matematica | Fisica | Computacion | Astronomia deriving Show

--b)
titulo:: Carrera -> String
titulo carrera = case carrera of
    Matematica -> "Licenciatura en Matematica"
    Fisica -> "Licenciatura en Fisica"
    Computacion -> "Licenciatura en Computacion"
    Astronomia -> "Licenciatura en Astronomia"

-- 2)
data Carrera' = Matematica' | Fisica' | Computacion' | Astronomia' deriving (Eq, Ord, Show)

-- 3)
-- a)
type Ingreso = Int

data Cargo = Titular | Asociado | Adjunto | Asistente | Auxiliar deriving Show
data Area = Administrativa | Enseñanza | Economica | Postgrado deriving Show

data Persona = Decane
  | Docente Cargo
  | NoDocente Area
  | Estudiante Carrera Ingreso
  deriving Show

-- b) El tipo del constructor docente es: Docente:: Cargo -> Persona
-- c)
cuantos_doc:: [Persona] -> Cargo -> Int
cuantos_doc [] _ = 0
cuantos_doc ((Docente Titular):xs) Titular = 1 + cuantos_doc xs Titular
cuantos_doc ((Docente Asociado):xs) Asociado = 1 + cuantos_doc xs Asociado
cuantos_doc ((Docente Adjunto):xs) Adjunto = 1 + cuantos_doc xs Adjunto
cuantos_doc ((Docente Asistente):xs) Asistente = 1 + cuantos_doc xs Asistente
cuantos_doc ((Docente Auxiliar):xs) Auxiliar = 1 + cuantos_doc xs Auxiliar
cuantos_doc (_:xs) c = cuantos_doc xs c

-- d)
cuantos_doc':: [Persona] -> Cargo -> Int
cuantos_doc' xs c = length (filter (esCargo c) xs)
  where
    esCargo Titular (Docente Titular) = True
    esCargo Asociado (Docente Asociado) = True
    esCargo Adjunto (Docente Adjunto) = True
    esCargo Asistente (Docente Asistente) = True
    esCargo Auxiliar (Docente Auxiliar) = True
    esCargo _ _ = False

-- 4) a)
primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:_) = Just x 

-- 5)
data Cola = VaciaC | Encolada Persona Cola deriving Show

atender:: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada _ VaciaC) = Nothing
atender (Encolada _ cola) = Just cola

encolar:: Persona -> Cola -> Cola
encolar p VaciaC = Encolada p VaciaC
encolar per (Encolada p cola) = Encolada p (encolar per cola)

busca:: Cola -> Cargo -> Maybe Persona
busca VaciaC _ = Nothing
busca (Encolada per cola) c2
  |sonIguales per c2 = Just (Docente c2)
  |otherwise = busca cola c2
  where
  sonIguales (Docente Titular) Titular = True
  sonIguales (Docente Asociado) Asociado = True
  sonIguales (Docente Adjunto) Adjunto = True
  sonIguales (Docente Asistente) Asistente = True
  sonIguales (Docente Auxiliar) Auxiliar = True
  sonIguales _ _ = False

-- b) Cola se parece a las listas, ya que ambos son tipos de datos recursivos con constructores que tienen un comportamiento similar.

-- 6)
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show
-- a)
type GuiaTelefonica = ListaAsoc String Int -- Ya que se asocia cada nombre con un numero de telefono

-- b)
-- 1) 
laLong:: ListaAsoc a b -> Int
laLong Vacia = 0
laLong (Nodo _ _ ls) = 1 + laLong ls

-- 2)
laConcat:: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
laConcat Vacia ys = ys
laConcat (Nodo a b ls) ys = Nodo a b (laConcat ls ys)

-- 3)
laPares :: ListaAsoc a b -> [(a,b)]
laPares Vacia = []
laPares (Nodo a b ls) = (a,b) : laPares ls

-- 4)
laBusca:: Eq a => ListaAsoc a b -> a -> Maybe b
laBusca Vacia _ = Nothing
laBusca (Nodo a b ls) c
  |a == c = Just b
  |otherwise = laBusca ls c

-- 5)
laBorrar:: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
laBorrar _ Vacia = Vacia
laBorrar clave (Nodo a b ls)
  |clave == a = laBorrar clave ls
  |otherwise = Nodo a b (laBorrar clave ls)

----------------------------------------------------------------


