#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

long long drink[10001];
long long table[10001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> drink[i];
	table[1] = drink[1];
	table[2] = table[1] + drink[2];
	for (int i = 3; i <= n; i++)
	{
		table[i] = max(table[i - 3]+drink[i-1]+drink[i],table[i-2]+drink[i]); // 3번째 전 까지의 최대와 바로 전 포도주 그리고 현재의 포도주와 
                                                                          // 2번째 전까지의 최대와 현재의 포도주의 합을 비교해서 큰 값을 현재 테이블에 저장한다.
		table[i] = max(table[i], table[i - 1]); // 저장 후에는 이전 테이블 것과 비교를 해서 큰 값으로 바꿔준다.
	}

	cout << table[n] << '\n';
	return 0;
}
