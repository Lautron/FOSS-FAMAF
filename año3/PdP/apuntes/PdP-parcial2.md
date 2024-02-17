# BASIC CONCEPTS IN CONCURRENCY
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

## Definitions
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
### A sequence of actions
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
may be called a process, thread, or task.


### process
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
is often used to refer to an operating system process,
which generally runs in its own address space.

### Threads,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

#### in speciﬁc languages
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
like Concurrent ML and Java, may run under control of the language run-time system, sharing the same operating system address space.

#### Some authors
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
deﬁne thread to mean **“lightweight process,”** which means a process that does not run in a separate operating system address space.


## Execution Order
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

Concurrent programs may have many possible execution orders.

## nondeterminism.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

### A program is deterministic if,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
for each sequence of program inputs, there one sequence of program actions and resulting outputs.

### a program is nondeterministic if
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
there is more than one possible sequence of actions corresponding to a single input sequence.


### makes it difﬁcult
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
to design and debug programs.

It is difﬁcult
to think carefully about millions of possible execution orders


## mechanisms
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


### communication between processes,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

achieved by mechanisms such as buffered or synchronous communication channels, broadcast, or shared variables or objects,


### coordination between processes,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

which may explicitly or implicitly cause one process to wait for another process before continuing,


### atomicity,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

which affects both interaction between processes and the handling of error conditions.


## message-passing mechanisms:
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


### Buffering.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

If communication is buffered, then every data item that is sent remains availableuntil it is received.In

#### unbuffered communication
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
a data item sent before the receiver is ready to accept that it may be lost.


### Synchronicity.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

In synchronous communication, the sender cannot transmit a data item unless the receiver is ready to receive it.

#### With asynchronous communication,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\

the sending process may transmit a data item and continue executing even if the receiver is not ready to receive the data.


### Message Order.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

A communication mechanism may preserve transmission order or it may not.

#### If a mechanism preserves transmission order,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
then a sequence of messages will be received in the order that they are sent.


## An action is atomic
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

if every execution will either complete successfully or terminate in a state that is indistinguishable from the state in which the action was initiated.

### A nonatomic action
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
may involve intermediate states that are observable by other processes.
A nonatomic action may also halt in error before the entire action is complete, leaving some trace of its partial progress.

### any concurrent programming language
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
must provide some atomic actions, because, without some guarantee of atomicity, it is extremely difﬁcult to predict the behavior of any program.


## Mutual Exclusion
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

### for certain operations,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
it is important to restrict concurrency so that only one process proceeds at a time.

### critical section.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
A critical section is a section of a program that accesses shared resources.
Because a process in a critical section may disrupt other processes, it may be important to allow only one process into a critical section at a time.

### mechanisms.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


#### Mutual exclusion:
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
Only one process at a time may be in its critical section.


#### Progress:
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\

If no processes are in their critical section and some process wants to enter a critical section, it becomes possible for one waiting process to enter its critical section.


#### Bounded waiting:
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\

no waiting process should have to wait indeﬁnitely.

if one process halts in a critical section, other processes will eventually be able to enter the critical section.


### A general approach
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
The main idea is that each process executes some kind of
**wait**
action before
and executes some kind of signal action afterward.


### Using a loop to wait for some condition is called
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
busy waiting.


## Deadlock
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
occurs if a process can never continue because the state of another process.
processes are waiting for the lock held by the other process. In this situation, neither process can proceed and deadlock has occurred.


### technique that prevents deadlock
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
two-phase locking.


### two-phase locking,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
a process is viewed as a sequence of independent tasks.
For each task, the process must ﬁrst acquire all locks that are needed
to perform the task.
Before proceeding from one task to the next, a process must release all locks.


## Semaphores
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


### A standard semaphore
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

#### is represented
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\

by an integer variable, an integer maximum, and a queue of waiting processes.

#### Initially,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
the integer variable is set to the maximum.

#### The maximum
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
indicates the number of processes that may enter a critical section at the same time;
in many situations the maximum is one.

#### If a program contains several shared resources,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
the program may use a separate semaphore for each resource.


### When a process waits on a semaphore,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

the wait operation checks the integer value of the semaphore.

#### If the value is greater than 0,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
this indicates that a process may proceed.
The value is decremented before proceeding to limit the number of processes that are allowed to proceed.


#### If a wait is executed on a semaphore whose integer value is 0,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\

then the process is suspended and placed on a queue of waiting processes.

### Suspending a process
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
is an operating system operation that keeps the process from continuing until the process is resumed.


### When a process leaves a critical section,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
The signal operation checks the semaphore queue to see if any process is suspended.

#### If the queue is not empty,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
one of the suspended waiting processes is allowed to run.

#### If no process is waiting,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
then the integer value of the semaphore is incremented.


## Monitors
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


### Monitors,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
place the responsibility for synchronization on the operations that access data.
Monitors are similar to abstract data types, with all synchronization placed in the operations of the data type. This makes it easier to write correct client code.


### A monitor consists of
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

one or more procedures, an initialization sequence, and local data.

#### local data
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
are accessible only by the monitor procedures, which are responsible for all synchronization associated with concurrent access to the data.

### In traditional terminology,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
a process
**enters**
the monitor by invoking one of its procedures.


### In modern terminology,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
a monitor might be called a
**synchronized object.**


# THE ACTOR MODEL
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


## Each actor
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
is a form of reactive object, executing some computation in response to a message and sending out a reply when the computation is done.
Actors do not have any
**shared state,**
but use buffered asynchronous message passing for all communication.


## three basic actions that an actor may perform:
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

It may send communication to itself or other actors,

It may create actors,

It may specify a replacement behavior,

which is essentially another actor that takes the place of the actor that creates it for the purpose of responding to later communication.


## Actor computation
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
is reactive, which means that computation is performed only in response to communication.

### an actor program
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
creates some number of actors and sends them messages. All of these actors can react to messages concurrently, but there is no explicit concept of thread.


### An actor is dormant until
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
it receives communication.


### When an actor receives a message,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
the script of the actor may specify subsequent communication and a set of new actors to create.

### After executing its script,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
the actor returns to its dormant state.

### The replacement behavior
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
speciﬁes how the actor will behave when it receives another message.


### In any computation,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
each actor receives a linearly ordered sequence of messages.


### messages
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
are not guaranteed to arrive in the order in which they are sent.


## the mail system,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

routes and buffers messages between actors.

### Every message must be sent to
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
a mail address;
one actor may communicate with another if it knows its mail address.

### When an actor A speciﬁes a replacement behavior,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
the replacement behavior will be the script for a new actor that receives all messages addressed to the mail address of A.


## A message from one actor to another
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
is called a task.

### A task has three parts:
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

A unique tag, distinguishing it from other tasks in the system,

A target, which is the mail address of the intended receiver,

A communication, which is the data contained in the message.


## a behavior may be deﬁned as a function of parameters, which are called
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
acquaintances:


## actor-speciﬁc concept
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

### forwarder.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

A forwarder actor does nothing itself, except forward all tasks to another actor.


## General aspects of actors
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


### An actor changes state
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
only by becoming another actor after it completes processing input.


### The motivation for using asynchronous communication
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

is that it is easily implemented on a wide-area network.


## problems
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

message order, message delivery, and coordination between sequences of concurrent actions


# CONCURRENT ML
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


## Threads and Channels
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


### A CML process is called
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
a thread.

### When a CML program begins,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
it consists of a single thread.
This thread may create additional threads by using the **spawn** primitive:


### When spawn f is evaluated,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
the function call f() is executed as a separate thread.


### The return value of the function
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
is discarded, but the function may communicate with other threads by using channels.

### The thread that evaluates spawn f is called
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
the parent thread

### the thread running f() is called
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
the child thread.

### the parent–child relation
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
does not have any impact on thread execution
either thread may terminate without affecting the other.


### Another CML primitive,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


#### is forever.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
This function takes an initial value and a function that can be repeatedly applied to this value:


### channel.
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

For each CML type ‘a, there is a type ‘a chan of channels that communicate values of type ‘a.

#### operations on channels
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\

recv : ‘a chan → ‘a
→ send : (‘a chan * ‘a) → unit


### CML message passing
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

is synchronous, meaning that communication occurs only when both a sender and a receiver are ready to communicate.


### Channels are created by
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
the channel constructor,

channel : unit → ‘a chan

### Functions Using Threads and Channels
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
Because channels are “just another type” in CML, we can deﬁne functions that take channel arguments and return channel results.


## A guarded command,
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
has historically been written in the form

Condition  $\Rightarrow$  Command

consists of a predicate and an action.

### The intent
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
is that, if the Condition is true, then the Command may be executed.


## Events
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->


### we can decompose send into two parts:
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
the code that will cause a **send** to occur is the **send event,**
and doing the send is called **synchronizing on this event.**


### Selective Communication
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->

#### The select operator
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\
for selective communication can be deﬁned from a primitive function on events that chooses an event out of a list.

#### The function choose
<!-- from Caps 14.1 14.2 14.3_Concepts in Programming Languages_HIGHEXT.md -->
\

choose : ‘a event list → ‘a event

takes a list of events and returns one event from the list.
choose must return an event that can be synchronized on if there is one in the list.

# Paradigma de scripting
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->


## En principio, cualquier lenguaje
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
puede ser utilizado como un lenguaje de scripting, siempre que cuente con las librerías o bindings para un entorno especíﬁco.

## los lenguajes especíﬁcamente de scripting están pensados para
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
ser muy rápidos de aprender y escribir, ya sea como archivos ejecutables o de forma interactiva en un
(REPL).

## típicamente un ”script”se ejecuta de
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
principio a ﬁn, como un ”guión”, sin un punto de entrada explícito.


## Tipos de lenguajes de scripting
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->


### propósito general,
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
fueron dise˜nados originalmente para ”pegar”las salidas y entradas de otros programas, para construir sistemas más grandes.

### especíﬁcos de dominio
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
están pensados para extender las capacidades de una aplicación o entorno, ya que permiten al usuario personalizar o extender las funcionalidades mediante la automatización de secuencias de comandos.

## Los lenguajes “pegamento” (glue languages)
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
son los que se especializan para conectar componentes de software.

### Algunos ejemplos
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
los pipes y las secuencias de comandos del shell.
conectar un servidor web con diferentes servicios web, como una base de datos.

### son especialmente útiles para
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->

comandos personalizados para una consola de comandos;

programas más peque˜nos que los que están mejor implementados en un lenguaje compilado;

programas de ¸contenedor”para archivos ejecutables, como manipular archivos y hacer otras cosas con el sistema operativo antes o después de ejecutar una aplicación

secuencias de comandos que pueden cambiar;

prototipos rápidos de una solución.


### Los lenguajes de macros que
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
manipulan componentes de un sistema o aplicación especíﬁcos pueden funcionar también como lenguajes de pegamento.

### Otras herramientas como
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
AWK también pueden ser considerados lenguajes pegamento, al igual que cualquier lenguaje implementado por un motor de Windows Script Host

## Con el advenimiento de interfaces gráﬁcas de usuario,
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->

### surgió un tipo especializado de lenguaje de scripting.
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
Estos lenguajes interactúan con los gráﬁcos de ventanas, menús, botones, etc.,
estos lenguajes se usan normalmente para automatizar las acciones del usuario.

#### A estos lenguajes también se les llama
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
\
”macros”si el control es a través de la simulación de las acciones de presionar teclas o clics del ratón,


## Muchos programas de aplicación grandes incluyen
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
un peque˜no lenguaje de programación adaptado a las necesidades del usuario de la aplicación.

## muchos juegos de computadora utilizan
<!-- from Cap 12_ApunteParadigmas2020_HIGHEXT.md -->
un lenguaje de programación especíﬁco para expresar las acciones de personajes no jugadores y del entorno del juego.

# SECURITY
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->


## One way that attackers may try to gain access to a system
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->

is to send data over the network to a program that processes network input.


## Mobile code,
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
code transmitted over the network before it is executed,
provides another way for an attacker to try to gain access to a system

### The two main mechanisms for managing risks raised by mobile code are called
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
sandboxing and code signing.

### The idea behind sandboxing,
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
is to give a program a restricted execution environment


### Code signing
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
is used to determine which person or company produced a class ﬁle.

With digital signatures, it is possible for the producer of code to sign it in a way that any recipient can verify the signature.


## Buffer Overﬂow Attack
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->

an attacker sends network messages that cause a program to read data into a buffer in memory.

### if the number of bytes in the buffer are not checked, then
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
the attacker may be able to write past the allocated memory.

### By writing over the return address of a function, the attacker
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
may cause the program to misbehave and “return” by jumping to instructions chosen by the attacker. This is a powerful form of attack.


### Java code is not
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->

vulnerable to buffer overﬂow attacks because the JVM checks array bounds at run time. This prevents a function from writing more data into an array than the array can hold.


## The Java Sandbox
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->


### The JVM executes Java bytecode in
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
a restricted environment called the Java sandbox.

### The word sandbox is used to indicate that,
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
when bytecode is executed, some operations that can be written in the Java language might not be allowed to proceed,


### mechanisms:
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
the class loader,
the Java bytecode veriﬁer,
run-time checks performed by the JVM,
and the actions of the security manager.


## Class Loader
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->

### contributes to the Java sandbox in three ways:
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->


#### separates trusted class libraries from
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

untrusted packages by making it possible to load each with different class loaders.


#### provides separate name spaces for
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

classes loaded by different class loaders.


#### places code into
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\
categories (called **protection domains**)

that let the security manager restrict the actions that speciﬁc code will be allowed to take.


## The Bytecode Veriﬁer and Virtual Machine Run-Time Tests
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
The Java bytecode veriﬁer checks Java bytecode programs before they are executed,
Complimentary run-time checks, are performed by the JVM.

### provide the following guarantees:
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->


#### No Stack Overﬂow or Underﬂow:
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

The veriﬁer examines the way that bytecode manipulates data on the operand stack and guarantees that no method will overﬂow the operand stack allocated to it.


#### All Methods are Called with Parameters of the Correct Type:
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

This type-correctness guarantee prevents
type-confusion attacks


#### No Illegal Data Conversions (Casts) Occur:
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

For example, treating an integer as a pointer is not allowed.


#### Private, Public, Protected, and Default Accesses must be Legal:
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

no improper access to restricted classes, interfaces, variables, and methods will be allowed.


## The Security Manager
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->

### The security manager is
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
a single Java object that answers at run time.

### The job of the security manager is
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
to keep track of which code is allowed to do which dangerous operations.

### The security manager does its job by
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
examining the protection domain associated with a class.

### Each protection domain has two attributes
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
a signer and a location.

### The signer is
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
the person or organization that signed the code before it was loaded into the virtual machine.
This will be null if the code is not signed by anyone.

### The location is
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
the URL where the Java classes reside.

### A standard security manager will
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
disallow most operations when they are requested by untrusted code and may allow trusted code to do whatever it wants.


### A running virtual machine can have only one
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
security manager installed at a time.


### once a security manager has been
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
installed, it cannot be uninstalled without restarting the virtual machine.


### how the standard Java library uses the security manager
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->


#### the program makes a call to a potentially dangerous operation
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

the associated Java API code asks the security manager whether the operation should be allowed.


#### If the operation is permitted,
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\
the call to the security manager returns normally

and the Java API performs the requested operation.


#### If the operation is not permitted,
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

the security manager throws a SecurityException. This exception propagates back to the Java program.


#### One limitation of the security manager using exceptions is that
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\
a hostile applet or other untrusted code may catch a security exception by using a try-ﬁnally block.


## Security and Type Safety
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->


### all of the sandbox mechanisms rely on
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
type safety.

### ways that type errors can allow code to perform arbitrary actions.
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->


#### One way for a C/C++ program to call an arbitrary function is
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

through a function pointer.


#### type confusion between object types would
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\

allow a program to perform dangerous actions.


#### a buggy class loader and linker.
<!-- from Cap 13.5_Concepts in Programming Languages_HIGHEXT.md -->
\
made it possible to successfully load another class with a different interface and to use the ﬁrst class name for objects of the second class.
