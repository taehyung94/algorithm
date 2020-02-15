#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;


bool isPrime(int x)
{
	if (x == 1)
		return false;
	for (int i = 2; i*i <= x; i++)
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
	vector<int> check(n + 1);
	for (int i = 2; i <= n; i++)
	{
		if (isPrime(i))
		{
			check[i]++;
		}
		else
		{
			int k = i;
			for (int j = 2; j <= k; j++)
			{
				if (isPrime(j))
				{
					while (k%j == 0)
					{
						check[j]++;
						k /= j;
					}
				}
			}
		}
	}
	printf("%d! = ", n);
	for (int i = 2; i <= n; i++)
	{
		if (check[i])
			printf("%d ", check[i]);
	}
	return 0;
}