# Sistemas Operativos de Redes

Los sistemas operativos de redes (SOR) están organizadas como una pila de capas o niveles, cada una construida arriba de la que está debajo de ella.

La cantidad de capas, los nombres de las capas, sus contenidos y su función, difieren de un tipo de red a otro.


## Jerarquías de Protocolos


### ¿Cuál es el propósito de una capa en arquitecturas multicapa?
ofrecer ciertos servicios a las capas superiores
ocultar la implementación a las capas superiores

operaciones y servicios primitivos ofrecidos por una capa a capa superior.


### ¿Cómo afecta esto al propósito de las capas?

Una capa n se piensa como una conversación entre la capa n de una máquina con la capa n de otra máquina,

sin tener que preocuparnos de ciertos problemas que resuelven las capas inferiores a la capa n.


### ¿Cuándo ocurren comunicaciones entre capas consecutivas?

Durante el envío de mensaje: cada capa pasa los datos y la información de control a la capa inmediatamente inferior, hasta que se alcanza la capa más baja.

Durante la recepción de mensaje: cada capa pasa cierta información conteniendo los datos a la capa inmediatamente superior hasta que alcanza la capa más alta.


### Procesos de aplicación (capa 5 o capa de aplicación)

Produce un mensaje y lo pasa a la capa 4 para su transmisión.


### La capa 4 (capa de transporte)
pone un encabezado en el mensaje para identificarlo y pasa el resultado a la capa 3.

El encabezado contiene números de secuencia para que la capa 4 en la máquina de destino entregue los mensajes en el orden correcto.


### Capa 3 (capa de red):
Hay limitaciones en el tamaño de los mensajes de capa 3.

Divide en paquetes los mensajes que llegan.

A cada paquete se le coloca un encabezado.

Decide cuál de las líneas que salen usar

Pasa los paquetes a la capa 2.


### La capa 2 (capa de enlace de datos)
agrega un encabezado y un terminador, a cada pieza

pasa la unidad resultante a la capa 1 para su transmisión.


## Aspectos de Diseño de las Capas


### Problema: Hace falta un mecanismo para identificar a las máquinas de una red.

Solución: Se usan direcciones para las máquinas.


### Situación indeseable: mensajes que llegan al receptor se pierden. – ¿Por qué se imaginan que puede pasar esto?

Causa: un emisor rápido satura de datos al receptor hasta que este ya no puede almacenar más datos que le llegan y comienza a perder datos.


### Problema: ¿Cómo evitar que un emisor rápido sature de datos a un receptor lento?

Idea de Solución: Uso de retroalimentación al emisor. • O sea, indicarle cuándo y cuánto puede enviar.


### Fragmentación de mensajes

Es común que las capas imponen un tamaño máximo a los mensajes.


### Situación indeseable: mensajes que llegan no pueden ser aceptados en una capa.

Causa: los procesos son incapaces de aceptar mensajes que superan una cierta longitud • por ejemplo en la capa de enlace de datos y en la capa de red • Por ejemplo en una inter-red (≠ redes aceptan ≠ tamaños max)


### Fragmentación de mensajes


#### Problema: ¿Cómo tratar un mensaje demasiado largo?\

Idea de solución: fragmentar mensajes, transmitir fragmentos y re-ensamblar mensajes.


### Congestión
Debido a las limitaciones de los enrutadores y las líneas de salida una red tiene una determinada capacidad de conducción de mensajes..


#### Situación indeseable: los mensajes enviados de host de origen a destino se pierden antes de llegar o demoran demasiado en llegar\


### congestión

La red no puede manejar la carga de paquetes que recibe de manera aceptable (esperas inaceptables o pérdida de paquetes)


#### Problema: ¿Cómo controlar la congestión?\

Idea de solución: que máquinas emisoras se enteren de la congestión y reduzcan el tráfico de salida.


## Capa de aplicación

En la capa de aplicación tenemos las aplicaciones de red.

Cada aplicación de red ofrece un servicio específico con su propia forma de interfaz con el usuario.

Hay dos opciones para desarrollar aplicaciones de red:

El programador para especificar la comunicación usa

una
(API).
Una API es conjunto básico de funciones a ser usadas.

La socket API es el estándar de facto para el software que se comunica sobre la internet.

El programador se apoya en middlewares para construir la aplicación de red.

Una

middleware provee servicios al software de la aplicación que • hacen más fácil a los desarrolladores implementar la comunicación y la entrada/salida de modo que • se pueden enfocar en el propósito específico de la aplicación.


## La capa de aplicación: TCP/IP

La capa de aplicación en TCP/IP contiene varios protocolos de nivel mas alto: transferencia de archivos (FTP), correo electrónico (SMTP), para resolución de nombres de host en sus direcciones de red (DNS), para páginas web (HTTP), etc.


## Capa de transporte

La capa de red provee comunicación entre hosts

los paquetes de la comunicación entre los hosts siguen rutas elegidas por la capa de red.

La capa de transporte (CT) provee comunicación entre procesos.

La CT mejora los servicios de la CR como veremos.
La CT se ejecuta por completo en los hosts.

Entidad de transporte (ET) = software/hardware de la CT.


#### ¿Qué cosas se debería solucionar la CT?\

– Uso de temporizadores y las retransmisiones de paquetes. – Uso de búferes y control de flujo. – Evitar congestionar la red poniendo demasiados paquetes en ella.

• Cuando la CR pierde paquetes, la CT puede solucionarlo.


## La capa de transporte: TCP/IP

Capa de transporte. Tiene dos protocolos:
TCP

• TCP divide el flujo de bytes entrantes en mensajes discretos y pasa cada uno de ellos a la capa de interred. • TCP proporciona entrega confiable y en orden de los mensajes.

• Permite que un flujo de bytes que se origina en una máquina se entregue sin errores en otra máquina en la interred. • Reensamblaje de los mensajes recibidos en el receptor.
• Mensajes recibidos son confirmados. • TCP también maneja el control de flujo y el control de congestión.

UDP

UDP proporciona entrega de mensajes no confiable y desordenada.

Un mensaje puede entregarse con errores, o no entregarse, o varios mensajes pueden entregarse en forma desordenada.

**¿Entonces qué cosas de TCP puedo sacar de UDP?**

Mensajes recibidos no son confirmados. • Control de flujo, control de congestión, retransmisiones cuando se recibe mensaje erróneo.

**¿Entonces para que tipo de aplicaciones se puede usar UDP?**

Se

usa para aplicaciones que no usan el control de flujo ni la secuenciación de mensajes. – Uso en consultas de solicitud-respuesta y en aplicaciones de transmisión de voz y video.


## Capa de Red

**Objetivos de la**
**(capa 3).**

– Algoritmos de almacenamiento y reenvío

– Control de congestión.

– Resolver problemas que surgen cuando un mensaje tiene que viajar por redes de distinta tecnología para llegar a destino.


#### Enrutamiento\

**➢Situación indeseable: un mensaje demora demasiado en llegar**

➢Causa: en determinadas redes (p.ej. WAN, internet, etc.) hay múltiples rutas entre el origen y el destino – Y justo se toma una ruta demasiado lenta/larga entre origen y destino

**➢Problema: ¿Cuando hay múltiples rutas entre el origen y el destino cómo elegir la mejor o las mejores?**

De esto se encargan los algoritmos de enrutamiento


#### Capa de interred:\



permite que los hosts inyecten paquetes dentro de cualquier red,

**¿Cómo viajan paquetes diferentes entre dos hosts?**
Estos viajan a su destino de manera independiente.
**¿Qué consecuencias tiene esto?**

Paquetes pueden llegar en un orden distinto al cual fueron enviados.

**¿Qué se hace con los paquetes que llegaron fuera de orden?**

las capas mas altas deberán ordenarlos, si se desea una entrega ordenada.


## La capa de red: TCP/IP

**¿Cómo se distingue entre diferentes máquinas (que tienen una conexión a internet)?**

Direcciones IP

**¿Cómo son los paquetes que se envían?**
Paquetes IP.

**¿Cómo se hace el enrutamiento?**

Hay protocolos de enrutamiento: se usan OSPF y BGP para enrutamiento de paquetes.


## Procesos en comunicación

procesos: programas ejecutándose dentro de un host

Proceso cliente: proceso que inicia la communicación

Proceso servidor: proceso que espera ser contactado

Dentro del mismo host, dos procesos se comunican usando comunicación inter-procesos

Los procesos en diferentes hosts se comunican intercambiando mensajes


## Direccionando Procesos

**❖**

**¿Cómo se identifican los procesos?**

Para recibir mensajes, los procesos deben tener un identificador

**❖**

❖ ❖ ❖ Para recibir mensajes, los procesos deben tener un identificador Un host tiene una dirección IP única de 32-bits

Identificadores de proceso incluyen tanto direcciones IP y número de puerto.

**¿Es la dirección IP del host en el cual ejecuta un proceso suficiente para identificar el proceso?**

▪ no, porque muchos procesos pueden estar ejecutándose en el mismo host.


## Capa de Enlace de Datos

**Objetivo de la**
**(capa 2)**

transformar un medio de transmisión puro en una línea de comunicación que aparezca libre de errores de transmisión.

**¿Qué problemas de diseño hay que considerar?**

Fragmentación de paquetes en tramas, cuando un paquete es demasiado grande

– Tramas

Tramas de confirmación de recepción son usadas cuando el servicio es confiable.



– Control de flujo. • Para evitar que un emisor rápido sature a un receptor lento.

– Control de acceso a un canal compartido: se busca manejar y minimizar o evitar colisiones.


#### – Control de errores\

**• Situación indeseable: mensajes llegan con errores**

• Causa: medio físico de comunicaciones es imperfecto y ocasiona errores


## Capa Física


#### ¿Cuál es el propósito de la capa física (CF)?\

Transportar un stream de datos de una máquina otra usando medios físicos.

**¿La CF consiste solo de medios físicos?**

– No. Los medios físicos se conectan entre sí usando dispositivos como codecs, modems, multiplexores, demultiplexores, etc.


## Capa Física: medios físicos

• • • • bit: se propaga entre pares de transmisor/receptor Enlace físico: lo que yace entre el transmisor & receptor Medios guiados: –Las señales se propagan en medios sólidos: copper, fiber, coax Medios no guiados: –Las señales se propagan libremente, e.g., radio Par trenzado (TP) ▪ 2 cables de cobre aislados • Category 5: 100 Mbps, 1 Gbps Ethernet • Category 6: 10Gbps

coaxial cable: ▪ 2 conductores concéntricos de cobre ▪ bidireccionales ▪ broadband: • Múltiples canales en el cable

Cable de fibra óptica: ▪ Fibra de vidrio que transporta pulsos de luz, cada pulso es un bit ▪ Operan a alta velocidad: • high-speed point-to-point transmission (e.g., 10’s-100’s Gbps transmission rate) ▪ Baja tasa de errores: • repeaters spaced far apart • immune to electromagnetic noise

radio link types:
▪ terrestrial microwave

▪ LAN (e.g., WiFi)

▪ wide-area (e.g., cellular)

▪ satellite


## Protocolos IoT

• • • • • • 802.15.4 – LR WPAN: es una colección de estándares para redes de área personal de tasa de transferencia baja (LR-WPANs). 6LoWPAN: (IPv6 over Low Power Wireless Personal Area Networks) trae el protocolo IP a los dispositivos de baja potencia que tienen capacidad de procesamiento limitada. CoAP: CoAP es un protocolo para usarse en dispositivos de internet restringidos en recursos (p.ej: nodos de redes de sensores inalámbricas). Websocket: WebSocket se basa en TCP y permite streams de mensages a ser enviados en ambos sentidos entre cliente y servidor, mientras se mantiene la conexión TCP abierta. DDS (Data distribution service): es un middleware centrado en datos para la comunicación de dispositivo-a-dispositivo or máquina-a-máquina. XMPP (Extensible Messaging and Presence Protocol) es un protocolo para comunicación de tiempo real y streaming de datos XML entre entidades de red. XMPP soporta caminos de comunicación client-to-server y server-to-server.


## Críticas al modelo de referencia TCP/IP

**•**
**• Problemas:**

– No se distingue entre servicio e interfaz. • Se quiere comunicar con aplicaciones por medio de direcciones físicas de interfaces. No hay dirección de nodo o aplicación. – No es un modelo general: no esta ajustado para describir ninguna pila de protocolos mas que TCP/IP. – No se mencionan las capas físicas y de enlace de datos – Protocolos altamente entrincherados y difíciles de remplazar.


## Modelo Híbrido

## Cómputo en la Nube (Cloud)

• Nube se refiere a una red pública, privada o híbrida que proporciona servicios remotos

– Permite la manipulación, configuración y acceso a recursos de hardware y software de forma remota.

**Hay 3 familias de recursos:**

–
Recursos de procesamiento:

• Aplicaciones

• Máquinas virtuales

• Contenedores:
(p.ej: Dockers)

– Recursos de almacenamiento:
Recursos de almacenamiento:

•
Almacenamiento de archivos:
(p.ej. dropbox)
dropbox)

Almacenamiento de bloques:

– Recursos de infraestructura: combinación de elementos de procesamiento y almacenamiento conectados en una red interna virtual

**•**
**Cómo se relaciona esto con redes?**

– 1) El cliente se conecta a los data centers por medio de redes TCP/IP (Internet), bajo el paradigma cliente-servidor (Se muestra en figura anterior). – 2) Dentro de los data-centers, el hardware de los servidores se conecta en red (“blades”, “patcheras”, “racks”). – 3) Dentro de los data-centers, los recursos de los servidores se abstraen en máquinas virtuales o contenedores que se conectan por medio de redes virtuales entre ellos.

Hay una red virtual adentro de una red física.

**• Servicios**
**• • Infrastructure-as-a-service (IaaS):**

**Platform-as-a-service (PaaS):**

**•**
**Software-as-a-service:**
**•**
**Virtualización:**

– Virtualización es el proceso de convertir un recurso IT físico en un recurso IT virtual. – Servidores virtuales usan guest OS. – La funcionalidad del software de virtualización incluye servicios de sistema relacionados a gestión de máquina virtual; este gestor de máquina virtual se llama hipervisor. – Tanto guest OS y software de aplicación ejecutando en servidor virtual no son conscientes del proceso de virtualización.

**•**
**Containerización:**

– Se empaqueta el código de la aplicación junto con los archivos de configuración relacionados, librerías y dependencias requeridas para que pueda ejecutar. – Este paquete de software o contenedor se abstrae del SO y es portable. – Las aplicaciones son desplegadas en contenedores. Cada contenedor ejecuta en un proceso.

– Usar contenedores permite a varios servicios de la nube ejecutarse como un servidor (físico o virtual) único mientras se accede al mismo SO.


## Convenciones a respetar

• • • • • • • • • • • B mayúscula = 1 byte = 8 bits (= 2^3 bits) 1KB = 2^10 B = 1024 B (=2^13 bits = 8192 bits) kibibyte 1MB = 2^20 B = 1.048.576 B 1GB = 2^30 B En resumen, para los casos anteriores se usan potencias de 2 junto con bytes. En cambio, b minúscula = 1 bit 1Kb = 10^3 b = 1000 b – Kilo bit 1Mb = 10^6 b = 1.000.000 b – Mega bit 1Gb = 10^9 b =

B mayúscula = 1 byte = 8 bits (= 2^3 bits) 1KB = 2^10 B = 1024 B (=2^13 bits = 8192 bits) kibibyte 1MB = 2^20 B = 1.048.576 B 1GB = 2^30 B En resumen, para los casos anteriores se usan potencias de 2 junto con bytes. En cambio, b minúscula = 1 bit 1Kb = 10^3 b = 1000 b – Kilo bit 1Mb = 10^6 b = 1.000.000 b – Mega bit 1Gb = 10^9 b = 1000.000.000 b – Giga bit En resumen, se usan potencias de 10 junto con bits. Para expresar velocidades de transmisión: – 1Kbps = 1000 bits por segundo – 10Mbps = 10^6 bps = 10.000.000 bits por segundo – 10Gbps = 10^9 bps