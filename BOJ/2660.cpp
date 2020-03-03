#define M 100

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <time.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m_f = -1249124;
	vector< vector<int> > map(n + 1, vector<int>(n + 1, M));
	vector<int> value(n + 1, m_f);
	vector<int> can;
	for (int i = 1; i <= n; i++)
		map[i][i] = 0;
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == -1 && b == a)
			break;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
	int mi = 14124124;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			value[i] = max(value[i], map[i][j]);
		}
		if (mi > value[i])
			mi = value[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (value[i] == mi)
			can.push_back(i);
	}
	cout << mi << ' ' << can.size() << '\n';
	for (auto i : can)
		cout << i << ' ';
	cout << '\n';
	return 0;
}
