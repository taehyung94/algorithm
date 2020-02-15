#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
// 숫자의 아스키코드는 48~57 영어 대문자는 65~90 소문자는 97~122
int main()
{
	vector<int> data;
	int n;
	int gap;
	int sum = 0;
	int max = -1000000000;
	scanf("%d %d", &n, &gap);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		data.push_back(k);
	}
	for (int i = 0; i < gap; i++)
	{
		sum += data[i];
	}
	for (int i = gap; i < n; i++)
	{
		sum = sum - data[i - gap] + data[i];
		if (max < sum)
			max = sum;
	}
	printf("%d\n", max);
	return 0;
}