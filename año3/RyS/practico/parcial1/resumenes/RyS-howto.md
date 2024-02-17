# Tips generales
## Introduccion
- Hay dos capas que tienen sistema de recuperacion de paquetes
    - Capa de transporte
        - Recupera errores dados por congestion (los bufferes se sobrecargan)
    - Capa de enlace
        - Recupera errores dados por el canal

- Si menciona alguna de las siguientes se habla de capa de enlace:
    - Errores
    - Colisiones

- Si menciona alguna de las siguientes se habla de capa de transporte:
    - Capacidad

- La capa de transporte no interviene en los routers intermedios

## Aplicacion
- UDP manda datos a la maxima velocidad disponible porque no le importa si el receptor recibe los datos o no

- En cambio en TCP se terminan equilibrando las entradas con las salidas de un determinado router

## Ejs capa de transporte

1. Plantear formula del Usage del sender donde L es el tamaño del segmento, R la tasa de transmision 
(L/R) / (RTT + (L/R) )
2. Plantear inecuacion con formula y eficiencia esperada
3. Despejar R

## Algoritmos TCP
### Tahoe
1. Slow start
2. Congestion avoidance
3. Fast retransmit (3 acks)

### Reno
1. Fast recovery: no se retransmite de inmediato al recibir varios ACKS, se entra en modo fast recovery y se siguen enviando paquetes. Si se recibe otro ACK se asume que se perdieron mas paquetes y se baja la tasa de transmision
2. Congestion Avoidance: aumentar cantidad de paquetes por RTT hasta detectar congestion
3. Additive increase multiplicative decrease

# http
## Problemas que ataca
1. Manejar sistema de archivos
2. Enviar info de la pagina
3. Uso eficiente de la capa de transporte 
4. Codificar parametros de un formulario

# TCP
## Tahoe
Setea umbral en timeout/2
Va aumentando multiplicativamente hasta timeout/2 y despues aditivamente
