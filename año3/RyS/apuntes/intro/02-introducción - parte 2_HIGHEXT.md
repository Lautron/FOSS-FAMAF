# Sistemas Operativos de Redes


## sistemas operativos de redes (SOR)

están organizadas como una
**pila de capas o niveles,**
cada una construida arriba de la que está debajo de ella.

La cantidad de capas, los nombres de las capas, sus contenidos y su función, difieren de un tipo de red a otro.


## Jerarquías de Protocolos


### propósito de una capa en arquitecturas multicapa?
ofrecer ciertos servicios a las capas superiores
ocultar la implementación a las capas superiores


### Interfaces entre capas
operaciones y servicios primitivos ofrecidos por una capa a capa superior.


### propósito de las capas?

Una capa n se piensa como una conversación entre la capa n de una máquina con la capa n de otra máquina,


### comunicaciones entre capas consecutivas?

#### Durante el envío de mensaje:
\

cada capa pasa los datos y la información de control a la capa inmediatamente inferior, hasta que se alcanza la capa más baja.


#### Durante la recepción de mensaje:
\

cada capa pasa cierta información conteniendo los datos a la capa inmediatamente superior hasta que alcanza la capa más alta.


## cómo funcionan las capas para el envío de mensajes.


### (capa 5 o capa de aplicación)

Produce un mensaje y lo pasa a la capa 4 para su transmisión.


### •La capa 4 (capa de transporte)
•La pone un encabezado en el mensaje para identificarlo y pasa el resultado a la capa 3.


#### El encabezado
\
contiene
**números de secuencia**
para que la capa 4 en la máquina de destino entregue los mensajes en el orden correcto.


### •Capa 3 (capa de red):
Hay limitaciones en el tamaño de los mensajes de capa 3.

Divide en
**paquetes**
los mensajes que llegan.

A cada paquete se le coloca un encabezado.

Decide cuál de las líneas que salen usar

Pasa los paquetes a la capa 2.


### •La capa 2 (capa de enlace de datos)
agrega un encabezado y un terminador, a cada pieza

pasa la unidad resultante a la capa 1 para su transmisión.


## problemas de diseño

### mecanismo para identificar a las máquinas de una red.

Se usan direcciones para las máquinas.


### Control de flujo:


#### evitar que un emisor rápido sature de datos a un receptor
\

Uso de

**retroalimentación al emisor.**

O sea, indicarle cuándo y cuánto puede enviar.


### Fragmentación de mensajes

Es común que las capas imponen un tamaño máximo a los mensajes.

los procesos son incapaces de aceptar mensajes que superan una cierta longitud


#### ejemplo
\
en la capa de enlace de datos y en la capa de red

en una inter-red


#### tratar un mensaje demasiado largo?
\

fragmentar mensajes, transmitir fragmentos y re-ensamblar mensajes.


### congestión

La red no puede manejar la carga de paquetes que recibe de manera aceptable


#### controlar la congestión?
\

que máquinas emisoras se enteren de la congestión y reduzcan el tráfico de salida.


# tipos de capas


## Capa de aplicación

En la capa de aplicación tenemos las

**aplicaciones de red.**


### aplicación de red

ofrece un servicio específico con su propia forma de interfaz con el usuario.


### opciones para desarrollar aplicaciones de red:


#### (API).
\
Una API es conjunto básico de funciones a ser usadas.

La socket API es el estándar de facto para el software que se comunica sobre la internet.


#### middlewares
\

provee servicios al software de la •aplicación que
•aplicación hacen más fácil a los desarrolladores implementar la comunicación y la entrada/salida de modo que

se pueden enfocar en el propósito específico de la aplicación.


### TCP/IP

La
**capa de aplicación**

en TCP/IP contiene varios protocolos de nivel mas alto:
transferencia de archivos (FTP), correo electrónico (SMTP),
resolución de nombres de host en sus direcciones de red (DNS),
páginas web (HTTP), etc.


## Capa de transporte

La capa de red provee comunicación entre hosts

La
**capa de transporte**

provee comunicación entre procesos.

La CT mejora los servicios de la CR
La CT se ejecuta por completo en los hosts.

### Entidad de transporte

software/hardware de la CT.


### ¿Qué cosas se debería solucionar la CT?

Uso de
**temporizadores**
y las
**retransmisiones de paquetes.**
Uso de búferes y control de flujo.

Evitar congestionar la red poniendo demasiados paquetes en ella.

• Cuando la CR pierde paquetes, la CT puede solucionarlo.


### TCP/IP


#### TCP
\

proporciona entrega confiable y en orden de los mensajes.

Permite que un flujo de bytes que se origina en una máquina se entregue
**sin errores**
en otra máquina en la interred.

**Reensamblaje**
de los mensajes recibidos en el receptor.
TCP también maneja el
**control de flujo**
y
**el control de congestión.**


#### UDP
\

Un mensaje puede entregarse con errores, o no entregarse, o varios mensajes pueden entregarse en forma desordenada.

Mensajes recibidos no son confirmados.


#### para que tipo de aplicaciones se puede usar UDP?
\

Se

usa para aplicaciones que no usan el control de flujo ni la secuenciación de mensajes. – Uso en consultas de solicitud-respuesta y en aplicaciones de transmisión de voz y video.


## Capa de Red


### Objetivos

Algoritmos de almacenamiento y reenvío

**Control de congestión.**

Resolver problemas que surgen cuando un mensaje tiene que viajar por redes de distinta tecnología para llegar a destino.


### Enrutamiento

¿Cuando hay múltiples rutas entre el origen y el destino cómo elegir la mejor o las mejores?

De esto se encargan los
**algoritmos de enrutamiento**


### TCP/IP


#### Capa de interred:
\



permite que los hosts inyecten paquetes dentro de cualquier red,

Estos viajan a su destino de manera independiente.

Paquetes pueden llegar en un orden distinto al cual fueron enviados.

las capas mas altas deberán ordenarlos, si se desea una entrega ordenada.


#### ¿Cómo se distingue entre diferentes máquinas
\

Direcciones IP

4 números entre 0 y 255 separados por ‘.’


#### ¿Cómo son los paquetes
\
**Paquetes IP.**
(tienen su propio formato


#### ¿Cómo se hace el enrutamiento?
\
Hay protocolos de enrutamiento: se usan
**OSPF**
y

**BGP**
para enrutamiento de paquetes.


### Procesos en comunicación

Los procesos en diferentes hosts se comunican intercambiando
**mensajes**


### Direccionando Procesos

**Identificadores de proceso**

incluyen tanto direcciones
**IP**
y número de
**puerto.**

porque muchos procesos pueden estar ejecutándose en el mismo host.


## Capa de Enlace de Datos


### Objetivo

transformar un medio de transmisión puro en una línea de comunicación que aparezca libre de errores de transmisión.


### problemas de diseño

#### Fragmentación de paquetes
\

en tramas, cuando un paquete es demasiado grande para ser aceptado por la CED.

Transmisión de las tramas de manera secuencial.


#### Tramas de confirmación de recepción
\

son usadas cuando el servicio es confiable.


#### Control de flujo.
\

Para evitar que un emisor rápido sature a un receptor lento.


#### Control de acceso a un canal compartido:
\

se busca manejar y minimizar o evitar colisiones.


#### Control de errores
\

medio físico de comunicaciones es imperfecto y ocasiona errores


## Capa Física


### propósito

Transportar un stream de datos de una máquina otra usando medios físicos.


### ¿La CF consiste solo de medios físicos?

No. Los medios físicos
**se conectan entre sí**

usando dispositivos como codecs, modems, multiplexores, demultiplexores, etc.


### medios físicos

**bit:**

**Par trenzado (TP)**

**Enlace físico:**

lo que yace entre el transmisor & receptor

2 cables de cobre aislados

**Medios guiados:**

–Las señales se propagan en medios sólidos: copper, fiber, coax

**Medios no guiados:**

–Las señales se propagan libremente, e.g., radio

**▪Cable de fibra óptica:**

**coaxial cable:**
**Radio:**

**terrestrial microwave**

**LAN**

**wide-area**

**satellite**


# Protocolos IoT


#### 802.15.4 – LR WPAN:
\
es una colección de estándares para redes de área personal de tasa de transferencia baja


#### 6LoWPAN:
\
trae el protocolo IP a los dispositivos de baja potencia


#### CoAP:
\
protocolo para usarse en dispositivos de internet restringidos en recursos


#### Websocket:
\
se basa en TCP y permite streams de mensages a ser enviados en ambos sentidos entre cliente y servidor,


#### DDS
\

middleware centrado en datos para la comunicación de dispositivo-a-dispositivo or máquina-a-máquina.


#### XMPP
\
protocolo para comunicación de tiempo real y streaming de datos XML entre entidades de red.


## Críticas al modelo de referencia TCP/IP

No se distingue entre servicio e interfaz.

No se mencionan las capas físicas y de enlace de datos


## Modelo Híbrido

\
![55a](./imgs/02-introducción parte 2/55a.png){ width=250px }


## Cómputo en la Nube (Cloud)


### Nube

red pública, privada o híbrida que proporciona
**servicios remotos**

Permite la
**manipulación,**
**configuración**
y
**acceso**
a

**recursos**
de hardware y software de forma remota.


### familias de recursos:


#### Recursos de procesamiento:
\

**Aplicaciones**
(P.ej. Google Docs, Gmail)

**Máquinas virtuales**

**Contenedores:**
(p.ej: Dockers)


#### Recursos de almacenamiento:
\

**Almacenamiento de archivos:**
(p.ej. dropbox)

**Almacenamiento de bloques:**

memoria de sistema asociada a las máquinas virtuales.


#### Recursos de infraestructura:
\

combinación de elementos de procesamiento y almacenamiento conectados en una red interna virtual


### Servicios

#### Infrastructure-as-a-service (IaaS):
\

Ambiente formado por recursos centrados en infraestructura que pueden ser accedidos/manejados vía interfaces basadas en servicios de la nube y en herramientas.

P.ej: servidor virtual.


#### Platform-as-a-service (PaaS):
\

Ambiente predefinido listo para usarse que se compone de recursos IT configurados y desplegados.


#### Software-as-a-service:
\

un programa de software posicionado como un recurso compartido en la nube es hecho disponible como un producto.

El consumidor de la nube tiene un control administrativo muy limitado sobre el programa de software. Usa y configura el servicio.


### Virtualización:

Virtualización es el proceso de convertir un recurso IT físico en un recurso IT virtual.


### Containerización:

Se empaqueta el código de la aplicación junto con los archivos de configuración relacionados, librerías y dependencias requeridas para que pueda ejecutar.

Este paquete de software o contenedor se abstrae del SO y es portable.

Los contenedores son más pequeños en capacidad que una VM y requieren menos tiempo de inicio.


## Convenciones a respetar


### B mayúscula
= 1 byte = 8 bits (= 2^3 bits)


#### 1KB
\
1KB = 2^10 B = 1024 B (=2^13 bits = 8192 bits) kibibyte


#### 1MB
\
1MB = 2^20 B = 1.048.576 B


#### 1GB
\
1GB = 2^30 B


#### resumen,
\
se usan potencias de 2 junto con bytes.


### b minúscula
= 1 bit

1Kb = 10^3 b = 1000 b – Kilo bit

#### 1Kb
\

1Mb = 10^6 b = 1.000.000 b – Mega bit

#### 1Mb
\

1Gb = 10^9 b = 1000.000.000 b – Giga bit

#### 1Gb
\


#### resumen,
\
se usan potencias de 10 junto con bits.


### velocidades de transmisión:

#### 1Kbps
\
1Kbps = 1000 bits por segundo

#### 10Mbps
\
10Mbps = 10^6 bps = 10.000.000 bits por segundo

#### 10Gbps
\
10Gbps = 10^9 bps