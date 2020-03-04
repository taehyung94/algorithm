#include <iostream>
#include <queue>


using namespace std;

int map[1001][1001];
int check[1001];
int n, m;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	cin >> n >> m;
	int a, b;
	queue<int> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	q.push(1);
	check[1] = 1;
  // 처음 시작 노드로 1을 넣고 방문 check
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{ // k와 연결되어 있는 원소 중에서 방문하지 않은 것을 큐에 넣고 방문처리한다.
			if (check[i] == 0 && map[k][i] == 1)
			{
				q.push(i);
				check[i] = 1;
			}
		}
    // 만약 큐가 비었다면 연결요소가 끊어진 것이므로 1개 카운트한다.
    // 카운트 이후에는 방문하지 않은 요소를 check배열에서 찾아 큐에 넣고 다시 반복한다.
		if (q.empty())
		{
			cnt++;
			for (int i = 1; i <= n; i++)
			{
				if (check[i] == 0)
				{
					q.push(i);
					check[i] = 1;
					break;
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
