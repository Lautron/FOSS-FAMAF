
.equ SCREEN_WIDTH, 		640
.equ SCREEN_HEIGH, 		480
.equ BITS_PER_PIXEL,  	32


.globl main
main:
	// X0 contiene la direccion base del framebuffer
 	mov x20, x0	// Save framebuffer base address to x20	
	//---------------- CODE HERE ------------------------------------
	
	movz x10, 0xC7, lsl 16
	movk x10, 0x1585, lsl 00

	mov x2, SCREEN_HEIGH         // Y Size 
loop1:
	mov x1, SCREEN_WIDTH         // X Size
loop0:
	stur w10,[x0]	   // Set color of pixel N
	add x0,x0,4	   // Next pixel
	sub x1,x1,1	   // decrement X counter
	cbnz x1,loop0	   // If not end row jump
	sub x2,x2,1	   // Decrement Y counter
	cbnz x2,loop1	   // if not last row, jump

/* makeSquare:
    Parametros:
      x1: ancho del cuadrado
      x2: alto del cuadrado
      x3: posicion inicial X
      x4: posicion inicial Y
      x5: color del cuadrado
*/
	eor x1, x1, x1 // set x1 to 0
	add x1, x1, 100 // set width to 100

	eor x2, x2, x2 // set x2 to 0
	add x2, x2, 100 // set height to 100

	eor x3, x3, x3 // set x3 to 0
	add x3, x3, 250 // set X to 250

	eor x4, x4, x4 // set x2 to 0
	add x4, x4, 250 // set Y to 250

	movz x5, 0x2AFF, lsl 00  // set x5 to blue
makeSquare:
	mov x9, x2        // assign height to x9
	lsl x10, x3, 2 	   // x10 = XDist * 4
	mov x11, SCREEN_WIDTH // assign screen width to x11
	lsl x12, x11, 2    // x12 = SCREEN_WIDTH * 4
	add x0, x0, x12     // Move x0 position Y pixels down
newStartPos:
	add x0, x0, x9     // Move x0 to desired position
loop2:
	mov x10, x1        // assign width to x10
loop3:
	
	stur x5,[x0]	   // Set color of pixel N
	add x0,x0,4	   // Next pixel
	sub x1,x1,1	   // decrement X counter
	cbnz x1,loop0	   // If not end row jump
	sub x2,x2,1	   // Decrement Y counter
	cbnz x2,loop1	   // if not last row, jump

// move WIDTH pixels from START






	//---------------------------------------------------------------
	// Infinite Loop 

InfLoop: 
	b InfLoop
