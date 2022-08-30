#include "GOL_SIMPLE.h"

//main takes three arguments (rows, columns, iterations)
int main(int argc, char **argv){
  //we need three plains for updates
  char** currPlain;
  char** prevPlain;
  int iter, columns, rows, iterations;
  struct timeval stop, start;
  srand(time(NULL));

  //user didn't give us 3 arguments
  if(argc != 7)
  {
    printf("Wrong number of arguments. Proper form of input : -rw [rows] -cl [columns] -it [iterations]\n");
    return -1;
  }

  getArguments(argc, argv, &rows, &columns, &iterations);

  //our plain must be NxN and with positive coordinates
  if(rows != columns)
  {
    printf("Given dimensions are not NxN!\n");
    return -1;
  }else if(rows < 0 || columns < 0)
  {
    printf("Given dimensions are negative!\n");
    return -1;
  }

  //allocating memory for the subsequent plains
  initializeArrays(&currPlain, &prevPlain, rows, columns);
  //initializing previous plain in order to feed info to the current one
  initializeEnvironment(prevPlain, rows, columns);
  gettimeofday(&start, NULL);

  //repeating the given amount of iterations of the game
  for(iter = 0; iter < iterations; iter++)
  {
    //for each pixel of previous plain, updating the current one
    produceNextPlain(prevPlain, currPlain, rows, columns);

    //checking for plains equality for each 10 iterations
    if(iter % 10 == 0)
    {
      if(!plainsDifferent(rows, columns, prevPlain, currPlain))
      {
        break;
      }
    }

    swapPlains(&prevPlain, &currPlain);
  }

  gettimeofday(&stop, NULL);
  printf("Total time spent: %lf sec\n", calculateTime(start, stop));
  freeArrays(prevPlain, currPlain, rows, columns);
  return 0;
}
