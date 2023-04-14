CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic

all: hsh

hsh: *.c
	$(CC) $(CFLAGS) $^ -o $@

run:
	./hsh

clean:
	rm hsh
