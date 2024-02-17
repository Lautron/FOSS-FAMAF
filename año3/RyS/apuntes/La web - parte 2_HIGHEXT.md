# La Web: Parte 2

## HTML

**es el lenguaje estándar para crear páginas web**
**describe la estructura de una página web**
**indica al navegador como mostrar el contenido de la página**
**Un documento HTML es una serie de elementos:**

Un elemento es contenido encerrado entre etiquetas.

Una etiqueta tiene un nombre.

Una etiqueta está demarcada entre ‘<‘ y ‘>’.

Etiquetas pueden tener o no atributos.

Un atributo tiene un nombre y un valor (que es un string) separados por ‘=‘.


## Páginas dinámicas

**Páginas dinámicas: Son páginas web generadas por programas que se ejecutan en el servidor (posiblemente con una base de datos).**

**Tareas que suelen hacer**
Procesar parámetros de formularios
Procesar encabezados de pedido HTTP
Pedir datos a fuentes de datos
Generar página web con los datos recibidos.
Generar encabezados de respuesta HTTP


## PHP


### Enfoque PHP (Preprocesador de Hipertexto).

Se definen páginas dinámicas mediante la inserción de comandos especiales dentro de páginas HTML

El código PHP es interpretado por un servidor web.

PHP se diseñó para trabajar con el servidor web Apache.

PHP puede ser usado en la mayoría de los servidores web.

Algunas cosas que puede hacer PHP:

puede generar contenido de página dinámica

puede operar con archivos en el servidor.

puede recolectar datos de formulario

puede enviar y recibir cookies

puede acceder a encabezados de pedido HTTP

permite definir encabezados de respuesta HTTP

**Acceso a campos de formularios:**

$_POST: usado para recolectar datos de formulario luego de someter un formulario con método POST.

$_GET: usado para recolectar datos de formulario luego de someter un formulario con método GET. Se usa como en el ítem anterior.

**Tipos de datos de PHP**

String:



Float:
Boolean:
Array:
Object:

**Acceso a información de encabezados HTTP:**

$_SERVER: contiene información de encabezados, caminos y localización de scripts.

Para acceder a encabezados poner como argumento alguna de las siguientes:

HTTP_USER_AGENT, SERVER_ADDR, SERVER_NAME, SERVER_SOFTWARE, SERVER_PROTOCOL, REQUEST_METHOD, REQUEST_TIME, QUERY_STRING, HTTP_ACCEPT, HTTP_ACCEPT_CHARSET, HTTP_HOST, etc.

P.ej.: Para acceder al encabezado User-Agent: $_SERVER[‘HTTP_USER_AGENT’]

**Definición de cookies:**

Setcookie() define cookie para ser enviada junto con el resto de los encabezados HTTP.

Esta función debe usarse antes de generar cualquier salida, o sea antes que la etiqueta <html>

**Acceso al valor de una cookie:**

$_COOKIE se usa para retornar el valor de una cookie.