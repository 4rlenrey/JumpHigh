CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -g -Wall
CODE_LOCATION = Code
INCLUDES = -I Code/

OBJ =\
	${CODE_LOCATION}/*.cpp\
	${CODE_LOCATION}/*/*.cpp


all: main

clean:
	@echo Deleting files
	@rm -f *.o ${CODE_LOCATION}/*.o ${CODE_LOCATION}/*/*.o

.c.o:
	$(CC) -g -c $(INCLUDES) $(FLAGS) $<

main: $(OBJ)
	$(CC) -g $(OBJ) $(LIBS) $(INCLUDES) -pthread -std=c++11  -o JumpHigh
	make clean
