# Lab Org. y Arq. de Computadoras

* Configuración de pantalla: `640x480` pixels, formato `ARGB` 32 bits.
* El registro `X0` contiene la dirección base del FrameBuffer (Pixel 1)
* El código de cada consigna debe ser escrito en el archivo _app.s_
* El archivo _start.s_ contiene la inicialización del FrameBuffer, al finalizar llama a _app.s_ **(NO EDITAR)**
* El código de ejemplo pinta toda la pantalla un solo color

## Estructura

* **[app.s](app.s)** Este archivo contiene a apliación. Todo el hardware ya está inicializado anteriormente.
* **[start.s](start.s)** Este archivo realiza la inicialización del hardwar
* **[Makefile](Makefile)** Archivo que describe como construir el software _(que ensamblador utilizar, que salida generar, etc)_
* **[memmap](memmap)** Este archivo contiene la descripción de la distribución de la memoria del programa y donde colocar cada sección.
* **README.md** este archivo

## Uso

El archivo _Makefile_ contiene lo necesario para construir el proyecto. Se pueden utilizar otros 
archivos **.s** si les resulta práctico para emprolijar el código y el Makefile los ensamblará

**Para correr el proyecto ejecutar**

```bash
$ make run
```
Esto construirá el código y ejecutará qemu para su emulación
