#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	char data[202];
	int i;
	int sum = 0;
	scanf("%s", data);
	int h_count = 0;
	int c_count = 0;
	int h_index;


	// case 1 c의 원소 갯수가 1개인 경우

	if (data[1] == 'H')
	{
		c_count = 1;
		if (data[2] == '\0')
		{
			sum = 13;
			printf("%d\n", sum);
			return 0;
		}
		else
		{
			for (int k = 2; data[k] != '\0'; k++)
			{
				h_count = (h_count * 10) + (data[k] - 48);
			}
		}
	}
	// case 2 c의 원소의 갯수가 1이 아닌 경우

	else
	{// h의 위치 찾기
		for (i = 2; data[i] != '\0'; i++)
		{
			if (data[i] == 'H')
			{
				h_index = i;
				break;
			}
		}
		if (data[h_index + 1] == '\0')
		{
			h_count = 1;
			for (int k = 1; k < h_index; k++)
			{
				c_count = (c_count * 10) + (data[k] - 48);
			}
		}
		else
		{
			for (int k = 1; k < h_index; k++)
			{
				c_count = (c_count * 10) + (data[k] - 48);
			}
			for (i = h_index + 1; data[i] != '\0'; i++)
			{
				h_count = (h_count * 10) + (data[i] - 48);
			}
		}
	}
	sum = (c_count * 12) + h_count;
	printf("%d\n", sum);
	return 0;
}
