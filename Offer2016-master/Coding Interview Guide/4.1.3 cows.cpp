/*
4.1.3 ĸţ��������

��������2������ũ���г����ĸţÿ��ֻ����1ͷСĸţ��������Զ����������һ��ũ����һֻ�����ĸţ��
�ӵڶ��꿪ʼ��ĸţ��ʼ��Сţ��ÿֻСĸţ3��֮������ֿ�����Сĸţ��
��������N�����N���ţ��������

������
f(1) = 1;  f(2) = 2; f(3) = 3; f(4) = 4; n>=5ʱ,f(n) = f(n-1) + f(n-3);
*/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*�����ݹ�*/
int cows_1(int n)
{
	if (n < 1)
	{
		return 0;
	}//if
	else if (n < 5)
	{
		return n;
	}//elif
	else{
		return cows_1(n - 1) + cows_1(n - 3);
	}//else
}

/*��ʱ����*/
int cows_2(int n)
{
	if (n < 1)
	{
		return 0;
	}//if
	else if (n < 5)
	{
		return n;
	}//elif
	else{
		int res = 3, secPre = 2, firPre = 1;
		for (int i = 4; i <= n; ++i)
		{
			int tmp1 = res, tmp2 = secPre;
			res = res + firPre;
			secPre = tmp1;
			firPre = tmp2;
		}//for
		return res;
	}//else
}

/*�ռ任ʱ��*/
int cows_3(int n)
{
	if (n < 1)
	{
		return 0;
	}//if
	else if (n < 5)
	{
		return n;
	}//elif
	else{
		vector<int> res(n + 1, 0);
		for (int i = 1; i < 5; ++i)
			res[i] = i;
		for (int i = 5; i <= n; ++i)
			res[i] = res[i - 1] + res[i - 3];
		return res[n];
	}
}

int main()
{
	cout << cows_1(5) << endl;
	cout << cows_2(5) << endl;
	cout << cows_3(5) << endl;

	system("pause");
	return 0;
}