# Semaphores


## Deﬁnition


### A semaphore is an object
with an integer value that we can manipulate with two routines;

### routines
sem wait()
sem post()1.

### the initial value
determines its behavior,
we must
initialize it to some value,


## how to use

### sem wait()

#### will either
\
return right away
(because the value of the semaphore was one or higher when we called sem wait()),
or it will cause the caller to suspend execution waiting for a subsequent post.

#### multiple calling threads
\
may call into sem wait(), and thus all be queued waiting to be woken.

### sem post()

#### does not
\
wait for some particular condition

#### it simply
\
increments the value of the semaphore
and then, if there is a thread waiting to be woken, wakes one of them up.

### the value of the semaphore, when negative,
is equal to the number of waiting threads


## Binary Semaphores (Locks)

we simply surround the critical section of interest with a sem wait()/sem post() pair.

### initial value of the semaphore
the initial value should be 1.

### trace

\
![4a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/threads-sema/4a.png){ width=250px }


## Semaphores For Ordering

### example,

#### a thread
\
may wish to wait for a list to become non-empty,

so it can delete an element from it.

### In this pattern of usage,
we often ﬁnd one thread
**waiting**
for something to happen,
and another thread making that something happen and then
**signaling**
that it has happened, thus waking the waiting thread.

#### We are thus using the semaphore
\
as an ordering primitive (similar to our use of condition variables

### example

\
![6a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/threads-sema/6a.png){ width=250px }


## The Producer/Consumer (Bounded Buffer) Problem


## ASIDE: SETTING THE VALUE OF A SEMAPHORE
what’s the general rule for semaphore initialization?

### One simple way to think about it,
consider the number of resources you are willing to give away immediately after initialization.

### With the lock,
it was 1, because you are willing to have the lock locked (given away) immediately after initialization.

### With the ordering case,
it was 0, because there is nothing to give away at the start;
only when the child thread is done is the resource created,


### A Working Solution

To solve this problem, we simply must reduce the scope of the lock.
simply move the mutex acquire and release to be just around the critical section;


## Reader-Writer Locks


### problem
imagine a number of concurrent list operations,
While inserts change the state of the list
lookups simply read the data structure;
as long as we can guarantee that no insert is on-going, we can allow many lookups to proceed concurrently.

### The code
once a reader has acquired a read lock, more readers will be allowed to acquire the read lock too;
however, any thread that wishes to acquire the write lock will have to wait until all readers are ﬁnished;


### should be used with some caution.
They often add more overhead
and thus do not end up speeding up performance as compared to just using simple and fast locking primitives


## Thread Throttling


### problem
how can a programmer prevent “too many” threads from doing something at once and bogging the system down?

#### Answer:
\
decide upon a threshold for “too many”, and then use a semaphore to limit the number of threads concurrently executing the piece of code in question.

### A simple semaphore can solve this problem.
By initializing the value of the semaphore to the maximum number of threads you wish to enter the memory-intensive region at once,
and then putting a sem wait() and sem post() around the region,
