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
	// �л����� �������� ����!
	sort(score.begin(), score.end());
	// ���� �� �ش� ������ ���� �ε��� ���� ���� ����� �����Ѵ�. �ش� �ε����� �̹� ����Ǿ��ִٸ� count�� +1 ������Ų��.
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