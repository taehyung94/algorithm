#include <vector>
#include <queue>
#include <iostream>



using namespace std;


int x_dir[] = { 0,0,-1,1 };
int y_dir[] = { 1,-1,0,0 };

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int m, n, k;
	int a, b;
	for (int i = 1; i <= t; i++)
	{
		int map[51][51]={};
		int check[51][51]={};
		vector<pair<int, int>> v;
		queue<pair<int, int>> q;
		int cnt = 0;
		cin >> m >> n >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> a >> b;
			v.push_back(make_pair(a, b));
			map[b][a] = 1;
		}
		q.push(v[0]);
		check[v[0].second][v[0].first] = 1;
		map[v[0].second][v[0].first] = 0;
		int v_index = 1;
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int xx = x + x_dir[i];
				int yy = y + y_dir[i];
				if (xx >= 0 && xx <= m - 1 && yy >= 0 && yy <= n-1)
				{
					if (check[yy][xx] == 0 && map[yy][xx] == 1)
					{
						q.push(make_pair(xx, yy));
						check[yy][xx] = 1;
						map[yy][xx] = 0;
					}
				}
			}
			if (q.empty())
			{
				cnt++;
				for (; v_index < v.size(); v_index++)
				{
					if (check[v[v_index].second][v[v_index].first] == 0)
					{
						q.push(v[v_index]);
						check[v[v_index].second][v[v_index].first] = 1;
						map[v[v_index].second][v[v_index].first] = 0;
						v_index++;
						break;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
