
.equ SCREEN_WIDTH, 		640
.equ SCREEN_HEIGH, 		480
.equ BITS_PER_PIXEL,  	32
.equ RETARDO, 0xFFFFF // Retardo utilizado para que el movimiento de estrellas sea más lento (Modificar en caso de ser necesario)
.equ COLOR_FONDO, 0x33
.data
UBIC_ESTRELLASX1: .dword 472,519,411,627,286,315,170,21,69,600,159,108,350,218,48,440 // Posiciones iniciales en X de las estrellas blancas
UBIC_ESTRELLASY1: .dword 222,550,303,75,237,100,189,53,391,303,600,13,517,420,586,634 // Posiciones iniciales en Y de las estrellas blancas
TAM_ESTRELLAS1: .dword 4,4,3,3,3,3,4,3,4,3,4,4,4,4,3,4
UBIC_ESTRELLASX2: .dword 493,277,607,85,200,139,320,65,635,375,23,484,566,369,169,247 // Posiciones iniciales en X de las estrellas grises
UBIC_PLANETASX: .dword 348,227,108,558,482,43,625,535 // Posiciones iniciales en X de las estrellas grises
UBIC_PLANETASY: .dword 408,75,230,175,279,59,378,264 // Posiciones iniciales en Y de las estrellas grises
TAM_PLANETAS: .dword 9,12,9,11,8,10,12,11,8,11,8,10,9,9,12,9
COLOR_PLANETAS: .dword 0xD51313, 0x883EF3, 0xF38B3E, 0x00AF64, 0xFFFF00, 0xA98307, 0x79553D, 0x1E2460
UBIC_ESTRELLASY2: .dword 422,227,19,323,449,131,180,144,348,63,45,41,233,308,360,53 // Posiciones iniciales en Y de las estrellas grises
TAM_ESTRELLAS2: .dword 2,2,2,1,3,3,1,1,2,3,2,1,3,2,1,2
UBIC_LUZ_X:	.dword 114, 507, 309, 159, 460, 206, 413, 258, 361
UBIC_LUZ_Y: .dword 286, 286, 336, 310, 310, 323, 323, 333, 333

BASE_PIXELES: .dword 0,0,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,2,1,1,2,1,2,1,2,2,2,2,3,2,3,3,3,4,3,4,3,4,5,4,5,5,6,6,7,7,7,8,9,10,13,15,19 // Secuencia de números útilizada para graficar el semicirculo correspondiente a la base de la nave
CUPULA_PIXELES_ARRIBA: .dword 0,0,0,0,1,0,0,1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,2,1,2,2,2,2,2,2,2,3,3,3,3,3,4,4,4,5,6,6,7,11,13,17
CUPULA_PIXELES_ABAJO: .dword 0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,4,4,4,5,5,6,6,7,7,9,11,13,17
LUZ_PIXELES: .dword 0,1,0,1,0,1,1,2,2,3
MARCIANITO_PIXELES: .dword -1,7,13,87,-1,6,0,75,12,13,-1,12,0,100,-1,7,0,26,49,25,-1,6,0,26,-1,6,0,50,-1,6,0,62,-1,6,0,100,-1,6,0,75,12,13,-1,12,0,75,-1,6,0,26,12,12,12,12,-1,7,0,26,36,25,-1,7,0,38,24,38,-1

.text

.globl main
main:
	// X0 contiene la direccion base del framebuffer
 	mov x20, x0	// Guardar dirección base del framebuffer en x20
	mov x21, SCREEN_HEIGH // Guardar alto de la pantalla (cant pixeles) en x21
	mov x22, SCREEN_WIDTH // Guardar largo de la pantalla (cant pixeles) en x22
	mov x23, COLOR_FONDO // Guardar el color del fondo en x23

	bl pintar_fondo 	// Establecer el color del fondo al indicado

 	bl base_nave // Imprimir la base de la nave
	bl cupula_nave // Imprimir cupula de la nave


	bl luces_nave
	bl marcianito

	// Ahora inicia un loop que está constantemente corriendo las estrellas hacia un costado
	nuevo_frame:

	cbnz x15, pintar_estrellas_blancas // Si el indice de cuando toca hacer mover las estrellas grises no es 0, salteo el pintar las estrellas grises
	pintar_estrellas_grises:
	movz x0, #0x7D7D
	movk x0, #0x007B, lsl 16 // Establezco el color en el que va a pintar las estrellas
	ldr x4, =UBIC_ESTRELLASX2 // Establezco que coordenadas en X va a utilizar para pintar las estrellas
	ldr x5, =UBIC_ESTRELLASY2 // Establezco que coordenadas en Y va a utilizar para pintar las estrellas
	ldr x6, =TAM_ESTRELLAS2
	bl pintar_estrellas // Pinto las estrellas
	mov x15, #5 // Escribo el indice de cuantos frame faltan para poder pintar de vuelta estrellas_grises


	pintar_estrellas_blancas:
	cbnz x17, saltoo
	mov x0, #0xFFFFFF // Establezco el color en el que va a pintar las estrellas
	ldr x4, =UBIC_ESTRELLASX1 // Establezco que coordenadas en X va a utilizar para pintar las estrellas
	ldr x5, =UBIC_ESTRELLASY1 // Establezco que coordenadas en Y va a utilizar para pintar las estrellas
	ldr x6, =TAM_ESTRELLAS1
	bl pintar_estrellas // Pinto las estrellas
	mov x17, #2

// Pintar planetas/mover el planeta en cuestión
	saltoo:
	ldr x4, =UBIC_PLANETASX // Establezco que coordenadas en X va a utilizar para pintar las estrellas
	ldr x5, =UBIC_PLANETASY // Establezco que coordenadas en Y va a utilizar para pintar las estrellas
	ldr x6, =TAM_PLANETAS
	ldr x26, =COLOR_PLANETAS
	bl pintar_planetas
    // Escribo el indice de cuantos frame faltan para poder pintar/mover de vuelta el planeta

	ldr x4, =UBIC_LUZ_X // Establezco que coordenadas en X va a utilizar para pintar las estrellas
	ldr x5, =UBIC_LUZ_Y // Establezco que coordenadas en Y va a utilizar para pintar las estrellas
	bl luces_nave // Pinto las estrellas


	bl arreglar_bug_visual // Arreglo un bug gráfico en uno de los bordes


	// Bucle de retardo
	mov x9, RETARDO // Guardo en x9 el valor del retardo
	pausa:
	sub x9, x9, #1 
	cbnz x9, pausa

	sub x15, x15, #1 // Resto un frame al indice para hacer movimiento de estrellas grises
	sub x17, x17, #1

	b nuevo_frame // Vuelvo a comenzar el ciclo del frame

	b fin

// ===== FIN DEL MAIN =====




	// PINTAR FONDO
	// -------------------------------
pintar_fondo:
	add x9, x20, xzr // Copio en x9 la dirección base del framebuffer
	movz x11, #0xB000 
	movk x11, #0x0004, lsl 16 // Establezco x11 como la cantidad de pixeles a pintar


	pintar_pixel_de_fondo: // inicio el loop
	stur w23, [x9] // Pinto el pixel
	add x9, x9, #4 // Guardo en x9 la próxima dirección a pintar
	sub x11, x11, #1 // Resto uno a la cantidad de pixeles que debo pintar
	cbnz x11, pintar_pixel_de_fondo // Reviso si todavía tengo que pintar pixeles para decidir si seguir pintando o no
	
	br lr // Salida de la función



	// PINTAR LINEA HORIZONTAL
	// -------------------------------
	// Argumentos:
	// 	X0 - color que se utilizará para pintar
	// 	X1 - posición vertical (eje x) del pixel inicial. Posiciones validas [0-479]
	// 	X2 - posición horizontal (eje y) del pixel inicial. Posiciones validas [0-639]
	// 	X3 - cantidad de pixeles que se van a pintar. Mínimo 1
pintar_linea_horizontal:
	sub sp, sp, #32 // PUSH
	stur x9, [sp, #24] //PUSH
	stur lr, [sp, #16] // PUSH
	stur x3, [sp, #8] // PUSH
	stur x1, [sp] // PUSH

	// Calculo el indice de la primera dirección donde debo pintar
	madd x9, x2, x22, x1 // x + (y * 640)
	add x9, x20, x9, lsl 2 // Dirección de inicio + 4 * [x + (y * 640)]

	pintar_pixel_de_linea_horizontal: // inicio el loop
	stur w0, [x9] // Pinto el pixel
	add x9, x9, #4 // Guardo en x9 la próxima dirección a pintar
	sub x3, x3, #1 // Resto uno a la cantidad de pixeles que debo pintar
	cbnz x3, pintar_pixel_de_linea_horizontal // Reviso si todavía tengo que pintar pixeles para decidir si seguir pintando o no


	ldur x1, [sp] // POP
	ldur x3, [sp, #8] // POP
	ldur lr, [sp, #16] // POP
	ldur x9, [sp, #24]
	add sp,sp, #32 // POP
	br lr // Salida de la función

	// PINTAR LINEA HORIZONTAL ESPECIAL
	// -------------------------------
	// Argumentos:
	// 	X0 - color que se utilizará para pintar
	// 	X1 - posición vertical (eje x) del pixel inicial. Posiciones validas [0-479]
	// 	X2 - posición horizontal (eje y) del pixel inicial. Posiciones validas [0-639]
	// 	X3 - cantidad de pixeles que se van a pintar. Mínimo 1
	// 	X6 - color de las puntas
pintar_linea_horizontal_especial:
	sub sp, sp, #32 // PUSH
	stur x9, [sp, #24] //PUSH
	stur lr, [sp, #16] // PUSH
	stur x3, [sp, #8] // PUSH
	stur x13, [sp] // PUSH

	// Calculo el indice de la primera dirección donde debo pintar
	madd x9, x2, x22, x1 // x + (y * 640)
	add x9, x20, x9, lsl 2 // Dirección de inicio + 4 * [x + (y * 640)]

	add x13, x13, #4
	lsl x13, x13, #2
	sub x9, x9, x13
	lsr x13, x13, #1
	add x3, x3, x13

	pintar_pixel_linea_horizontal_especial: // inicio el loop
	stur w0, [x9] // Pinto el pixel
	add x9, x9, #4 // Guardo en x9 la próxima dirección a pintar
	sub x3, x3, #1 // Resto uno a la cantidad de pixeles que debo pintar
	cbnz x3, pintar_pixel_linea_horizontal_especial // Reviso si todavía tengo que pintar pixeles para decidir si seguir pintando o no


	ldur x13, [sp] // POP
	ldur x3, [sp, #8] // POP
	ldur lr, [sp, #16] // POP
	ldur x9, [sp, #24]
	add sp,sp, #32 // POP
	br lr // Salida de la función




	// PINTAR LINEA DEPENDIENDO DEL COLOR DEL PIXEL
	// -------------------------------
	// Explicacion:
	//	- Pinta una linea, y si el color del pixel sobre el que va a pintar es de color X5,
	//	  pinta dicho pixel de color X4, en los demas casos pinta el pixel de color X0
	// Argumentos:
	// 	X0 - color que se utilizará para pintar
	// 	X1 - posición vertical (eje x) del pixel inicial. Posiciones validas [0-479]
	// 	X2 - posición horizontal (eje y) del pixel inicial. Posiciones validas [0-639]
	// 	X3 - cantidad de pixeles que se van a pintar. Mínimo 1
	//	X4 - Color secundario que se utiliza si el pixel es de color X5
	//	X5 - Color de pixel a chequear
pintar_linea_dependiendo_del_color_del_pixel:
	sub sp, sp, #32 // PUSH
	stur x9, [sp, #24] //PUSH
	stur lr, [sp, #16] // PUSH
	stur x3, [sp, #8] // PUSH
	stur x1, [sp] // PUSH

	// Calculo el indice de la primera dirección donde debo pintar
	madd x9, x2, x22, x1 // x + (y * 640)
	add x9, x20, x9, lsl 2 // Dirección de inicio + 4 * [x + (y * 640)]

	pintar_pixel_condicionalmente: // inicio el loop
	    ldur w14, [x9] // Cargo a w14 con el color del pixel
	    cmp w5, w14
	    B.EQ pintar_pixel_de_color_secundario
	    B pintar_pixel_de_color_primario

	    pintar_pixel_de_color_secundario:
	    stur w4, [x9] // Pinto el pixel
	    B calcular_siguiente_direccion_de_memoria_de_pixel_condicional

	    pintar_pixel_de_color_primario:
	    stur w0, [x9] // Pinto el pixel

	    calcular_siguiente_direccion_de_memoria_de_pixel_condicional:
	    add x9, x9, #4 // Guardo en x9 la próxima dirección a pintar
	    sub x3, x3, #1 // Resto uno a la cantidad de pixeles que debo pintar
	cbnz x3, pintar_pixel_condicionalmente // Reviso si todavía tengo que pintar pixeles para decidir si seguir pintando o no

	ldur x1, [sp] // POP
	ldur x3, [sp, #8] // POP
	ldur lr, [sp, #16] // POP
	ldur x9, [sp, #24]
	add sp,sp, #32 // POP
	br lr // Salida de la función

	// ESTRELLA
	// -------------------------------
	// Explicación:
	// 	Pinta todos los pixeles de un cuadrado 4x4 que cumplan la condición de que son igual a un color
	// Argumentos:
	// 	X0 - color que se utilizará para pintar
	// 	X1 - posición vertical (eje x) del pixel inicial. Posiciones validas [0-479]
	// 	X2 - posición horizontal (eje y) del pixel inicial. Posiciones validas [0-639]
	// 	X3 - tamaño de la estrella
	// 	x7 - color necesario para sobrepintar ese pixel
estrella:
	// Calculo el indice de la primera dirección donde debo pintar
	madd x9, x2, x22, x1 // x + (y * 640)
	add x9, x20, x9, lsl 2 // Dirección de inicio + 4 * [x + (y * 640)]

	// Guardo en x10 cuanto debo saltar para llegar a la primera posición de la próxima linea
	sub x10, x22, x3
	lsl x10, x10, #2

	mov x13, x3 // Guardo en x13 el indice de cuantas lineas debo pintar
	pintar_lineas_estrella:
	  add x9, x9, x10 // Le sumo a x9 lo necesario para que ahora apunte al primer pixel de la próxima linea
	  mov x12, x3 // Guardo en x12 el indice de cuantos pixeles debo pintar en esta linea
	  
	  pintar_pixel_de_estrella: // Inicio el loop
	  ldur w11, [x9] // Guardo en x11 el color del pixel que quiero pintar
	  cmp w11, w7 // Reviso si es del color que tengo permitido pintar
	  b.ne else // Si no son iguales, salto la próxima instrucción
	  stur w0, [x9] // Pintar pixel requerido
	  else:
	  sub x12, x12, #1 // Resto un pixel a los pixeles pintados en esta linea
	  add x9, x9, #4
	  cbnz x12, pintar_pixel_de_estrella // Reviso si todavía tengo que pintar pixeles para decidir si seguir pintando o no
	  
	  sub x13, x13, #1 // Resto uno a la cantidad de lineas que debo pintar
	cbnz x13, pintar_lineas_estrella // Reviso si todavía tengo que pintar lineas para decidir si seguir pintando o no

	br lr // Salida de la función	

	// PINTAR ESTRELLAS
	// -------------------------------
	// Argumentos:
	// 	X0 - color que se utilizará para pintar las estrellas
	// 	X1 - posición vertical (eje x) del pixel inicial. Posiciones validas [0-479]
	// 	X2 - posición horizontal (eje y) del pixel inicial. Posiciones validas [0-639]
	//	X4 - dirección de las coordenadas en X de las estrellas
	// 	X5 - dirección de las coordenadas en Y de las estrellas
pintar_estrellas:
	sub sp, sp, #32 // PUSH
	stur lr, [sp, #24] // PUSH
	stur x3, [sp, #16] // PUSH
	stur x2, [sp, #8] // PUSH	
	stur x1, [sp] // PUSH
	
	mov x14, #16 // Contador de cantidad de estrellas que debo pintar
	faltan_pintar_estrellas: // Inicio del loop
	  ldur x1, [x4, #0] // Asigno en x1 la dirección en X de la estrella que debo pintar
	  ldur x2, [x5, #0] // Asigno en x2 la dirección en Y de la estrella que debo pintar
	  ldur x3, [x6, #0] // Asigno en x3 el tamaño de la estrella que debo pintar

	  // Despinto la estrella anterior
	  add x7, xzr, x0
	  mov x0, #0x33
	  bl estrella

	  // Pinto la nueva estrella
	  add x0, xzr, x7
	  mov x7, #0x33
	  sub x1, x1, #1 // Resto uno a x1 para desplazar hacia la izquierda la posición de la estrella
	  bl estrella
	  
	  // Si x1 es 4, le asigno a x1 (X) 480 para que vuelva a dar la vuelta y le asigno a x2 (Y) un número pseudoaleatorio entre 0 y 639 para que las estrellas no sean repetitivas
	  cmp x1, #4 
	  b.ne pintar_estrellas_x1_es_diferente_de_2 // Reviso si x1 es diferente de 2 para saltearme todas las siguientes lineas

	    add x1, xzr, x22 //guardo en x1 el 480
	    mov x16, #73 // Guardo el número 73 en x16 (elegido arbitrariamente por ser número de Sheldon)
	    madd x16, x2, x16, x7 // Calculo random para obtener algo pseudoaleatorio
	    udiv x2, x16, x21 // Divido x16 por 640 (División entera) y lo guardo en x2
	    mul x2, x2, x21 // Multiplico la división anterior por 640  
	    sub x2, x16, x2 // Guardo en x2 el modulo 640 del número pseudo aleatorio (Número - [Número div 640] * 640)
	    stur x2, [x5] // Guardo el valor de x2 en el elemento correspondiente del arreglo

	  pintar_estrellas_x1_es_diferente_de_2:
	  stur x1, [x4] // Guardo el valor de x1 en el elemento correspondiente del arreglo

	  add x4, x4, #8 // Paso al siguiente elemento del arreglo de coordenadas en X
	  add x5, x5, #8 // Paso al siguiente elemento del arreglo de coordenadas en Y
	  add x6, x6, #8 // Paso al siguiente elemento del arreglo de coordenadas en Y	
	  sub x14, x14, #1 // Resto uno a la cantidad de estrellas que me faltan pintar
	cbnz x14, faltan_pintar_estrellas // Reviso si me faltan pintar estrellas todavia


	ldur x1, [sp] // POP
	ldur x2, [sp, #8] // POP
	ldur x3, [sp, #16] // POP
	ldur lr, [sp, #24] // POP
	add sp,sp, #32 // POP
	br lr // Salida de la función		


	// ARREGLAR BUG
	// -------------------------------
	// Explicación:
	// 	Hace una columna del color del fondo a la derecha para evitar uno errores graficos
arreglar_bug_visual:
	sub sp, sp, #32 // PUSH
	stur lr, [sp, #24] // PUSH
	stur x3, [sp, #16] // PUSH
	stur x2, [sp, #8] // PUSH	
	stur x1, [sp] // PUSH


	mov x0, COLOR_FONDO
	mov x1, -6
	mov x2, #0 // Dirección inicial del bug en X
	mov x4, SCREEN_HEIGH
	mov x3, #12
	arreglar_bug_visual_loop:
	bl pintar_linea_horizontal
	sub x4, x4, #1
	add x2, x2, #1
	cbnz x4, arreglar_bug_visual_loop

	ldur x1, [sp] // POP
	ldur x2, [sp, #8] // POP
	ldur x3, [sp, #16] // POP
	ldur lr, [sp, #24] // POP
	add sp,sp, #32 // POP
	br lr // Salida de la función	

	// BASE NAVE
	// -------------------------------
	// Explicación:
	// 	Dibuja la base de la nave espacial (semicirculo)
base_nave:
	sub sp, sp, #32 // PUSH
	stur lr, [sp, #24] // PUSH
	stur x3, [sp, #16] // PUSH
	stur x2, [sp, #8] // PUSH	
	stur x1, [sp] // PUSH	


	mov x1, #80 // Asigno a x1 las coordenadas en X de donde comienzo a dibujar la nave
	mov x2, #300 // Asigno a x2 las coordenadas en Y de donde comienzo a dibujar la nave
	mov x3, #480 // Asigno a x3 la cantidad de pixeles que va a tener la parte más amplia de la nave
	mov x10, #60 // Asigno a x10 la mitad de la cantidad de pixeles que va a tener de altura la nave
	ldr x11, =BASE_PIXELES // Guardo en x11 la dirección de los pasos para dibujar la circunferencia
	mov x13, #0

	base_nave_pintar_parte_de_abajo: // Inicio el bucle para pintar la parte de abajo de la base de la nave
	    ldur x12, [x11, #0] // Guardo en x12 el elemento del arreglo que corresponde
	    movz x0, 0xD6EA
	    movk x0, 0x00D2, lsl 16
	    bl pintar_linea_horizontal_especial // Llamada a la función para pintar la linea
	    mov x13, x12
	    movz x0, 0xA9C2
	    movk x0, 0x00A4, lsl 16
	    bl pintar_linea_horizontal // Llamada a la función para pintar la linea	
	    add x1, x1, x12 // Agrego a la coordenada en X donde dibujo la linea la cantidad que diga segun los pasos para dibujar la circunferencia
	    sub x2, x2, #1  // Bajo una coordenada en Y
	    lsl x12, x12, #1 // Calculo auxiliar para la próxima linea
	    sub x3, x3, x12 // Resto a x3 2 veces lo sumado a x1, para que me quede centrado (el punto más a la izquierda de la linea se corre hacia la derecha "z" pixeles y yo achico la cantidad de pixeles de la linea "2*z")

	    sub x10, x10, #1 // Resto 1 a la cantidad de lineas que tengo que hacer
	    add x11, x11 , #8 // Paso al siguiente elemento del arreglo de pasos para dibujar la circunferencia
	cbnz x10, base_nave_pintar_parte_de_abajo // Reviso si ya hice todas las lineas
	

	mov x1, #80 // Asigno a x1 las coordenadas en X de donde comienzo a dibujar la nave
	mov x2, #300 // Asigno a x2 las coordenadas en Y de donde comienzo a dibujar la nave
	mov x3, #480 // Asigno a x3 la cantidad de pixeles que va a tener la parte más amplia de la nave
	mov x10, #60 // Asigno a x10 la mitad de la cantidad de pixeles que va a tener de altura la nave
	ldr x11, =BASE_PIXELES // Guardo en x11 la dirección de los pasos para dibujar la circunferencia
	mov x13, #0

	base_nave_pintar_parte_de_arriba: // Inicio el bucle para pintar la parte de arriba de la base de la nave
	    ldur x12, [x11, #0] // Guardo en x12 el elemento del arreglo que corresponde
	    movz x0, 0xD6EA
	    movk x0, 0x00D2, lsl 16
	    bl pintar_linea_horizontal_especial // Llamada a la función para pintar la linea
	    add x13, x13, x12
	    mov x0, #2
	    udiv x13, x13, x0
	    movz x0, 0xA9C2
	    movk x0, 0x00A4, lsl 16
	    bl pintar_linea_horizontal // Llamada a la función para pintar la linea	
	    add x1, x1, x12 // Agrego a la coordenada en X donde dibujo la linea la cantidad que diga segun los pasos para dibujar la circunferencia
	    add x2, x2, #1 // Subo una coordenada en Y
	    lsl x12, x12, #1 // Calculo auxiliar para la próxima linea
	    sub x3, x3, x12 // Resto a x3 2 veces lo sumado a x1, para que me quede centrado (el punto más a la izquierda de la linea se corre hacia la derecha "z" pixeles y yo achico la cantidad de pixeles de la linea "2*z")

	    sub x10, x10, #1 // Resto 1 a la cantidad de lineas que tengo que hacer
	    add x11, x11 , #8 // Paso al siguiente elemento del arreglo de pasos para dibujar la circunferencia
	cbnz x10, base_nave_pintar_parte_de_arriba // Reviso si ya hice todas las lineas
	
	movz x0, 0xD6EA
	movk x0, 0x00D2, lsl 16
	add x1, x1, #4
	sub x3, x3, #8
	bl pintar_linea_horizontal_especial


	ldur x1, [sp] // POP
	ldur x2, [sp, #8] // POP
	ldur x3, [sp, #16] // POP
	ldur lr, [sp, #24] // POP
	add sp,sp, #32 // POP
	br lr // Salida de la función

	// CUPULA NAVE
	// -------------------------------
	// Explicación:
	// 	Dibuja la cupula de la nave espacial (semicirculo)
cupula_nave:
	sub sp, sp, #32 // PUSH
	stur lr, [sp, #24] // PUSH
	stur x3, [sp, #16] // PUSH
	stur x2, [sp, #8] // PUSH	
	stur x1, [sp] // PUSH	

	movz x0, 0xEAEA
	movk x0, 0x00D6, lsl 16

	movz x4, 0xBCC0
	movk x4, 0x0089, lsl 16 // guardar color 0x868db2 en X4 para luego llamar a pintar_linea_dependiendo_del_color_del_pixel

	movz x5, 0xA9C2
	movk x5, 0x00A4, lsl 16 // guardar color 0xA4A9C2 en X5 para luego llamar a pintar_linea_dependiendo_del_color_del_pixel

	mov x1, #160 // Asigno a x1 las coordenadas en X de donde comienzo a dibujar la nave
	mov x2, #256 // Asigno a x2 las coordenadas en Y de donde comienzo a dibujar la nave
	mov x3, #320 // Asigno a x3 la cantidad de pixeles que va a tener la parte más amplia de la nave
	mov x10, #80 // Asigno a x10 la mitad de la cantidad de pixeles que va a tener de altura la nave
	ldr x11, =CUPULA_PIXELES_ARRIBA // Guardo en x11 la dirección de los pasos para dibujar la circunferencia
	mov x13, #0

	cupula_nave_pintar_parte_de_abajo: // Inicio el bucle para pintar la parte de abajo de la base de la cupula
	    ldur x12, [x11, #0] // Guardo en x12 el elemento del arreglo que corresponde
	    bl pintar_linea_dependiendo_del_color_del_pixel // Llamada a la función para pintar la linea
	    add x1, x1, x12 // Agrego a la coordenada en X donde dibujo la linea la cantidad que diga segun los pasos para dibujar la circunferencia
	    sub x2, x2, #1 // Subo una coordenada en Y
	    lsl x12, x12, #1 // Calculo auxiliar para la próxima linea
	    sub x3, x3, x12 // Resto a x3 2 veces lo sumado a x1, para que me quede centrado (el punto más a la izquierda de la linea se corre hacia la derecha "z" pixeles y yo achico la cantidad de pixeles de la linea "2*z")

	    sub x10, x10, #1 // Resto 1 a la cantidad de lineas que tengo que hacer
	    add x11, x11 , #8 // Paso al siguiente elemento del arreglo de pasos para dibujar la circunferencia
	cbnz x10, cupula_nave_pintar_parte_de_abajo // Reviso si ya hice todas las lineas
	

	mov x1, #160 // Asigno a x1 las coordenadas en X de donde comienzo a dibujar la nave
	mov x2, #257 // Asigno a x2 las coordenadas en Y de donde comienzo a dibujar la nave
	mov x3, #320 // Asigno a x3 la cantidad de pixeles que va a tener la parte más amplia de la nave
	mov x10, #40 // Asigno a x10 la mitad de la cantidad de pixeles que va a tener de altura la nave
	ldr x11, =CUPULA_PIXELES_ABAJO // Guardo en x11 la dirección de los pasos para dibujar la circunferencia

	cupula_nave_pintar_parte_de_arriba: // Inicio el bucle para pintar la parte de arriba de la base de la cupula
	    ldur x12, [x11, #0] // Guardo en x12 el elemento del arreglo que corresponde
	    bl pintar_linea_dependiendo_del_color_del_pixel // Llamada a la función para pintar la linea
	    add x1, x1, x12 // Agrego a la coordenada en X donde dibujo la linea la cantidad que diga segun los pasos para dibujar la circunferencia
	    add x2, x2, #1  // Bajo una coordenada en Y
	    lsl x12, x12, #1 // Calculo auxiliar para la próxima linea
	    sub x3, x3, x12 // Resto a x3 2 veces lo sumado a x1, para que me quede centrado (el punto más a la izquierda de la linea se corre hacia la derecha "z" pixeles y yo achico la cantidad de pixeles de la linea "2*z")

	    sub x10, x10, #1 // Resto 1 a la cantidad de lineas que tengo que hacer
	    add x11, x11 , #8 // Paso al siguiente elemento del arreglo de pasos para dibujar la circunferencia
	cbnz x10, cupula_nave_pintar_parte_de_arriba // Reviso si ya hice todas las lineas


	ldur x1, [sp] // POP
	ldur x2, [sp, #8] // POP
	ldur x3, [sp, #16] // POP
	ldur lr, [sp, #24] // POP
	add sp,sp, #32 // POP
	br lr // Salida de la función

	// LUCES NAVE
	// -------------------------------
	// Explicación:
	// 	Dibuja las luces de la nave basandose en los arreglos UBIC_LUZ_X y UBIC_LUZ_Y
luces_nave:
	sub sp, sp, #32 // PUSH
	stur lr, [sp, #24] // PUSH
	stur x5, [sp, #16] // PUSH
	stur x4, [sp, #8] // PUSH	
	stur x0, [sp] // PUSH

	ldr x4, =UBIC_LUZ_X
	ldr x5, =UBIC_LUZ_Y
	movz x0, 0xFF00
	movk x0, 0x00FF, lsl 16
	mov x14, #9
	pintar_luces_nave:
	bl pintar_luz_nave //Imprime las luces de la nave
	add x4, x4, #8
	add x5, x5, #8
	sub x14, x14, #1
	cbnz x14, pintar_luces_nave

	ldur x0, [sp] // POP
	ldur x4, [sp, #8] // POP
	ldur x5, [sp, #16] // POP
	ldur lr, [sp, #24] // POP
	add sp,sp, #32 // POP
	br lr

	// PINTA LUZ NAVE
	// -------------------------------
	// Explicación:
	// 	Dibuja un circulo que representa la luz de la nave.
	// Argumentos:
	//	X4 - dirección de las coordenadas en X de las luces
	// 	X5 - dirección de las coordenadas en Y de las luces
pintar_luz_nave:
	sub sp, sp, #32 // PUSH
	stur lr, [sp, #24] // PUSH
	stur x3, [sp, #16] // PUSH
	stur x2, [sp, #8] // PUSH	
	stur x1, [sp] // PUSH

	ldur x1, [x4, #0]
	ldur x2, [x5, #0]
	mov x3, #23 // Asigno a x3 la cantidad de pixeles que va a tener la parte más amplia del foco de la nave
	mov x10, #10 // Asigno a x10 la mitad de la cantidad de pixeles que va a tener de altura del foco de la nave
	ldr x11,=LUZ_PIXELES // Guardo en x11 la dirección de los pasos para dibujar las luces
	mov x13, #0

	pintar_parte_de_arriba_de_luz: // Inicio el bucle para pintar la parte de abajo de la base de la luz
	    ldur x12, [x11, #0] // Guardo en x12 el elemento del arreglo que corresponde
	    movz x0, 0x3B42
	    movk x0, 0x003A, lsl 16
	    bl pintar_linea_horizontal_especial // Llamada a la función para pintar la linea
	    add x13, x13, x12
	    mov x0, #2
	    udiv x13, x13, x0
	    movz x0, 0xFF00
	    movk x0, 0x00FF, lsl 16
	    bl pintar_linea_horizontal // Llamada a la función para pintar la linea
	    add x1, x1, x12 // Agrego a la coordenada en X donde dibujo la linea la cantidad que diga segun los pasos para dibujar la circunferencia
	    sub x2, x2, #1 // Subo una coordenada en Y
	    lsl x12, x12, #1 // Calculo auxiliar para la próxima linea
	    sub x3, x3, x12 // Resto a x3 2 veces lo sumado a x1, para que me quede centrado (el punto más a la izquierda de la linea se corre hacia la derecha "z" pixeles y yo achico la cantidad de pixeles de la linea "2*z")

	    sub x10, x10, #1 // Resto 1 a la cantidad de lineas que tengo que hacer
	    add x11, x11 , #8 // Paso al siguiente elemento del arreglo de pasos para dibujar la circunferencia
	cbnz x10, pintar_parte_de_arriba_de_luz // Reviso si ya hice todas las lineas

	movz x0, 0x3B42
	movk x0, 0x003A, lsl 16
	bl pintar_linea_horizontal_especial
	sub x2, x2, #1 // Subo una coordenada en Y
	add x1, x1, #2
	sub x3, x3, #4
	bl pintar_linea_horizontal_especial
	sub x2, x2, #1 // Subo una coordenada en Y
	add x1, x1, #2
	sub x3, x3, #4
	bl pintar_linea_horizontal_especial


	ldur x1, [x4, #0]
	ldur x2, [x5, #0]
	mov x3, #23 // Asigno a x3 la cantidad de pixeles que va a tener la parte más amplia del foco de la nave
	mov x10, #10 // Asigno a x10 la mitad de la cantidad de pixeles que va a tener de altura el foco de la nave
	ldr x11, =LUZ_PIXELES// Guardo en x11 la dirección de los pasos para dibujar la circunferencia
	mov x13, #0

	pintar_parte_de_abajo_de_luz: // Inicio el bucle para pintar la parte de abajo de la luz
	  ldur x12, [x11, #0] // Guardo en x12 el elemento del arreglo que corresponde
	  movz x0, 0x3B42
	  movk x0, 0x003A, lsl 16
	  bl pintar_linea_horizontal_especial // Llamada a la función para pintar la linea
	  add x13, x13, x12
	  mov x0, #2
	  udiv x13, x13, x0
	  movz x0, 0xFF00
	  movk x0, 0x00FF, lsl 16
	  bl pintar_linea_horizontal // Llamada a la función para pintar la linea
	  add x1, x1, x12 // Agrego a la coordenada en X donde dibujo la linea la cantidad que diga segun los pasos para dibujar la circunferencia
	  add x2, x2, #1 // Subo una coordenada en Y
	  lsl x12, x12, #1 // Calculo auxiliar para la próxima linea
	  sub x3, x3, x12 // Resto a x3 2 veces lo sumado a x1, para que me quede centrado (el punto más a la izquierda de la linea se corre hacia la derecha "z" pixeles y yo achico la cantidad de pixeles de la linea "2*z")

	  sub x10, x10, #1 // Resto 1 a la cantidad de lineas que tengo que hacer
	  add x11, x11 , #8 // Paso al siguiente elemento del arreglo de pasos para dibujar la circunferencia
	cbnz x10, pintar_parte_de_abajo_de_luz // Reviso si ya hice todas las lineas

	movz x0, 0x3B42
	movk x0, 0x003A, lsl 16
	bl pintar_linea_horizontal_especial
	add x2, x2, #1 // Subo una coordenada en Y
	add x1, x1, #2
	sub x3, x3, #4
	bl pintar_linea_horizontal_especial
	add x2, x2, #1 // Subo una coordenada en Y
	add x1, x1, #2
	sub x3, x3, #4
	bl pintar_linea_horizontal_especial


	ldur x1, [sp] // POP
	ldur x2, [sp, #8] // POP
	ldur x3, [sp, #16] // POP
	ldur lr, [sp, #24] // POP
	add sp,sp, #32 // POP
	br lr

	// DIBUJAR FORMA COMPLEJA
	// -------------------------------
	// Explicacion:
	// 	- Va dibujando una forma linea a linea y usa un arreglo como parametro para decidir que pixels pintar y cuales no
	//	- Cada seccion del arreglo está delimitada por '-1', el primer numero luego del '-1' es la cantidad de lineas a hacer
	//	- Despues de la cantidad de lineas los elementos en posicion impar (empezando a contar desde 1) son pixels a saltear
	//	- Los elementos en posicion par son pixels a dibujar
	// Argumentos:
	// 	X0 - color que se utilizará para pintar las estrellas
	// 	X1 - posición vertical (eje x) del pixel inicial. Posiciones validas [0-479]
	// 	X2 - posición horizontal (eje y) del pixel inicial. Posiciones validas [0-639]
	//	X4 - dirección del array
	// 	X5 - tamaño maximo en Y

dibujar_forma_compleja:
  sub sp, sp, 	#40 // PUSH
  stur lr, [sp, #32 ] // PUSH
  stur x6, [sp, #24 ] // PUSH
  stur x5, [sp, #16  ] // PUSH	
  stur x4, [sp, #8 ] // PUSH
  stur x2, [sp] // PUSH

  dibujar_forma_compleja_downto_x5:			  // do
    add x4, x4, #8		 	  //   x4 = x4+8 -> mueve x4 a la posicion que contiene la cantidad de lineas
    ldur x10, [x4]			  //   x10 = *x4  -> cargo en x10 cantidad de lineas a dibujar
    add x6, x4, #8		          //   x6 = x4+8 -> mover puntero a inicio del subarray
    dibujar_forma_compleja_dowto_x10:		          //   do
      bl linea_from_array	          //     linea_from_array x0 x1 x2 x6
      sub x5, x5, #1		          //     x5 = x5 - 1 -> resto a la cantidad total de lineas a dibujar
      cbz x5, dibujar_forma_compleja_end		          // 	 if x5 == 0 then EXIT
      sub x10, x10, #1		          //     x10 = x10 - 1 -> resto 1 a la cantidad de lineas a dibujar
      add x2, x2, #1		          // 	 x2 = x2 + 1 -> aumento posicion en y
    cbnz x10, dibujar_forma_compleja_dowto_x10	  	  //   while x10 != 0

    encontrar_sig_delimitador:	  	  //   do
      add x4, x4, #8		  	  //      x4 = x4+8
      ldur x10, [x4]		  	  // 	  x10 = *x4

      cmp x10, #-1
    B.NE encontrar_sig_delimitador  	  // while x10 != -1

  cbnz x5, dibujar_forma_compleja_downto_x5		  // while x5 != 0

  dibujar_forma_compleja_end:
  ldur x2, [sp] // POP
  ldur x4, [sp, #8 ] // POP
  ldur x5, [sp, #16  ] // POP	
  ldur x6, [sp, #24 ] // POP
  ldur lr, [sp, #32 ] // POP
  add sp, sp, 	#40 // POP
  br lr

	// LINEA FROM ARRAY
	// -------------------------------
	// Argumentos:
	// 	X0 - color que se utilizará para pintar las estrellas
	// 	X1 - posición vertical (eje x) del pixel inicial. Posiciones validas [0-479]
	// 	X2 - posición horizontal (eje y) del pixel inicial. Posiciones validas [0-639]
	//	X6 - dirección del array
linea_from_array:
  sub sp, sp, 	#16 // PUSH
  stur lr, [sp, #8 ] // PUSH
  stur x6, [sp, #0 ] // PUSH

  mov x12, #0 				    		// pintar = false
  madd x11, x2, x22, x1 	 			// x11 = x + (y * 640)
  add x11, x20, x11, lsl 2 				// x11 = Dirección de inicio + 4 * [x + (y * 640)]
  ldur x9, [x6]						// x9 = *x6
  linea_from_array_encontrar_sig_delimitador:   	// do 
    cbnz x12, linea_from_array_pintar_pixels
    B linea_from_array_no_pintar

    linea_from_array_pintar_pixels:	    		//   if pintar then
      linea_from_array_pintar_pixel:          		// 	   do
      stur w0, [x11]                          		// 	     Pinto el pixel
      add x11, x11, #4                        		// 	     Guardo en x11 la próxima dirección a pintar
      sub x9, x9, #1                          		// 	     Resto uno a la cantidad de pixeles que debo pintar
      cbnz x9, linea_from_array_pintar_pixel   		// 	   while x9 != 0
      mov x12, #0 			      		//     pintar=false
      B linea_from_array_calcular_siguiente_direccion

    linea_from_array_no_pintar:	    	    		//   else 
      add x11, x11, x9, lsl #2	            		//     x11 = x11 + (4 * (*x6)) // mover direccion de x11 (*x6) pixels hacia adelante
      mov x12, #1	     		    		//     pintar=true

  linea_from_array_calcular_siguiente_direccion:
  add x6, x6, #8	     		    		//   x6 = x6 + 8
  ldur x9, [x6]						//   x9 = *x6

  cmp x9, #-1
  B.NE linea_from_array_encontrar_sig_delimitador 	// while *x6 != -1


  ldur x6, [sp, #0 ] // POP
  ldur lr, [sp, #8 ] // POP
  add sp, sp, 	#16 // POP
  br lr

marcianito:
  sub sp, sp, #8 // PUSH
  stur lr, [sp, #0] // PUSH

  // Calculo argumentos de pintar_forma_compleja
  movz x0, #0x3220, lsl 0
  movk x0, #0x01, lsl 16
  mov x1, #270
  mov x2, #193
  ldr x4, =MARCIANITO_PIXELES
  mov x5, #94
  bl dibujar_forma_compleja

  ldur lr, [sp, #0] // POP
  add sp, sp, #8 // POP
  br lr

pintar_planetas:
	sub sp, sp, #32 // PUSH
	stur lr, [sp, #24] // PUSH
	stur x3, [sp, #16] // PUSH
	stur x2, [sp, #8] // PUSH	
	stur x1, [sp] // PUSH

	mov x14, #8 // Contador de cantidad de estrellas que debo pintar
	pintar_planetas_loop: // Inicio del loop
	    ldur x1, [x4, #0] // Asigno en x1 la dirección en X de la estrella que debo pintar
	    ldur x2, [x5, #0] // Asigno en x2 la dirección en Y de la estrella que debo pintar
	    ldur x3, [x6, #0] // Asigno en x3 el tamaño de la estrella que debo pintar
	    ldur x25, [x26, #0]
	    mov x0, x25
	    // Despinto la estrella anterior
	    add x7, xzr, x0
	    mov x0, #0x33
	    bl estrella

	    // Pinto la nueva estrella
	    add x0, xzr, x7
	    mov x7, #0x33
	    sub x1, x1, #1 // Resto uno a x1 para desplazar hacia la izquierda la posición de la estrella
	    bl estrella

	    // Si x1 es 4, le asigno a x1 (X) 480 para que vuelva a dar la vuelta y le asigno a x2 (Y) un número pseudoaleatorio entre 0 y 639 para que las estrellas no sean repetitivas
	    cmp x1, #6 
	    b.ne pintar_planeta_x1_es_diferente_de_2 // Reviso si x1 es diferente de 2 para saltearme todas las siguientes lineas

	    add x1, xzr, x22 //guardo en x1 el 480
	    mov x16, #73 // Guardo el número 73 en x16 (elegido arbitrariamente por ser número de Sheldon)
	    madd x16, x2, x16, x7 // Calculo random para obtener algo pseudoaleatorio
	    udiv x2, x16, x21 // Divido x16 por 640 (División entera) y lo guardo en x2
	    mul x2, x2, x21 // Multiplico la división anterior por 640  
	    sub x2, x16, x2 // Guardo en x2 el modulo 640 del número pseudo aleatorio (Número - [Número div 640] * 640)
	    stur x2, [x5] // Guardo el valor de x2 en el elemento correspondiente del arreglo

	    mov x2, #0xFFFFFF
	    mov x16, #73 // Guardo el número 73 en x16 (elegido arbitrariamente por ser número de Sheldon)
	    madd x16, x25, x16, x7 // Calculo random para obtener algo pseudoaleatorio
	    udiv x25, x16, x2 // Divido x16 por #0xFFFFFF (División entera) y lo guardo en x25
	    mul x25, x2, x25 // Multiplico la división anterior por #0xFFFFFF 
	    sub x25, x16, x25 // Guardo en x25 el modulo #0xFFFFFF del número pseudo aleatorio (Número - [Número div #0xFFFFFF] * #0xFFFFFF)
	    stur x25, [x26] // Guardo el valor de x2 en el elemento correspondiente del arreglo



	    pintar_planeta_x1_es_diferente_de_2:
	    stur x1, [x4] // Guardo el valor de x1 en el elemento correspondiente del arreglo

	    add x4, x4, #8 // Paso al siguiente elemento del arreglo de coordenadas en X
	    add x5, x5, #8 // Paso al siguiente elemento del arreglo de coordenadas en Y
	    add x6, x6, #8 // Paso al siguiente elemento del arreglo de coordenadas en Y	
	    add x26, x26, #8
	    sub x14, x14, #1 // Resto uno a la cantidad de estrellas que me faltan pintar
	cbnz x14, pintar_planetas_loop // Reviso si me faltan pintar estrellas todavia


	ldur x1, [sp] // POP
	ldur x2, [sp, #8] // POP
	ldur x3, [sp, #16] // POP
	ldur lr, [sp, #24] // POP
	add sp,sp, #32 // POP
	br lr // Salida de la función

fin:	
	b fin
