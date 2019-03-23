all: printPrime test
printPrime.o: primenum2.c prime.h
	cc -Wall -o printPrime.o -c -fPIC primenum2.c
printPrime: printPrime.o prime.o
	cc -Wall -o printPrime primenum2Start.c printPrime.o prime.o
musstdirwasausdenken: prime.o primenum2.c
	cc -Wall -o musstdirwasausdenken primenum2.c prime.o
prime.o:  prime.c prime.h
	cc -Wall -o prime.o -c -fPIC prime.c
clean::
	rm -f prime.o printPrime.o printPrime test
test: primenum2.o test.c
	cc -Wall -o test primenum2.o prime.o test.c	
