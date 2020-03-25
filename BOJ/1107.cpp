#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int er_num[10]; // 고장난 숫자 리스트

int calc(int k)
{
	int len = 0;
	if (k == 0) // k가 0이면 이동하는데 걸리는 횟수는 1이다. 만약 고장났다면 0을 리턴
	{
		if (er_num[0])
			return 0;
		else return 1;
	}
	while (k)
	{
		int a = k % 10;
		if (er_num[a]) // k안에 고장난 숫자가 포함되어 있다면 이동할 수 없으므로 0리턴
			return 0;
		else
		{
			len++; // 고장난숫자가 없다면 이동횟수를 1씩 증가시켜 준다.
			k /= 10;
		}
	}
	return len; //모든 자리를 계산했다면 총 이동횟수를 리턴한다.
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a;
		cin >> a;
		er_num[a] = 1;
	}
	if (n == 100) // 입력숫자가 100이면 시작 위치가 100이므로 0을 출력한다.
		cout << 0 << '\n';
	else // 100이 아니라면
	{ 
		int ans = abs(n - 100); //채널 +,-로 만 이동했을 때 걸리는 횟수를 초기값으로 지정한다.
		for (int i = 0; i <= 1000000; i++)
		{
			int c = i;
			int len = calc(c);
			if (len) // 0부터 시작해서 숫자가 이동 가능하고 
			{
				int press = abs(c - n); // +,- 로 이동하는 데 걸리는 횟수
				if (ans > press + len) // 그 숫자로 이동하는 데 걸리는 횟수와 이동 후 목표 위치로 +,-로 이동하는 횟수의 합이 
					ans = press + len; // 초기값과 비교해서 작다면 초기값을 바꿔준다.
			}
		}
		cout << ans << '\n'; // 최종적으로 가장 작은 값을 출력해준다.
	}
	return 0;
}
