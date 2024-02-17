## Crear partida
### Frontend:
- Programar el botón de "Crear Partida".
- Programar el formulario de creacion de partida
- Crear un cuadro de diálogo para confirmar la creación de la partida.

### Backend:
- Validar numero de jugadores
- Implementar una función para guardar la partida la base de datos.

## Unir jugador
### Frontend:
- Programar el botón de "Unirse a Partida".
- Crear un cuadro de diálogo para ingresar los datos de la partida a la que desea unirse el usuario.
- Mostrar un mensaje de error si no se encuentra la partida o si ya ha comenzado.

### Backend:
- Validar union del jugador
- Crear una función para agregar al jugador a la partida en la base de datos.

## Iniciar partida
### Frontend:
- Programar el botón de "Iniciar partida".
- Programar Mensaje de confirmación para iniciar la partida.
- Crear un mensaje de error si el jugador no es el creador de la partida.

### Backend:
- Validar que el jugador que inicia la partida sea el creador de la misma.
- Crear función para asignar roles a los jugadores.
- Crear funcion para cambiar el estado de la partida a "en progreso" en la base de datos.

## Crear mazo
### Backend:
- Crear función para generar las cartas del mazo.

## Repartir cartas
### Backend:
- Crear funcion para hacer la repartida inicial de cartas

## Robar carta mazo
### Frontend:
- Crear botón de "Robar Carta".

### Backend:
- Crear funcion que agregué cartas a la mano de un jugador
- Crear funcion que saca una carta del mazo
- Crear reglas para el manejo de cartas especiales como Pánico y Lanzallamas.

## Jugar Carta
### Frontend:
- Crear opción en la interfaz para seleccionar una carta para jugar.

### Backend:
- Crear función para jugar una carta de la mano del jugador.
- Crear función para mover la carta jugada a la pila de descartes.

## Efecto Lanzallamas
### Frontend:
- Crear una opción para que el jugador pueda seleccionar a qué jugador adyacente eliminar.

### Backend:
- Crear una función para eliminar a un jugador de la partida.
- Crear una regla para prevenir que "La Cosa" juegue la carta Lanzallamas.

## Finalizar partida
### Frontend:
- Mostrar los resultados y los ganadores cuando la partida termine.
- Crear un botón que lleve a los jugadores a la pantalla principal del juego después de que termine la partida.

### Backend:
- Crear funcion que verifica las condiciones para terminar la partida.
- Crear proceso que termine la partida.
