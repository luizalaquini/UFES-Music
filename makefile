all:
	gcc -c *.c
	gcc -o luiza *.o
	./luiza
	rm -rf *.o luiza
