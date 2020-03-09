#include <iostream>

using namespace std;


long long map[101][10];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		map[1][i] = 1;
	}


	// 자릿수가 i이고 끝자리가 j 일때의 갯수는 자릿수가 i-1이고 끝자리가 j-1이거나 j+1인 갯수들의 합이다.
	// 즉 map[i][j]=map[i-1][j-1]+map[i-1][j+1]
	// 그러나 끝자리가 0일때에는 그 앞에 올수 있는 수는 1밖에 없으므로 map[i][0]=map[i-1][1];
	// 끝자리가 9인 경우에도 그 앞에 올수 있는 수는 8밖에 없으므로 map[i][9]=map[i-1][8]이다.
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				map[i][j] = map[i - 1][1]; 
			else if (j == 9)
				map[i][j] = map[i - 1][j - 1];
			else
				map[i][j] = (map[i - 1][j - 1] + map[i - 1][j + 1]) % 1000000000;
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += map[n][i]; // 최종적으로 n자리의 계단수의 갯수는 자리수가 n이고 끝자리가 0~9인 수들의 합이다.
	cout << sum % 1000000000 << '\n';
	return 0;
}
