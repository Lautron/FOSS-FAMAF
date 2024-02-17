data LugarALimpiar = Cocina | Habitacion | Comedor | Baño deriving (Eq, Show) 
-- Agregué deriving Eq para poder compararlo en el ejercicio siguiente, ya que en el enunciado no aparecia nada al respecto
type Fiaca = Int
cantidadDeFiaca:: LugarALimpiar -> Fiaca
cantidadDeFiaca lugar = case lugar of
    Cocina -> 1
    Habitacion -> 4
    Comedor -> 3
    Baño -> 5
-- Ejemplo de ejecucion:
-- >cantidadDeFiaca Cocina
-- >1
--
-- >cantidadDeFiaca Comedor
-- >3
----------------------------------------------
type NombrePersona = String
data HayQueLimpiar = Ninguna | AgregaTarea LugarALimpiar NombrePersona HayQueLimpiar deriving Show
tocaLimpiar:: HayQueLimpiar -> LugarALimpiar -> NombrePersona -> Bool
tocaLimpiar Ninguna _ _ = False
tocaLimpiar (AgregaTarea l1 p1 hql) l2 p2
    | l1 == l2 && p1 == p2 = True
    | otherwise = tocaLimpiar hql l2 p2

-- Ejemplo de ejecucion:
-- test = AgregaTarea Baño "Lautaro" (AgregaTarea Cocina "Carlos" Ninguna)
-- >tocaLimpiar test Baño "Lautaro"
-- >True
--
-- >tocaLimpiar test Habitacion "Lautaro"
-- >False
--------------------------------------------------------------------------
type Tiempo = Int
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show

agregaLA:: ListaAsoc LugarALimpiar Tiempo -> LugarALimpiar -> Tiempo -> ListaAsoc LugarALimpiar Tiempo
agregaLA Vacia lugar tiempo = Nodo lugar tiempo Vacia
agregaLA (Nodo a b la) lugar tiempo = Nodo a b (agregaLA la lugar tiempo)
 
-- Ejemplo de ejecucion:
-- test = Nodo Baño 30 (Nodo Cocina 50 (Nodo Habitacion 30 Vacia))
--
-- > agregaLA test Comedor 10
-- >Nodo Baño 30 (Nodo Cocina 50 (Nodo Habitacion 30 (Nodo Comedor 10 Vacia))) 
------------------------------------------------------------------------------

data Arbol a = Hoja | Rama (Arbol a) a (Arbol a) deriving Show 
aMenor:: Arbol Int -> Int -> Bool
aMenor Hoja _ = False
aMenor (Rama left nodo right) num
    |nodo < num = True
    |otherwise = False || aMenor left num || aMenor right num

--Ejemplo de ejecucion:
-- test = (Rama (Rama (Rama Hoja 1 (Rama Hoja 2 Hoja)) 3 Hoja) 4 (Rama Hoja 5 Hoja))
-- > aMenor test 4
-- > True
--
-- > aMenor test 0
-- > False
-------------------------------------------------------------------------------------


