# Capa de Transporte Direccionamiento


## Direccionamiento

**Existe un proceso especial llamado servidor de directorio que para cada tipo de servicio sabe cuáles son los puertos de los servidores que prestan ese tipo de servicio.**
Pasos
usuario establece una conexión con el servidor de directorio

usuario envía un mensaje especificando el nombre del servicio.

servidor de directorio le devuelve la dirección puerto.

usuario libera la conexión con el servidor de directorio y establece una nueva con el servicio deseado.

**cuando se crea un servicio nuevo?**

servicio nuevo debe registrarse en el servidor de directorio, dando su nombre de servicio como la dirección de su puerto.

servidor de directorio registra esta información en su base de datos.

**¿Cómo hacer para que un proceso servidor atienda a las necesidades de una máquina cliente?**

Usar servidor que ejecuta los servidores inactivos

**Servidor de procesos = intermediario de los servidores de menor uso.**

pasos de la solución.

Escucha en un grupo de puertos al mismo tiempo esperando una solicitud de conexión

Un usuario emite una solicitud CONNECT, especificando el puerto del servicio que desea.

Si no hay ningún servidor esperándolo, consigue una conexión al servidor de procesos.

El servidor de procesos genera el servidor solicitado, permitiéndole heredar la conexión con el usuario existente.

El nuevo servidor hace el trabajo requerido y el servidor de procesos retorna a escuchar solicitudes nuevas.

**Puertos bien conocidos**

**N° puertos bien conocidos < 1024**
**Tabla de puertos bien conocidos.**
**Demonios = procesos servidores que atienden en un puerto**

**P. ej. que el demonio FTP se conecte a sí mismo al puerto 21 en el tiempo de arranque.**

**Problema: Se podría llenar la memoria con demonios que están inactivos la mayor parte del tiempo.**

**Solución: Un solo demonio llamado inetd (demonio de internet), escucha un conjunto de puertos al mismo tiempo y espera por un pedido de conexión.**

Usuarios potenciales de un servicio comienzan a hacer pedido CONNECT especificando el puerto del servicio que quieren. – Si no hay ningún servidor esperando por ellos, inetd bifurca un nuevo proceso y ejecuta el demonio apropiado en él, y ese demonio maneja la solicitud.

Inetd aprende qué puertos va a usar de un archivo de configuración.

Se puede tener demonios permanentes en los puertos más ocupados e inetd en los demás. • Esto lo fija el administrador de sistema.