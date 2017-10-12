FLAGS = -g -std=c89 -Wall -Wextra
LIBS = -lcurl

all: src/tdl.c src/cmd.c src/cmd.h src/signals.c src/signals.h src/types.h
	cc $(FLAGS) $(LIBS) -c src/cmd.c -o obj/cmd.o
	cc $(FLAGS) $(LIBS) -c src/tdl.c -o obj/tdl.o
	cc $(FLAGS) $(LIBS) -c src/signals.c -o obj/signals.o
	cc obj/cmd.o obj/tdl.o obj/signals.o -o obj/tdl.out

obj: src/tdl.c src/cmd.c src/cmd.h
	cc $(FLAGS) $(LIBS) -c src/cmd.c -o obj/cmd.o
	cc $(FLAGS) $(LIBS) -c src/tdl.c -o obj/tdl.o
	cc $(FLAGS) $(LIBS) -c src/signals.c -o obj/signals.o

clean: obj/tdl.o obj/cmd.o
	rm obj/*
	rm *.out
