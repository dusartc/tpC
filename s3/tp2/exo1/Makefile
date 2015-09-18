.PHONY : clean

CC = gcc
W = -W -Wall -Werror
STD = -std=c99
E = exo1

$(E) : main.o $(E)_1.o $(E)_2.o $(E)_3.o $(E)_4.o 
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(W) $(STD) -c $^

clean:
	rm -rf *.o
