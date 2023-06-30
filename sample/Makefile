CC=gcc
type=
CFLAGS=-Wall -O3

all: app

app:
ifeq ($(type),weak)
	$(CC) $(CFLAGS) -s main.c -ldl -D WEAK_LOAD -o execve
else
	$(CC) $(CFLAGS) -s main.c -I../src -L../src -lload -Wl,-rpath=../src -o execve
endif

clean:
	rm -rf execve
