#include <vector>

#include <string>

using namespace std;

char map[11][11];
int n;     
vector v;
 
int check(int k)
{
    int sum = 0;
    for (int i = k; i >= 0; i--)  // 행이 위로 올라가면서 앞쪽의 숫자를 더해줄 것이므로 인덱스를 1씩 감소시켜준다.
    {
        sum += v[i]; // 현재 인덱스까지의 합
        if (sum <= 0 && map[i][k] == '+') // 현재 인덱스까지의 합이 좌표의 부호와 다르면 0을 리턴
            return 0;
        if (sum >= 0 && map[i][k] == '-')
            return 0;
        if (sum != 0 && map[i][k] == '0')
            return 0;
    }
    return 1;  // 모두 확인했음에도 이상이 없으면 1을 리턴해준다.
}

void DFS(int k)
{
    if (k == n) // n개의 수열을 완성했으면 그대로 출력 해준다.
    {
        for (auto k : v)
        {
            cout << k << ' ';
        }
        cout << '\n';
        exit(0);
    }
    for (int i = -10; i <= 10; i++) // 수의 범위는 -10부터 10까지이다.
    {
       v.push_back(i); //일단 수를 삽입
       if (check(k))  // 수를 삽입했을 때 부호의 이상이 없으면 다음 숫자로 넘어간다
       {
           DFS(k + 1);
       }
       v.pop_back(); // 다음 숫자로 넘어가지않았으면 부호와 일치하지 않는 것이므로 다시 빼준다.
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string s;
    cin >> s;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
       {
            map[i][j] = s[idx++];  // 주어진 정보대로 표를 완성한다.
        }
    }
    DFS(0); // 첫번째 문자부터 탐색 시작!
    return 0;
}
