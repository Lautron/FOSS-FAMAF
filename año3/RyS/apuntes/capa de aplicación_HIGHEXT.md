# Capa de aplicación

En la capa de aplicación tenemos las aplicaciones de red.

Cada aplicación de red ofrece un servicio específico – con su propia forma de interfaz con el usuario.


#### dos enfoques para desarrollar aplicaciones de red:\

**1. El programador para especificar la comunicación usa una interfaz para programas de aplicación (API).**

– Una API es conjunto básico de funciones. – La socket API se usa para el software que se comunica sobre la internet.

**2. La Web: El programador se apoya en la tecnología de la web para construir una aplicación de red..**

– La Web provee servicios al software de la aplicación que • hacen más fácil a los desarrolladores implementar la comunicación y la entrada/salida de modo que • se pueden enfocar en el propósito específico de la aplicación.


## Arquitecturas de aplicaciones

**Las aplicaciones red suelen usar uno de los siguientes estilos de arquitectura:**
• cliente-servidor • peer-to-peer (P2P)


## Arquitecturas Cliente-Servidor

• • En el modelo cliente-servidor hay dos procesos que se comunican: uno en la máquina cliente y otro en la máquina servidor. Forma de la comunicación: 1. El proceso cliente manda solicitud al proceso servidor, 2. el proceso cliente espera un mensaje de respuesta; 3. luego el proceso servidor recibe y procesa la solicitud; 4. el proceso servidor manda mensaje de respuesta al proceso cliente.

**Características de los servidores:**

• Siempre están en un host; • con dirección IP permanente; • se pueden usar centros de datos para escalabilidad.

**Características de los clientes:**

• Pueden estar conectados intermitentemente; • usando direcciones IP dinámicas; • Los clientes no se comunican directamente entre sí.


## Aplicaciones Cliente Servidor en internet usando UDP

**Pasos de una aplicación cliente-servidor usando UDP.**

1. Cliente crea datagrama con IP y puerto del servidor y envía datagrama • Datagrama puede perderse. 2. Si llega, servidor lee datagrama 3. Servidor envía respuesta especificando dirección y puerto de cliente • Datagrama puede perderse. 4. Si llega, cliente lee datagrama. 5. Cliente finaliza • Evaluación: – No se dice qué se hace si respuesta no llega al cliente. – Es responsabilidad de la aplicación red manejar esto.


## Aplicaciones Cliente Servidor en internet usando TCP

**Pasos de una aplicación cliente-servidor usando TCP:**

1. Se ejecuta proceso del servidor 2. Servidor espera por pedido de conexión entrante. 3. El cliente requiere pedido de conexión al servidor 4. El servidor acepta la conexión con el cliente 5. El cliente envía pedido al servidor 6. El servidor lee el pedido 7. El servidor envía la respuesta 8. El cliente lee la respuesta – TCP provee transferencia de stream de bytes ordenada 9. Si hay más pedidos al servidor: Goto 5 10. El cliente cierra la conexión 11. El servidor cierra la conexión


## Arquitectura P2P

**Características de una arquitectura P2P:**

• Mínimo o ningún apoyo en servidores. • Hosts arbitrarios (llamados compañeros) se comunican directamente entre sí. • Compañeros piden servicio de otros compañeros, y proveen servicio en retorno a otros compañeros • Nuevos compañeros traen nueva capacidad de servicio, así como nuevas demandas de servicios. • Los compañeros se conectan intermitentemente y cambian las direcciones IP.

**Ejemplos**

Distribución de archivos:
la aplicación distribuye
distribuye un archivo

de una única fuente a un gran
a un gran número de compañeros.

Un ejemplo es BitTorrent.

Bases de datos distribuidas

Streaming:
VoIP:


## P2P vs cliente-servidor

**Problema: ¿Cuánto tiempo se requiere para distribuir un archivo (de tamaño F) de un servidor a N compañeros?**

La capacidad de subida y de bajada de compañeros es un recurso limitado.


### Distribución de Archivos: Cliente-Servidor

**¿Qué Parámetros hay que considerar?**
– Tasa de subida del enlace de acceso al compañero i: ui
– Tasa de subida del enlace de acceso al servidor: us
– Tasa de descarga del enlace de acceso al compañero i: di
– Tamaño del archivo a ser distribuido: F
– Número de compañeros que quieren adquirir una copia del archivo: N

**El tiempo de distribución es el tiempo que toma obtener una copia del archivo por los N compañeros.**
–
Asumimos

Asumimos que la internet tiene abundante ancho de banda y todos los cuellos de botella suceden en ISP de acceso.

– Asumimos que los servidores y clientes no participan de otras aplicaciones de red.

**Transmisión del servidor:**

Transmisión del servidor: debe enviar secuencialmente (subida) N copias de archivo a cada peer (manda NF bits). – Tiempo para enviar 1 copia: F/us

– Tiempo para enviar N copias: NF/us

– Demasiado trabajo del servidor

**Descarga del Cliente:**

cada cliente debe descargar una copia de archivo. ▪ dmin = min{d1,dp,...,dN}. ▪ Tiempo de descarga del cliente con dmin: F/dmin segs ▪ Este es el tiempo de descarga peor.

** Dc-s > max{NF/us,,F/dmin}**

**Tiempo para distribuir F a N clientes usando enfoque cliente-servidor**


## Distribución de Archivos: P2P

**Al comienzo de la distribución**
solo el servidor tiene el archivo.

**Para que la comunidad de compañeros reciba este archivo,**

el servidor debe enviar cada bit del archivo al menos una vez en su enlace de acceso.

**En P2P cada compañero puede redistribuir cualquier porción del archivo que ha recibido a cualesquiera otros compañeros.**

Así los compañeros asisten al servidor en el proceso de distribución.

Cuando un compañero recibe algo de datos de un archivo, puede usar su capacidad de subida para redistribuir los datos a los otros compañeros.

La capacidad total de subida del sistema es:

utotal = us + Sui
utotal

Por lo tanto el tiempo mínimo de distribución es: NF/utotal

**Transmisión de servidor:**
debe subir al menos una copia.

Tiempo para enviar una copia : F/us

**cliente:**

cada cliente debe descargar   la copia de un archivo

ui Tiempo mínimo de descarga de cliente: F/dmin

**clientes:**
como agregado deben subir NF bits

Tasa de subida máxima

es us + Sui

 DP2P > max{F/us,,F/dmin,,NF/(us + Sui)}

tiempo para distribuir F a N clientes usando enfoque P2P


## Distribución de archivos P2P: BitTorrent

El archivo se divide en trozos de 256Kb.

Los compañeros en torrent envían/reciben trozos.

tracker: lleva la pista de compañeros torrent: grupo de compañeros Participando en Torrent intercambiando trozos de un archivo


#### Cuando compañero se une a Torrent:\

No tiene trozos, pero va a acumularlos a lo largo del tiempo de otros compañeros

Se registra con tracker para obtener lista de compañeros.

Se conecta con un subconjunto de compañeros (“vecinos.”)

Un compañero avisa periódicamente a tracker que está en BitTorrent.

Mientras descarga, compañero sube trozos a otros compañeros. Un compañero puede cambiar de compañeros con los cuales intercambia trozos. Los compañeros pueden ir y venir.

Una vez que un compañero tiene un archivo completo: ▪ Puede (egoístamente) irse o (altruísticamente) permanecer en Torrent subiendo trozos.


### BitTorrent: pedir y enviar trozos de archivos


#### Enviar trozos: tit-for-tat\


#### Pedir trozos:\
En

Alicia envía trozos a aquellos 4 compañeros actualmente enviándole a Alicia trozos a la velocidad mayor. ▪ re-evalua los 4 mejores cada 10 seg • Cada 30 seg: elegir aleatoriamente otro compañero, y comenzar enviándole trozos.

En un momento dado, diferentes compañeros tienen diferentes subconjuntos de trozos de archivos • Periódicamente, Alicia pide a cada compañero por una lista de trozos que ellos tienen.


#### Alicia puede hacer esto porque\

Un compañero nuevo elegido puede unirse a los 4 de más arriba. Pero para esto tiene que ser uno de los 4 mejores subidores para Alicia.

sabe qué trozos tienen sus compañeros.


#### Conviene pedir primero los trozos\

menos comunes (i.e. con menos copias en compañeros).


## Protocolos de capa de aplicación

**Reglas**


#### Cosas a definer en un protocolo de capa de aplicación:\

de cuándo y cómo los procesos envían y responden a mensajes.

**Tipos de mensajes intercambiados**

**Estado**

de la aplicación. En qué consiste y cómo se lo mantiene.

**Sintaxis del mensaje:**


#### Tipos de protocolos\
**Protocolos abiertos:**
Son definidos en RFCs

**Semántica del mensaje**

Permiten interoperabilidad

P.ej: HTTP,

**Protocolos propietarios:**
P.ej: Skype


## FTP: Protocolo de Transferencia de Archivos


#### Algunas características de FTP:\

Usado para transferir archivo hacia/desde host remoto

Cada archivo tiene restricciones de acceso y poseción.

FTP permite inspeccionar carpetas.

FTP permite mensajes de control textuales.


#### 3 tipos de mensajes son intercambiados:\

Uso de comandos enviados al servidor ftp

Mensajes de respuesta a comandos del servidor ftp
Mensajes con datos enviados.


#### Sintaxis de Mensajes de respuesta\

Código de estatus y frase
**Ejemplos**


#### Sintaxis de comandos\
USER username

331 Username OK, password required

PASS password

LIST return list of file in current directory

RETR filename retrieves (gets) file

STOR filename stores (puts) file onto remote host

452 Error writing file


#### Reglas:\

1. Cliente FTP contacta servidor FTP en puerto 21, usando TCP.

2. El cliente es autorizado en la conexión de control.

3. El cliente inspecciona directorio remoto, envía comandos sobre la conexión de control.

Se comienza con
identificación de usuario y password.


#### Estado\

4. Cuando el servidor recibe un comando de transferencia de archivo, el servidor abre una 2da conexión de datos TCP

El servidor FTP mantiene el “estado”: directorio corriente, autenticación previa.

(para el archivo) con el cliente.
con el cliente.

5. Luego de transferir un archivo, el servidor cierra la conexión de datos.