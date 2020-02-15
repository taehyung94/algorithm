#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> data(n + 1);
	vector<int> check(n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &data[i]);
	int count;
	for (int i = 1; i <= n; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (i < check[j] || check[j] == 0)
			{
				count++;
				if (count == data[i])
					check[count] = i;
			}
		}

	}
	for (int i = 0; i < n; i++)
		printf("%d ", check[i]);
}