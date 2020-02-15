#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	int n;
	scanf("%d", &n);
	vector<int> data(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (data[i] < 0)
		{
			for (int j = i; j > 0; j--)
			{
				if (data[j - 1] > 0)
				{
					swap(data[j], data[j - 1]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	return 0;
}
