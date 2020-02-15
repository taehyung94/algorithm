#define _CRT_SECURE_NO_WARNIGNS

#include <stdio.h>
#include <vector>

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
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (data[j] < data[index])
			{
				index = j;
			}
		}
		swap(data[i], data[index]);
	}
}
