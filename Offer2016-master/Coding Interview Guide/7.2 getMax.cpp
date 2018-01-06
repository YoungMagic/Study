/*
7.2 �����καȽ��ж��ҳ��������нϴ����
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*���ܣ����n=1����0�����n=0����1*/
int flip(int n)
{
	return n ^ 1;
}

/*��������n�ķ���,������0����1����������0*/
int sign(int n)
{
	return flip((n >> 31) & 1);
}

/*����һ�������ԣ�a-b��ֵ�������*/
int getMax1(int a, int b)
{
	int c = a - b;
	int scA = sign(c);
	int scB = flip(scA);
	return a*scA + b*scB;
}

/*��������������*/
int getMax2(int a, int b)
{
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	int difSab = sa^sb;

	int sameSab = flip(difSab);

	int returnA = difSab * sa + sameSab *sc;
	int returnB = flip(returnA);

	return returnA * a + returnB * b;
}
//
//int main()
//{
//	cout << getMax1(1, 2) << endl;
//	cout << getMax2(1, 2) << endl;
//
//	system("pause");
//	return 0;
//}