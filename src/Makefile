CC = gcc
CFLAGS = -Wall -O3

all: libload.so libmtype.so

libload.so:
	$(CC) $(CFLAGS) -fPIC -shared loader.c -o libload.so

libmtype.so:
	$(CC) $(CFLAGS) -fPIC -I. -lload -Wl,-rpath=. -shared set_mtype.c -o libmtype.so

clean:
	rm -rf libmtype.so libload.so
