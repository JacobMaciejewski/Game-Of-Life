#some name types for readable make file
OB = main.o GOL_SIMPLE.o
HEADERS = GOL_SIMPLE.h
EXEC = gol_simple
COMP = gcc
FLAGS = -g -Wall -c 
#executable
all: gol_simple

gol_simple: $(OB)
	$(COMP) -g $(OB) -o $(EXEC) -lm

main.o: main.c $(HEADERS)
	$(COMP) $(FLAGS) main.c 
	   
GOL_SIMPLE.o: GOL_SIMPLE.c GOL_SIMPLE.h
	$(COMP) $(FLAGS) GOL_SIMPLE.c
	
#  cleaning command
clean :
	rm -f $(OB) $(EXEC)
