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
		for (int j = i; j >= 1; j--)
		{
			if (arr[i] <= arr[j])
				cnt++;
		}
		if(cnt==0)
			cout << cnt+1 << ' ';
		else
			cout << cnt << ' ';
	}
	cout << '\n';
	return 0;
}
