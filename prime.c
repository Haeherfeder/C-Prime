#include "prime.h"

int is_prime(int n)
{
	int divisor = 2;
	while (divisor*divisor <= n)
	{
		if (0==n%divisor)
		{
			return 0;
		}
		divisor++;
	}
	if (n<2)
	{
		return 0;
	}
	return 1;
}

int next_prime(int m)
{
	if (m<2) { return 2; }
	if (m%2==0) { m--; }

	do { m += 2; }
	while (!is_prime(m));

	return m;
}

int next_prime_unsafe(int m)
{
	do { m += 2; }
	while (!is_prime(m));

	return m;
}
