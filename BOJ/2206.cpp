#include <iostream>
#include <queue>
#include <string>
#include <tuple>


#define M 100001

using namespace std;


int map[101][101];

int dis[101][101][2]; // 벽을 1개 부순 상태로 진입하는 것과 벽을 부수지 않은 상태에서 진입하는데 이동 한 거리 2개 모두를 구해야하므로 3차원

int x_dir[] = { 1,-1,0,0 };
int y_dir[] = { 0,0,1,-1 };


int main()
{
	int m, n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1] - 48; // 문자로 입력받았으므로 48을 빼줘서 정수형태로 만들어준다.
		}
	}
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 1, 0)); // 현재 지점에서 벽을 부순 횟수 까지 넣어야하므로 튜플로 삽입한다.
	dis[1][1][0] = 1; // 시작점도 이동거리에 카운팅 되므로 1부터 시작한다.
	while (!q.empty())
	{
		int x, y, c;
		tie(x, y, c) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + x_dir[i];
			int yy = y + y_dir[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) // 이동한 곳은 범위를 벗어나지않아야한다.
			{
				if (map[xx][yy] == 0 && dis[xx][yy][c] == 0) // 벽이 없는 곳이고 이곳에 방문한 적이 없다면 +1 시켜주고 삽입한다.
				{
					dis[xx][yy][c] = dis[x][y][c] + 1;
					q.push(make_tuple(xx, yy, c));
				}
				else if (c == 0 && map[xx][yy] == 1 && dis[xx][yy][c+1] == 0) // 벽이 있는 곳이라면 이 전에 벽을 부순 적이 없어야하고 현 위치를 방문한 적이 없어야 한다.
				{
					dis[xx][yy][c+1] = dis[x][y][c] + 1;
					q.push(make_tuple(xx, yy, c + 1));
				}
			}
		}
	}
	if (dis[n][m][0] != 0 && dis[n][m][1] != 0) // 도착 지점에서 현 위치에 오기까지 벽을 부순 것과 안부순 것의 횟수를 비교해서 출력
	{
		cout << min(dis[n][m][0], dis[n][m][1]);
	}
	else if (dis[n][m][0] != 0)
		cout << dis[n][m][0] << '\n';
	else if (dis[n][m][1] != 0)
		cout << dis[n][m][1] << '\n';
	else
		cout << -1 << '\n';
	return 0;
}
