apellidos [] = []
apellidos ((a,b,c):xs) = b : apellidos xs
