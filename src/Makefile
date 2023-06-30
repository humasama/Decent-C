CC = gcc
type=
CFLAGS = -Wall -O3

all: libload.so libmtype.so

libload.so:
ifeq ($(type),weak)
	$(CC) $(CFLAGS) -fPIC -D WEAK_LOAD -shared loader.c -o libload.so
else
	$(CC) $(CFLAGS) -fPIC -shared loader.c -o libload.so
endif

libmtype.so:
	$(CC) $(CFLAGS) -fPIC -I. -lload -Wl,-rpath=. -shared set_mtype.c -o libmtype.so

clean:
	rm -rf libmtype.so libload.so
