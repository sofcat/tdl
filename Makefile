FLAGS = -g -std=c89 -Wall -Wextra
LIBS = -lcurl
BDIR = src/builtins
CFILES = src/tdl.c src/cmd.c src/signals.c src/parse.c
HFILES = src/cmd.h src/signals.h src/parse.h $(BDIR)/builtins.h
OFILES = obj/cmd.o obj/signals.o obj/parse.o obj/help.o obj/echo.o obj/set.o obj/builtins.o obj/tdl.o 
BFILES = $(BDIR)/builtins.h $(BDIR)/builtins.c
CC = gcc

all: $(CFILES) $(HFILES) $(BFILES)
	$(CC) $(FLAGS) $(LIBS) -c src/cmd.c -o obj/cmd.o
	$(CC) $(FLAGS) $(LIBS) -c src/signals.c -o obj/signals.o
	$(CC) $(FLAGS) $(LIBS) -c src/parse.c -o obj/parse.o
	$(CC) $(FLAGS) $(LIBS) -c $(BDIR)/help.c -o obj/help.o
	$(CC) $(FLAGS) $(LIBS) -c $(BDIR)/echo.c -o obj/echo.o
	$(CC) $(FLAGS) $(LIBS) -c $(BDIR)/set.c -o obj/set.o
	$(CC) $(FLAGS) $(LIBS) -c $(BDIR)/builtins.c -o obj/builtins.o
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
