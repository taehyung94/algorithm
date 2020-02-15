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
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	sort(data.begin(), data.end());
	int k = n / 2;
	while (k > 0)
	{
		if (data[k] > m)
		{
			k /= 2;
		}
		else if (data[k] < m)
		{
			k++;
		}
		else
		{
			break;
		}
	}
	printf("%d\n", k + 1);
	return 0;
}