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
		int j = i;
		while (j > 0)
		{
			if (j % 10 == 3)
				count += 1;
			j /= 10;
		}
	}
	printf("%d\n", count);
	return 0;
}