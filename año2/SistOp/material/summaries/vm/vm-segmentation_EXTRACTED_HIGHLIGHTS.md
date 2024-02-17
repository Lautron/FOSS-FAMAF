# Segmentation


## Segmentation: Generalized Base/Bounds


### The idea
instead of having just one base and bounds pair in our MMU, why not have a base and bounds pair per logical
**segment**
of the address space?

### A segment
is just a contiguous portion of the address space of a particular length,


#### we have three logically-different segments:\
code, stack, and heap.

### What segmentation allows the OS to do
place each one of those segments in different parts of physical memory, and thus avoid ﬁlling physical memory with unused virtual address space.


### The hardware structure in our MMU
required to support segmentation is
a set of three base and bounds register pairs.


## Which Segment Are We Referring To?

The hardware uses segment registers during translation. How does it know the offset into a segment, and to which segment an address refers?

### explicit approach,
chop up the address space into segments based on the top few bits of the virtual address;
we have three segments; thus we need two bits to accomplish our task.

one segment of the address space goes unused.

#### Another issue\
with using the top so many bits to select a segment is that it limits use of the virtual address space.

### the implicit approach,
the hardware deter-

mines the segment by noticing how the address was formed.

#### the address was generated from the program counter\
then the address is within the code segment;

#### if the address is based off of the stack or base pointer,\
it must be in the stack segment;

#### any other address\
must be in the heap.


## What About The Stack?


### little extra hardware support.
the hardware also needs to know which way the segment grows


## Support for Sharing

to save memory,

### share certain memory
segments between address spaces. In particular, code sharing is common and still in use in systems today.
To support sharing, we need a little extra support from the hardware,

### protection bits.
Basic support adds a few bits per segment, indicating whether or not a program can read or write a segment, or perhaps execute code that lies within the segment.


### the hardware algorithm
would also have to change.
In addition to checking whether a virtual address is within bounds,
the hardware also has to check whether a particular access is permissible.


## Fine-grained vs. Coarse-grained Segmentation


### coarse-grained,
it chops up the address space into relatively large, coarse chunks.
large number of smaller segments,

### ﬁne-grained

### segment table
support the creation of a very large number of segments, and thus enable a system to use segments in more ﬂexible ways


## OS Support


### how segmentation works.
Pieces of the address space are relocated into physical memory as the system runs, and thus a huge savings of physical memory is achieved

### segmentation

### issues

#### what should the OS do on a context switch?\
the segment registers must be saved and restored. Clearly, each process has its own virtual address space, and the OS must make sure to set up these registers correctly before letting the process run again.

#### interaction when segments grow\
In some cases, the existing heap will be able to service the request,

In others,
the heap segment itself may need to grow.

#### managing free space in physical memory.\
When a new address space is created, the OS has to be able to ﬁnd space in physical memory for its segments.
we have a number of segments per process, and each segment might be a different size.

### The general problem
is that physical memory quickly becomes full of little holes of free space, making it difﬁcult to allocate new segments, or to grow existing ones.

### external fragmentation

### One solution
would be to
**compact**
physical memory by rearranging the existing segments.
However, compaction is expensive, as copying segments is memory-intensive and generally uses a fair amount of processor time;


### use a free-list management algorithm
tries to keep large extents of memory available for allocation.

#### hundreds of approaches\
**best-ﬁt**
(which keeps a list of free spaces and returns the one closest in size that satisﬁes the desired allocation to the requester),
**worst-ﬁt, ﬁrst-ﬁt,**
and more complex schemes like
**buddy algorithm**


## Summary


### Segmentation
solves a number of problems, and helps us build a more effective virtualization of memory.
segmentation can
**better support sparse address spaces,**
by avoiding the huge potential waste of memory between logical segments of the address space.
**It is also fast,**
as doing the arithmetic segmentation requires is easy and well-suited to hardware;
**the overheads of translation are minimal.**
A fringe beneﬁt arises too:
**code sharing.**
If code is placed within a separate segment, such a segment could potentially be shared across multiple running programs.

### allocating variable-sized segments
in memory leads to some problems

#### The ﬁrst,\
is external fragmentation.
Because segments are variablesized, free memory gets chopped up into odd-sized pieces, and thus satisfying a memory-allocation request can be difﬁcult.

#### The second\
is that segmentation still isn’t ﬂexible enough to support our fully generalized, sparse address space.
if our model of how the address space is being used doesn’t exactly match how the underlying segmentation has been designed to support it, segmentation doesn’t work very well.