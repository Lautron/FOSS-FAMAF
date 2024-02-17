# Hard Disk Drives


## I/O Time: Doing The Math


### represent I/O time as the sum of three major components:

\
![6a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-disks/6a.png){ width=250px }


#### rate of I/O (RI/O),
\


is easily computed from the time.
Simply divide the size of the transfer by the time it took:

\
![7b](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-disks/7b.png){ width=250px }


### random workload.

#### Assuming
\
each 4 KB read occurs at a random location on disk, we can calculate how long each such read would take.

#### HDD specs
\
![7a](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-disks/7a.png){ width=250px }

#### On the Cheetah:
\

\
![7c](/home/lautarob/Documents/Facultad/año2/SistOp/final/temas-pdfs/file-disks/7c.png){ width=250px }


#### The average seek time
\
(4 milliseconds) is just taken as the average time reported by the manufacturer;


#### The average rotational delay
\
is calculated from the RPM directly.
15000 RPM is equal to 250 RPS
thus, each rotation takes 4 ms.

#### the transfer time
\
is just the size of the transfer over the peak transfer rate;
here it is vanishingly small (30 microseconds;

####  TI/O for the Cheetah
\
roughly equals 6 ms.

#### To compute the rate of I/O,
\
just divide the size of the transfer by the average time,
 RI/O for the Cheetah under the random workload of about 0.66 MB/s.
