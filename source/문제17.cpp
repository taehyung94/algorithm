#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// ������ �ƽ�Ű�ڵ�� 48~57 ���� �빮�ڴ� 65~90 �ҹ��ڴ� 97~122

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		int check;
		scanf("%d %d", &num, &check);
		if (check == (num*(num + 1) / 2))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}