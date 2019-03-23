#include <stdlib.h>
#include <stdio.h>
#include "prime.h"

int primeNumMain(int argc,char **argv)
{
	int p = 1;
	int count = atoi(argv[1]);
	p = next_prime(p);
	count--;

	if(!count)
	{
		printf("%i\n",p);
		return p;
	}
	p = next_prime(p);
	count--;

	if(!count)
	{
		printf("%i\n",p);
		return p;
	}

	while(count--)
	{
		p = next_prime_unsafe(p);		
	}

	printf("%i\n",p);
	return p;
}
