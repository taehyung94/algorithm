#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int map[301][3];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int s;
	for (int i = 1; i <= n; i++)
	{
		cin >> map[i][0];
	}
	// 두번째 숫자가 1인 것은 1번에 올라온 것
	// 두번째 숫자가 2인 것은 2번에 걸쳐 올라온 것
	map[2][1] = map[2][0];
	map[2][2] = map[2][0] + map[1][0];
	map[1][1] = map[1][0];
	map[1][2] = map[1][0];
	for (int i = 3; i <= n; i++)
	{
		map[i][1] = max(map[i-2][1],map[i-2][2]) + map[i][0]; //1번에 걸쳐 올라왔으므로 2칸전의 제일 큰 점수와 자신 칸의 점수를 합한다.
		map[i][2] = map[i-1][1] + map[i][0]; // 2번에 걸쳐올라왔으므로 1칸전의 1칸 밟고 올라온 점수와 자신 칸의 점수를 합한다.
	}
	cout << max(map[n][1], map[n][2]); // 2번에 걸쳐 올라온 것과 1번에 올라온 것의 점수 중 큰 값을 출력
	return 0;
}
