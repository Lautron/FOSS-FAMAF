## El proceso de testing


### Testing incremental


#### Testing incremental:

- agregar partes no testeadas
- incrementalmente

- a la parte ya testeada.


#### esencial para


- ayuda a encontrar más defectos

- ayuda a la identiﬁcación
- eliminación.


#### El testing de grandes sistemas

- siempre de manera incremental.


### Niveles de testing


#### se utilizan distintos niveles de testing


- para revelar los distintos tipos de defectos.


#### Testing de unidad:

- distintos módulos del programa

- se testean separadamente contra el diseño,

- Se enfoca en
- defectos inyectados durante la codiﬁcación.

- objetivo
- testear
- lógica interna de los módulos.

- programador
- realiza el test


#### Testing de integración:

- Se enfoca en
- interacción
- módulos

- énfasis en
- testing de las interfaces


#### Testing del sistema:

- El sistema
- completo es testeado.
- veriﬁcar si
- software implementa
- requerimientos.
- etapa ﬁnal del testing
- antes de que el software sea entregado.
- realizado por
- personal independiente.

- fase de testing que
- consume mas tiempo.


#### Testing de aceptación:


- veriﬁcar
- software satisfaga
- necesidades
- usuario.

- se realiza por
- usuario/cliente

- después de que el testing de aceptación resulte satisfactorio,

- software es puesto en ejecución (“deployed”).

- El plan del test de aceptación
- se basa en
- criterio del test de aceptación

- SRS.


#### Otras formas

- Testing de desempeño:

- Requiere de herramientas
- medir el desempeño.

- Testing de estrés

- sistema se sobre carga al máximo;

- Testing de regresión:

- funcionalidades previas continúen funcionando


### Especiﬁcación de los casos de test


#### realizar separadamente


- cada unidad.


#### Por cada unidad de test

- se determinan
- test
- de acuerdo
- plan

- (enfoques, características, etc.).


#### cada caso de test se especiﬁca:


- entradas a utilizar,

- condiciones que éste testeará,

- resultado esperado.


#### efectividad y costo del testing

- dependen
- conjunto de

- test seleccionado.


#### determinar si un conjunto de casos de test es bueno?


- No existe una manera


#### Para cada testeo,

- se desarrolla
- especiﬁcación de
- test

- que se revisa y se ejecuta.


#### preparación de la especiﬁcación


- tarea exigente y que demanda tiempo:

- Se pueden utilizar
- criterios para casos de test.

- casos especiales y escenarios.


### Ejecución de los casos de test y análisis


#### puede requerir de

- “drivers”
- “stubs”.
- módulos extras para preparar el entorno

- acorde a las condiciones establecidas en la especiﬁcación


#### Algunos test

- pueden automatizarse,
- otros necesitan ser manuales:


### Registro de defectos y seguimiento


#### Los defectos encontrados

- se registran en

- sistema seguidor de defectos (“tracking”)
- permite rastrearlos hasta que se “cierren”.


#### ciclo de vida;


- Alguien lo encuentra
- y lo registra

- Se asigna la tarea de corrección;

- veriﬁca que el defecto fue

- corregido


#### severidad del defecto


- Crítico:
- puede demorar el proceso;
- afecta a muchos usuarios.

- Mayor:
- mucho impacto
- posee soluciones provisorias;

- requiere de mucho esfuerzo
- tiene menor impacto en el cronograma.

- Menor:
- se maniﬁesta raramente
- tiene poco impacto.

- Cosmético:
- pequeños errores
- sin impacto en el funcionamiento

