#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// ������ �ƽ�Ű�ڵ�� 48~57 ���� �빮�ڴ� 65~90 �ҹ��ڴ� 97~122

int main()
{
	char word1[101];
	char word2[101];
	char item1[123] = {};
	char item2[123] = {};
	int check = 1;
	scanf("%s", word1);
	scanf("%s", word2);
	for (int i = 0; word1[i] != '\0'; i++)
		item1[word1[i]]++;
	for (int i = 0; word2[i] != '\0'; i++)
		item2[word2[i]]++;
	for (int i = 65; i <= 122; i++)
	{
		if (item1[i] != item2[i])
		{
			check = 0;
			break;
		}
	}
	if (check == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}