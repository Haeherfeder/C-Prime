all: print_nth_prime test
print_nth_prime.o: nth_prime_prog.c prime.h
	cc -Wall -o print_nth_prime.o -c -fPIC nth_prime_prog.c
print_nth_prime: print_nth_prime.o prime.o nth_prime_prog_start.c
	cc -Wall -o print_nth_prime nth_prime_prog_start.c print_nth_prime.o prime.o
prime.o:  prime.c prime.h
	cc -Wall -o prime.o -c -fPIC prime.c
nth_prime_prog.o: nth_prime_prog.c nth_prime_prog.h prime.o
	cc -Wall -o nth_prime_prog.o -c -fPIC nth_prime_prog.c
clean::
	rm -f prime.o print_nth_prime.o nth_prime_prog.o print_nth_prime test
test: nth_prime_prog.o prime.o test.c
	cc -Wall -o test nth_prime_prog.o prime.o test.c	
