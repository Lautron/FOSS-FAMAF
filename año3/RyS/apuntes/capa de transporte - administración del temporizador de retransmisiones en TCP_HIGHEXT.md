# Capa de Transporte Administración del temporizador de retransmisiones en TCP


## Administración del temporizador del TCP

**¿qué tan grande debe ser el intervalo de expiración del temporizador de retransmisión?**

Si se hace demasiado corto

Ocurrirán retransmisiones innecesarias.

Si se hace demasiado largo?

Sufrirá el desempeño por el gran retardo de retransmisión de cada paquete perdido

**La varianza y la media de la distribución de llegada de las ack pueden variar a medida que se generan y se resuelven congestionamientos.**

Idea: Ajustar constantemente el intervalo de expiración del temporizador, con base en mediciones continuas del desempeño de la red.

**Solución: Algoritmo de Jacobson (1988) usado por TCP**

Por cada conexión el TCP mantiene una variable, RTT (round time),

significa estimación actual del tiempo de ida y vuelta al destino.

Al enviarse un segmento se inicia un temporizador,

para saber el tiempo que tarda el ack,

y para habilitar una retransmisión si se tarda demasiado.

Si llega el ack antes de expirar el temporizador:

TCP mide el tiempo que tardó el ack , digamos M,

entonces actualiza el RTT así:

**RTT = α RTT + (1-α) M,**

**α es el peso que se le da al valor anterior. Por lo común α = 7/8.**

Un RTT inicial de 1 sec se aconseja en RFC 6298.

**Dado RTT, hay que elegir una expiración adecuada del temporizador de retransmisión.**

**Solución**
hacer que el valor de timeout sea sensible tanto a la variación de RTT como a la varianza de la función de densidad de probabilidad del tiempo de llegada de los ack.

**Se**
**Se mantiene una variable amortiguada D (la desviación media).**

**Al llegar un ack, se calcula |RTT M|.**

**Se mantiene en D mediante:**

**D = β D + (1β )|RTT M|,**

**donde β típicamente es ¾**

**D es una aproximación bastante cercana a la desviación estándar.**

**¿Cómo estimar la expiración del temporizador? ¿De qué parámetros depende?**

La mayoría de las implementaciones TCP usan ahora este algoritmo y establecen:

**Expiración del temporizador = RTT + 4 x D.**

Con esto menos del 1% de los ack vienen en más de 4 desviaciones estándares tarde.

**¿qué se hace al recolectar muestras M cuando expira el temporizador de un segmento y se envía de nuevo?**

Cuando llega el ack no es claro si éste se refiere a la primera transmisión o a una posterior.

Si se adivina mal, se puede contaminar seriamente la estimación del RTT.

**¿Cómo se puede estimar el temporizador de retransmisiones en ese caso?**

**Solución: (algoritmo de Karn)**

No actualizar el RTT (cuando llega ack) de ninguno de los segmentos retransmitidos.

Cuando ocurre un timeout se duplica la expiración del temporizador.

Tan pronto se recibe un ack de segmento no retransmitido, el RTT estimado es actualizado y la expiración del temporizador se computa nuevamente usando la fórmula anterior.

**El algoritmo de Karn lo usan la mayoría de las implementaciones TCP.**

**UDP (protocolo de datagramas de usuario)**

Es no orientado a la conexión.

**segmentos = encabezado de 8 B + carga útil.**

2 puertos de 16b.

El campo longitud UDP incluye el encabezado de 8 bytes y los datos.

**UDP no realiza:**

**control de flujo, control de congestión, o retransmisión cuando se recibe un segmento erróneo.**

**Todo lo anterior le corresponde a los procesos de usuario.**

**UDP es especialmente útil en las situaciones clienteservidor.**

El cliente envía una solicitud corta al servidor y espera una respuesta corta.

**¿Qué pasa si se pierde la solicitud o la respuesta?**

El cliente puede probar nuevamente.