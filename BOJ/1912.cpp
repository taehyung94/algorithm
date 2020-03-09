#include <iostream>

 

using namespace std;


int map[100001];

    
int main()
{
    int n;
    cin >> n;
    int mx = -100000;
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i];
        if (map[i] > mx)
            mx = map[i];
    }
    for (int i = 2; i <= n; i++)
    {
        // 이전 인덱스까지의 합이 음수라면 그대로 넘어가고 그렇지 않다면 자신의 합과 합쳐준다. 합친 값과 mx값과 비교해 최대값을 계속해서 찾아준다.
        if (map[i - 1] < 0)
            continue;
        map[i] += map[i - 1];
        if (mx < map[i])
            mx = map[i];
    }
    cout << mx << '\n';
    return 0;
}
