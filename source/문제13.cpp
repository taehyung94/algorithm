#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>

int main()
{
	char num[101];
	int data[10] = {};
	int max = -100;
	int max_index = -1;
	scanf("%s", num);
	for (int i = 0; num[i] != '\0'; i++)
	{
		data[num[i] - 48]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (max <= data[i])
		{
			max = data[i];
			max_index = i;
		}
	}
	printf("%d\n", max_index);
	return 0;
}