.PHONY: clean
SRC=$(wildcard *.c)
JOBS= $(SRC:.c = .o)
CC = gcc
CFLAG = -Wall -W -Werror 

all: prog

makefile.dep: $(SRC)
	$(CC) -MM $(CFLAG) *.c $^ > $@

prog: $(JOBS)
	$(CC) -o $@ $^

include makefile.dep

clean:
	rm -f *.o
