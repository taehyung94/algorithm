#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int check[26];

int n;
int cnt;

vector<string> v;

bool compare(int a, int b)
{
	return a > b;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
		for (int j = 0; j < v[i].size(); j++)
		{
			check[v[i][j] - 65] += pow(10, v[i].size() - 1 - j); // 각 문자가 숫자로 나타냈을 때 자릿수 * 횟수만큼 인덱스에 저장
		}
	}
	sort(check, check + 26,compare); // 횟수가 큰 것을 기준으로 정렬한다.
	int c = 9;
	int sum = 0;
	for (int i = 0; i < 26; i++) // 정렬 후 9부터 시작해서 값을 대입해서 sum에 더해준다.
	{
		if (check[i])
		{
			sum += check[i] * c;
			c--;
		}
	}
	cout << sum << '\n';
	return 0;
}
