CC = gcc
CFLAGS = -g -Wall

all: $(patsubst %.c, %.out, $(wildcard *.c))

%.out: %.c Makefile
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.out

