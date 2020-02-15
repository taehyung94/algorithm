#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>

int reverse(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum = ((sum * 10) + x % 10);
		x /= 10;
	}
	return sum;
}


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
	int data[100] = {};
	scanf("%d", &n);
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		x = reverse(x);
		if (isPrime(x))
		{
			data[index++] = x;
		}
	}
	for (int i = 0; i < index; i++)
		printf("%d ", data[i]);
	return 0;
}