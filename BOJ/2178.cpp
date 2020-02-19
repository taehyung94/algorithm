#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <time.h>
#include <iostream>
#include <string>



using namespace std;


int n, m, start;

int map[101][101];
int check[101][101];

int x_dir[] = { 0,0,1,-1 };
int y_dir[] = { 1,-1,0,0 };

int main()
{
	string s;
	int a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int k = 0;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = (s[k]-48);
			k++;
		}
	}
	queue<pair<int,int>> q;
	q.push(make_pair(1, 1));
	check[1][1] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + x_dir[i];
			int yy = y + y_dir[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m)
			{
				if (check[xx][yy]==0&&map[xx][yy]==1)
				{
					q.push(make_pair(xx, yy));
					check[xx][yy] = check[x][y] + 1;
					map[xx][yy] = 0;
				}
			}
		}
	}
	cout << check[n][m] << '\n';
	return 0;
}
