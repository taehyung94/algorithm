#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> data(n, 1);
	int count = 0;
	int index = 0;
	int check = 0;
	while (1)
	{
		int c = index % (n);
		if (data[c] == 1)
		{
			count++;
			if (count == k)
			{
				data[c] = 0;
				check++;
				count = 0;
			}
			index++;
		}
		else
		{
			index++;
		}
		if (check == n - 1)
			break;
	}
	for (int i = 1; i <= n; i++)
	{
		if (data[i])
		{
			printf("%d\n", i + 1);
			break;
		}
	}
	return 0;
}