CC=gcc
sdl2=$(shell sdl2-config --libs --cflags)
obs=base.o main.o
out=spacegame
CFLAGS=-lm -Iinclude $(sdl2)

all : $(obs)
	$(CC) $(obs) -o $(out)  $(CFLAGS)

main.o : base.o

.PHONY : clean tidy

clean :
	-rm $(obs) $(out)

tidy :
	-rm $(obs)
