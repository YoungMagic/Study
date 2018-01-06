/*
������8.9.8 �����������޵�Ӳ�ң���ֵΪ25�֣�10�֣�5�ֺ�1�֣���д�������n���м��ֱ�ʾ����
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int makeChange(int n , int denom)
{
	int next_denom = 0;
	switch (denom)
	{
	case 25:
		next_denom = 10;
		break;
	case 10:
		next_denom = 5;
		break;
	case 5:
		next_denom = 1;
		break;
	case 1:
		return 1;
	}

	int ways = 0;
	for (int i = 0; i*denom <= n; ++i)
	{
		ways += makeChange(n - i*denom, next_denom);
	}//for
	return ways;
}

int main()
{
	cout << "100�ı�ʾ��ʽ��" << makeChange(100, 25) << endl;

	cout << "200�ı�ʾ��ʽ��" << makeChange(200, 25) << endl;

	system("pause");
	return 0;
}