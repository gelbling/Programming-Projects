# Email: gelbling@nd.edu
# File Name: Makefile
# Date Created: 03/03/2022
# File Contents: This is the Makefile for compilation
# -----------------------------------------------------------

# This is the Makefile for Programming Challenge 04
# g++ is for the GCC compiler for C++
CC := g++
# CFLAGS are the compiler flags for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 $(FLAGS)
# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# Make initialize - Create the objects and executables

initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

$(OBJ)/sudoku.o: $(SRC)/sudoku.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/sudoku.cpp -o $@
$(OBJ)/PC05.o: $(SRC)/PC05.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/PC05.cpp -o $@
# Singly Linked List Objects
PC05_objs := $(OBJ)/sudoku.o $(OBJ)/PC05.o
# Singly Linked List Executable and Run
PC05: $(PC05_objs)
	$(CC) $(CXXFLAGS) -o $(EXE)/PC05 $(PC05_objs)
# Make Clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*