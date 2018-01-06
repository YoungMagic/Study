/*
4.1.2 ��̨������
������Ŀ1����������N������̨������һ�ο��Կ�Խ2����1��̨�ף������ж������߷���
������
f(1) = 1; f(2) = 2; f(n) = f(n-1)+f(n-2);
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*�����ݹ� O(2^n)*/
int steps_1(int n)
{
	if (n < 1)
	{
		return 0;
	}//if
	else if (n == 1)
	{
		return 1;
	}//elif
	else if (n == 2)
	{
		return 2;
	}//elif
	else
	{
		return steps_1(n - 1) + steps_1(n - 2);
	}//else
}

/*�ռ任ʱ��*/
int steps_2(int n)
{
	vector<int> res(n+1, 0);
	if (n <= 2)
	{
		return n;
	}//if
	else{
		res[1] = 1;
		res[2] = 2;
		for (int i = 3; i <= n; ++i)
			res[i] = res[i - 1] + res[i - 2];
		return res[n];
	}//else
}

int main()
{
	cout << steps_1(5) << endl;
	cout << steps_2(5) << endl;

	system("pause");
	return 0;
}