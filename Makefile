CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -g -Wall

OBJ =\
	game/*.cpp

all: main

clean:
	@echo Deleting files
	@rm -f *.o game/*.o

.c.o:
	$(CC) -g -c $(INCLUDES) $(FLAGS) $<

main: $(OBJ)
	$(CC) -g $(OBJ) $(LIBS) -pthread -std=c++11  -o JumpHigh
