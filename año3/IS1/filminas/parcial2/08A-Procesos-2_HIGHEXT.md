# Procesos de desarrollo


## Un proceso adecuado
- ayuda a lograr los objetivos del proyecto con alta C&P


## Procesos y modelos de proceso


### proyecto exitoso
- satisface
- expectativas en
- costo,
- tiempo,
- calidad.


### modelo de proceso
- especiﬁca un proceso general,
- usualmente con fases

- con
- restricciones
- condiciones
- para
- ejecución de dichas fases.


#### No se traduce directamente al proceso:

- proceso real

- adaptación del modelo del proceso.


#### es el proceso

- el que guía un proyecto,
- inﬂuye

- resultado esperado


## Componentes del proceso de software


### procesos fundamentales:


#### Desarrollo:

- se enfoca
- actividades para el desarrollo
- garantizar

- calidad necesarias


#### Administración del proyecto:

- se enfoca
- planeamiento

- control del proceso de desarrollo
- con el ﬁn
- cumplir los objetivos.

- proceso de desarrollo
- es el “corazón” del proceso de software;

- los otros procesos giran alrededor de él.


#### se ejecuta por gente diferente:


- Desarrolladores
- ejecutan el proceso de desarrollo.

- Administradores del proyecto
- ejecutan el proceso de administración.


## Especiﬁcación del proceso


### El proceso
- generalmente es
- conjunto de fases.


### Cada fase
- realiza
- tarea bien deﬁnida
- produce una salida.


#### salida intermedia

- se llama
- producto de trabajo.


### producto de trabajo
- entidad
- formal
- tangible,

- capaz de ser veriﬁcada.


### Cada fase
- puede ser llevada a cabo
- usando distintas metodologías.


## Enfoque “ETVX”


### Cada fase
- sigue el enfoque ETVX
- (Entry
- Task
- Veriﬁcation
- Exit):


### Criterio de entrada:
- condiciones
- para iniciar la fase.


### Tarea:
- Lo que debe realizar esa fase.


### Veriﬁcación:
- inspecciones/controles/revisiones/veriﬁcaciones

- realizarse a la salida
- (i.e. al producto de trabajo).


### Criterio de salida:
- Cuando
- considerarse

- fase fue realizada exitosamente.


### cada fase
- produce información para la administración del proceso.

## Características deseadas


### alta C&P


#### sw testeable:

- testing es la tarea más cara


#### sw mantenible:

- mantenimiento puede ser más caro que

- desarrollo;


#### eliminar defectos

- en etapas tempranas.


#### predecible y repetible.



#### soportar cambios


#### producir sw que se adapte a cambios.



### Control de calidad:
- actividad
- propósito principal
- identiﬁcar
- eliminar
- errores.


### Los procesos deben conseguir

- repetir el desempeño cuando se utilizan en distintos proyectos.

- resultado de utilizar un proceso
- poder predecirse.


#### Proyectos

- similares
- desarrollados
- mismo procesos
- tendrán costos similares.


#### Sin predicción:

- no se puede estimar la C&P.


#### Con predicción:

- desempeño pasado
- estimar

- desempeño futuro.


### El SW cambia por muchas razones.


#### cambio de requerimientos


- son esperables


#### Todo proceso de desarrollo

- debe dejar lugar para cambios


# Proceso de desarrollo de software


## Objetivo:

### construir sistemas de sw

#### dentro de

- costos
- tiempo
- planeado,

- cronograma,

#### que posea

- calidad apropiada,
- satisfaciendo al cliente,
- alta C&P.


## el proceso de desarrollo a seguir

- se especiﬁca durante el planeamiento.


## Es un
- conjunto de fases.


### Cada fase
- secuencia de pasos
- deﬁnen
- metodología de la fase.


## ¿Por qué utilizar fases?

- Dividir y conquistar.

- Cada fase ataca
- distintas partes del problema.

- Ayuda a validar continuamente el proyecto.


## Análisis de requerimientos y especiﬁcación


### Objetivo:
- comprender precisamente el problema.

- Forma la base
- acuerdo
- cliente
- desarrollador.

- Especiﬁca el “qué”
- no el “cómo”.


### Salida
- Especiﬁcación
- requerimientos del software
- (SRS).


## Diseño


### Diseño arquitectónico:
- establece
- componentes
- conectores

- que conforman el sistema.


### Diseño de alto nivel:
- establece
- módulos
- estructuras de datos

- necesarios para implementar la arquitectura.


### Diseño detallado:
- establece
- lógica de los módulos.


### Salida:
- Documentos correspondientes.


## Codiﬁcación


### Objetivo:
- Implementar el diseño con código
- simple
- fácil de comprender


### afecta
- testing
- mantenimiento.


### Salida:
- el código.


## Testing


### Objetivo:
- Identiﬁcar la mayoría de los defectos.


### tarea muy cara:
- debe
- planearse
- ejecutarse
- apropiadamente.


### Salida:
- Plan de test
- resultados,
- código ﬁnal testeado
- (y conﬁable).


# Otros procesos del software

## 1. Proceso para la administración del proyecto


### proceso de desarrollo
- divide el desarrollo en
- fases
- actividades.


#### ejecutarlas eﬁcientemente,

- se deben
- asignar recursos,
- administrarlos,

- observar el progreso,
- tomar acciones correctivas,
- etc.


### parte esencial

- de la ejecución del proyecto.


### Fases:

- Planeamiento

- Seguimiento y control

- Análisis de terminación


### Planeamiento:

#### se realiza

- antes de comenzar el proyecto.


#### Tareas claves:


- Estimación de costos y tiempos.
- Seleccionar el personal.
- Planear el seguimiento.
- Planear el control de calidad.


### Seguimiento y control:


#### Acompaña

- al proceso de desarrollo:


#### Tareas:


- observar parámetros claves como
- costo,
- tiempos,
- riesgo,

- factores que los afectan.

- Tomar acción correctiva
- si es necesario.


#### métricas

- proveen
- información
- necesaria
- para

- seguimiento.


### Análisis de terminación:


#### Se realiza

- al ﬁnalizar el proceso de desarrollo.


#### propósito

- analizar
- desempeño del proceso
- identiﬁcar

- lecciones aprendidas.


#### En procesos iterativos


- se realiza al ﬁnalizar cada iteración
- se usa para mejorar
- iteraciones siguientes.


## 2. El proceso de inspección


### Objetivo principal:
- detectar
- defectos
- productos de trabajo.


### reconocido como
- mejores prácticas de la industria.


### Mejora
- calidad
- productividad.


### defectos
- deben eliminarse

- en cada etapa.


### pueden realizarse sobre
- cualquier documento,


### Realizado por
- personal técnico
- para personal técnico:
- revisión/crítica (review)

- hecha por pares.


### Foco en
- encontrar problemas,
- no en resolverlos.


### La información recolectada
- es registrada
- utilizada para monitorear

- efectividad de la solución.


### Roles y responsabilidades:


#### Moderador:

- tiene la responsabilidad general.


#### Autor:

- quien realizó el producto de trabajo.


#### Revisor:

- identiﬁca los defectos.


#### Lector:

- lee línea a línea el producto de trabajo

- enfocar el progreso de la reunión.


#### Escriba:

- registra las observaciones indicadas.


### Planeamiento:

- Seleccionar el equipo de revisión.

- Identiﬁcar al moderador


#### Preparar el paquete para la distribución:


- producto de trabajo a revisar;
- especiﬁcaciones del producto de trabajo;
- lista de control con items relevantes;
- estándares.


### Preparación y repaso previo (overview):


#### Breve reunión (opcional):


- se entrega el paquete;
- se explica el propósito de la revisión;
- se da una breve intro señalando áreas de cuidado.


#### En esta etapa

- todos los miembros
- revisan individualmente

- producto de trabajo:


### Reunión de revisión grupal:


#### Propósito:

- deﬁnir la lista ﬁnal de defectos.


#### Criterio de entrada:

- cada miembro debe haber hecho

- revisión individual


#### La reunión:


- lector lee línea a línea el producto de trabajo
- cualquier observación que hubiere

- es efectuada.

- La decisión es registrada por el escriba.


#### A ﬁnal de la reunión:


- El escriba
- presenta la lista de defectos/observaciones.

- Si hay pocos defectos
- producto de trabajo se acepta;
- si no,

- se puede requerir otra revisión.

- El grupo
- no propone soluciones,


### El moderador


#### Asegura que

- foco permanece sobre
- identiﬁcación de defectos
- evitar

- se discutan soluciones.

- la reunión se ejecute
- ordenada
- amigablemente.


#### Utiliza el resumen

- para analizar la efectividad de la revisión.


### Corrección y seguimiento:


#### Los defectos

- son
- corregidos por el autor.


#### Una vez corregidos,

- autor obtiene
- visto bueno del moderador

- producto de trabajo
- nueva revisión.


## 3. Proceso de administración de conﬁguración


### Un proyecto de software produce

- programas,
- documentos,
- datos,
- manuales,
- etc.


#### Cualquiera de ellos

- puede cambiar fácilmente

- necesario saber el progreso


### administración de conﬁguración del software (SCM):

- controla sistemáticamente los cambios producidos.
- los cambios de requerimientos

- se manejan aparte.


### usualmente independiente
- del proceso de desarrollo:


### medida que los ítems se producen,
- se introducen en la SCM.


### SCM controla
- solo los productos del proceso de desarrollo.


### Durante el proceso
- ítems/archivos
- cambian
- generando distintas versiones.


### debe asegurar

- distintas versiones se combinen apropiadamente sin pérdidas.


### Funcionalidades necesarias:


#### Recolectar

- fuentes,
- documentos
- otra información
- del sistema actual.


#### Evitar

- cambios
- eliminaciones
- desautorizadas.


#### Deshacer

- cambios
- revertir a una versión especiﬁcada.


#### Hacer disponible

- última versión del programa.


### Mecanismos principales:

- Control de acceso.

- Control de versiones.

- Identiﬁcación de la conﬁguración.


#### Otros mecanismos

- convenciones de nombres,

- estructuras de directorios,
- etc.


### Ítems de conﬁguración:

#### El software comprende

- muchos ítems

- que son puestos bajo el control de la
- administración de la conﬁguración.


#### Cada ítem

- es una unidad de modiﬁcación
- se modiﬁcan intensamente:

- Los cambios a estos ítems
- se siguen rigurosamente.

- distintas versiones
- deben combinarse apropiadamente

- de manera periódica:

#### baseline:

- arreglo apropiado
- ítems de conﬁguración.

- establece
- puntos de referencia a lo largo del desarrollo


### Control de versión:

- Fundamental en la administración de conﬁguración.


#### Auxilia a

- preservar viejas versiones
- deshacer cambios.


### Control de acceso:


#### limitan el acceso a personal especíﬁco:

- procedimientos de
- check-in,

- check- out.


### El proceso:

#### Deﬁnir

- actividades que requieren control de cambio.

### Fases principales:


#### Planeamiento:

- identiﬁcar ítems;
- deﬁnir la estructura del repositorio;

- deﬁnir control de acceso,
- puntos de referencia,
- reconciliación,
- procedimientos;
- deﬁnir procedimiento de publicación.


#### Ejecución:

- Realizar los procedimientos
- según lo establecido

#### Auditoría:

- veriﬁcar que no se cometieron errores,


## 4. Proceso de Administración de Cambios de Requisitos


### Los requerimientos
- pueden cambiar
- cualquier momento
- durante el desarrollo.


### Los cambios

#### producen impactos

- productos de trabajo

- ítems de conﬁguración.


#### no controlados

- pueden impactar adversamente

- tanto en
- costo
- como en tiempo.


#### deben permitirse,

- pero
- de manera controlada.


### El proceso:

- Registrar los cambios.


#### Realizar análisis de impacto sobre

- productos de trabajo
- ítems.


#### Estimar

- impacto en
- esfuerzo
- cronograma.


#### Analizar

- impacto
- con
- personas involucradas.


#### Reprocesar

- productos de trabajo
- ítems.


### Los cambios

#### se inician

- a través de un requerimiento de cambio.


#### Existe un

- registro de requerimientos de cambio.


#### análisis de impacto

- identiﬁcar

- cambios necesarios en los distintos ítems
- naturaleza del cambio.


## 5. Proceso de Administración de Procesos


### Un proceso
- no es una entidad estática:
- debe cambiar para mejorar
- calidad

- productividad.


### enfoca en
- evaluación
- mejora
- del proceso.


### Distinto de
- administración de proyecto,

- el cual se enfoca en el proyecto.


### Para mejorar el proceso,


#### requiere que

- el proceso este bien documentado,
- sea apropiadamente ejecutado
- recolecta datos
- comprender el desempeño del proceso


### CMM

- 1ro es ad-hoc).

#### niveles

- Nivel 5 - Optimizado:

- Nivel 4 - Administrado:

- Nivel 3 - Deﬁnido:

- Nivel 2 - Repetible: