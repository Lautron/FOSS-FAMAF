# SECURITY


## One way that attackers may try to gain access to a system

is to send data over the network to a program that processes network input.


## Mobile code,
code transmitted over the network before it is executed,
provides another way for an attacker to try to gain access to a system

### system.Thetwomainmechanismsformanagingrisksraisedbymobilecodearecalled
sandboxing and code signing.

### The idea behind sandboxing,
thedevelopmentofJava,istogiveaprogramarestrictedexecutionenvironment.This


### Code signing
is used to determine which person or company produced a class ﬁle.

With digital signatures, it is possible for the producer of code to sign it in a way that any recipient can verify the signature.


## Buffer Overﬂow Attack

an attacker sends network messages that cause a program to read data into a buffer in memory.

### If the program does not check the number of bytes placed in the buffer, then
the attacker may be able to write past the allocated memory.

### By writing over the return address that is stored in the activation record of a function, the attacker
may cause the program to misbehave and “return” by jumping to instructions chosen by the attacker. This is a powerful form of attack.


### Java code is not

vulnerable to buffer overﬂow attacks because the JVM checks array bounds at run time. This prevents a function from writing more data into an array than the array can hold.


## The Java Sandbox


### The JVM executes Java bytecode in
a restricted environment called the Java sandbox.

### The word sandbox is used to indicate that,
when bytecode is executed, some operations that can be written in the Java language might not be allowed to proceed,


### mechanisms:
the class loader, the Java bytecode veriﬁer, run-time checks performed by the JVM, and the actions of the security manager.


## Class Loader

### contributes to the Java sandbox in three ways:


#### separates trusted class libraries from
\

untrusted packages by making it possible to load each with different class loaders.


#### provides separate name spaces for
\

classes loaded by different class loaders.


#### places code into
\
categories (called
**protection domains)**

that let the security manager restrict the actions that speciﬁc code will be allowed to take.


## The Bytecode Veriﬁer and Virtual Machine Run-Time Tests
The Java bytecode veriﬁer checks Java bytecode programs before they are executed,
Complimentary run-time checks,
are performed by the JVM.

### Together, these checks provide the following guarantees:


#### No Stack Overﬂow or Underﬂow:
\

The veriﬁer examines the way that bytecode manipulates data on the operand stack and guarantees that no method will overﬂow the operand stack allocated to it.


#### All Methods are Called with Parameters of the Correct Type:
\

This type-correctness guarantee prevents
type-confusion attacks


#### No Illegal Data Conversions (Casts) Occur:
\

For example, treating an integer as a pointer is not allowed.


#### Private, Public, Protected, and Default Accesses must be Legal:
\

no improper access to restricted classes, interfaces, variables, and methods will be allowed.


## The Security Manager

### The security manager is
a single Java object that answers at run time.

### The job of the security manager is
to keep track of which code is allowed to do which dangerous operations.

### The security manager does its job by
examining the protection domain associated with a class.

### Each protection domain has two attributes
a signer and a location.

### The signer is
the person or organization that signed the code before it was loaded into the virtual machine.
This will be null if the code is not signed by anyone.

### The location is
the URL where the Java classes reside.

### A standard security manager will
disallow most operations when they are requested by untrusted code and may allow trusted code to do whatever it wants.


### A running virtual machine can have only one
security manager installed at a time.


### once a security manager has been
installed, it cannot be uninstalled without restarting the virtual machine.


### the standard Java library uses the security manager according to the following steps:


#### If a Java program makes a call to a potentially dangerous operation
\

the associated Java API code asks the security manager whether the operation should be allowed.


#### If the operation is permitted,
\
the call to the security manager returns normally

and the Java API performs the requested operation.


#### If the operation is not permitted,
\

the security manager throws a SecurityException. This exception propagates back to the Java program.


#### One limitation of this mechanism is that
\
a hostile applet or other untrusted code may catch a security exception by using a try-ﬁnally block.


## Security and Type Safety


### all of the sandbox mechanisms rely on
type safety.

### ways that type errors can allow code to perform arbitrary and potentially dangerous actions.


#### One way for a C/C++ program to call an arbitrary function is
\

through a function pointer.


#### type confusion between object types would
\

allow a program to perform dangerous actions.


#### a buggy class loader and linker.
\
This made it possible to then successfully load another class with a different interface and to use the ﬁrst class name for objects of the second class.

