#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int check[101];
int n;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{    // 현재 인덱스 i와 연결 되있는 것을 찾고 큐에 넣는다.
			if (map[i][j]) 
				{
          q.push(j);
          check[j]=1;
        }
		}
		while (!q.empty())
		{
			int k = q.front();
			q.pop();
			for (int e = 1; e <= n; e++)
			{ // q에서 나온 원소와 연결되 있는 것을 찾고 연결되있다면 처음의 원소 i와의 값을 1로 바꿔준다.
				if (map[k][e] == 1&&check[e]==0)
				{
					map[i][e] = 1;
					q.push(e);
					check[e] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) // 루프문을 n번 돌아야하므로 check배열 초기화
			check[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << map[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
