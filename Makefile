FLAGS = -g -std=c89 -Wall -Wextra
LIBS = -lcurl
OFILES = obj/cmd.o obj/signals.o obj/parse.o obj/builtins.o obj/tdl.o 
BDIR = src/builtins
CFILES = src/tdl.c src/cmd.c src/signals.c src/parse.c
HFILES = src/cmd.h src/signals.h src/parse.h $(BDIR)/builtins.h
BFILES = $(BDIR)/builtins.h $(BDIR)/builtins.c
CC = gcc

all: $(CFILES) $(HFILES) $(BFILES)
	$(CC) $(FLAGS) $(LIBS) -c src/cmd.c -o obj/cmd.o
	$(CC) $(FLAGS) $(LIBS) -c src/signals.c -o obj/signals.o
	$(CC) $(FLAGS) $(LIBS) -c src/parse.c -o obj/parse.o
	$(CC) $(FLAGS) $(LIBS) -c $(BDIR)/builtins.c
	$(CC) $(FLAGS) $(LIBS) -c src/tdl.c -o obj/tdl.o
	$(CC) $(OFILES) -o tdl.out

object: $(CFILES) $(HFILES)
	$(CC) $(FLAGS) $(LIBS) -c src/cmd.c -o obj/cmd.o
	$(CC) $(FLAGS) $(LIBS) -c src/signals.c -o obj/signals.o
	$(CC) $(FLAGS) $(LIBS) -c src/parse.c -o obj/parse.o
	$(CC) $(FLAGS) $(LIBS) -c src/builtins.c -o obj/builtins.o
	$(CC) $(FLAGS) $(LIBS) -c src/tdl.c -o obj/tdl.o

bin: $(OFILES)
	$(CC) $(OFILES) -o tdl.out

clean: $(OFILES)
	rm obj/*
	rm *.out
