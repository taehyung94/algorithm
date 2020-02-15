#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>

/*
³» ÄÚµå
int get(int k)
{
	int sum = 0;
	while (k > 0)
	{
		sum += 1;
		k /= 10;
	}
	return sum;
}


int main()
{
	int n;
	int sum = 0;
	int i = 0;
	int index;
	scanf("%d", &n);
	index = n;
	while (1)
	{
		index /= 10;
		if (index == 0)
			break;
		i++;
	}
	sum += (get(n)*(n - (int)pow(10, i) + 1));
	while (i > 0)
	{
		sum += (get(pow(10, i - 1))*((int)pow(10, i) - (int)pow(10, i - 1)));
		i--;
	}
	printf("%d\n", sum);
	return 0;
}*/

int main()
{


	return 0;
}