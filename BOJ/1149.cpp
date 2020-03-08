#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

// 각 인덱스 경우마다 RGB 세개의 수를 입력받고 각각의 인덱스마다 
// 1부터 해당 인덱스까지의 합 중에서
//  red를 칠했을 때의 최솟값, green을 칠했을 때의 최솟값, blue를 칠했을 때의 최솟값을 구해준다.

int map[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int r, g, b;
	for (int i = 1; i <= n; i++)
	{
		cin >> r >> g >> b;
		map[i][0] = min(map[i - 1][1], map[i - 1][2]) + r;
		map[i][1] = min(map[i - 1][0], map[i - 1][2]) + g;
		map[i][2] = min(map[i - 1][0], map[i - 1][1]) + b;
	}
	cout << min(min(map[n][0],map[n][1]),map[n][2]) << '\n';
	return 0;
}
