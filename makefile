CC=gcc
sdl2=$(shell sdl2-config --libs --cflags)
obs=main.c
out=spacegame
CFLAGS=$(sdl2) -o $(out)

all: $(obs)
	$(CC) $(CFLAGS) $(obs)

.PHONY: clean tidy

clean:
	-rm $(obs) $(out)

tidy:
	-rm $(obs)
