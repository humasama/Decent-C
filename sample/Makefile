CC=gcc
CFLAGS=-Wall -O3

all:
	$(CC) $(CFLAGS) -s main.c -I../src -L../src -lload -Wl,-rpath=../src -o execve

clean:
	rm -rf execve
