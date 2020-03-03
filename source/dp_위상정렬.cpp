#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <time.h>
#include <queue>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int a, b;
	cin >> n >> m;
	vector< vector<int> > map(n + 1, vector<int>(n + 1));
	vector<int> degree(n + 1);
	queue<int> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		degree[b]++;
		// 자신에게 들어오는 간선의 갯수를 degree 배열에 넣는다.
	}
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		cout << k << ' ';
		for (int i = 1; i <= n; i++)
		{
			if (map[k][i])
			{
				degree[i]--;
				if (degree[i] == 0)
					q.push(i);
			}
		}
	}
	cout << '\n';
	return 0;
}