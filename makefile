CC = gcc
CFLAGS = -g -Wall

all: project

clean:
	rm -f *.o project project1

project: project1.c
	$(CC) $(CFLAGS) project1.c -o project
