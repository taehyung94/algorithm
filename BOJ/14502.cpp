#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이 전략
// 빈 공간중에서 벽 3개를 세울 공간을 골라야 하므로 조합 알고리즘 + BFS로 해결한다.
// ---   ------

// 위치 정보를 담을 클래스
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



int map[9][9]; // 지도 정보를 담을 배열
int check[3]; // 빈 공간 중에서 벽을 세울 공간의 인덱스를 저장할 배열
int n, m; // 가로, 세로를 담을 변수
int mx = -112;
int x_dir[] = { 0,0,-1,1 }; // 바이러스가 움직이므로 이를 움직이기 위한 방향 배열
int y_dir[] = { 1,-1,0,0 };

vector<Place> b_map;
vector<Place> v_map;
vector<Place> w_map;


void DFS(int a, int b)
{
	if (b == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			Place p = b_map[check[i]]; 
			map[p.x][p.y] = 1; // 선택된 빈 공간에 벽을 세운다.
		}
		queue<Place> q;
		int v_check[81] = {};
		int v_index = 0;
		q.push(v_map[v_index]); // 바이러스 벡터안에 담긴 정보를 q에 삽입
		v_check[v_index++];
		while (!q.empty()) // 바이러스는 인접 4방향에 바이러스를 계속해서 퍼트리기 때문에 인접한 곳을 바이러스로 바꿔주고 큐에 넣어준다.
		{
			Place p = q.front();
			q.pop();
			int x = p.x;
			int y = p.y;
			for (int i = 0; i < 4; i++)
			{
				int xx = x + x_dir[i];
				int yy = y + y_dir[i];
				if (xx >= 1 && xx <= n && yy >= 1 && yy <= m)
				{
					if (map[xx][yy] == 0)
					{
						map[xx][yy] = 2;
						q.push(Place(xx, yy));
					}
				}
			}
			if (q.empty()) // 바이러스가 벽에 가로막혀 더 이상 못간다면 바이러스 벡터에서 새로 찾고 다시 넣는다.
			{
				for (; v_index < v_map.size(); v_index++)
				{
					if (v_check[v_index] == 0)
					{
						q.push(v_map[v_index]);
						v_index++;
						break;
					}
				}
			}
			
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (map[i][j] == 0) cnt++; // 빈 공간의 갯수 세기
		if (mx < cnt) // 비교후 mx에 넣어줌
			mx = cnt;


		// map 정보 초기화
		for (int i = 0; i < b_map.size(); i++)
		{
			Place p = b_map[i];
			map[p.x][p.y] = 0;
		}
	}
	else
	{
		for (int i = a; i < b_map.size(); i++)
		{
			check[b] = i;
			DFS(i + 1, b + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				b_map.push_back(Place(i, j)); // 빈 공간 정보를 b_map에 넣어줌
			else if (map[i][j] == 1)
				w_map.push_back(Place(i, j)); // 벽 공간 정보를 w_map에 넣어줌
			else
				v_map.push_back(Place(i, j)); // 바이러스 공간 정보를 v_map에 넣어줌
		}
	}
	DFS(0, 0);
	cout << mx << '\n';
	return 0;
}
