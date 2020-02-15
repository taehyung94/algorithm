#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int m;
	scanf("%d", &n);
	vector<int> first(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &first[i]);
	scanf("%d", &m);
	vector<int> second(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &second[i]);
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	int i = 0, j = 0;
	while (i < n&&j < m)
	{
		if (first[i] == second[j])
		{
			printf("%d ", first[i]);
			i++;
			j++;
		}
		else if (first[i] > second[j])
		{
			j++;
		}
		else
			i++;
	}
	return 0;
}