#ifndef GOL_SIMPLE
#define GOL_SIMPLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>

void getArguments(int, char**, int*, int*, int*);
void initializeArrays(char*** , char***, int, int);
void initializeEnvironment(char** , int, int);
void produceNextPlain(char**, char**, int, int);
void swapPlains(char*** , char ***);
int getNumOfNeighbours(char**, int, int, int, int);
int updateState(char**, int, int, int);
bool plainsDifferent(int, int, char**, char**);
void freeArrays(char**, char**, int, int);
double calculateTime(struct timeval, struct timeval);
void printPlain(char **, int, int);

#endif
