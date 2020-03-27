#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int map[1000001];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	queue<int> q;
	q.push(s);
	map[s] = 1;
	vector<int> dir;
	dir.push_back(u);
	dir.push_back(-d);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < dir.size(); i++)
		{
			int xx = x + dir[i];
			if (xx >= 1 && xx <= f)
			{
				if (map[xx]==0)
				{
					map[xx] = map[x] + 1;
					if (xx == g)
						goto EXIT;
					q.push(xx);
				}
			}
		}
	}
EXIT:
	if (map[g]==0)
		cout << "use the stairs\n";
	else
		cout << map[g] - 1 << '\n';
	return 0;
}
