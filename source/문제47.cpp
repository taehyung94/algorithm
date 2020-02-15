#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int data[52][52] = {};
	int count = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &data[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int k = data[i][j];
			if (k > data[i - 1][j] && k > data[i][j - 1] && k > data[i + 1][j] && k > data[i][j + 1])
			{
				count++;
				j++;
			}
		}
	}
	printf("%d\n", count);

	return 0;
}