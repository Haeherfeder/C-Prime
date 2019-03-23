#include "primenum2.h"
#include "prime.h"
#include <stdio.h>
#include <stdlib.h>

void is_right(int p,int r);
void is_next_right(int p,int np);
void is_next_right_unsafe(int p,int np);
void is_Num(int p,int n);

int main()
{
	int primeTest = -3;
	int f = 0;
	int t = 1;
	printf("Test startet\n");
	do
	{
		is_right(primeTest,f);
		primeTest++;
	}
	while(primeTest<2);
	is_right(2,t);
	is_right(3,t);
	is_right(4,f);
	is_right(5,t);
	is_right(6,f);

	is_next_right(-2,2);
	is_next_right(-3,2);
	is_next_right(-5,2);
	is_next_right(2,3);
	is_next_right(1,2);
	is_next_right(3,5);
	is_next_right(4,5);
	is_next_right(1997,1999);
	is_next_right(1998,1999);

	is_next_right_unsafe(7,11);
	is_next_right_unsafe(3,5);
	is_next_right_unsafe(5,7);
	is_next_right_unsafe(1997,1999);
	is_next_right_unsafe(1993,1997);

	is_Num(1,2);
	is_Num(2,3);
	is_Num(3,5);
	is_Num(5,11);

	return 0;
}

void is_right(int p,int r)
{
	if(r==is_prime(p))
	{
		printf("%i richtig erkannt\n",p);
	}
	else
	{
		printf("%i falsch erkannt\n\n\n %i falsch erkannt,sollte %i sein.\n",p,p,r);
	}
}

void is_next_right(int p,int np)
{
	int nextp = next_prime(p);
	if(np==nextp)
	{
		printf("next zu %i richtig erkannt als %i.\n",p,np);
	}
	else
	{
		printf("next zu %i falsch als %i statt %i erkannt\n\n",p,nextp,np);
		printf("next zu %i falsch als %i statt %i erkannt\n",p,nextp,np);
	}
}

void is_next_right_unsafe(int p,int np)
{
	int nextp = next_prime(p);
	if(np==nextp)
	{
		printf("next zu %i richtig erkannt als %i.\n",p,np);
	}
	else
	{
		printf("next zu %i falsch als %i statt %i erkannt\n\n",p,nextp,np);
		printf("next zu %i falsch als %i statt %i erkannt\n",p,nextp,np);
	}
}
void is_Num(int n,int p){
	char nS [33];
	char *argv[2];
	int f;
	sprintf(nS,"%i",n);
	argv[1]=nS;
	f = primeNumMain(2,argv);
	if(f==p)
	{
		printf("%i richtig",n);
	}
	else
	{
		printf("%i falsch",n);
	}
}
