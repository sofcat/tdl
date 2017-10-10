FLAGS = -Wall -Wextra
LIBS = -lcurl
WD := $(shell pwd)
OBJ := $(WD)/obj
SRCDIR := $(WD)/src

all: $(SRCDIR)/tdl.c $(SRCDIR)/cmd.c $(SRCDIR)/cmd.h $(SRCDIR)/signals.c $(SRCDIR)/signals.h
	cc $(FLAGS) $(LIBS) -c $(SRCDIR)/cmd.c -o $(OBJ)/cmd.o
	cc $(FLAGS) $(LIBS) -c $(SRCDIR)/tdl.c -o $(OBJ)/tdl.o
	cc $(FLAGS) $(LIBS) -c $(SRCDIR)/signals.c -o $(OBJ)/signals.o
	cc $(OBJ)/cmd.o $(OBJ)/tdl.o $(OBJ)/signals.o -o $(WD)/tdl

obj: $(SRCDIR)/tdl.c $(SRCDIR)/cmd.c $(SRCDIR)/cmd.h
	cc $(FLAGS) $(LIBS) -c $(SRCDIR)/cmd.c -o $(OBJ)/cmd.o
	cc $(FLAGS) $(LIBS) -c $(SRCDIR)/tdl.c -o $(OBJ)/tdl.o
	cc $(FLAGS) $(LIBS) -c $(SRCDIR)/signals.c -o $(OBJ)/signals.o

clean: $(OBJ)/tdl.o $(OBJ)/cmd.o
	rm $(OBJ)/*
