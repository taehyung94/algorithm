#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


int x_dir[] = { 0,0,-1,1 };
int y_dir[] = { 1,-1,0,0 };

class Place
{
public:
	int x;
	int y;
	Place()
	{
		x = 0;
		y = 0;

	}
	Place(int a, int b)
	{
		x = a;
		y = b;
	}
};

int map[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, k;
	vector<int> h;
	cin >> m >> n >> k;
	int lx, ly, rx, ry;
	for (int i = 1; i <= k; i++)
	{
		cin >> lx >> ly >> rx >> ry;
		for (int i = ly; i < ry; i++) for (int j = lx; j < rx; j++) map[i][j] = 1; // 직사각형이 들어간 부분을 1로 바꿔 check 해준다.
	}
	queue<Place> q;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if (map[i][j] == 0)
			{
				q.push(Place(i, j));
				map[i][j] = 1;  // 맵에서 직사각형 부분이 아닌 것을 찾고 check 해주고 빠져나간다!
				goto EXIT;
			}
EXIT:
	int cnt = 1; // 위의 반복문에서도 하나를 찾고 빠져나왔고 큐가 비었을 때에도 맵에서 하나를 찾고 빠져나왔기 때문에 cnt는 1부터 시작한다.
	while (!q.empty())
	{
		Place p = q.front();
		q.pop();
		int x = p.x;
		int y = p.y;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + x_dir[i];
			int yy = y + y_dir[i];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n)
			{
				if (map[xx][yy] == 0)
				{
					q.push(Place(xx, yy));
					map[xx][yy] = 1;
					cnt++;
				}
			}
		}
		if (q.empty())
		{
			h.push_back(cnt);  // 큐가 빈 상황이라면 현재까지 카운트 한것을 h벡터에 넣어준다.
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (map[i][j] == 0)
					{
						q.push(Place(i, j));
						map[i][j] = 1;
						goto EXIT;
					}
				}
			}
		}
	}
	sort(h.begin(), h.end()); // 오름차순 출력해야 하므로 정렬해준다.
	cout << h.size() << '\n';
	for (auto k : h)
		cout << k << ' ';
	cout << '\n';
	return 0;
}
