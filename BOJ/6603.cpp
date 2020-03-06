#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n;

int arr[51];
int check[7];
// 조합 알고리즘
void DFS(int a, int b)
{
	if (b == 7)
	{
		for (int i = 1; i <= 6; i++)
			cout << arr[check[i]] << ' ';
		cout << '\n';
	}
	else
	{
		for (int i = a; i <= n; i++)
		{
			check[b] = i;
			DFS(i + 1, b + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1)
	{
		string s;
		string play;
		getline(cin, s); // 한줄 단위로 입력받기 때문에 getline을 사용해준다.
		if (s[0] == '0') // 첫번째로 오는 숫자가 0일 경우 반복문 종료!
			break;
		int i = 0;
		int j = 1;
		for (; i < s.size(); i++) // 공백문자일 경우 건너띄고 아닌 경우 play 문자열에 하나씩 추가해줘서 배열의 길이를 찾아준다.
		{
			if (s[i] == ' ')
				break;
			play += s[i];
		}
		n = stoi(play); // 찾은 배열의 길이를 정수로 바꿔준다.
		play = "";
		i++;
		for (; i <= s.size(); i++) 
		{
			if (s[i] == ' '||s[i]=='\0') //문자의 끝이거나 공백일 경우 arr배열에 play를 (정수형태로)삽입해준다.
			{
				arr[j++] = stoi(play);
				play = "";
				continue;
			}
			play += s[i];
		}
		DFS(1, 1);
        cout<<'\n';
	}
	return 0;
}
