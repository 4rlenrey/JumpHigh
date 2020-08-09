CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm
FLAGS = -g -Wall
CODE_LOCATION = Code
INCLUDES = -I Code/

CPP =\
	${CODE_LOCATION}/*.cpp\
	${CODE_LOCATION}/*/*.cpp

all: main

clean:
	@echo Deleting files
	@rm -f *.o ${CODE_LOCATION}/*.o ${CODE_LOCATION}/*/*.o

compile:
	$(CC) -g -c $(CPP) $(INCLUDES) $(FLAGS) $<

main: $(CPP)
	$(CC) -g $(CPP) $(LIBS) $(INCLUDES) -pthread -std=c++11  -o JumpHigh
	make clean
