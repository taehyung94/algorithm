#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 숫자의 아스키코드는 48~57 영어 대문자는 65~90 소문자는 97~122

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