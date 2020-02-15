#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int data[9][9];
	int avg[9] = {};
	double sum = 0;
	int index[9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &data[i][j]);
			sum += data[i][j];
		}
		avg[i] = round(sum / 9);
		sum = 0;
	}
	for (int i = 0; i < 9; i++)
	{
		int min = 100;
		for (int j = 0; j < 9; j++)
		{
			int check = abs(avg[i] - data[i][j]);
			if (check < min)
			{
				min = check;
				index[i] = j;
			}
			else if (check == min)
			{
				if (data[i][index[i]] < data[i][j])
					index[i] = j;
			}
		}
	}
	for (int i = 0; i < 9; i++)
		printf("%d %d\n", avg[i], data[i][index[i]]);
	return 0;
}