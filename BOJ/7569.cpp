#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


int x_dir[] = { 0,0,-1,1,0,0 };
int y_dir[] = { 1,-1,0,0,0,0 };
int z_dir[] = { 0,0,0,0,1,-1 };

class Place
{
public:
	int x;
	int y;
	int z;
	Place()
	{
		x = 0;
		y = 0;
		z = 0;

	}
	Place(int a, int b,int c)
	{
		x = a;
		y = b;
		z = c;
	}
};


int map[101][101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<Place> v;
	int n, m, h;
	cin >> n >> m >> h;
	//vector<vector< vector<int> > > map(h + 1, vector< vector<int> >(m+1, vector<int>(n+1)));
	queue<Place> q;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)
				{
					q.push(Place(i,j,k)); // 익은 토마토가 있는 곳을 모두 큐에 넣는다.
				}
			}
		}
	}
	
	int max = 0;
	while (!q.empty())
	{
		Place p = q.front();
		q.pop();
		int x = p.x;
		int y = p.y;
		int z = p.z;
		for (int i = 0; i < 6; i++)
		{
			int xx = x + x_dir[i];
			int yy = y + y_dir[i];
			int zz = z + z_dir[i];
			if (xx >= 1 && xx <= h && yy >= 1 && yy <= m && zz >= 1 && zz <= n) // 토마토가 범위에 있고 익지 않았다면 map의 값에서 1 증가시킨 값을 넣는다.
			{
				if (map[xx][yy][zz] == 0)
				{
					map[xx][yy][zz] = map[x][y][z] + 1;
					if (max < map[xx][yy][zz])
						max = map[xx][yy][zz];
					q.push(Place(xx, yy, zz));
				}
			}
		}
	}
	
	int key = 0;

	for (int i = 1; i <= h; i++)
	{
		if (key == 1)
			break;
		for (int j = 1; j <= m; j++)
		{
			if (key == 1)
				break;
			for (int k = 1; k <= n; k++)
				if (map[i][j][k] == 0)
				{
					key = 1;
					break;
				}
		}
	}
	if (key) // key가 1이면 안 익은 토마토가 있으므로 -1 출력!
		cout << "-1\n";
	else if (max == 0) // max가 0이면 0일 걸린 것이므로 0 출력
		cout << max << '\n';
	else // 0이 아니면 max-1을 출력해준다. (초기 시작 값이 익은 토마토의 값 1에서 시작했기 때문에 )
		cout << max-1 << '\n';
	return 0;
}
