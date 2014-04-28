# [Han Chen CS-541]
# [2/1/2014]
CC=gcc
CFLAGS=-Wall -g -O0
PROGS=hello cmdline

all: $(PROGS) 

hello: hello.c
	$(CC) -o hello hello.c $(CFLAGS)

cmdline: cmdline.c
	$(CC) -o cmdline cmdline.c $(CFLAGS)

clean:
	$(RM) $(PROGS)
	$(RM) -rf *.o *.dSYM