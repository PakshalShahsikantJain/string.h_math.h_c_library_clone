CC = gcc

all: app libmystring.so String.o libmymath.so Math.o
app:
	$(CC) Client.c -o app

libmystring.so: String.o
	$(CC) -shared -o libmystring.so String.o

String.o: String.c String.h
	$(CC) -c -fPIC String.c -o String.o

libmymath.so: Math.o
	$(CC) -shared -o libmymath.so Math.o

Math.o:	Math.c Math.h
	$(CC) -c -fPIC Math.c -o Math.o

run:
	./app
	
clean:		
	rm -f app *.o

.PHONY: run clean