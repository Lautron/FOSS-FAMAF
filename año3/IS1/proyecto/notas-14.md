# Metodologia
Santi martes, Lean jueves
Trabajamos con scrum y sprints de 3 semanas

## Primer demo
3 octubre

## Scrum
planning: se asignan tareas y se compremeten a hacer cosas
daily
demo
retro

## Roles
Se van sorteando

### PO
Son los profes

Se comunica con PO equipo

#### Funciones
Clarifica cuestiones requerimientos

### SM
Se encarga de que las ceremonias se lleven bien
Preside reuniones
Se encarga situaciones humanas

# Pendientes Martes
- Planning
- Todo cargado Jira
- Asignar tareas
- Repos creados
- Agregar profes repos y jira

## Planning
- Contar quien es PO y SM
- Historias con crit aceptacion

### Poker planning
Se ve la historia y se vota, anonimamente
Usamos fibonacci, se asigna puntaje

Puntaje no son horas, es complejidad
Se usa para comparar

Primer estimacion va a ser mala

Luego se asignan subtareas

# Escribir tareas Jira
## Criterio de aceptacion
Que puntos considero para que la tarea sea considerada como hecha

Define lo que es un error o no en la demo.

Mientras mas concreto mejor

### Ejemplo
Para crear partida no se puede iniciar la partida si la cantidad de usuarios es invalida.

## Definition of DONE
Cuando una tarjeta está lista

- Cumple criterios aceptacion
- Tiene todos los tests
- 60% test coverage
- Documentacion


## Historias usuario
Se encaran a nivel usuario, no a nivel programacion.

Pueden tener su parte back y su parte front.

# Branches

## Master
Tiene versiones taggeadas
Ultima version testeada, probada y funcional

## Dev
Ultima version funcional
Se está desarrollando actualmente
No se puede subir codigo basura
Pueden haber casos borde que no funcionan.
Tiene que estar funcionando siempre

## Features
Crear branch que sale de develop y ponerle ID jira y una descripcion corta.
Ahí se hacen los commit.
Acá se commitea lo que quieran, pero mejor si compila.

## Pull request
Permite code review
Se hace entre feature branch y develop.
Asignamos dos personas para que revisen codigo.
Minimo dos approval.
Al mirar PR pensar que tenes que mantener ese codigo.

### Rebase
Hago rebase con develop y soluciono conflictos

## Estilos
### Python
- Black, 79 columnas
- Naming convention: snake case
- Docstrings

# IA
Ayuda, pero no te hace el trabajo
Hay que entender el codigo
Cada uno es reponsable por el codigo que hace

# Web sockets
Para el chat
No es requisito

# Evaluacion
Se evalua cuan buenos son aplicando el proceso de ingenieria de software
Hacer ultimo momento todo, sin proceso, tiene un 2
buen proceso => buen producto


