# Modelo P2
## 1)
Usar formula
$$tamBloq = cantCB * tamCB + (cantCB +1) * tamPuntero$$

y despejar cantCB.

### Valores no definidos
Para valores no definidos como tamCB o tamPuntero, mientras se elijan valores razonables
no hay problema.

#### Ejemplo\
$$tamCB = 50$$
$$tamPuntero = 6 u 8$$

## 2)
$$altArbol = \left\lceil \log_{\lceil\frac{cantCB}{2}\rceil} cantValoresPosibles \right\rceil$$

# Parcial 2
## Calcular factor selectividad
$$fs(A, r) = \frac{valoresPosiblesSeleccion}{valoresTotales}$$

Siendo:

- A: predicado
- r: tabla

## Calcular tuplas resultado intermedio
$$cantTuplasTabla * fs$$

## Calcular cantidad de bloques resultado intermedio
$$\text{cantBloq} = \left\lceil \frac{\text{cantTup} \times \text{tamTup}}{\text{tamBloq}} \right\rceil$$

- cantTuplas no es la cantidad total, si no la del resultado intermedio
- IMPORTANTE: acordarse de añadir puntero a tamTup

