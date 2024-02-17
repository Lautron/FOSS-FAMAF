# Capa de Transporte Transferencia de datos confiable y control de flujo


## Entrega de datos confiable

La capa de transporte debe soportar al menos un protocolo para entrega de datos confiable.

**Estos protocolos asumen que el canal puede:**
Corromper paquetes



Perder paquetes

La transferencia de datos es en un sentido, o sea hay un emisor y un receptor.




## Preliminares

**CT se ocupa de uso de temporizadores y retransmisiones de paquetes.**
Paquetes perdidos deben retransmitirse.

**Sabemos que un paquete no se perdió**

**porque fue confirmado con un paquete de confirmación de recepción.**

**Podemos asumir que si pasa un cierto tiempo y no fue confirmado entonces se perdió y hay que retransmitirlo.**

**Para medir el tiempo: – Usar temporizadores (timers)**

**El mismo paquete llega dos o más veces al receptor y la capa de transporte la pasa a la capa de aplicación más de una vez.**

asignar números de secuencia a los paquetes que salen.
La idea es que dado un número de secuencia de un segmento que acaba de llegar,

el receptor puede usar ese número de secuencia para decidir si el segmento es un duplicado y en ese caso descartarlo.


## Protocolo de Parada y Espera

**Comportamiento del emisor:**

**Suposición: el canal de comunicaciones subyacente puede perder paquetes**

El emisor envía paquete P y para de enviar.

Espera: El emisor espera una cantidad “razonable” de tiempo para el ACK

Los paquetes tienen N°de secuencias

Si llega el ACK a tiempo, se envía siguiente paquete. Goto 2.

Se trabaja con Acks

Sino se retransmite paquete P. Goto 2.

El receptor debe especificar N° de secuencia del paquete siendo confirmado.

Si hay paquete o ACK demorado pero no perdido:

Se usan retransmisiones de paquetes.

La retransmisión va a ser un duplicado con igual N°de secuencia ; luego se descarta en el receptor.

Para esto se requiere de uso de temporizadores.


## Desempeño de Parada y Espera

**desempeño pobre.**

** Denvío es la demora en enviar un paquete. ▪ U sender : utilización– fracción del tiempo en que el emisor está ocupado enviando. ▪ RTT es tiempo de ida y vuelta de un bit: RTT = 30 msec.**

**El protocolo de red limita el uso de recursos físicos.**


### Operación de Parada y Espera


#### Protocolos de tubería\

**Tubería: el emisor puede enviar múltiples paquetes al vuelo a ser confirmados**

El rango de números de sequencia debe ser incrementado usando palabras de más de un bit.

Hay que usar búferes en el emisor.

dos formas genéricas de protocolos de tubería:

retroceso N y repetición selectiva


### Tubería: utilización

### incrementada

#### Protocolos de tubería: visión general\

**Retroceso-N:**

**Repetición selectiva:**

Receptor envía ack acumulativo

El receptor envía confirmaciones individuales para cada paquete

No confirma paquetes si hay un agujero.

El emisor tiene un timer para el paquete más viejo no confirmado

El emisor mantiene un timer para cada paquete no confirmado

Cuando expira el timer retransmite todos los paquetes no confirmados.

Cuando el timer expira, retransmite solo ese paquete no confirmado.


#### Uso de búferes en el emisor\

**La ET emisora debe manejar búferes para los mensajes de salida.**

**porque:**

**puede hacer falta retransmitirlos**

**¿Cómo se usan búferes en el emisor? • El emisor almacena en búfer todas los segmentos**

**hasta que se confirma su recepción.**


#### Retroceso N\

Si un paquete T a la mitad de una serie larga se daña o pierde:

La CT receptora debe entregar paquetes a la capa de aplicación en secuencia.

Por lo que no se pueden entregar a la capa de aplicación los paquetes que llegaron bien después de T.

**¿qué debe hacerse con los paquetes correctos que le siguen a un paquete que se perdió?**

Con retroceso N el receptor descarta todos los paquetes subsecuentes al paquete perdido, sin enviar ack para los paquetes descartados.
Suposición:

Hay un límite en la cantidad de paquetes enviados y no confirmados + paquetes por enviar que puede almacenar el emisor en búferes.

¿Cómo representar

eficientemente?

Usar intervalos de números de secuencia dentro del espacio de números de secuencia.

Un intervalo de esos recibe el nombre de ventana corrediza.


## Retroceso-N: en el emisor

La“ventana” permite hasta N paquetes consecutivos sin confirmar

ventana emisora = tramas enviadas sin ack positivo o tramas listas para ser enviadas.

timeout(n): retransmite paquete n y todos los paquetes de mayor N°de secuencia en la ventana.

un paquete de confirmación solamente,



número de secuencia



Enviar ACK con N° de secuencia más alto tal que los N° de secuencia anteriores fueron recibidos.

**A esto se le llama ACK acumulativo.**

Si se pierde un segmento llegan bien varios de los siguientes, para estos se generan ACKs duplicados.

Para los números de secuencia, el receptor maneja variable expectedSeqnum que es el número de secuencia más chico que no llegó aun.


### Retroceso-N en acción

**¿Si el espacio de secuencia es de MAX_SEQ + 1 números de secuencia (estos comienzan desde 0), se puede hacer la ventana emisora de tamaño MAX_SEQ + 1?**

La respuesta es no

**El tamaño de la ventana emisora no puede superar MAX_SEQ cuando hay MAX_SEQ + 1 números de secuencia.**

**¿Cómo evitar que haya más de MAX_SEQ paquetes sin ack pendientes?**

prohíbir a la CR que moleste con más trabajo.

Usar enable_network_layer y disablenetwork_layer.

**¿Cuál es el problema principal de retroceso N?**

El uso ineficiente del canal frente a segmentos perdidos o demorados.


## Repetición Selectiva

¿qué debe hacerse con los paquetes correctos que le siguen a un paquete que se perdió?

Los paquetes en buen estado recibidos después de un paquete dañado E se almacenan en búfer.

Cuando el paquete E llega correctamente, el receptor entrega a la capa de aplicación, en secuencia, todos los paquetes posibles que ha almacenado en el búfer.

Mecanismo común de retransmisiones: o El temporizador de E termina y el emisor lo manda de nuevo.

Una solución mejor:

Uso de una ack negativa (NAK) por el receptor.

Así se estimula la retransmisión de paquetes antes que temporizadores terminen y así se mejora el rendimiento.

¿Y si
¿Y si la NAK se pierde?

El receptor confirma individualmente todos los paquetes recibidos correctamente.

Hay búferes para paquetes según se necesiten para su entrega eventual en orden a la capa de aplicación.

El emisor solo reenvía paquetes para los cuales el ACK no fue recibido o se recibió un NAK.

Hay un temporizador del emisor para cada paquete no confirmado.

**Ventana del emisor**

Contiene N N°de secuencias consecutivos
Limita N°de sequencias a enviar a paquetes no confirmados.

**¿Qué tipos de paquetes puede haber en la ventana del emisor?**

Paquetes enviados y confirmados porque antes hay paquetes no confirmados

Paquetes enviados y no confirmados
Paquetes listos para enviarse en búfer
**¿Cómo representar el conjunto de paquetes que puede almacenar en búfer el receptor?**

Usar intervalos de números de secuencia dentro del espacio de números de secuencia.
Un
intervalo de esos recibe el nombre de ventana corrediza.

Tipos de paquetes que puede haber en la ventana del receptor:
Paquetes esperados y no recibidos
Paquetes recibidos fuera de orden
Paquetes aceptables en la ventana que no han llegado aun

**Se mantiene en búfer un paquete aceptado por la ventana receptora**

hasta que todos los que le preceden hayan sido pasados a la capa de aplicación.


#### Repetición Selectiva: ventanas del emisor y del receptor\


#### Repetición Selectiva\

Algunos detalles

tamaño de ventana emisora comienza en 0 y crece hasta MAX_SEQ.

El receptor tiene un búfer para cada N° de secuencia en su ventana.

**¿Qué se hace cuando llega un paquete?**

Cuando llega un paquete, su número de secuencia es revisado para ver si cae dentro de la ventana.

De ser así, y no ha sido recibido aun, se acepta y almacena.


#### Repetición selectiva en acción\

#### Dilema de repetición\

#### selectiva\

#### Repetición Selectiva\

**Regla para el tamaño de la ventana receptora:**

Tamaño de ventana receptora = (MAX_SEQ + 1)/2.
Con tamaños mayores de ventana receptora no funciona.

En encabezado de paquete hay N° de secuencia de k bits.

**¿Cómo transmitir datos entre dos máquinas y en ambas direcciones eficientemente?**

**llevar a caballito (piggybacking).**

cuando llega un segmento S con datos, el receptor se aguanta y espera hasta que la capa de aplicación le pasa el siguiente paquete P.

La confirmación de recepción de S se anexa a P en un segmento de salida (usando el campo ack en el encabezado del segmento de salida).

extender repetición selectiva para tener flujos de datos entre 2 máquinas en las dos direcciones?

Se usa llevar a caballito.

La capa de transporte para mandar un ack, debe esperar por un paquete al cual superponer un ack.

**¿Cómo evitar retrasar demasiado envío de confirmaciones de recepción por no tener tráfico de regreso?**

**método que usa temporizador auxiliar**

tras llegar un paquete de datos en secuencia, se arranca un temporizador auxiliar mediante start_ack_timer.

Si no se ha presentado tráfico de regreso antes de que termine este temporizador, se envía un paquete de ack independiente.

tiempo de temporizador auxiliar << tiempo de temporizador de retransmisiones.

<< significa mucho menor.
<<

para asegurarse que la ack de un paquete correctamente recibido llegue antes que el emisor termine su temporización y retransmita el paquete.


## Control de flujo

**Control de Flujo:**
Hay que evitar que un host emisor rápido desborde a un host receptor lento.

**Tipo de control de flujo del que se ocupa la capa de enlace de datos:**

Control de flujo entre dos máquinas directamente conectadas entre sí

**¿Por qué puede necesitarse control de flujo en la capa de transporte si la capa de enlace de datos lo hace?**

El receptor puede demorarse en procesar mensajes debido a los problemas de la red:

pérdida de segmentos,

no se pueden procesar segmentos porque faltan anteriores.


## Uso de búferes

**¿Porqué esto es necesario?**

Si la llegada de segmentos del emisor es mucho más rápido que el receptor para procesar los segmentos recibidos,

entonces el receptor necesitará poder almacenar segmentos antes de procesarlos.

El receptor puede acumular una cantidad de segmentos suficientes antes de pasarlos a la capa de aplicación para que los procese.

Los segmentos pueden llegar desordenados;

por lo tanto si llegan un grupo de segmentos y faltan segmentos previos a ellos, habrá que almacenarlos segmentos de ese grupo en buffer.

**¿Qué hace el receptor con los búferes si tiene varias conexiones?**

Solución 1: se usan los búferes a medida que llegan segmentos.

Solución 2: se dedican conjuntos de búferes específicos a conexiones específicas.

**¿Qué hace el receptor cuando entra un segmento?**

Cuando entra un segmento el receptor intenta adquirir un búfer nuevo;

si hay uno disponible, se acepta el segmento; de otro modo se lo descarta.

**Suposición:**
**cambia el patrón de tráfico de la red; se abren y cierran varias conexiones en el receptor.**

**Consecuencias:**
El receptor y el emisor deben ajustar dinámicamente sus alojamientos de búferes.

Esto significa ventanas de tamaños variables.

Ahora el emisor no sabe cuántos datos puede mandar en un momento dado, pero sí sabe cuántos datos le gustaría mandar.

**¿Qué reglas cumpliría un protocolo entonces?**

El host emisor solicita espacio en búfer en el otro extremo.

Para estar seguro de no enviar de más y sobrecargar al receptor. o Porque sabe cuánto necesita.

**¿Qué pasa con el receptor al recibir ese pedido?**

Sabe cuál es su situación y cuánto espacio puede otorgar.
Aquí el receptor reserva una cierta cantidad de búferes al emisor.

Los búferes podrían repartirse por conexión, o no.

**¿Qué pasa si los búferes se reparten por conexión y aumenta la cantidad de conexiones abiertas?**

El receptor necesita ajustar dinámicamente sus reservas de búferes.

**¿Cómo funciona la comunicación entre host emisor y host receptor usando la solución?**

Inicialmente el emisor solicita una cierta cantidad de búferes, con base en sus necesidades percibidas.

El receptor otorga entonces tantos búferes como puede.

El receptor, sabiendo su capacidad de manejo de búferes podría indicar al emisor “te he reservado X búferes”.

**¿Cómo hace el receptor con las confirmaciones de recepción?**

El receptor puede incorporar tanto las ack como las reservas de búfer al en el mismo segmento.

El emisor lleva la cuenta de su asignación de búferes con el receptor.

**¿qué pasa con la asignación de búferes (disponibles) en el emisor cada vez que el emisor envía un segmento?**

Debe disminuir su asignación

**¿qué pasa si la asignación de búferes (disponibles) en el emisor llega a 0?**

El emisor debe detenerse por completo

**Situación: Información de reserva de búferes viaja en segmento que no contiene datos y ese segmento se pierde.**
**Esto termina ocasionando deadlock.**

Solución: Cada host puede enviar periódicamente un segmento de control con el ack y estado de búferes de cada conexión.
Así el estancamiento se romperá tarde o temprano.


## Control de flujo en TCP

**No se requiere:**

**que los emisores envíen datos tan pronto como llegan de la aplicación.**

**que los receptores envíen confirmaciones de recepción tan pronto como sea posible.**

**que los receptores entreguen datos a la aplicación apenas los reciben.**

**Esta libertad puede explotarse para mejorar el desempeño.**

**Campo Tamaño de ventana en el encabezado TCP:**

N° de bytes que pueden enviarse comenzando por el byte cuya recepción se ha confirmado.

0: indica que se han recibido los bytes hasta n° de confirmación de recepción – 1, inclusive, pero el receptor quisiera no recibir más datos por el momento.

El permiso para enviar puede otorgarse enviando un segmento con el mismo n° de confirmación de recepción y un campo tamaño de ventana distinto de 0.

**¿Qué se hace si la ventana anunciada por el receptor es de 0?**

El emisor debe detenerse hasta que el proceso de aplicación del host receptor retire algunos datos del búfer

en cuyo momento el TCP puede anunciar una ventana más grande.

En TCP los hosts en cada lado de una conexión tienen un buffer de recepción circular para la conexión.
**un buffer de recepción circular**

Cuando la conexión TCP recibe bytes en el orden correcto y en secuencia, coloca los datos en el buffer de recepción.

**Cálculo de tamaño de ventana:**

**Tamaño de ventana =RcvBuffer $-$ [LastByteRcvd $-$ LastByteRead]**

**Inicialmente se puede mandar:**

**Tamaño de ventana = tamaño RcvBuffer**

**Propiedad a respetar en el emisor:**

**LastByteSent $-$ LastByteAcked  $\leq$  tamaño de ventana**

**¿Cómo manejar pérdidas de segmentos en TCP?**

**Solución 1:**

el receptor solicita segmento/s específico/s mediante segmento especial llamado NAK.

Tras recibir segmento/s faltante/s, el receptor puede enviar una confirmación de recepción de todos los datos que tiene en búfer.

Cuando el receptor nota una brecha entre el número de secuencia esperado y el número de secuencia del paquete recibido, el receptor envía un NAK en un campo de opciones.

**Solución 2:**

(acks selectivos) el receptor le dice al emisor que piezas recibió.

El emisor puede así reenviar los datos no confirmados que ya envió.

Se usan dos campos de opciones:

Sack permited option: se envía en segmento SYN para indicar que se usarán acks selectivos.

• Sack option: Con lista de rangos de números de secuencia recibidos.