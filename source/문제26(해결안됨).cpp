#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

/// timelimit이 나므로  추후에 merge를 이용해서 다시 풀어보기!


int main()
{
	int n;
	scanf("%d", &n);
	vector<int> player(n + 1);
	vector<int> order(n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &player[i]);
	}
	int max = player[1];
	int min = player[1];
	int count;
	printf("1 ");
	for (int i = 2; i <= n; i++)
	{
		count = i;
		if (player[i] > max)
		{
			printf("%d ", 1);
			max = player[i];
		}
		else
		{
			for (int j = i - 1; j >= 1; j--)
			{
				if (player[i] > player[j])
				{
					count--;
				}
			}
			printf("%d ", count);
		}
	}
	return 0;
}