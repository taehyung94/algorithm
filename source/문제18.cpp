#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
// ������ �ƽ�Ű�ڵ�� 48~57 ���� �빮�ڴ� 65~90 �ҹ��ڴ� 97~122

int main()
{
	int n, m;
	int currcount = -1;
	int max = -100;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		if (k > m)
		{
			if (currcount == -1)
			{
				currcount = 1;
				continue;
			}
			currcount += 1;
		}
		else
		{
			if (currcount > max)
				max = currcount;
			currcount = 0;
		}
	}
	if (currcount > max)
		max = currcount;
	printf("%d\n", max);
	return 0;
}