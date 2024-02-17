# HDD
## Sequential transfer
### Is the same as
Max transfer

## Random access
Is really slow

# Files and directories
Entrada de un directorio es asociar un nombre a un inodo

# File implementation
## Podemos verlo como
Arreglo de bloques que yo leo y escribo

## Inode
Son los archivos tal cual
Guardan informacion sobre donde se encuentran los datos del archivo

### Nombre
Viene de index node

### "Bomba fork FS"
Se puede llenar la cantidad de Inodes por mas que haya espacio en disco
Para hacer esto habria que crear miles de archivos

### Estructura
Los primeros 12 bloques son directos (apuntan directo a la data)
El 13 apunta a un directorio
el 14 a un directorio que apunta a directorios
el 15 a un directorio que apunta a directorios que apunta a directorios

Esto se hace para poder almacenar archivos grandes

## Ext2
No se pueden archivos de mas de 4Gb
Usa algo similar a las page tables para lograr esto

## Calcular tamaño máximo archivo
1. Cuantos indices por bloque entran en BLOCK_SIZE
    - BLOCK_INDEXES_PER_BLOCK = BLOCK_SIZE/BLOCK_INDEX_NUM_BYTES
2. Calcular número total de bloques y multiplicar por BLOCK_SIZE
    - (DIRECT_BLOCK_NUM + BLOCK_INDEXES_PER_BLOCK)* BLOCK_SIZE
