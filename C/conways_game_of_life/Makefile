# Email: gelbling@nd.edu
# File Name: Makefile
# Date Created: 02/03/2022
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
$(OBJ)/life.o: $(SRC)/life.c
	$(PP) $(CFLAGS) -c $(SRC)/life.c -o $@

$(OBJ)/PC02.o: $(SRC)/PC02.c
	$(PP) $(CFLAGS) -c $(SRC)/PC02.c -o $@

# Singly Linked List Objects
PC02_objs := $(OBJ)/life.o $(OBJ)/PC02.o

# Singly Linked List Executable and Run
PC02: $(PC02_objs)
	$(PP) $(CFLAGS) -o $(EXE)/PC02 $(PC02_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*