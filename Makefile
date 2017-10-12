FLAGS = -g -std=c89 -Wall -Wextra
LIBS = -lcurl
CFILES = src/tdl.c src/cmd.c src/signals.c
OFILES = obj/tdl.o obj/cmd.o src/signals.o
CC = gcc

all: $(CFILES)
	$(CC) $(FLAGS) $(LIBS) -c src/cmd.c -o obj/cmd.o
	$(CC) $(FLAGS) $(LIBS) -c src/tdl.c -o obj/tdl.o
	$(CC) $(FLAGS) $(LIBS) -c src/signals.c -o obj/signals.o
	$(CC) obj/cmd.o obj/tdl.o obj/signals.o -o tdl.out

obj: $(OFILES)
	$(CC) $(FLAGS) $(LIBS) -c src/cmd.c -o obj/cmd.o
	$(CC) $(FLAGS) $(LIBS) -c src/tdl.c -o obj/tdl.o
	$(CC) $(FLAGS) $(LIBS) -c src/signals.c -o obj/signals.o

clean: $(OFILES)
	rm obj/*
	rm *.out
