#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>


bool isPrime(int x)
{
	if (x == 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isPrime(i))
			count++;
	}
	printf("%d\n", count);
	return 0;
}