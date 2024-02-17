---
title: Take Home - Ing. Software 1
author: Lautaro Bachmann
---
# Alcance del proyecto

## Objetivos
El objetivo del proyecto consiste en implementar un sistema de software que permita a varios jugadores jugar al juego de cartas "La Cosa".

## Facultades del usuario
El usuario podrá:

- Elegir un nombre de usuario.
- Crear una sala:
    - Con o sin contraseña.
    - Con un número específico de jugadores mínimos y máximos.
    - Con un nombre único determinado por el usuario.
- Enviar mensajes a los demás jugadores presentes en una misma partida.
- Ver una lista de partidas disponibles.
- Buscar una partida con un nombre específico.

El usuario no podrá:

- Abandonar una partida.
- Agregar amigos.
- Guardar sus estadísticas.
- Interactuar con otros usuarios por fuera de la partida en la que está.
- Jugar contra bots.
- Crear una cuenta.
- Jugar varias partidas en simultáneo.

## Facultades del anfitrión de una partida
El anfitrión es aquel jugador que haya creado la sala.

El anfitrión podrá:

- Decidir cuándo comenzar la partida.

El anfitrión no podrá:

- Expulsar a jugadores de una partida.

## Requerimientos no funcionales

#### Usabilidad
\

- **Interfaz Intuitiva:** La interfaz de usuario debe ser fácil de usar y comprensible para los jugadores.
- **Instrucciones de juego:** Deben proporcionarse instrucciones claras para que los usuarios comprendan cómo utilizar el sistema.

#### Escalabilidad
\

- **Escalabilidad Horizontal:** El sistema debe ser capaz de escalar horizontalmente para admitir un mayor número de usuarios y partidas concurrentes.
- **Rendimiento:** El sistema debe mantener un rendimiento óptimo incluso cuando haya un gran número de usuarios en línea.

