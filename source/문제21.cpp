#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
// ������ �ƽ�Ű�ڵ�� 48~57 ���� �빮�ڴ� 65~90 �ҹ��ڴ� 97~122


class USER
{
public:
	int point = 0;
	int data[10] = {};
	int check = 0;
	char name;
	USER(char name)
	{
		this->name = name;
	}
};

void fight(USER& a, USER& b, int i)
{
	if (a.data[i] > b.data[i])
	{
		a.point += 3;
		a.check = 1;
		b.check = 0;
	}

	else if (a.data[i] == b.data[i])
	{
		a.point++;
		b.point++;
	}
	else
	{
		b.point += 3;
		b.check = 1;
		a.check = 0;
	}
}

int main()
{
	int n = 10;
	USER a('A');
	USER b('B');
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		a.data[i] = k;
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		b.data[i] = k;
	}
	for (int i = 0; i < n; i++)
	{
		fight(a, b, i);
	}
	printf("%d %d\n", a.point, b.point);
	if (a.point > b.point)
		printf("%c\n", a.name);
	else if (a.point < b.point)
		printf("%c\n", b.name);
	else
	{
		if (a.check > b.check)
			printf("%c\n", a.name);
		else if (a.check < b.check)
			printf("%c\n", b.name);
		else
			printf("D\n");
	}
	return 0;
}