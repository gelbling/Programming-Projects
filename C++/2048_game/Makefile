# Email: gelbling@nd.edu
# File Name: Makefile
# Date Created: 02/24/2022
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
$(OBJ)/game.o: $(SRC)/game.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/game.cpp -o $@
$(OBJ)/PC04.o: $(SRC)/PC04.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/PC04.cpp -o $@
# Singly Linked List Objects
PC04_objs := $(OBJ)/game.o $(OBJ)/PC04.o
# Singly Linked List Executable and Run
PC04: $(PC04_objs)
	$(CC) $(CXXFLAGS) -o $(EXE)/PC04 $(PC04_objs)
# Make Clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*