CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm -lstdc++fs
FLAGS = -g -Wall
CODE_LOCATION = Code
TESTS_LOCATION = Tests
INCLUDES = -I Code/

CPP =\
	${CODE_LOCATION}/*.cpp\
	${CODE_LOCATION}/*/*.cpp

InputTest = ${TESTS_LOCATION}/InputTest.cpp
InputTest_Code = $(CODE_LOCATION)/Input/Input.cpp

all: main

clean:
	@echo Deleting files
	@rm -f *.o ${CODE_LOCATION}/*.o ${CODE_LOCATION}/*/*.o

compile:
	$(CC) -g -c $(CPP) $(INCLUDES) $(FLAGS) $<

main: $(CPP)
	$(CC) -g $(CPP) $(LIBS) $(INCLUDES) -pthread -std=c++17 -o JumpHigh
	make clean

input:
	$(CC) -g ${InputTest} ${InputTest_Code} $(LIBS) $(INCLUDES) -o InputTest