# Modelos de proceso de desarrollo


## modelo de proceso

### especiﬁca
- proceso general,
- usualmente como
- conjunto
etapas.


### provee
- estructura genérica procesos
- que puede seguirse
- para alcanzar objetivos.

### Es decir:


#### Modelo del proceso:

- especiﬁcación genérica
- proceso.


#### Especiﬁcación del proceso:

- plan de lo que debe ejecutarse.


#### Proceso:

- lo que realmente se ejecuta.


## cascada


### fases:

- 1. Análisis de requerimientos

- 2. Diseño de alto nivel

- 3. Diseño detallado

- 4. Codiﬁcación

- 5. Testing

- 6. Instalación


### Una fase

#### comienza

- sólo cuando
- anterior ﬁnaliza


#### divide

- proyecto;

#### cada una

- se encarga de
- distintas incumbencias.


### orden lineal
- tiene
- consecuencias importantes:


### Todas las fases

- deben producir
- salida deﬁnida.


### Ventajas:


#### Conceptualmente simple:

- divide problema
- fases

- que pueden
- realizarse independiente.


#### Fácil de administrar

- en un contexto contractual:
- fronteras
- bien deﬁnidas
- entre fases


### Uso:

- Ampliamente usado.


#### proyectos donde

- requerimientos
- bien comprendidos
- decisiones
- tecnología tempranas.

- desarrolladores
- familiarizados con
- problema
- proceso a seguir.


## Prototipo


### se construye
- prototipo
- para comprender
- requerimientos.


### Permite
- cliente de
- mejor feedback


### etapa de análisis
- reemplazada por
- "mini-cascada"


#### “mini-fases”
- no son muy
- formales
- minuciosas


### Desarrollo


#### solo incluye

- características claves
- que necesitan
- comprensión.


#### El cliente

- “juega” con prototipo
- provee feedback
- mejora comprensión
- requerimientos.


#### Luego del feedback

- prototipo
- se modiﬁca
- se repite
- proceso
- hasta que
- costos
- tiempo
- superen
- beneﬁcios proceso.


#### Teniendo en cuenta el feedback,

- se modiﬁcan
- requerimientos iniciales
- para producir
- especiﬁcación ﬁnal


### debe
- descartarse.


### costo de prototipado

#### debe

- mantenerse bajo:


#### Construir sólo

- aspectos a aclarar.


#### calidad

- no importa,
- sólo importa
- desarrollar rápidamente.


#### Omitir

- manejo excepciones,
- recuperación,
- estándares.


#### Reducir

- testing.


#### Costos

- debe ser
- pequeño % del total.


### Ventajas:


#### Mayor

- estabilidad requerimientos.


#### requerimientos

- se congelan más tarde.


#### experiencia

- en construcción
- prototipo
- ayuda desarrollo


### Desventajas:

- Potencial impacto
- costo
- tiempo.


### Aplicación:


#### requerimientos

- difíciles de determinar
- conﬁanza en ellos
- baja

## Desarrollo iterativo


### Aborda
- problema “todo o nada”
- de cascada.


### Combina
- beneﬁcios
- prototipado
- cascada.


### Desarrolla y entrega
- SW
- incrementalmente.


### Cada incremento
- es completo
- en sí mismo.


### Provee
- marco para
- facilitar testing

- testing incremento
- más fácil
- testing sistema completo.


### feedback
- iteración
- puede usarse
- iteraciones futuras.


### Primer paso:

#### implementación simple

- subconjunto del problema completo


#### crear lista de control del proyecto (LCP)

- contiene
- (en orden)
- tareas

- a realizar
- para implementación ﬁnal.


#### Cada paso consiste en

- eliminar
- la siguiente tarea
- de la lista
- haciendo
- diseño,

- implementación
- análisis
- sistema parcial,
- y actualizar la LCP.


#### El proceso

- se repite
- hasta vaciar
- lista.

### LCP:
- guía
- pasos iteración
- lleva
- tareas a realizar.

#### Cada entrada

- es una tarea
- a realizarse
- en un paso
- iteración

- debe ser
- suﬁcientemente simple
- para comprenderla completamente.


### Aplicación:


#### desarrollo de productos:

- desarrolladores
- proveen especiﬁcación,
- usuarios
- proveen feedback
- cada release,

#### Desarrollo “a gusto del comprador” (customized):

- empresas requieren
- respuestas rápidas.
- No arriesgar
- “todo o nada”.


### Beneﬁcios:


#### pagos


#### entregas

- incrementales;


#### feedback para

- mejorar lo desarrollado.


### Inconvenientes:


#### arquitectura
- pueden
- no ser óptimos;


#### diseño

- pueden
- no ser óptimos;


#### revisión

- trabajo hecho
- puede incrementarse;


#### costo total

- puede
- ser mayor.


### Aplicación:


#### tiempo de respuesta

- importante;


#### no se puede

- tomar riesgo
- proyectos largos;


#### no se conocen

- todos los requerimientos.


## timeboxing


### Timeboxing:
- ﬁja duración
- iteraciones
- luego determina
- especiﬁcación.

#### Divide la iteración

- partes iguales

#### usa pipelining

- para ejecutar
- iteraciones
- en paralelo.

- (INSERTAR IMAGEN)


#### El desarrollo

- se realiza
- iterativamente
- en time boxes
- de igual duración.


#### Cada time box

- divide
- etapas ﬁjas.


#### Cada etapa

- realiza tarea
- bien deﬁnida
- que puede
- desarrollarse independientemente.

- tienen
- igual duración.
- (aprox)

- Tiene equipo dedicado


#### equipo de una etapa ﬁnaliza,

- se lo pasa
- al equipo
- siguiente etapa.


#### un alto compromiso

- con el cronograma:
- este no es negociable.


### Ventajas:


#### todas

- las del iterativo;


#### menor

- tiempo de entrega;


#### ejecución

- del proyecto distribuida.


### Desventajas:


#### grandes

- equipos de trabajo;


#### administración

- proyecto
- más compleja;


#### se necesita

- mucha sincronización.


### Aplicación:


#### tiempos de entrega cortos

- muy importantes.
