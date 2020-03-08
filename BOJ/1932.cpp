#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

long long map[501][501];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long mx = -123214;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
      // 현재 위치까지의 합은 현재 위치에서 왼쪽 위와 오른쪽 위의 최대값에 자기자신의 값을 더한 것이다.
			map[i][j] = max(map[i - 1][j], map[i - 1][j - 1])+map[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
		if (map[n][i] > mx)
			mx = map[n][i];
	cout << mx << '\n';
	return 0;
}
