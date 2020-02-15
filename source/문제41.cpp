#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	int count = 0;
	int index;
	for (int i = 1; i < ((n / 2) + 5); i++)
	{
		for (int j = i; j <= ((n / 2) + 5); j++)
		{
			sum += j;
			if (sum >= n)
			{
				index = j;
				break;
			}
		}
		if (sum == n)
		{
			for (int j = i; j < index; j++)
				printf("%d + ", j);
			printf("%d = %d\n", index, sum);
			count++;
		}
		sum = 0;
	}
	printf("%d\n", count);
	return 0;
}