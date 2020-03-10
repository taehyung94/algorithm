#include <iostream>

#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int x_dir[] = { 0,0,-1,1 };
int y_dir[] = { 1,-1,0,0 };

char map[21][21];
int check[100];

int mx = -10000;

int r, c;


void DFS(int a, int b, int sum)
{
	if (sum > mx) //현재까지의 합과 mx와 비교를 해서 큰값을 받아온다.
		mx = sum;
	for (int i = 0; i < 4; i++)
	{
    int x = a + x_dir[i];
		int y = b + y_dir[i];
		if (x >= 1 && x <= r && y >= 1 && y <= c) // 각각의 x, y 좌표가 표의 크기를 벗어나지 않고 해당 인덱스가 방문처리 되지않았으면 DFS해준다.
    {
			if (check[map[x][y]] == 0)
			{
        check[map[x][y]] = 1;
				DFS(x, y, sum + 1);
				check[map[x][y]] = 0;
			}
		}		
  }
}

int main()
{
	// 알파벳의 대문자의 범위는 65~90

	string s;
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			map[i][j + 1] = s[j];
	}
	check[map[1][1]] = 1; // 현재 알파벳을 방문처리한다.
	DFS(1, 1, 1); // 현재 위치인 1,1 과 지금까지 방문한 알파벳 갯수를 넣어준다.
	cout << mx << '\n';
	return 0;
}
