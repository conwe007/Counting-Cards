CC = g++

OBJS = ./src/main.cpp
INCS = -Iinclude
COMPILER_FLAGS = -lm

OBJ_NAME = main

all : $(OBJS)
	$(CC) $(OBJS) $(INCS) $(COMPILER_FLAGS) -o $(OBJ_NAME)

clean :
	rm $(OBJ_NAME)
 
 .PHONY: clean