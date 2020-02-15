#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
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
	vector<int> data(n + 1);
	for (int i = 2; i <= n; i++)
	{
		if (i == 2 || i == 5)
			data[i]++;
		else
		{
			int k = i;
			for (int j = 2; j <= k; j++)
			{
				if (j == 2 || j == 5)
				{
					while (k%j == 0)
					{
						data[j]++;
						k /= j;
					}
				}
			}
		}
	}
	if (data[2] > 0 && data[5])
	{
		printf("%d", min(data[2], data[5]));
	}
	else
		printf("%d", 0);
	return 0;
}