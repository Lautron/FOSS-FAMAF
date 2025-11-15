## Set membership (`IN`, `NOT IN`):
Se utiliza para verificar si un valor coincide con algún valor dentro de
un conjunto de resultados o una lista de valores.

### Sintaxis:
```sql
SELECT column_name
FROM table_name
WHERE column_name IN (value1, value2, ...);
```

## Set comparison (`ALL`, `SOME`):
`ALL` verifica si una condición es verdadera para todos los valores en
una subconsulta, mientras que `SOME` verifica si es verdadera para al
menos un valor.

### Sintaxis:
```sql
SELECT column_name
FROM table_name
WHERE column_name > ALL (subquery);
```

## Empty relations (`EXISTS`, `NOT EXISTS`):
`EXISTS` verifica si una subconsulta devuelve alguna fila, indicando una
relación no vacía. `NOT EXISTS` verifica si hay una relación vacía.

### Sintaxis:
```sql
SELECT column_name
FROM table_name
WHERE EXISTS (subquery);
```

## Subconsulta Correlacionada:
Este tipo de subconsulta depende de la consulta externa para sus valores
y se ejecuta repetidamente para cada fila en la consulta externa.

### Ejemplo:
```sql
SELECT column_name
FROM table_name t1
WHERE column_name = (SELECT column_name FROM table_name t2 WHERE t1.column_name = t2.column_name);
```

## Subconsulta Escalar:
Esta subconsulta devuelve un solo valor y se puede utilizar en varias
cláusulas como `SELECT`, `WHERE` y `HAVING`.

### Ejemplo:
```sql
SELECT column_name
FROM table_name
WHERE column_name = (SELECT avg(value) FROM table_name);
```

## CTE (Common Table Expresion):
Un conjunto de resultados temporal nombrado definido dentro de una
consulta, mejorando la legibilidad y la modularidad.

### Sintaxis:
```sql
WITH cte_name AS (
    SELECT column_name
    FROM table_name
)
SELECT *
FROM cte_name;
```

## Agregaciones:
Funciones que operan sobre un conjunto de valores para devolver un solo
valor, como `AVG`, `MAX`, `MIN`, `COUNT` y `SUM`.

### Sintaxis:
```sql
SELECT AVG(column_name)
FROM table_name;
```

## `GROUP BY`:
Agrupa filas con los mismos valores en columnas especificadas,
permitiendo que se apliquen funciones de agregación a cada grupo.

### Sintaxis:
```sql
SELECT column_name, COUNT(*)
FROM table_name
GROUP BY column_name;
```

## `HAVING`:
Filtra los resultados de las agregaciones de `GROUP BY` basándose en
condiciones especificadas.

### Sintaxis:
```sql
SELECT column_name, COUNT(*)
FROM table_name
GROUP BY column_name
HAVING COUNT(*) > value;
```

# Tips
## JOINS
### Cuando usar LEFT o RIGHT join
Cuando pueden haber valores nulos.

Por ejemplo, un pais que no tiene capital.

## SELECT
### SELECT DISTINCT
se utiliza para eliminar las filas duplicadas y mostrar una lista única de valores.

## Si hace falta un agregador
Probablemente haga falta una agrupacion

## LIMITS inside views
LIMITS inside views seem to be tricky, try to avoid them
