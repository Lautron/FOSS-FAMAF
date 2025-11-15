# procesamiento de lenguaje natural


## (PLN)

### es


#### subdisciplina


##### (IA)


### se ocupa

##### comprensión,


##### interpretación


##### generación


##### lenguaje humano



### objetivo

##### computadoras comprendan



##### texto


##### habla


##### manera similar ser humano



## Componentes Clave:


### Análisis Sintáctico:

##### estructura gramatical oraciones,



##### (sustantivos, verbos, etc.) y su relación.



### Análisis Semántico:

#### significado


##### palabras


##### frases



##### en contexto,



### Reconocimiento de Entidades Nombradas

#### (NER):



#### Identifica y clasifica entidades


##### nombres de personas,


##### lugares


##### fechas.



### Generación de Lenguaje Natural

#### (NLG):



#### generar texto


##### coherente


##### relevante


##### a partir de


##### datos estructurados.



### Análisis de Sentimientos:

#### tono emocional del texto,



##### positivo,


##### negativo


##### neutral.



## Aplicaciones Comunes:


### Asistentes Virtuales:

##### Siri o Alexa,



### Traducción Automática:

##### Google Translate



### Chatbots:


### Análisis de Opiniones:

##### percepción cliente comentarios redes sociales.



## Comprensión del Lenguaje Natural (NLU)

### es

#### subcampo



#### inteligencia artificial


### centrado en

##### comprender


##### interpretar


##### lenguaje humano



### trata de entender


##### contexto,


##### intención


##### sentimiento



## generación de lenguaje natural (NLG)

### es

##### subcampo



##### inteligencia artificial


### se centra

##### creación automática


##### narraciones


##### a partir de


##### datos estructurados.



## Etapas de la comprensión del lenguaje natural


### Preprocesamiento:

#### Consiste en


##### limpiar


##### preparar


##### datos



#### tokenización



#### etiquetado del discurso


##### (identificación funciones gramaticales estructura gramatical de las frases).


#### análisis sintáctico



### Análisis semántico:

#### se centra


##### comprender



##### significado palabras en su contexto.



#### reconocimiento de entidades



#### extracción de relaciones


##### entre entidades



### Comprensión del contexto:


#### evaluar tema general reconocer significados específicos


##### pueden cambiar en función de



##### interacciones anteriores


##### texto circundante.



### Reconocimiento de intenciones:

#### Determina


##### intención



##### usuario



#### es crucial para


##### chatbots


##### asistentes virtuales,



#### Ejemplos


##### obtener información sobre un tema



##### resolver una duda


##### conversar por curiosidad


##### realizar una acción concreta



## Etapas de la generación del lenguaje natural


### Determinación de contenido:

#### se decide


##### qué información



##### incluirse



##### resultado tenga sentido



#### Ejemplo:


##### informe meteorológico,



##### incluir


##### temperatura,


##### humedad


##### previsiones.



### Estructuración de documentos:

#### organiza información



##### manera lógica.



#### Se estructura


##### en


##### párrafos


##### secciones.


#### Se deciden


##### títulos


##### viñetas



### Planificación de frases:

#### planifica cómo



##### expresar en frases contenido seleccionado.



#### Involucra


##### elegir estructuras gramaticales adecuadas.


#### contempla


##### uso de


##### pronombres


##### conjunciones



#### garantiza


##### oraciones generadas sean gramaticalmente



##### correctas


##### fluidas.



### Generación de expresiones de referencia:


##### crear expresiones hagan referencia


##### entidades


##### conceptos


##### mencionados en el texto.



### Realización:

#### Las frases planificadas


##### se transforman



##### texto real.



#### Se aplican reglas


##### sintácticas,


##### morfológicas


##### ortográficas.


#### Se garantiza


##### fluidez


##### coherencia


##### texto generado.


#### Esta etapa produce


##### texto final usuarios,



### Post procesamiento (opcional):

##### se produce refinamiento



##### adicional



#### Se comprueban


##### errores gramaticales


##### frases incómodas.


#### Se mejora


##### estilo


##### tono


##### en función preferencias usuario



## Etapas del preprocesamiento


### Limpieza de datos:

##### eliminan elementos innecesarios



#### Se eliminan


##### caracteres especiales



##### (p.ej. puntuaciones, símbolos y caracteres no alfabéticos).



#### Conversión a minúsculas:



#### Eliminación de


##### etiquetas HTML



### Tokenización:

##### divide texto unidades más pequeñas



### Eliminación de stop words:

#### elimina palabras



##### que no aportan significado relevante


##### “y”,


##### “el”,


##### “de”.


#### como



##### cantidad datos eficiencia


#### reduce mejora



##### procesamiento



### Stemming y lematización:


##### corta palabras a su raíz, eliminando


#### Stemming



##### sufijos


##### prefijos.



##### devuelve forma base


#### Lematización:



##### palabra


##### considerando


##### contexto gramatical.



### Análisis morfológico:

#### se centra


##### estructura interna



##### palabras, componentes


##### (raíces,


##### sufijos).


#### identificando



### Part of speech tagging:

#### Asigna


##### etiquetas gramaticales cada token



##### (sustantivo,


##### verbo,


##### adjetivo,


##### etc.)



##### comprensión función cada palabra oración.


#### Facilita



### Conversión a formato estructurado:

#### se transforma



##### a formato fácilmente analizado por algoritmos.



##### entidades nombradas.


#### extraer organizar la información


##### en formato estructurado


##### Tabla de BD,



##### JSON


##### XML.)



#### traducir las frases y palabras


##### a representaciones numéricas



## Etapas del Análisis Semántico


### Desambiguación de Palabras:

#### determinar


##### significado correcto



##### palabra dependiendo contexto.



#### Ejemplo:


##### "banco"


##### entidad financiera


##### banco para sentarse.



### Reconocimiento de Entidades Nombradas (NER):

#### identificar y clasificar



##### entidades clave dentro del texto,



### Análisis de Relaciones:

#### identificar


##### relaciones entre



##### entidades



### Análisis de Sentimientos:

#### Se utiliza para


##### determinar el tono emocional



### Comprensión Contextual:

#### analizar el contexto general



##### tema


##### interacciones previas.



### Construcción de Representaciones Semántica:

#### creación


##### modelos



##### representan significado del texto formato estructurado



## El contexto


### se refiere a

##### información



##### adicional que rodea


##### palabra,


##### frase


##### conversación


##### ayuda a interpretar significado



## Tipos de contexto en PLN


### Local:

#### entorno inmediato


##### palabra


##### frase



##### dentro de una oración.



#### Incluye


##### palabras que


##### preceden


##### siguen


##### unidad de texto



##### información que se extiende más allá de


### Global:


##### una sola


##### oración


##### párrafo.



#### Incluye


##### historial interacciones anteriores en diálogo


##### o


##### tema general



##### conversación.



### Conversacional:

#### dinámica del diálogo



#### incluyendo


##### turnos de habla


##### respuestas anteriores.



### Situacional:

#### Incluye


##### factores externos pueden influir



##### interpretación


##### como el


##### entorno físico,


##### estado emocional


##### contexto cultural.



### Histórico:

#### conocimiento acumulado


##### a lo largo del



##### tiempo sobre


##### un tema


##### preferencias del usuario.



#### Cultural: factores


##### sociales


##### culturales



##### influyen en cómo se interpreta el lenguaje.



## Comprensión del contexto Etapas de Comprensión del contexto


### Análisis Sintáctico:


### Desambiguación de Palabras:

#### identificación


##### significado



##### correcto palabras



### Análisis de Relaciones:


### Análisis Pragmático:

##### contexto situacional,



##### intención del hablante


##### implicaciones sociales.



### Resolución de Correferencia:

#### identificar



### Comprensión Contextual:

#### analizar el contexto



### Análisis de Sentimientos:

#### tono emocional



### Adaptación al Contexto Cultural:

#### variaciones


##### culturales


##### lingüísticas