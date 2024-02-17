# Capa de Transporte Establecimiento y liberación de conexiones


## Comparación de segmentos

**T sec es el tiempo de vida de paquete**

**Se eliminan paquetes viejos que andan dando vueltas por ahí.**

**El origen etiqueta los segmentos con n° de secuencia que no van a reutilizarse dentro de T sec.**

**El T debería ser lo suficientemente grande como para incluir retransmisión confirmada**
**de un paquete.**


## Establecimiento de Conexión

**Como al establecer una conexión se usan segmentos, una conexión debería tener un N° inicial de secuencia con el que comienza a operar.**

vincular N° inicial de secuencia de algún modo al tiempo y para medir el tiempo usar un reloj.

**Implementación de la idea (de Tomlinson):**
Cada host tiene un reloj de hora del día.

Los relojes de los hosts no necesitan ser sincronizados;

se supone que cada reloj es un contador binario que se incrementa a si mismo en intervalos uniformes.

El reloj continua operando aun ante la caída del host

Cuando se establece una conexión los k bits de orden mayor del reloj = número inicial de secuencia.

**Para lograr que al regresar al principio de los n° de secuencia, los segmentos viejos con el mismo n° de secuencia hayan desaparecido hace mucho tiempo**

el espacio de secuencia debe ser lo suficientemente grande.

**Problema: Cuando un host se cae, al reactivarse sus ET no saben dónde estaban en el espacio de secuencia.**

**Solución:**

requerir que las ET estén inactivas durante T segundos tras una recuperación para permitir que todos los segmentos viejos expiren

**¿Cómo hacer para establecer una conexión entre dos hosts?**

Para establecer conexión el host de origen envía un segmento CONNECTION REQUEST al destino y espera una respuesta CONNECTION ACCEPTED.
**Situación: No se recuerda en el destino n° de secuencias para conexiones.**

**Solución: Acuerdo de tres vías de Tomlinson de 1975.**

Caso de operación Normal • Fijarse en el número de secuencia del segmento de datos enviado.

**Solución: Acuerdo de tres vías de Tomlinson de 1975. Caso de segmento CR duplicado con retraso:**

Al rechazar el host 1 el intento establecimiento de conexión del host 2,

el host 2 se da cuenta de que fue engañado por un duplicado con retardo y abandona la conexión;

así, un duplicado con retardo no causa daño.

**Solución: Acuerdo de tres vías de Tomlinson de 1975. Caso de tanto segmento CR como de datos con retraso.**

cuando llega el segundo segmento retrasado al host 2,

el hecho de que se confirmó la recepción de z en lugar de y indica al host 2 que este también es un duplicado viejo.


## Establecimiento de una conexión TCP

**El n° de secuencia inicial de una conexión no es 0.**

Se usa un esquema basado en reloj con un pulso de reloj cada 4 μsec.

Al caerse un host, no podrá reiniciarse durante el tiempo máximo de paquete

para asegurar que no haya paquetes de conexiones previas vagando por Internet.

**Campos del encabezado TCP para el establecimiento de conexiones**

SYN se usa para establecer conexiones.

**Solicitud de conexión: SYN = 1 y ACK = 0.**

**La respuesta de conexión sí lleva una confirmación de recepción, por lo que tiene SYN = 1 y ACK = 1.**

**En TCP las conexiones usan el acuerdo de 3 vías**

Para establecer una conexión, el servidor, espera pasivamente una conexión entrante ejecutando LISTEN y ACCEPT y

especificando cierto origen o bien nadie en particular.

En el lado del cliente ejecuta CONNECT

la cual envía un segmento TCP con el bit SYN encendido y el bit ACK apagado, y espera una respuesta.

Al llegar el segmento al destino, la ETCP allí revisa si hay un proceso que haya ejecutado un LISTEN en el puerto indicado en el campo puerto de destino.

Si no lo hay envía una respuesta con el bit RST encendido para rechazar la conexión.

Si algún proceso está escuchando en el puerto ese proceso recibe el segmento TCP entrante y puede entonces aceptar o rechazar
rechazar la conexión; si la acepta se envía un segmento de ack.

La secuencia de segmentos TCP enviados en el caso normal se muestra en la Figura siguiente.


## Liberación de Conexiones

**¿Cómo hacer un protocolo para liberación de conexiones?**

Podríamos pensar en un protocolo en el que:

el host 1 dice “ya terminé ¿terminaste también?”; – Si el host 2 responde “Ya terminé también. Adiós”, la

“Ya terminé también. Adiós”, la conexión puede liberarse con seguridad.
liberarse con seguridad.

**un protocolo así no siempre funciona.**

**problema de los dos ejércitos**

**No existe un protocolo que resuelva el problema de los dos ejércitos:**

**¿Cómo hacer para que no ocurran las conexiones abiertas a medias?**

**Solución 1: Pudimos haber evitado este problema no permitiendo que el emisor se diera por vencido tras N reintentos, sino obligándolo a seguir insistiendo hasta recibir una respuesta.**

**Problema**

si se permite que expire el temporizador en el otro lado, entonces el emisor continuará eternamente, pues nunca aparecerá una respuesta.

**¿Cómo acabar con las conexiones abiertas a medias de los dos lados?**

**Solución 2: Una manera de matar conexiones abiertas a medias es:**

si no ha llegado ningún segmento durante una cierta cantidad de segundos al host 2, se libera automáticamente la conexión en el host 2.

Luego el host 1 detectará la falta de actividad y también se desconectará.

Esta solución también resuelve el caso que la red “se rompió” y los hosts ya no pueden conectarse.

**¿Cómo se puede implementar la solución anterior?**

**Es necesario que cada ET tenga un temporizador que se detenga y se reinicie con cada envío de un segmento.**

no se puede garantizar absolutamente que cuando se libera una conexión no ocurre pérdida de datos.
Pero si se puede limitar mucho que esto suceda.

**La liberación simétrica:**

Cada parte se cierra por separado, independientemente de la otra

Una de las partes emite un DISCONNECT porque ya no tiene más datos por enviar y aun está dispuesta a recibir datos de la otra parte.

Una

Una conexión se libera cuando ambas partes han emitido una primitiva DISCONNECT.

Es ideal cuando cada proceso tiene una cantidad fija de datos por enviar y sabe con certidumbre cuándo los ha enviado.

En otras situaciones la determinación de si se ha efectuado o no todo el trabajo o si debe terminarse o no la conexión no es tan obvia.

**TCP trabaja con liberación simétrica.**


## Liberación de una conexión TCP

**Campo usado por TCP para liberación de conexiones:**

FIN: especifica que el emisor no tiene más datos que transmitir.

Tras cerrar una conexión, un proceso puede continuar recibiendo datos indefinidamente.

Ambos segmentos, SYN y FIN, tienen n° de secuencia, y por tanto, tienen la garantía de procesarse en el orden correcto.


#### Resumen\

**Para liberar una conexión cualquiera de las partes puede enviar un segmento TCP con el bit FIN establecido, lo que significa que no tiene más datos por transmitir, pero todavía puede recibir datos del otro lado.**

**Al confirmarse la recepción del FIN, ese sentido se apaga (el receptor del ack no va a enviar más). • Sin embargo puede continuar un flujo de datos indefinido en el otro sentido.**

**Cuando ambos sentidos se han apagado, se libera la conexión.**

**Normalmente se requieren 4 segmentos TCP para liberar una conexión: un FIN y un ACK para cada sentido. • Sin embargo es posible que el primer ACK y el segundo FIN estén contenidos en el mismo segmento, reduciendo la cuenta total a 3.**