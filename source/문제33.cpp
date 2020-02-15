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
	int count = 1;
	int third;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	sort(data.begin(), data.end());
	int now = data[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (data[i] != now)
		{
			now = data[i];
			count++;
		}
		if (count == 3)
		{
			third = data[i];
			break;
		}

	}
	printf("%d\n", third);
	return 0;
}
