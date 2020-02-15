#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int find(int k, vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == k)
		{
			return i;
		}
	}
	return 101;
}

int main()
{
	int s, n;
	scanf("%d %d", &s, &n);
	vector<int> data(s);
	int rec = 0;
	int k;
	int now = 0;
	int get;
	data.insert(data.begin(), 1);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		get = find(k, data);
		if (get > 100)
		{
			//data.insert(data.begin(), k);	
			for (int i = s - 1; i > 0; i--)
			{
				data[i] = data[i - 1];
			}
			data[0] = k;
		}
		else
		{
			for (get; get > 0; get--)
			{
				swap(data[get], data[get - 1]);
			}
		}
	}
	for (int i = 0; i < s; i++)
	{
		printf("%d ", data[i]);
	}

	return 0;
}
