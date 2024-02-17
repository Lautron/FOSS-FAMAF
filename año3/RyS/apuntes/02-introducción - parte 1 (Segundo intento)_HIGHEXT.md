## La Internet


### La internet

está formada por billones de dispositivos de computación conectados entre sí.

En la internet se ejecutan
**aplicaciones de red.**

La internet es una red de redes que interconecta varias redes entre sí.

Para envío y recepción de mensajes entre sistemas finales se usan
**protocolos.**


### Estructura de la Internet

Hosts acceden a la internet a través de

**proveedores de servicios de internet de acceso**
(ISPs de acceso).


#### ¿Qué tipos de ISP de acceso existen?
\

**ISP residenciales**
compañías de cable, telefónicas, fibra a la casa (FTTH), etc.).

**ISP empresarial**
(da acceso a sus empleados).

**ISPs universitaria**
(da acceso a docentes, estudiantes y personal).

**Celulares.**

**ISPs que proveen acceso a WiFI**
(p.ej. en aeropuertos, hoteles, restaurantes, etc.

Las ISP de acceso son interconectadas a través de redes ISP nacionales e internacionales de más alto nivel llamados

### ISPs de capa superior
o globales de tránsito.
son ISP que proveen
**servicios de tránsito.**
Una ISP de capa superior consiste de
**enrutadores de alta velocidad**

interconectados con
**enlaces de fibra óptica**
de alta velocidad.

Las ISP globales de tránsito deben estar interconectadas entre sí.

Cada red ISP, ya sea de acceso o de capa superior, es manejada independientemente.


### redes proveedoras de contenido
(por ejemplo, Google, Facebook, Microsoft, Apple, etc.).


#### ¿Por qué se usan
\

Para reducir pagos a redes de tránsito global.

Para tener control sobre cómo sus servicios son entregados a los usuarios finales.


#### ¿A qué redes se conectan
\

A ISP regionales e ISP de acceso.


### ¿Qué redes tenemos en cada nivel de la jerarquía?

**“tier-1” ISPs comerciales**

(p.ej. redes globales de tránsito) cobertura nacional e internacional.

**Redes proveedoras de contenido**
En el medio
**ISP regionales.**
**Finalmente ISPs de acceso**


## Internet de las Cosas (IoT)


### ¿Qué es el IoT?

es extender Internet desde “computadoras” a “objetos”, sin necesidad de un “humano” en el medio.


### IOT nace de paradigmas de redes anteriores


#### Machine-to-Machine (M2M):
\
redes para conectar máquinas entre sí.


#### Radio-Frequency ID (RFID):
\
para chips embebidos en productos que hacen saltar alarmas en locales.


#### Wireless Sensor Networks (WSN):
\
sensores distribuidos conectados a una red.


#### Mobile Ad-Hoc Networks (MANET):
\
redes de autos que se comunican entre ellos.


#### Domótica (Smart home):
\

dispositivos hogareños conectados en red Ciudades, rural (Smart cities)


#### Vehículos
\
(Vehicle to everything)


#### Industria (Industria 4.0):
\

se conectan dispositivos en sistema productivo, en una fábrica.


#### Cyber-physical systems (CPS)
\


## Redes de área amplia (WANs)


### red de área amplia (WAN)

cubre un área geográfica grande, típicamente un país o hasta un continente.
Una red de área amplia va a permitir interconectar varias redes hogareñas e institucionales

### ¿Cómo se hace para enviar mensajes en una WAN?

**Algoritmo de almacenamiento y reenvío.**
Un paquete sigue una ruta de enrutadores.

El paquete se almacena enteramente en cada enrutador de la ruta.

El paquete almacenado en un enrutador espera allí hasta que la línea requerida de salida esté libre y luego se reenvía al siguiente enrutador.


### Encolado y pérdida de paquetes

Si la tasa de llegada al enlace (en bits) excede la tasa de transmisión del enlace por un período de tiempo.

**¿Qué va a suceder?**

Los paquetes se van a encolar, y esperarán a ser transmitidos en el enlace.

Los paquetes pueden ser descartados (perdidos) si la memoria (el búfer) se llena.

### ¿Cuánto demora el almacenamiento y reenvío?

 dnodal = dproc + dqueue + dtrans + dprop

 dproc: procesamiento del nodo

 dqueue: demora por encolado

Chequeo de errores

Tiempo de espera en el enlace de salida para transmisión.

Determinar la línea de salida

typically < msec

Depende de cuán congestionado está el enrutador


### Sistema telefónico fijo (p.ej. DSL):
Cada domicilio está conectado por un cable de cobre a una
**End office**

Toda oficina central está conectada a una
**Toll office.**

**Toll offices**
son usadas para reenvío de mensajes.

**Toll offices**
unidas por cables (de fibra óptica).


## Redes de Área Metropolitana (MAN)

Una
**red de área metropolitana (MAN)**

cubre una ciudad.


### tipos:


#### Redes de cable:
\

se basan en la red de TV por cable.


#### Redes móbiles:
\

son redes inalámbricas de alta velocidad.


## Redes de Área Local

Una
**red de área local**

(LAN) es una red operada privadamente dentro de un edificio o casa.


### ¿Dónde puede usarse una LAN?

Una LAN puede usarse en un hogar o en una organización (pública o privada).

Las LAN usadas por compañías se llaman

**redes empresariales.**


### ¿Qué tipos de hosts se comunican a una LAN?

Las LAN se usan para comunicar PCs, notebooks, celulares, impresoras, electrónicos del hogar, etc.

La idea es que los hosts puedan compartir recursos e intercambiar información.


### tipos de LAN:

#### LAN inalámbricas:
\
en su forma más simple las máquinas se comunican entre sí
por medio de una estación base (access point).


#### La Ethernet:
\
las máquinas se conectan por medio de cables a un commutador (switch).


### Difusión:

Si una máquina envía un mensaje, todas las demás lo reciben.


### ¿A quién puede estar destinado un mensaje cuando se usa difusión?¿Qué
Estar destinado a una única máquina
Ser enviado a todas las máquinas (broadcasting)

Ser enviado a un grupo de máquinas en particular (multicasting)


### Colisión:

más de una máquina manda simultáneamente un mensaje.
Los mensajes colisionan y se dañan.


#### ¿Qué hay que hacer en relación a las colisiones?
\
Evitar o minimizar colisiones.
Detectar las colisiones
Tratar las colisiones


### Redes de acceso empresarial


## Internet

Red dorsales (backbone) están conectadas a varias WAN

Redes metropolitanas pueden conectarse a WANs

LANs están conectadas a WANs o a redes metropolitanas


## Protocolos


### Protocolos de comunicación definen:
**formato,**

**orden**
de
**mensajes enviados y recibidos**
entre máquinas de la red, y
**acciones tomadas**
en la transmisión y recepción de mensajes
