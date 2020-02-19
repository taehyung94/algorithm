#include <iostream>

using namespace std;

int arr[10001];

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = i-1; j >= 1; j--)  // 자신보다 실력이 큰 사람의 숫자를 센다. 하지만 순서는 1등부터 시작하므로 +1 해서 출력!					    
		{                             				
			if (arr[i] <= arr[j]) // 
				cnt++;
		}
		cout << cnt+1 << ' ';
	}
	cout << '\n';
	return 0;
}
