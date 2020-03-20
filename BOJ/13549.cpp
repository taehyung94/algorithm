#include <iostream>
#include <queue>

#define M 100001

using namespace std;

int check[100001];
int dis[100001];

int dir[] = { 1,-1 };

int main()
{
	int n, k;
	cin >> n >> k;
	check[n] = 1;
	queue<int> q;
	queue<int> nq;
	q.push(n);
	while (!q.empty())
	{
		int c = q.front();
		q.pop();
		if (c * 2 < M) // 순간 이동한 범위가 지도를 벗어나지 않고 방문한적이 없다면 현재 큐에 삽입
		{
			if (check[c * 2] == 0)
			{
				check[c * 2] = 1; // 순간이동에 걸리는 시간은 0이기 때문에 순간이동한 곳 까지 걸린시간은 현재와 같다.
				dis[c * 2] = dis[c]; 
				if (c * 2==k) // 순간이동 한 곳이 목표 지점과 같다면 반복문을 빠져나온다.
					goto EXIT;
				q.push(c * 2);
			}
		}
		for (int i = 0; i < 2; i++)
		{
			int x = c + dir[i];
			if (x >= 0 && x < M)
			{
				if (check[x] == 0) //범위를 벗어나지 않고 방문한 적이 없다면 방문처리 후 거리는 현재에서 1 증가시켜준다.
				{
					nq.push(x);
					check[x] = 1;
					dis[x] = dis[c] + 1;
					if (x == k) // 목표 지점을 찾았으면 반복문을 빠져나간다.
						goto EXIT;
				}
			}
		}
		if (q.empty())
		{
			q = nq; // 큐가 비었으면 다음큐로 바꿔주고 다음큐는 빈큐로 초기화 해준다.
			nq = queue<int>();
		}
	}
EXIT:
	cout << dis[k] << '\n';
	return 0;
}
