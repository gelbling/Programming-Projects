# Email: gelbling@nd.edu
# File Name: Makefile
# Date Created: 01/27/2022
# File Contents: This is the Makefile for compilation of the rotations program

# gcc is for the compiler for C
PP := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe

# Initialize the folders for the objects and executables
initialize:
	mkdir $(OBJ) $(EXE)

# Create the Singly Linked List Object
$(OBJ)/rotations.o: $(SRC)/rotations.c
	$(PP) $(CFLAGS) -c $(SRC)/rotations.c -o $@

$(OBJ)/PC01.o: $(SRC)/PC01.c
	$(PP) $(CFLAGS) -c $(SRC)/PC01.c -o $@

# Singly Linked List Objects
PC01_objs := $(OBJ)/rotations.o $(OBJ)/PC01.o

# Singly Linked List Executable and Run
PC01: $(PC01_objs)
	$(PP) $(CFLAGS) -o $(EXE)/PC01 $(PC01_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*