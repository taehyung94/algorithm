#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>

int digit_sum(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += (x % 10);
		x /= 10;
	}
	return sum;
}

int main()
{
	int index;
	int k;
	int max = -100;
	int max_num;
	scanf("%d", &index);
	while (index > 0)
	{
		scanf("%d", &k);
		if (max < digit_sum(k))
		{
			max = digit_sum(k);
			max_num = k;
		}
		index--;
	}
	printf("%d\n", max_num);
	return 0;
}