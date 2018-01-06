/*
7.4 �����Ķ�������ͳ��1�ĸ���
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int count1(int n)
{
	int count = 0;
	while (n)
	{
		count += n & 0x1;
		n >>= 1;
	}//while

	return count;
}

int count2(int n)
{
	int count = 0;
	while (n)
	{
		n &= (n - 1); /*ÿִ��һ�Σ�����Ĩ�����Ҷ˵�1*/
		++count;
	}//while
	return count;
}

int count3(int n)
{
	int count = 0;
	while (n)
	{
		n -= (n & (~n + 1)); /*Ĩ�����Ҷ˵�1*/
		++count;
	}//while
	return count;
}

int main()
{
	cout << count1(9) << endl;
	cout << count2(9) << endl;
	cout << count3(9) << endl;

	system("pause");
	return 0;
}