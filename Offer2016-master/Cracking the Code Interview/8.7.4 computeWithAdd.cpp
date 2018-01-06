/*
* ������8.7.4 ��д������ʵ�������ĳ˷��������ͳ������㡣ֻ����ʹ��+�š�
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
	//���෴��
	int negate(int a)
	{
		int flag = 0, ret = 0;
		if (a > 0)
			flag = -1;
		else
			flag = 1;
		while (a != 0)
		{
			ret += flag;
			a += flag;
		}//while
		return ret;
	}

	//�����ֵ
	int myAbs(int a)
	{
		return a < 0 ? negate(a) : a;
	}

	//����ʵ��
	int minus(int a, int b)
	{
		return b > 0 ? a + negate(b) : a + b;
	}

	//�˷�ʵ��
	int multi(int a, int b)
	{
		if (a == 0 || b == 0)
			return 0;
		else if (a < b)
			return multi(b, a);
		else
		{
			int sum = 0;
			for (int i = myAbs(b); i>0; --i)
			{
				sum += a;
			}//for
			if (b < 0)
				return negate(sum);
			else
				return sum;
		}//else
	}

	//����ʵ��
	int divide(int a, int b)
	{
		if (0 == b)
		{
			perror("The input number is invalid.\n");
			return INT_MIN;
		}//if

		int absa = myAbs(a), absb = myAbs(b);
		int product = 0, x = 0;
		while (product + absb <= absa)
		{
			product += absb;
			++x;
		}//while

		if ((a<0 && b<0) || (a>0 && b>0))
			return x;
		else
			return negate(x);
	}
};

int main()
{
	Solution s;
	cout << s.minus(1, 2) << endl;
	cout << s.multi(1, 2) << endl;
	cout << s.divide(1, 2) << endl;

	system("pause");
	return 0;

}