#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
// ������ �ƽ�Ű�ڵ�� 48~57 ���� �빮�ڴ� 65~90 �ҹ��ڴ� 97~122
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