#include <iostream>

using namespace std;

int main()
{
	int n, age;
	int max = -10000, min = 10000;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> age;
		if (age < min)
			min = age;
		if (age > max)
			max = age;
	}
	cout << (max - min) << '\n';
	return 0;
}