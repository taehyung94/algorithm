#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int map[21][21];
int n;

int MIN = 1000000000;
int check[21];


void DFS(int a, int b)
{	
	if (b == (n / 2 + 1)) // 입력은 항상 짝수가 들어오므로 그의 절반까지 탐색되면 최솟값 찾기!
	{
		vector<int> v1;
		vector<int> v2;
		for (int i = 1; i <= n; i++)
		{
			if (check[i])
				v1.push_back(i);
			else
				v2.push_back(i);
		}
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < v1.size(); i++)
		{
			for (int j = i + 1; j < v1.size(); j++)
			{
				sum1 += map[v1[i]][v1[j]];
				sum1 += map[v1[j]][v1[i]];
				sum2 += map[v2[i]][v2[j]];
				sum2 += map[v2[j]][v2[i]];
			}
		}
		if (MIN > abs(sum1 - sum2))
			MIN = abs(sum1 - sum2);
	}
	else
	{
		for (int i = a; i <= n; i++)
		{
			if (!check[i])
			{
				check[i] = 1;
				DFS(i + 1, b + 1);
				check[i] = 0;
			}
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	DFS(1, 1);
	cout << MIN << '\n';
	return 0;
}
