FLAGS = -std=c89 -Wall -Wextra
LIBS = -lcurl
WD := $(shell pwd)
OBJ := $(WD)/obj
SRC := $(WD)/src

all: $(SRC)/tdl.c $(SRC)/cmd.c $(SRC)/cmd.h $(SRC)/signals.c $(SRC)/signals.h $(SRC)/types.h
	cc $(FLAGS) $(LIBS) -c $(SRC)/cmd.c -o $(OBJ)/cmd.o
	cc $(FLAGS) $(LIBS) -c $(SRC)/tdl.c -o $(OBJ)/tdl.o
	cc $(FLAGS) $(LIBS) -c $(SRC)/signals.c -o $(OBJ)/signals.o
	cc $(OBJ)/cmd.o $(OBJ)/tdl.o $(OBJ)/signals.o -o $(WD)/tdl.out

obj: $(SRC)/tdl.c $(SRC)/cmd.c $(SRC)/cmd.h
	cc $(FLAGS) $(LIBS) -c $(SRC)/cmd.c -o $(OBJ)/cmd.o
	cc $(FLAGS) $(LIBS) -c $(SRC)/tdl.c -o $(OBJ)/tdl.o
	cc $(FLAGS) $(LIBS) -c $(SRC)/signals.c -o $(OBJ)/signals.o

clean: $(OBJ)/tdl.o $(OBJ)/cmd.o
	rm $(OBJ)/*
	rm $(WD)/*.out
