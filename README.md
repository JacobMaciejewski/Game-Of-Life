# Game-of-Life
Implementation of [Conway's Game Of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), bench-marking a variety of parallelization approaches
</br>

## Game Of Life Definition & Rules:

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead. Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1.  Any alive cell with fewer than two alive neighbours dies (underpopulation)
2.  Any alive cell with two or three alive neighbours lives on to the next generation.
3.  Any alive cell with more than three alive neighbours dies (overpopulation)
4.  Any dead cell with exactly three live neighbours becomes a live cell (reproduction)

**Rules simplified:**

1.  Any alive cell with two or three live neighbours survives
2.  Any dead cell with three alive neighbours becomes an alive cell
3.  Other alive cells die in the next generation, other dead cells remain dead

## From iterative to parallel approach:

We start with a randomly initialized `N x N` binary array (Grid). Specified percentage of cells start alive.
User can specify the dimensionality (`rows (N)` and `columns (N)`) of the Grid, as well as the `iterations` of the game.

One can easily infer the time complexity of Grid's states update is $O(N^2)$ in each iteration, meaning that even a small increase in the size of the grid can lead to a **dramatic increase** of execution time.

Initially, we were granted permission to access ARGO super-computer (equipped with 64 cores and 2 powerful GPUs).
In order to take full advantage of such a powerful resource,we decided to tackle the execution time issue by implementing a parallelized instance of the initial program.
We implemented 3 different versions of Game Of Life, exploiting the usage of the [MPI](https://en.wikipedia.org/wiki/Message_Passing_Interface), [OpenMP](https://en.wikipedia.org/wiki/OpenMP), and [CUDA](https://en.wikipedia.org/wiki/CUDA) to take advantage of GPU's cores.  

## Compilation & Execution:

*   __SIMPLE__: Contains the iterative implementation of GOL, used the explore the limitations of single core architecture. To compile and run the program, type: `make` , and then `./main <rows> <columns> <iterations>`.  

*   __MPI__: Contains the parallelized version of the initial version of GOL, using the MPI library. Compilation is done by typing: `make`. Execution gets more complicated, we have to add our program to the execution queue
(ARGO can take several requests from those that are authorized to use her resources), by typing: `qsub myPBSScript.sh` . This script contains information about the execution environment of our program.
It can be edited to specify a number of nodes and processes per core that will be used. </br>
Once GOL terminates, 2 files are reproduced: __myJob.o*****__ and __myJob.e*****__ .The __myJob.o*__ file contains the output of our program. __myJob.e*__ contains potential error messages (used for debugging).

*   __OPENMP__ and __CUDA__: Same approach followed as in MPI 

### Further informations

readMe.pdf file contains an extensive analysis of the different implementations, though process, results of different experiments and interesting
conclusions about the pros and cons of parallel programming.

For this big project, I've collaborated with the fellow partner: [Dimitrios Foteinos](https://github.com/dfwteinos)

*This project is part of the course: Parallel Systems , Winter of 2019. University of Athens, DiT.*
