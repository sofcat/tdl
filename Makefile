FLAGS = -g -std=c89 -Wall -Wextra
LIBS = -lcurl
CFILES = src/tdl.c src/cmd.c src/signals.c src/parse.c src/builtins.c
OFILES = obj/tdl.o obj/cmd.o obj/signals.o obj/parse.o obj/builtins.o
CC = gcc

all: $(CFILES)
	$(CC) $(FLAGS) $(LIBS) -c src/cmd.c -o obj/cmd.o
	$(CC) $(FLAGS) $(LIBS) -c src/signals.c -o obj/signals.o
	$(CC) $(FLAGS) $(LIBS) -c src/parse.c -o obj/parse.o
	$(CC) $(FLAGS) $(LIBS) -c src/builtins.c -o obj/builtins.o
	$(CC) $(FLAGS) $(LIBS) -c src/tdl.c -o obj/tdl.o
	$(CC) obj/cmd.o obj/tdl.o obj/signals.o -o tdl.out

obj: $(OFILES)
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
