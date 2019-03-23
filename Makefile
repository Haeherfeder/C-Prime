all: printPrime test
printPrime.o: primenum2.c prime.h
	cc -Wall -o printPrime.o -c -fPIC primenum2.c
printPrime: printPrime.o prime.o primenum2Start.c
	cc -Wall -o printPrime primenum2Start.c printPrime.o prime.o
prime.o:  prime.c prime.h
	cc -Wall -o prime.o -c -fPIC prime.c
primenum2.o: primenum2.c primenum2.h prime.o
	cc -Wall -o primenum2.o -c -fPIC primenum2.c
clean::
	rm -f prime.o printPrime.o primenum2.o printPrime test
test: primenum2.o prime.o test.c
	cc -Wall -o test primenum2.o prime.o test.c	
