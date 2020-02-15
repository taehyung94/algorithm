#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <time.h>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int mx = -41241;
	ios_base::sync_with_stdio(false);
	int n;
	char a[100];
	string val;
	map<string, int> check;
	map<string, int>::iterator it;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		check[a]++;
	}
	for (it = check.begin(); it != check.end(); it++)
	{
		if (it->second > mx)
		{
			mx = it->second;
			val = it->first;
		}
	}
	cout << val;
	return 0;
}