#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
// 숫자의 아스키코드는 48~57 영어 대문자는 65~90 소문자는 97~122
int main()
{
	int n;
	vector<int> data;
	int count = 0;
	int max = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		data.push_back(k);
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i + 1] >= data[i])
		{
			count++;
			if (max < count)
				max = count;
		}
		else
		{
			count = 1;
		}
	}
	printf("%d\n", max);
	return 0;
}