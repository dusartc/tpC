.PHONY: clean
SRC=$(wildcard *.c)
JOBS=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -W -Werror 

all: prog

makefile.dep: $(SRC)
	$(CC) -MM $(CFLAGS) -std=c99 *.c $^ > $@

prog: $(JOBS)
	$(CC) --std=c99 -o $@ $^

include makefile.dep

clean:
	rm -f *.o
