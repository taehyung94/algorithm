#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <time.h>
#include <iostream>
#include <string>



using namespace std;

int check[100001];

// 앞, 뒤, 순간이동 할 수 있음
int dir[3] = { 1,-1,2 };

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	check[n] = 1;
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			if (i == 2)
			{
				int x = k * 2;
				if (x >= 0 && x <= 100000 && check[x] == 0)
				{
					check[x] = check[k] + 1;
					q.push(x);
				}
			}
			else
			{
				int x = k + dir[i];
				if (x >= 0 && x <= 100000 && check[x] == 0)
				{
					check[x] = check[k] + 1;
					q.push(x);
				}
			}
		}
	}
	cout << check[k] - 1 << '\n';
	return 0;
}
