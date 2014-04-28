# [Han Chen]
# [2/3/2014]
# [Project 0.2]

CC=gcc
CFLAGS=-Wall -g -O0
PROGS=input verify checker

all: $(PROGS)

input: input.c
	$(CC) -o input input.c $(CFLAGS)

verify: verify.c
	$(CC) -o verify verify.c $(CFLAGS)

checker: checker.c
	$(CC) -o checker checker.c $(CFLAGS)

clean:
	$(RM) $(PROGS)
	$(RM) -rf *.o *.dSYM