CC = gcc
CFLAGS = -c -g -Wall

all: first 
first: first.o
first.o: first.c


