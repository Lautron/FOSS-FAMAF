Specific Themes


### Here are some specific themes that are addressed repeatedly in the text:

Computability: Some problems cannot be solved by computer. The undecidability of the halting problem implies that programming language compilers and interpreters cannot do everything that we might wish they could do.

Static analysis: There is a difference between compile time and run time. At compile time, the program is known but the input is not. At run time, the program and the input are both available to the run-time system.
Although a program designer or implementer would like to find errors at compile time, many will not surface until run time.
Methods that detect program errors at compile time are usually conservative, which means that when they say a program does not have a certain kind of error this statement is correct. However, compile-time error-detection methods will usually say that some programs contain errors even if errors may not actually occur when the program is run.

Expressiveness versus efficiency:
There are many situations in which it would be convenient to have a programming language implementation do something automatically.

Computability


### PARTIAL FUNCTIONS AND COMPUTABILITY

From a mathematical point of view, a program defines a function.
In practice, there is a lot more to a program than the function it computes. However, as a starting point in the study of programming languages, it is useful to understand some basic facts about computable functions.

The fact that not all functions are computable has important ramifications for programming language tools and implementations. Some kinds of programming constructs, however useful they might be, cannot be added to real programming languages because they cannot be implemented on real computers.


### Expressions, Errors, and Nontermination

In mathematics, an expression may have a defined value or it may not.
There is nothing to try to do when we see the expression 3/0; a mathematician would just say that this operation is undefined, and that would be the end of the discussion.

In computation, there are two different reasons why an expression might not have a value:

Error termination:
Evaluation of the expression cannot proceed because of a conflict between operator and operand.

Nontermination:
Evaluation of the expression proceeds indefinitely.

An example of the first kind is division by zero. There is nothing to compute in this case, except possibly to stop the computation in a way that indicates that it could not proceed any further. This may halt execution of the entire program, abort one thread of a concurrent program, or raise an exception if the programming language provides exceptions. The second case is different: There is a specific computation to perform, but the computation may not terminate and therefore may not yield a value.


### Partial Functions

A partial function is a function that is defined on some arguments and undefined on others.
This is ordinarily what is meant by function in programming, as a function declared in a program may return a result or may not if some loop sequence of recursive calls does not terminate.
some loop

In words, a partial function is single valued, but need not be defined on all elements of its domain.


### Computability

Computability theory gives us a precise characterization of the functions that are computable in principle.
Computability theory gives us a precise characterization of the functions that are computable in principle. The
The class

The reason why we say "computable in principle" instead of "computable in practice" is that some computable functions might take an extremely long time to compute.
If a function call will not return for an amount of time equal to the length of the entire history of the universe, then in practice we will not be able to wait for the computation to finish.
Nonetheless, computability in principle is an important benchmark for programming languages.


### Computable Functions

Intuitively, a function is computable if there is some program that computes it.

One problem with this intuitive definition of computable is that a program has to be written out in some programming language, and we need to have some implementation to execute the program. It might very well be that, in one programming language, there is a program to compute some mathematical function and in another language there is not.

In the 1930s,
1930s,
Alonzo Church of Princeton University proposed an important principle, called Church's thesis.
Church's
thesis,
states that the same class of functions on the integers can be computed by any general computing device. This is the class of partial recursive functions, sometimes called the class of computable functions.
There is a mathematical definition of this class of functions that does not refer to programming languages, a second definition that uses a kind of idealized computing device called a Turing machine,
and a third (equivalent) definition that uses lambda calculus
a Turing machine consists of an infinite tape, a tape read-write head, and a finite-state controller. The tape is divided into contiguous cells, each containing a single symbol. In each computation step, the machine reads a tape symbol and the finite-state controller decides whether to write a different symbol on the current tape square and then whether to move the read-write head one square left or right.
Church cited in formulating this thesis was the proof that Turing machines and lambda calculus are equivalent. The fact that all standard programming languages express precisely the class of partial recursive functions is often summarized by the statement that all programming languages are Turing complete.


### Noncomputable Functions

It is useful to know that some specific functions are not computable.
An important example is commonly referred to as the halting problem.

The undecidability of the halting problem is the fact that the function fhalt is not computable. The undecidability of the halting problem is an important fact to keep in mind in designing programming language implementations and optimizations. It implies that many useful operations on programs cannot be implemented, even in principle.


### Applications

Programming language compilers can often detect errors in programs. However, the undecidability of the halting problem implies that some properties of programs cannot be determined in advance. The simplest example is halting itself.


### SUMMARY

The following main concepts from this short overview should be remembered:

Partiality:
Recursively defined functions may be partial functions. They are not always total functions. A function may be partial because a basic operation is not defined on some argument or because a computation does not terminate.

Computability:
Some functions are computable and others are not. Programming languages can be used to define computable functions; we cannot write programs for functions that are not computable in principle.

Turing completeness:
All standard general-purpose programming languages give us the same class of computable functions.

Undecidability:
Many important properties of programs cannot be determined by any computable function. In particular, the halting problem is undecidable.

Fundamentals

### COMPILERS AND SYNTAX

A program is a description of a dynamic process. The text of a program itself is called its syntax; the things a program does comprise its semantics.
The function of a programming language implementation is to transform program syntax into machine instructions that can be executed to cause the correct sequence of actions to occur.


### Structure of a Simple Compiler

Programming languages that are convenient for people to use are built around concepts and abstractions that may not correspond directly to features of the underlying machine. For this reason, a program must be translated into the basic instruction set of the machine before it can be executed. This can be done by a compiler, which translates the entire program into machine code before the program is run, or an interpreter, which combines translation and program execution.
This can be done by a compiler, which translates the entire program into machine code before the program is run, or an interpreter, which combines translation and program execution.


### Lexical

### Lexical Analysis

The input symbols are scanned and grouped into meaningful units called tokens.
For example,
:= x+1,
five tokens: the identifier temp, the assignment "symbol" :=, the variable x, the addition symbol+, and the number 1.
Lexical analysis can distinguish numbers from identifiers. However, because lexical analysis is based on a single left-to-right (and top-to-bottom)scan, lexical analysis does not distinguish between identifiers that are names of variables and identifiers that are names of constants.
Because variables and constants are declared differently, variables and constants are distinguished in the semantic analysis phase.


### Syntax Analysis

tokens are grouped into syntactic units such as expressions, statements, and declarations that must conform to the grammatical rules of the programming language.
action performed during this phase,
parsing,
The purpose of parsing is to produce a data structure called a parse tree, which represents the syntactic structure of the program in a way that is convenient for subsequent phases of the compiler. If a program does not meet the syntactic requirements to be a well formed program, then the parsing phase will produce an error message and terminate the compiler.


### Semantic Analysis

In this phase of a compiler, rules
rules and procedures that depend on the context surrounding an expression are applied.


### Intermediate Code Generation

Although it might be possible to generate a target program from the results of syntactic and semantic analysis, it is difficult to generate efficient code in one phase. Therefore, many compilers first produce an intermediate form of code and then optimize this code to produce a more efficient target program.

It is important to use an intermediate representation that is easy to produce and easy to translate into the target language. The intermediate representation can be some form of generic low-level code that has properties common to several computers.


### Code Optimization

There are a variety of techniques that may be used to improve the efficiency of a program. These techniques are

usually applied to the intermediate representation.

The following list describes some standard optimizations:

Common Subexpression Elimination:
If a program calculates the same value more than once and the compiler can detect this, then it may be possible to transform the program so that the value is calculated only once and stored for subsequent use.

Copy Propagation:
If a program contains an assignment such as x=y, then it may be possible to change subsequent statements to refer to y instead of to x and to eliminate the assignment.

Dead-Code Elimination:
If some sequence of instructions can never be reached, then it can be eliminated from the program.

Loop Optimizations:
There are several techniques that can be applied to remove instructions from loops. For example, if some expression appears inside a loop but has the same value on each pass through the loop, then the expression can be moved outside the loop.

In-Lining Function Calls:
If a program calls function f, it is possible to substitute the code for f into the place where f is called. This makes the target program more efficient, as the instructions associated with calling a function can be eliminated, but it also increases the size of the program. The most important consequence of in-lining function calls is usually that they allow other optimizations to be performed by removing jumps from the code.


### Code Generation

The final phase of a standard compiler is to convert the intermediate code into a target machine code. This involves choosing a memory location, a register, or both, for each variable that appears in the program. There are a variety of register allocation algorithms that try to reuse registers efficiently. This is important because many machines have a fixed number of registers, and operations on registers are more efficient than transferring data into and out of memory.


### Grammars

Grammars provide a convenient method for defining infinite sets of expressions. In addition, the structure imposed by a grammar gives us a systematic way of processing expressions.

A grammar consists of a start symbol, a set of nonterminals, a set of terminals, and a set of productions.

BNF.

The main ideas are illustrated by example. A simple language of numeric expressions is defined by the following grammar: e ::= n | e+e | e-e n ::= d | nd d ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

e is the start symbol,
e, n, and d are nonterminals,
and 0,
and 0, 1, 2, 3,
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, and are the terminals.
The language defined by this grammar consists of all the sequences of terminals that we can produce by starting with the start symbol e and by replacing nonterminals according to the preceding productions.


### Derivations

A sequence of replacement steps resulting in a string of terminals is called a derivation.

Here are two derivations in this grammar, the first given in full and the second with a few missing steps that can be filled in by the reader

e → n

→ n → nd → dd → 2d → 25 e → e e → e e+e → … → n-n+n → … … 10-15+12


### Parse Trees and Ambiguity

It is often convenient to represent a derivation by a tree. This tree, called the parse tree of a derivation, or derivation tree, is constructed with the start symbol as the root of the tree.

The parse tree for the derivation of 10 $-$ 15+12 in the preceding subsection has some useful structure. Specifically, because the first step yields e-e, the parse tree has the form

which is another parse tree for the same expression. An important fact about parse trees is that each corresponds to a unique parenthesization of the expression.

A grammar is ambiguous if some expression has more than one parse tree. If every expression has at most one parse tree, the grammar is unambiguous.


### Parsing and Precedence

Parsing is the process of constructing parse trees for sequences of symbols.
Suppose we define a language L by writing out a grammar G. Then, given a sequence of symbols s, we would like to determine if s is in the language L. If so, then we would like to compile or interpret s, and for this purpose we would like to find a parse tree for s.
An algorithm that decides whether s is in L, and constructs a parse tree if it is, is called a parsing algorithm for G.

Programming in Lambda Calculus


### Functions of Several Arguments


### Declarations


### Recursion and Fixed Points

DENOTATIONAL SEMANTICS

In computer science, the phrase denotational semantics refers to a specific style of mathematical semantics for imperative programs.
The term denotational semantics suggests that a meaning or denotation is associated with each program or program phrase

The denotation of a program is a mathematical object, typically a function, as opposed to an algorithm or a sequence of instructions to execute. In denotational semantics, the meaning of a simple program like

x := 0; y:=0; while x  $\leq$  z do y:=y+x;x:=x+1

is a mathematical function from states to states, in which a state is a mathematical function representing the values in memory at some point in the execution of a program.

Associating mathematical functions with programs is good for some purposes and not so good for others. In many situations, we consider a program correct if we get the correct output for any possible input. This form of correctness depends on only the denotational semantics of a program, the mathematical function from input to output associated with the program.

Forms of denotational semantics are commonly used for reasoning about program optimization and static analysis methods.


### Compositionality

An important principle of denotational semantics is that the meaning of a program is determined from its text compositionally. This means that the meaning of a program must be defined from the meanings of its parts, not something else, such as the text of its parts or the meanings of related programs obtained by syntactic operations.


### Object Language and Metalanguage

One source of confusion in talking (or writing) about the interpretation of syntactic expressions is that everything we write is actually syntactic. When we study a programming language, we need to distinguish the programming language we study from the language we use to describe this language and its meaning.


### States and Commands

The meaning of a program is a function from states to states. In a more realistic programming language, with procedures or pointers, it is necessary to model the fact that two variable names may refer to the same location.
However, in the simple language of while programs, we assume that each variable is given a different location.
State of mathematical representations of machine states be

State = Variables → Values

In words, a state is a function from variables to values.

The meaning of a program is an element of the mathematical set Command of commands, defined by Command = State → State

In words, a command is a function from states to states. Unlike states themselves, which are total functions, a command may be a partial function. The reason we need partial functions is that a program might not terminate on an initial state.


### Perspective and Nonstandard Semantics

FUNCTIONAL AND IMPERATIVE LANGUAGES


### Imperative and Declarative Sentences

In an imperative sentence, the subject of the sentence is implicit. For example, the subject of the sentence Pick up that fish is (implicitly) the person to whom the command is addressed. A declarative sentence expresses a fact and may consist of a subject and a verb or subject, verb, and object.

In many programming languages, the basic constructs are imperative statements. For example, an assignment statement such as x:=5

is a command to the computer (the implied subject of the utterance) to store the value5 in a certain location. Programming languages also contain declarative constructs such as the function declaration

function f(int x) {return x+1;} that states a fact. One reading of this as a declarative sentence is that the subject is the name f and the sentence about f is "f is a function whose return value is 1 greater than its argument." In programming, the distinction between imperative and declarative constructs rests on the distinction between changing an existing value and declaring a new value.
example,

{ int x=1; /* declares new x */ x = x+1; /* assignment to existing x */ { int y = x+1; /* declares new y */ { int x = y+1; /* declares new x */ }}}

Here, only the second line is an imperative statement. This is an imperative command that changes the state of the machine by storing the value 2 in the location associated with variable x. The other lines contain declarations of new variables.


### Functional versus Imperative Programs

The phrase functional language is used to refer to programming languages in which most computation is done by evaluation of expressions that contain functions.
Two examples are Lisp and ML. Both of these languages contain declarative and imperative constructs. However, it is possible to write a substantial program in either language without using any imperative constructs.

Some people use the phrase functional language to refer to languages that do not have expressions with side effects or any other form of imperative construct. However, we will use the more emphatic phrase pure functional language for declarative languages that are designed around flexible constructs for defining and using functions.

As a consequence, pure functional languages have a useful optimization property: If expression e occurs several places within a specific scope, this expression needs to be evaluated only once.


### Referential Transparency

In some of the academic literature on programming languages, including some textbooks on programming language semantics, the concept that is used to distinguish declarative from imperative languages is called referential transparency.
the concept that is used to distinguish declarative from imperative languages is called referential transparency.

it is traditional to say that a language is referentially transparent if we may replace one expression with another of equal value anywhere in a program without changing the meaning of the program. This is a property of pure functional languages.
a language is referentially transparent if we may replace one expression with another of equal value anywhere in a program without changing the meaning of the program.


### Functional Programming and Concurrency

An appealing aspect of pure functional languages and of programs written in the pure functional subset of larger languages is that programs can be executed concurrently. This is a consequence of the declarative language test mentioned at the beginning of this subsection.

Functional Programming: We can evaluate f(e1,…,en) by evaluating e1,…,en in parallel because values of these expressions are independent.

Imperative Programming: For an expression such as f(g(x), h(x)), the function g might change the value of x. Hence the arguments of functions in imperative

languages must be evaluated in a fixed, sequential order. This order ing restricts the use of concurrency.

CHAPTER SUMMARY

A standard compiler transforms an input program, written in a source language, into an output program, written in a target language.
This process is organized into a series of six phases,
The first three phases, lexical analysis, syntax analysis, and semantic analysis, organize the input symbols into meaningful tokens, construct a parse tree, and determine context-dependent properties of the program such as type agreement of operators and operands.
The last three phases, intermediate code generation, optimization, and target code generation, are aimed at producing efficient target code through language transformations and optimizations.
generation, are aimed at producing

Lambda calculus provides a notation and symbolic evaluation mechanism that is useful for studying some properties of programming languages.

Lambda expressions are symbolically evaluated by use of β-reduction, with the function argument substituted in place of the formal parameter. This process resembles macro expansion and function in lining, two transformations that are commonly done by compilers. Although lambda calculus is a very simple system, it is theoretically possible to write every computable function in the lambda calculus.

In pure functional programs, syntactically identical expressions within the same scope have identical values. This property allows certain optimizations and makes it possible to execute independent subprograms in parallel. Because functional languages are theoretically as powerful as imperative languages, we discussed some of the pragmatic differences between functional and imperative languages. Although functional languages may be simpler to reason about in certain ways, imperative languages often make it easier to write efficient programs.