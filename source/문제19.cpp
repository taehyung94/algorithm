#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
// ������ �ƽ�Ű�ڵ�� 48~57 ���� �빮�ڴ� 65~90 �ҹ��ڴ� 97~122


// ���� �ڵ�
int main()
{
	int n;
	scanf("%d", &n);
	int count = 0;
	int data[101] = {};
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &data[i]);
	}
	int max = data[n];
	for (int i = n-1; i >= 1; i--)
	{
		if (max < data[i])
		{
			max = data[i];
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}

// �� �ڵ�
/*int main()
{
	int n;
	int count = 0;
	int get = 0;
	int max = -100;
	int ca = 0;
	vector<int> data;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		data.push_back(k);
	}
	for (int i = data.size() - 2; i >= 0; i--)
	{
		ca = data.size() - i - 1;
		get = 0;
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data[i] > data[j])
			{
				get++;
			}
		}
		if (get == ca)
			count++;
	}
	printf("%d\n", count);
	return 0;
}*/