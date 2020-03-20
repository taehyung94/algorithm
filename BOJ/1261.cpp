#include <iostream>
#include <queue>
#include <string>

#define M 100001

using namespace std;


int map[101][101];
int check[101][101];
int dis[101][101];

int x_dir[] = { 1,-1,0,0 };
int y_dir[] = { 0,0,1,-1 };

int main()
{
	int m, n;
	cin >> m >> n;
	string s;
	queue<pair<int, int> > q;
	queue<pair<int, int> > nq;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1] - 48;
		}
	}
	q.push(make_pair(1, 1));
	check[1][1] = 1; // 시작점 삽입 후 방문처리
	while (!q.empty())
	{
		int x = q.front().first; 
		int y = q.front().second;
		q.pop();	
		for (int i = 0; i < 4; i++)
		{
			int xx = x + x_dir[i];
			int yy = y + y_dir[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) // 지도의 범위를 넘지않아야한다.
			{
				if (map[xx][yy] == 1 && check[xx][yy] == 0) // 벽을 부숴야한다면 +1 시켜주고 다음 큐에 삽입해준다.
				{
					nq.push(make_pair(xx, yy));
					check[xx][yy] = 1;
					dis[xx][yy] = dis[x][y]+1;
				}
				else if (map[xx][yy] == 0 && check[xx][yy] == 0) // 벽을 부수지 않고 방문 할 수있는 곳을 삽입해준다.
				{
					q.push(make_pair(xx, yy));
					check[xx][yy] = 1;
					dis[xx][yy] = dis[x][y];
				}
			}
		}
		if (q.empty()) // 벽을 부수지않고 방문할 수 있는 곳을 모두 방문했다면 큐를 다음 큐로 교체해주고 다음큐는 빈큐로 초기화 해준다.
		{
			q = nq;
			nq = queue<pair<int, int> >();
		}
	}
	cout << dis[n][m] << '\n';
	return 0;
}
