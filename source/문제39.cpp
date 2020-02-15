#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <iostream>

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
	vector<int> mer;
	int k = 0;
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (first[i] > second[j])
		{
			mer.push_back(second[j++]);
		}
		else
		{
			mer.push_back(first[i++]);
		}
	}
	while (i < n)
	{
		mer.push_back(first[i++]);
	}
	while (j < m)
	{
		mer.push_back(second[j++]);
	}
	for (int i = 0; i < (m + n); i++)
	{
		printf("%d ", mer[i]);
	}
	return 0;
}