CC=gcc
LDFLAGS=-pthread
OBJS=v1.o v2.o hw2.o function.o
EXEC= v1 v2 
CFLAGS = -std=c99  #if you have CFLAGS you do not have to write for each file $(CC) -c $*.c!!!

all: $(EXEC)

v1: v1.o hw2.o function.o
	$(CC) -o $@ $(LDFLAGS) $^

v2: v2.o hw2.o function.o
	$(CC) -o $@ $(LDFLAGS) $^


v1.c: hw2.h function.h
v2.c: hw2.h function.h
hw2.c: hw2.h function.h
function.c: function.h

clean: 
	rm -f $(EXEC) $(OBJS)


	

