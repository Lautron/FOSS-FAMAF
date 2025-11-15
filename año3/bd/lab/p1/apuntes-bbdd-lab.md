# Subqueries
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

# Triggers (Sintaxis)
```sql
CREATE TRIGGER trigger_name trigger_time trigger_event
ON table_name FOR EACH ROW
BEGIN
    [trigger_order]
    trigger_body
END;
```
## trigger_name
Este es el nombre que asignas al trigger. Debe ser único dentro de la base de datos para evitar conflictos con otros triggers.

## trigger_time
### BEFORE
Cuando se especifica como `BEFORE`, el trigger se ejecutará antes de que ocurra el evento que lo activa.

### AFTER
Cuando se especifica como `AFTER`, el trigger se ejecutará después de que haya ocurrido el evento que lo activa.

## trigger_event

### INSERT
El trigger se activará cuando se inserte una nueva fila en la tabla especificada.

### UPDATE
El trigger se activará cuando se actualice una fila existente en la tabla especificada.

### DELETE
El trigger se activará cuando se elimine una fila de la tabla especificada.

## FOR EACH ROW
Esta cláusula indica que el trigger se ejecutará para cada fila afectada por el evento que lo activa.

## trigger_order

### FOLLOWS
Cuando se especifica como `FOLLOWS other_trigger_name`, esto indica que el trigger actual debe ejecutarse después del trigger especificado.

### PRECEDES
Cuando se especifica como `PRECEDES other_trigger_name`, esto indica que el trigger actual debe ejecutarse antes del trigger especificado.

## trigger_body
El `trigger_body` contiene las declaraciones SQL que definen qué acciones realizará el trigger cuando se active.

# Transactions

## Que es una transaccion?
Una transacción de base de datos es una unidad lógica de trabajo que agrupa una o más operaciones de base de datos.

### Properties

#### Atomicity:
La transacción se ejecuta completamente o no se ejecuta en absoluto (el principio de "todo o nada").

#### Consistency:
La base de datos pasa de un estado válido a otro, manteniendo las reglas de integridad de los datos.

#### Isolation:
Las transacciones se ejecutan de manera independiente, con efectos intermedios ocultos para otros.

#### Durability:
Una vez confirmados, los efectos de la transacción son permanentes, persistiendo incluso a través de fallos del sistema.

## What are the different states of a transaction?

### Active
La transacción ha comenzado y actualmente está ejecutando operaciones de lectura/escritura.

### Committed
Todas las operaciones se han ejecutado, pero los cambios aún no se han guardado permanentemente. Este estado ocurre justo antes del commit.

### Failed
Ocurrió un error, impidiendo que la transacción se complete. Esto podría deberse a errores lógicos, fallos del sistema o violaciones de restricciones.

### Aborted
La transacción ha sido revertida, deshaciendo todos los cambios y revirtiendo la base de datos a su estado antes de que comenzara la transacción.

### Committed
La transacción se completó con éxito y todos los cambios se almacenan permanentemente.

## What are the different types of transactions?

### Flat Transactions
La forma más simple, que consiste en una secuencia de operaciones tratadas como una sola unidad.

### Nested Transactions
Estas contienen sub-transacciones dentro de una transacción principal, permitiendo un control más detallado. Si una sub-transacción falla, puede revertirse de manera independiente sin afectar a toda la transacción.

### Distributed Transactions
Estas implican operaciones que abarcan múltiples bases de datos o sistemas, requiriendo un coordinador para asegurar que todas las partes se completen o se reviertan juntas.

## What are concurrency problems in databases, and how do they relate to transactions?

### Dirty Read
Una transacción lee datos que otra transacción aún no ha confirmado.

### Non-Repeatable Read
Una transacción lee los mismos datos dos veces y obtiene valores diferentes debido a modificaciones concurrentes.

### Phantom Read
Una transacción vuelve a ejecutar una consulta y recupera un conjunto diferente de filas debido a las modificaciones de otra transacción.

## How are concurrency problems addressed in database systems?

### Locking
Los bloqueos compartidos (para lectura) y los bloqueos exclusivos (para escritura) previenen operaciones en conflicto sobre los datos. El bloqueo en dos fases (fases de crecimiento y reducción) es una implementación estándar para asegurar la consistencia.

### Timestamping
Cada transacción recibe una marca de tiempo única para determinar el orden de ejecución, previniendo anomalías específicas pero potencialmente llevando a más abortos de transacciones.

### Multi-Version Concurrency Control (MVCC)
Se mantienen múltiples versiones de los datos, permitiendo que las transacciones accedan a instantáneas consistentes sin bloqueos.

## What are isolation levels, and why are they important?

### Read Uncommitted
Permite leer datos no confirmados, susceptible a lecturas sucias.

### Read Committed
Previene lecturas sucias asegurando que las transacciones solo lean datos confirmados.

### Repeatable Read
Garantiza que leer los mismos datos múltiples veces dentro de una transacción devolverá los mismos valores.

### Serializable
Proporciona el aislamiento más fuerte, asegurando que las transacciones se ejecuten como si estuvieran ocurriendo en completo aislamiento.

## Transaction Control Statements in MySQL

### SET TRANSACTION
Se utiliza para establecer el nivel de aislamiento para una transacción en MySQL.
```sql
SET [GLOBAL | SESSION] TRANSACTION transaction_characteristic [, transaction_characteristic] …;
```
**Ejemplo:**
```sql
SET SESSION TRANSACTION ISOLATION LEVEL READ COMMITTED;
```
### COMMIT
Se utiliza para completar con éxito una transacción, haciendo que los cambios sean permanentes.
```sql
COMMIT;
```
### ROLLBACK
Se utiliza para deshacer completamente una transacción, revirtiendo la base de datos a su estado antes de que comenzara la transacción.
```sql
ROLLBACK;
```
### ROLLBACK TO <SAVEPOINT>
Se utiliza para deshacer una transacción hasta un punto de guardado específico dentro de una transacción anidada.
```sql
ROLLBACK TO <savepoint_name>;
```
**Ejemplo:**
```sql
ROLLBACK TO my_savepoint;
```
### SAVEPOINT <savepoint_name>
Crea un punto de guardado dentro de una transacción al que puedes volver más tarde.
```sql
SAVEPOINT <savepoint_name>;
```
**Ejemplo:**
```sql
SAVEPOINT my_savepoint;
```
### SELECT ... FOR UPDATE
Establece un bloqueo exclusivo en las filas seleccionadas para que otras transacciones no puedan actualizarlas hasta que tu transacción confirme.
```sql
SELECT * FROM table_name WHERE condition FOR UPDATE;
```
**Ejemplo:**
```sql
SELECT * FROM accounts WHERE account_id = 1 FOR UPDATE;
```
### SELECT ... FOR SHARE
Establece un bloqueo compartido en las filas seleccionadas para que otras sesiones puedan leerlas pero no modificarlas hasta que tu transacción confirme.
```sql
SELECT * FROM table_name WHERE condition FOR SHARE;
```
**Ejemplo:**
```sql
SELECT * FROM accounts WHERE account_id = 1 FOR SHARE;
```
### LOCK TABLES and UNLOCK TABLES
Se utiliza para bloquear y desbloquear tablas para la sesión actual.
```sql
LOCK TABLES table_name [AS alias] lock_type [, ...];
UNLOCK TABLES;
```
**Ejemplo:**
```sql
LOCK TABLES accounts WRITE;
-- Realizar operaciones
UNLOCK TABLES;
```


# Tips
## JOINS
### Cuando usar LEFT o RIGHT join
Cuando pueden haber valores nulos.

Por ejemplo, un pais que no tiene capital.

### Muchos joins seguidos
Se pueden concatenar varios joins

```sql
SELECT
    a.district,
    COUNT(r.rental_id) AS rental_count
FROM rental AS r
INNER JOIN inventory AS i
    ON r.inventory_id = i.inventory_id
INNER JOIN store AS s
    ON i.store_id = s.store_id
INNER JOIN address AS a
    ON s.address_id = a.address_id
GROUP BY a.district;
```

## SELECT
### SELECT DISTINCT
se utiliza para eliminar las filas duplicadas

## Preferir agregaciones
Ante la duda, preferir agregaciones antes que ORDER BY y LIMIT.

## Crear tabla
Suele ser buena idea asignarle una ID especifica a cada tabla
