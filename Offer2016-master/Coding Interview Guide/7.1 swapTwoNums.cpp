/*
7.1 ���ö���ı�����������������ֵ
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*���ö������������ͨ+-��ʵ��*/
void swapTwoNums(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

/*ʹ��λ����*/
void swapTwoNums2(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}