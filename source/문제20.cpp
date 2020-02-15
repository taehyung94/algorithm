#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
// 숫자의 아스키코드는 48~57 영어 대문자는 65~90 소문자는 97~122

class USER
{
public:
	char name;
	int data[101] = {};
	USER(char name)
	{
		this->name = name;
	}
};

void fight(USER a, USER b, int i)
{
	if (a.data[i] == 1 && b.data[i] == 3)
		printf("%c\n", a.name);
	else if (a.data[i] == 2 && b.data[i] == 1)
		printf("%c\n", a.name);
	else if (a.data[i] == 3 && b.data[i] == 2)
		printf("%c\n", a.name);
	else if (a.data[i] == b.data[i])
		printf("D\n");
	else
		printf("%c\n", b.name);
}

int main()
{
	int n;
	class USER a('A');
	class USER b('B');
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int a_;
		scanf("%d", &a_);
		a.data[i] = a_;
	}
	for (int i = 1; i <= n; i++)
	{
		int b_;
		scanf("%d", &b_);
		b.data[i] = b_;
	}
	for (int i = 1; i <= n; i++)
		fight(a, b, i);
	return 0;
}