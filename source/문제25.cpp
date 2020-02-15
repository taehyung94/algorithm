#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	scanf("%d", &n);
	vector<int> score(n);
	int data[101] = {};
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
	}
	vector<int> student(score);
	// 학생들의 성적순서 정렬!
	sort(score.begin(), score.end());
	// 정렬 후 해당 성적에 따른 인덱스 값에 현재 등수를 저장한다. 해당 인덱스에 이미 저장되어있다면 count만 +1 증가시킨다.
	for (int i = n - 1; i >= 0; i--)
	{
		if (data[score[i]])
		{
			count++;
		}
		else
			data[score[i]] = (count++);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", data[student[i]]);
	}
}