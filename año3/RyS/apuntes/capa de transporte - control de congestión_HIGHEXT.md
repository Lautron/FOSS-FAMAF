# Capa de Transporte Control de Congestión


## Control de Congestión

**Si un emisor manda a un receptor más información que la capacidad de carga de la subred:**

**la subred se congestionará pues será incapaz de entregar los segmentos a la velocidad con que llegan.**

**Se necesita un mecanismo de control de congestión basado en la capacidad de carga de la subred.**

**El mismo debe aplicarse al emisor.**

Para controlar la congestion:

En TCP algunos hosts disminuirán la tasa de datos.

Para llevar la cuenta de cuántos datos un host puede enviar por la red:

TCP maneja una ventana para la congestión (VC) cuyo tamaño es el número de bytes que el emisor puede tener en la red en todo momento.

En TCP el host tiene una forma de detectar congestión.

En TCP cuando un host detecta congestion:

El host ajusta el tamaño de la VC.

**La expiración de un temporizador causada por un paquete perdido se puede deber a:**
**ruido en la línea de transmisión o**

**el descarte de paquetes en el enrutador congestionado.**

**Hoy la pérdida de paquetes por errores de transmisión es rara debido a que las troncales de larga distancia son de fibra óptica.**

Luego, la mayoría de las expiraciones de tiempo en Internet se deben a la congestión.

**Solucíón de TCP:**

Todos los algoritmos de congestión de TCP suponen que las expiraciones de tiempo son causados por congestión.

**¿Cómo calcular un tamaño para la ventana de congestión (VC)?**

probar con un mínimo de datos e ir duplicando gradualmente hasta que no se pueda más.

Un algoritmo basado en esta idea se llama arranque lento.

**Algoritmo de arranque lento**

El emisor asigna a la VC el segmento de tamaño máximo (STM) usado por la conexión; entonces envía 1 STM.

Emisor y receptor se ponen de acuerdo en el tamaño del STM.

Si se recibe el ack de este segmento antes que expire el temporizador, el emisor agrega el equivalente en bytes de un segmento a la VC para hacerla de 2 STM y envía dos segmentos.

Cuando la VC es de n segmentos, si de todos los n se reciben acks a tiempo, se aumenta la VC en la cuenta de bytes correspondiente a n segmentos.

La VC sigue creciendo exponencialmente hasta expiración temporizador (timeout) o alcanzar el tamaño de la ventana receptora.



Si ocurre timeout se recorta la VC a tamaño VC/2, o sea no se enviarán ráfagas de segmentos mayores a VC/2.

**¿Cómo puede reconocer rápidamente el emisor que uno de sus paquetes se perdió?**

Asumimos: cada paquete que llega al receptor dispara un paquete ack.

**Cuando se pierde un segmento y otros segmentos luego del segmento perdido llegan al receptor:**

El receptor genera acks que confirman lo mismo

**Se llaman acks duplicados.**

**¿Qué significa que el emisor recibió un ack duplicado?**

Es probable que llegó otro segmento al receptor y el segmento perdido no dio señales de vida.

**Significado de recibir acks duplicados:**

Como segmentos pueden tomar distintos caminos, pueden llegar fuera de orden y esto va a disparar acks duplicados incluso cuando no se ha perdido ningún segmento.

Si se pierde un segmento, habrá probablemente varios ack duplicados.

**Solución: TCP asume que 3 acks duplicados implican que el paquete se perdió.**

**Luego ese paquete puede retransmitirse inmediatamente y antes de que expire el temporizador.**

**Esta heurística se llama retransmisión rápida.**

**Solución 2: Algoritmo de control de congestión de Internet (o TCP Tahoe):**

Usa un umbral además de las ventanas de recepción y congestión.

Al ocurrir una expiración del temporizador o detectarse 3 acks duplicados, se fija el umbral en la mitad de la ventana de congestión actual, y la ventana de congestión se restablece a un segmento máximo.

Luego se usa el arranque lento para determinar lo que puede manejar la red, excepto que el crecimiento exponencial termina al alcanzar el umbral.

A partir del punto en el que se alcanza el umbral las transmisiones exitosas aumentan linealmente la ventana de congestión (en un segmento máximo por ráfaga).

Recomenzar con una ventana de congestión de un paquete toma un RTT (para todos los datos previamente transmitidos que dejen la red y para ser confirmados, incluyendo el paquete retransmitido).

Si no ocurren más expiraciones de temporizador/3 acks duplicados, la ventana de congestión continuará creciendo hasta el tamaño de la ventana del receptor.

En ese punto dejará de crecer y permanecerá constante mientras no ocurran más expiraciones de temporizador y la ventana del receptor no cambie de tamaño.

**Comenzar con arranque lento cada vez que se pierde un paquete puede ser demasiado.**

**¿Qué se puede hacer para resolver este problema?**

**TCP Tahoe:**

Invariante: tamaño ventana congestión  $\leq$  tamaño ventana receptor
Se usa arranque lento hasta alcanzar el umbral

Luego vienen incrementos aditivos hasta alcanzar timeout o 3 acks duplicados

Luego el umbral se fija a la mitad del tamaño de la ventana de congestión

Goto 1

**Solución: Algoritmo de TCP Reno**

Evitar arranque lento (excepto cuando la conexión es comenzada) cuando expira el temporizador de re-envíos.

**Funcionamiento:**

1. Luego de iniciada la conexión se comienza con arranque lento. 2. A continuación la ventana de congestión crece linealmente hasta que se detecta una pérdida de paquete. – Se cuentan acks duplicados – Se considera pérdida de paquete 3 acks duplicados

3. El paquete perdido es retransmitido (usando retransmisión rápida).

4. Recuperación rápida: – Se manda un paquete por cada ack duplicado recibido. – Un RTT luego de la retransmisión rápida el paquete perdido es confirmado. – La recuperación rápida termina con esa confirmación de recepción.

5. Luego de recibir el nuevo ack: • la ventana de congestión de una conexión se achica a la mitad de lo que era cuando se encontraron 3 duplicados (decrecimiento multiplicativo). • El conteo de ack duplicados se pone en 0.

6. Luego la ventana de congestión va incrementando de a un segmento por cada RTT (crecimiento aditivo). 7. Este comportamiento continua indefinidamente.

**TCP Reno: – Invariante: tamaño ventana congestión  $\leq$  tamaño ventana receptor 1. Luego de iniciada la conexión viene arranque lento hasta alcanzar umbral. 2. Luego vienen incrementos aditivos hasta 3 ack duplicados. 3. Luego viene recuperación rápida. 4. Luego se reduce ventana de congestión a la mitad 5. Goto 2**