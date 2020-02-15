#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int count = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		while (k > 0)
		{
			if (k % 10 == 3)
				count++;
			k /= 10;
		}
	}
	return 0;
}