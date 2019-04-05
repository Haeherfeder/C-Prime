#include "nth_prime_prog.h"
#include "prime.h"
#include <stdio.h>
#include <stdlib.h>

void is_prime_test(int p, int r);
void is_next_test(int p, int np);
void is_next_unsafe_test(int p, int np);
void nth_prime_prog_test(int n, int p);


int main()
{
	int primeTest = -3;
	int f = 0;
	int t = 1;
	printf("Test startet\n");

	do
	{
		is_prime_test(primeTest, f);
		primeTest++;
	}
	while (primeTest < 2);

	is_prime_test(2, t);
	is_prime_test(3, t);
	is_prime_test(4, f);
	is_prime_test(5, t);
	is_prime_test(6, f);
	is_prime_test(341, f);
	is_prime_test(561, f);
	is_prime_test(271441, f);
	is_prime_test(2251, t);

	is_next_test(-2, 2);
	is_next_test(-3, 2);
	is_next_test(-5, 2);
	is_next_test(2, 3);
	is_next_test(1, 2);
	is_next_test(3, 5);
	is_next_test(4, 5);
	is_next_test(1997, 1999);
	is_next_test(1998, 1999);

	is_next_unsafe_test(7, 11);
	is_next_unsafe_test(3, 5);
	is_next_unsafe_test(5, 7);
	is_next_unsafe_test(1997, 1999);
	is_next_unsafe_test(1993, 1997);

	nth_prime_prog_test(1, 2);
	nth_prime_prog_test(2, 3);
	nth_prime_prog_test(3, 5);
	nth_prime_prog_test(5, 11);
	nth_prime_prog_test(100, 541);
	printf("unsafe Tests Startet\n");	
	is_prime_test(25326001, f);
	is_prime_test(2147483647, f);
	nth_prime_prog_test(0, 0);
	nth_prime_prog_test(-1, 0);
	printf("Test finished\n");
	return 0;
}

void is_prime_test(int p,int r)
{
	if(r == is_prime(p))
	{
		printf("%i richtig erkannt\n", p);
	}
	else
	{
		printf("%i falsch erkannt\n\n\n %i falsch erkannt,sollte %i sein.\n", p, p, r);
	}
}

void is_next_test(int p, int np)
{
	int nextp = next_prime(p);

	if(np == nextp)
	{
		printf("next zu %i richtig erkannt als %i.\n", p, np);
	}
	else
	{
		printf("next zu %i falsch als %i statt %i erkannt\n\n", p, nextp, np);
		printf("next zu %i falsch als %i statt %i erkannt\n", p, nextp, np);
	}
}

void is_next_unsafe_test(int p, int np)
{
	int nextp = next_prime(p);

	if(np == nextp)
	{
		printf("next zu %i richtig erkannt als %i.\n", p, np);
	}
	else
	{
		printf("next zu %i falsch als %i statt %i erkannt\n\n", p, nextp, np);
		printf("next zu %i falsch als %i statt %i erkannt\n", p, nextp, np);
	}
}

void nth_prime_prog_test(int n, int p)
{
	// Erzeuge char-array
	char nS [33];

	// Erzeuge Speicheradressen
	char *argv[2];

	// Integer zum Speichern des Rückgabewertes von nth_prime_prog(...)
	int nth_prime;

	// Konvertiere Zahl n in einen char-array und kopiere das Ergebnis in den char-array nS
	sprintf(nS, "%i", n);

	// Verwende erste Speicheradresse des char-arrays nS als zweites Argument von argv
	argv[1] = nS;

	// Weise nth_prime den Rückgabewert von nth_prime_prog zu
	// nth_prime_prog werden "2" Argumente und "indirekt" die Speicheradresse des char-arrays nS übergeben
	nth_prime = nth_prime_prog(2, argv);

	// Wenn nth_prime gleich p, dann wurde p als n-te Primezahl korrekt berechnet
	if(nth_prime == p)
	{
		printf("%i richtig\n", n);
	}
	else
	{
		printf("%i falsch als %i \n", n, nth_prime);
	}
}
