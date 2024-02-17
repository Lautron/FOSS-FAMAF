# Capa de Transporte Complementos de control de flujo


## Uso de búferes

**Aun si el receptor está de acuerdo en usar búferes, todavía queda la cuestión del tamaño de estos.**

**Solución 1:**
Si la mayoría de los segmentos tiene aproximadamente el mismo tamaño organizar los búferes como un grupo de búferes de tamaño idéntico,

Si el tamaño de búfer se escoge igual al tamaño del segmento más grande, se desperdiciará espacio cada vez que llegue un segmento corto.

Si el tamaño se escoge menor que el tamaño máximo de segmento, se requerirán varios búferes para los segmentos grandes, con la complejidad inherente.

**Solución 2:**
Uso de búferes de tamaño variable

la ventaja aquí es un mejor uso de la memoria, al costo de una administración de búferes más complicada.

**Solución 3:**

dedicar un solo búfer circular grande por conexión,

se

se hace buen uso de la memoria cuando todas las conexiones tienen una carga alta,

pero es deficiente si algunas conexiones cuentan con poca carga.


## Control de flujo en TCP

**Cuando la ventana es de 0, el emisor no puede enviar segmentos, salvo en dos situaciones:**

pueden enviarse datos urgentes

el emisor puede enviar un segmento de 1 B para hacer que el receptor re-anuncie el siguiente byte esperado y el tamaño de la ventana.

TCP proporciona esta opción para evitar un bloqueo irreversible si llega a perderse un anuncio de ventana.

**Un tamaño de ventana más grande permitirá al emisor continuar enviando datos, pero como el campo de tamaño de ventana es de 16 bits, es imposible expresar tal tamaño.**

**Solución (opción de escala de ventana):**

permitir al emisor y al receptor negociar un factor de escala de ventana.

Ambos lados pueden desplazar el tamaño del campo de ventana hasta 14 bits a la izquierda,

permitiendo por lo tanto ventanas de hasta 2^30 bytes.

La mayoría de las implementaciones actuales de TCP manejan esta opción.