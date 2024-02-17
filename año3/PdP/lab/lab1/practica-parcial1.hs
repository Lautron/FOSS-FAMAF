mapLista [] func = []
mapLista (tup:ts) func = func tup : mapLista ts func

lista = [(1,2), (3,4), (5,6)]

main :: IO ()
main = do
    putStrLn $ show $ mapLista lista
