#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;


int check[21];
int n, k;

void DFS(int s, int l)
{
	if (l == k + 1)
	{
		for (int i = 1; i <= k; i++)
			printf("%d ", check[i]);
		printf("\n");
	}
	else
	{
		for (int i = s; i <= n; i++)
		{
			check[l] = i;
			DFS(i + 1, l + 1);
		}
	}
}


int main()
{
	scanf("%d %d", &n, &k);
	DFS(1, 1);
	return 0;
}