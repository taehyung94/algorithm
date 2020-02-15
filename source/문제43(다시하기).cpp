#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> data(n);
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
		sum += data[i];
	}
	int start = 1;
	int end = sum;
	int check = 0;
	int mid;
	int k;
	sum = 0;
	while (start <= end)
	{
		int check_d = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
		{
			if ((sum + data[i]) > mid)
			{
				check_d++;
				sum = data[i];
			}
			else
			{
				sum += data[i];
			}
		}
		if (check_d > m)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
			k = mid;
		}
	}
	printf("%d\n", k);
	return 0;
}