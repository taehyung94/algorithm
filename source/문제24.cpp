#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
// ������ �ƽ�Ű�ڵ�� 48~57 ���� �빮�ڴ� 65~90 �ҹ��ڴ� 97~122
/*int main()
{
	int n;
	scanf("%d", &n);
	vector<int> data(n);
	vector<int> get_data(n);
	int check = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	// 5������ �迭 0�� 1  1�� 2 2�� 3 3�� 4 
	for (int i = 0; i < n - 1; i++)
	{
		int cha = abs(data[i] - data[i + 1]);
		if (cha >= 1 && cha <= n - 1)
		{
			get_data[cha]++;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (get_data[i] != 1)
		{
			check = 0;
			break;
		}
	}
	if (check)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}*/

// ������ �ڵ�

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> data(n);
	vector<int> check_data(n);
	int check = 1;
	int now;
	int next;
	scanf("%d", &now);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &next);
		int k = abs(now - next);
		if (k >= 1 && k < n&&check_data[k] == 0)
			check_data[k]++;
		else
		{
			check = 0;
			break;
		}
		now = next;
	}
}