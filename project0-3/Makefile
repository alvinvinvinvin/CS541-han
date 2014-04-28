#
# [Han Chen]
# [2/7/2014]
#
CC=gcc
CFLAGS=-Wall -g -O0 -lm

PROGS=finput calc


all: $(PROGS)


finput: finput.c support.h
	$(CC) -o finput finput.c $(CFLAGS)

calc: calc.c support.h
	$(CC) -o calc calc.c $(CFLAGS)

clean:
	$(RM) $(PROGS)
	$(RM) -rf *.o *.dSYM
