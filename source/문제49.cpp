#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int data[11][11] = {};
	int row[11];
	int col[11];
	for (int i = 0; i < n; i++)
		scanf("%d", &row[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &col[i]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (row[j] > col[n - 1 - i])
				data[i][j] = col[n - 1 - i];
			else
				data[i][j] = row[j];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += data[i][j];
		}
	}
	printf("%d\n", sum);
	return 0;
}