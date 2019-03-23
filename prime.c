#include "prime.h"

int is_prime(int n)
{
	int nenner = 2;
	while (nenner*nenner <= n)
	{
		if(0==n%nenner)
		{
			return 0;
		}
		nenner++;
	}
	if(n<2)
	{
		return 0;
	}
	return 1;
}

int next_prime(int m)
{
	if(m<2){ return 2; }
	if(m%2==0)
	{
		m--;
	}

	do
	{
		m += 2;
	}
	while(!is_prime(m));

	return m;
}

int next_prime_unsafe(int m)
{
	do
	{
		m += 2;
	}
	while(!is_prime(m));

	return m;
}
