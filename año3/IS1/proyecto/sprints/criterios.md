1. Formulario creación de partida:
   - El formulario debe tener campos para el nombre de la partida
   - El campo debe ser obligatorio
   - Al enviar el formulario, se debe crear una nueva partida en el sistema.

2. Endpoint creación de partida:
   - EL endpoint debe aceptar una solicitud POST con los detalles de la nueva partida en el cuerpo de la solicitud.
   - Debe devolver un código de estado HTTP 201 si la partida se crea exitosamente.
   - Debe devolver un código de estado HTTP 400 si los detalles de la partida son inválidos.

3. Formulario para unirse a partida:
   - El formulario debe tener un campo para el nombre de la partida
   - El campo debe ser obligatorio
   - Al enviar el formulario, el jugador debe ser agregado a la partida en el sistema.

4. Endpoint para agregar un jugador a una partida:
   - EL endpoint debe aceptar una solicitud POST con el ID del jugador en la URL
   - Debe devolver un código de estado HTTP 200 si el jugador se agrega correctamente.
   - Debe devolver un código de estado HTTP 404 si la partida no existe.
   - Debe devolver un código de estado HTTP 400 si la ID del jugador es invalida

5. Interfaz para iniciar partida:
   - La interfaz debe mostrar un botón para iniciar la partida.
   - Al hacer clic en el botón, la partida debe iniciar y la interfaz debe cambiar para reflejar el estado de la partida.

6. Endpoint para iniciar una partida:
   - El endpoint debe aceptar una solicitud POST con los detalles de la nueva partida en el cuerpo de la solicitud.
   - Debe devolver un código de estado HTTP 200 al iniciar con éxito la partida.

7. Interfaz para robar carta del mazo:
   - Debe mostrar un botón para robar carta del mazo.
   - Al hacer clic en el botón, se debe agregar una carta a la mano del jugador.

8. Endpoint para repartir una carta a un jugador:
   - El endpoint debe aceptar una solicitud PUT con la id de la partida y la ID del jugador en el cuerpo de la solicitud
   - Debe agregar una carta al mazo del jugador.
   - Debe eliminar la carta del mazo.
   - Debe devolver un código de estado HTTP 200 al entregar con éxito la carta.

9. Interfaz para seleccionar una carta de la mano del jugador:
   - La interfaz debe mostrar todas las cartas en la mano del jugador.
   - El jugador debe poder seleccionar una carta haciendo clic en ella.

10. Endpoint para jugar una carta de la mano de un jugador:
    - El endpoint debe aceptar una solicitud POST con los detalles de la carta en el cuerpo de la solicitud.
    - Debe eliminar la carta de la mano del jugador y ponerla en el campo de juego.
    - Debe devolver un código de estado HTTP 200 al jugar con éxito la carta.

