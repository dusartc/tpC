.PHONY: clean

.SUFFIXES:

CC = gcc
W = -Wall -W -Werror

clean:
	rm -rf *.o

tp1: tp1_1.o tp1_2.o tp1_3.o
	$(CC) -o tp1 tp1_1.o tp1_2.o tp1_3.o

%.o: %.c
	$(CC) $(W) -c -o $@ $^
