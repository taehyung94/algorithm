#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <time.h>
#include <iostream>
#include <string>



using namespace std;


int n, m, start;

int map[26][26];
int check[26][26];
vector<pair<int, int>> house;


// 상하좌우이므로 각각 방향 설정
int x_dir[] = { 0,0,1,-1 };
int y_dir[] = { 1,-1,0,0 };
vector<int> apt;

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int k = 0;
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = s[k]-48;
			k++;
			if (map[i][j] == 1) //집의 위치를 house 벡터에 저장
				house.push_back(make_pair(i, j));
		}
	}

	queue<pair<int, int>> q;
	q.push(house[0]);
	check[house[0].first][house[0].second] = 1;
	map[house[0].first][house[0].second] = 0;
	int h_index = 1;
	int cnt = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + x_dir[i];
			int yy = y + y_dir[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)
			{
				if (map[xx][yy] == 1 && check[xx][yy] == 0)
				{
					q.push(make_pair(xx, yy));
					check[xx][yy] = 1;
					map[xx][yy] = 0;
					cnt++;
				}
			}
		}
		if (q.empty()) //하나의 단지를 찾았을 때 이므로 큐가 비어있다. 새로운 집을 house 벡터에서 찾는다.
		{
			apt.push_back(cnt); // apt벡터에 현재 단지의 카운트 된 집의 수를 넣는다.
			for (h_index; h_index < house.size(); h_index++)
			{
				if (check[house[h_index].first][house[h_index].second] == 0)
				{
					check[house[h_index].first][house[h_index].second] = 1;
					map[house[h_index].first][house[h_index].second] = 0;
					q.push(house[h_index]);
					h_index++;
					cnt = 1;
					break;
				}
			}
		}
	}
	sort(apt.begin(), apt.end());
	cout << apt.size()<<'\n';
	for (int i = 0; i < apt.size(); i++)
		cout << apt[i] << '\n';
	return 0;
}
