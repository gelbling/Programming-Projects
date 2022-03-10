# Email: gelbling@nd.edu
# File Name: Makefile
# Date Created: 02/17/2022
# File Contents: This is the Makefile for compilation

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
$(OBJ)/fenwick.o: $(SRC)/fenwick.c
	$(PP) $(CFLAGS) -c $(SRC)/fenwick.c -o $@

$(OBJ)/PC03.o: $(SRC)/PC03.c
	$(PP) $(CFLAGS) -c $(SRC)/PC03.c -o $@

# Singly Linked List Objects
PC03_objs := $(OBJ)/fenwick.o $(OBJ)/PC03.o

# Singly Linked List Executable and Run
PC03: $(PC03_objs)
	$(PP) $(CFLAGS) -o $(EXE)/PC03 $(PC03_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*