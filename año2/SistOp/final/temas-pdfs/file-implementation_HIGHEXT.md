# File System Implementation


## The Way To Think


### data structures of the ﬁle system.
what types of on-disk structures are utilized by the ﬁle system to organize its data and metadata?


### access methods.
How does it map the calls made by a process, such as open(), read(), write(), etc., onto its structures?

Which structures are read during the execution of a particular system call?

Which are written?

How efﬁciently are all of these steps performed?


## Overall Organization


### divide the disk into blocks;
simple ﬁle systems use just one block size,
Let’s choose a commonly-used size of 4 KB.

### our view of the disk partition
a series of blocks, each of size 4 KB.
The blocks are addressed from 0 to N  $-$  1, in a partition of size N 4-KB blocks.

\
![2a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-implementation/2a.png){ width=250px }


### what we need to store in these blocks to build a ﬁle system.

#### user data.
\
Let’s call the region of the disk we use for user data the
**data region,**

\
![3a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-implementation/3a.png){ width=250px }


#### metadata,
\
tracks things like which data blocks
comprise a ﬁle,
the size of the ﬁle,
its owner and access rights,
access and modify times,
and other similar kinds of information.
Let’s call this portion of the disk the
**inode table,**
which simply holds an array of on-disk inodes.

\
![3b](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-implementation/3b.png){ width=250px }


#### inodes
\
are typically not that big, for example 128 or 256 bytes.
a 4-KB block can hold 16 inodes, and our ﬁle system above contains 80 total inodes.
some way to track whether inodes or data blocks are free or allocated.

#### allocation structures
\
We
choose
a bitmap,
one for the data region
and one for the inode table


#### superblock,
\
The superblock contains information about this particular ﬁle system,
how many inodes and data blocks are in the ﬁle system
where the inode table begins
and so forth.
It will likely also include a magic number of some kind to identify the ﬁle system type

\
![4a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-implementation/4a.png){ width=250px }


## The Inode


### The name
is short for index node,

is the generic name
to describe the structure that holds the metadata for a given ﬁle,


### Each inode
is implicitly referred to by a number
(called the i-number),
given an i-number, you should directly be able to calculate where on the disk the corresponding inode is located.

\
![5a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-implementation/5a.png){ width=250px }


### To read inode number 32,
the ﬁle system would ﬁrst calculate the offset into the inode region
(32  $\cdot$  sizeof(inode) or 8192),
add it to the start address of the inode table on disk
(inodeStartAddr = 12KB),
and thus arrive upon the correct byte address of the desired block of inodes: 20KB.


### the sector address sector of the inode block can be calculated as follows:

blk = (inumber * sizeof(inode_t)) / blockSize;

sector = ((blk * blockSize) + inodeStartAddr) / sectorSize;


### Inside each inode
is virtually all of the information you need about a ﬁle:
- its type
- its size,
- the number of blocks allocated to it,
- protection information
- some time information,
- information about where its data blocks reside on disk

We refer to all such information about a ﬁle as **metadata**;


### The Multi-Level Index


#### One common idea
\
is to have a special pointer known as an
**indirect pointer.**
it points to a block that contains more pointers,
each of which point to user data.

#### an inode may have
\
some ﬁxed number of direct pointers (e.g., 12), and a single indirect pointer.
If a ﬁle grows large enough, an indirect block is allocated
Assuming 4-KB blocks and 4-byte disk addresses, that adds another 1024 pointers;


#### support even larger ﬁles.
\
To do so, just add another pointer to the inode:
the
**double indirect pointer.**
This pointer refers to a block that contains pointers to indirect blocks, each of which contain pointers to data blocks.

#### this imbalanced tree is referred to as
\
the multi-level index approach to pointing to ﬁle blocks.

#### why use an imbalanced tree like this?
\
most ﬁles are small.
if most ﬁles are indeed small, it makes sense to optimize for this case.


## Directory Organization


### a directory
basically just contains a list of (entry name, inode number) pairs.

### The on-disk data for dir might look like:

\
![8a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-implementation/8a.png){ width=500px }


#### each entry has
\
- an inode number,
- record length (the total bytes for the name plus any left over space),
- string length (the actual length of the name),
- and ﬁnally the name of the entry.

Note that each directory has two extra entries, . “dot” and .. “dot-dot”;


### ﬁle systems treat directories as a special type of ﬁle.
a directory has an inode, somewhere in the inode table
(with the type ﬁeld of the inode marked as “directory” instead of “regular ﬁle”).
The directory has data blocks pointed to by the inode
these data blocks live in the data block region of our simple ﬁle system.

## Free Space Management


### when we create a ﬁle,
we will have to allocate an inode for that ﬁle.
The ﬁle system will thus search through the bitmap for an inode that is free,
and allocate it to the ﬁle;
the ﬁle system will have to mark the inode as used (with a 1)
and eventually update the on-disk bitmap with the correct information.

#### A similar set of activities
\
take place when a data block is allocated.

### Some other considerations might also come into play
some Linux ﬁle systems,
will look for a sequence of blocks (say 8) that are free
by ﬁnding such a sequence
the ﬁle system guarantees that a portion of the ﬁle will be contiguous on the disk,
thus improving performance.


## Access Paths: Reading and Writing


### For the following examples,
let us assume that the ﬁle system has been mounted and thus that the superblock is already in memory.
Everything else (i.e., inodes, directories) is still on the disk.


### Reading A File From Disk

let us ﬁrst assume that you want to simply open a ﬁle (e.g., /foo/bar), read it, and then close it.
For this simple example, let’s assume the ﬁle is just 12KB in size (i.e., 3 blocks).

#### you issue an open("/foo/bar", O RDONLY) call,
\
the ﬁle system ﬁrst needs to ﬁnd the inode for the ﬁle bar,
The ﬁle system must traverse the pathname and thus locate the desired inode.

#### All traversals
\
begin at the root of the ﬁle system, in the root directory which is simply called /.
the ﬁrst thing the FS will read from disk is the inode of the root directory.

#### the root inode number
\
In most UNIX ﬁle systems, the root inode number is 2.

#### The next step
\
is to recursively traverse the pathname until the desired inode is found.

#### In this example,
\
the FS reads the block containing the
inode of foo and then its directory data,
ﬁnally ﬁnding the inode number of bar.

#### The ﬁnal step of open()
\
is to read bar’s inode into memory;
the FS then does a ﬁnal permissions check, allocates a ﬁle descriptor for this process in the per-process open-ﬁle table, and returns it to the user.

#### Once open,
\
the program can then issue a read()
The ﬁrst read
will
read in the ﬁrst block of the ﬁle,

#### The read
\
will further update the in-memory open ﬁle table for this ﬁle descriptor,
updating the ﬁle offset such that the next read will read the second ﬁle block, etc.

#### At some point, the ﬁle will be closed.
\
the ﬁle descriptor should be deallocated,
that is all the FS really needs to do.

### ASIDE: READS DON’T ACCESS ALLOCATION STRUCTURES
Allocation structures, such as bitmaps, are only accessed when allocation is needed.

### Figure 40.3
\
![11a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-implementation/11a.png){ width=550px }

the open causes numerous reads to take place in order to ﬁnally locate the inode of the ﬁle.
Afterwards, reading each block requires the ﬁle system to ﬁrst consult the inode,
then read the block,
and then update the inode’s last-accessed-time ﬁeld with a write.

### the amount of I/O generated by the open
is proportional to the length of the pathname.
Making this worse would be the presence of large directories;
writing out a ﬁle
is even worse.


### Writing A File To Disk

#### process.
\
- First, the ﬁle must be opened
- Then, the application can issue write()
- Finally, the ﬁle is closed.

#### writing to the ﬁle may also
\
allocate a block

#### When writing out a new ﬁle,
\
each write not only has to write data to disk but has to ﬁrst decide

which block to allocate to the ﬁle and thus update other structures of the disk accordingly
(e.g., the data bitmap and inode).

#### each write to a ﬁle logically generates ﬁve I/Os:
\

- one to read the data bitmap (which is then updated to mark the newly-allocated block as used),
- one to write the bitmap (to reﬂect its new state to disk),
- two more to read and then write the inode (which is updated with the new block’s location),
- and ﬁnally one to write the actual block itself.

#### To create a ﬁle,
\

- one read to the inode bitmap (to ﬁnd a free inode),
- one write to the inode bitmap (to mark it allocated),
- one write to the new inode itself (to initialize it),
- one to the data of the directory (to link the high-level name of the ﬁle to its inode number),
- and one read and write to the directory inode to update it.

**If the directory needs to grow**
to accommodate the new entry, additional I/Os (i.e., to the data bitmap, and the new directory block) will be needed too.


### Figure 40.4
\
![13a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-implementation/13a.png){ width=500px }


## Caching and Buffering


### most ﬁle systems
aggressively use system memory (DRAM) to cache important blocks.
without caching, every ﬁle open would require at least two reads for every level in the directory hierarchy

### ﬁxed-size cache
to hold popular blocks.
strategies such as LRU and different variants would decide which blocks to keep in cache.

#### This ﬁxed-size cache
\
would usually be allocated at boot time to be roughly 10% of total memory.

### dynamic partitioning approach.
many modern operating systems integrate virtual memory pages and ﬁle system pages into a uniﬁed page cache
memory can be allocated more ﬂexibly across virtual memory and ﬁle system, depending on which needs more memory at a given time.

### the ﬁle open example with caching.
The ﬁrst open may generate a lot of I/O trafﬁc to read in directory inode and data,
subsequent ﬁle opens of that same ﬁle
will mostly hit in the cache and thus no I/O is needed.

### TIP: UNDERSTAND STATIC VS. DYNAMIC PARTITIONING

#### The static approach
\
simply divides the resource into ﬁxed proportions once;

#### The dynamic approach
\
is more ﬂexible, giving out differing amounts of the resource over time;

### effect of caching on writes.
write trafﬁc has to go to disk in order to become persistent.

#### write buffering
\
by delaying writes, the ﬁle system can
**batch**
some updates into a smaller set of I/Os;

#### for example,
\
if an inode bitmap is updated when one ﬁle is created and then updated moments later as another ﬁle is created,
the ﬁle system saves an I/O by delaying the write after the ﬁrst update.

#### by buffering a number of writes
\
in memory, the system can then schedule the subsequent I/Os and thus increase performance.

#### some writes are avoided altogether
\
by delaying them;
if an application creates a ﬁle and then deletes it,
delaying the writes to reﬂect the ﬁle creation to disk avoids them entirely.

#### trade-off:
\
if the system crashes before the updates have been propagated to disk, the updates are lost;
by keeping writes in memory longer, performance can be improved by batching, scheduling, and even avoiding writes.


#### Some applications (such as databases) don’t enjoy this trade-off.
\
Thus, to avoid unexpected data loss due to write buffering, they simply force writes to disk,
or by using the raw disk interface and avoiding the ﬁle system altogether2.
