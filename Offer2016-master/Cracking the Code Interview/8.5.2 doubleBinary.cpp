/*
* ������8.5.2 ��0~1֮���ʵ����32λ�����Ʊ�ʾ��
* ����һ������0��1֮���ʵ���磨0.72������Ϊdouble����ӡ���Ķ����Ʊ�ʾ��
* ����������޷���ȷ����32λ���ڵĶ����Ʊ�ʾ����ӡERROR��
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class Solution{
public:
	//��2��1�Ƚ�
	string doubleBinary(double num)
	{
		if (num >= 1 || num <= 0)
			return "ERROR";

		string ret = ".";
		while (num)
		{
			if (ret.length() > 32)
				return "ERROR";
			num *= 2;
			if (num >= 1)
			{
				ret += '1';
				num -= 1;
			}
			else{
				ret += '0';
			}//else
		}//while
		return ret;
	}

	//��2��1�Ƚ�
	string doubleBinary2(double num)
	{
		if (num >= 1 || num <= 0)
			return "ERROR";

		string ret = ".";
		double tmp = 0.5;
		while (num)
		{
			if (ret.length() > 32)
				return "ERROR";
			if (num >= tmp)
			{
				ret += '1';
				num -= tmp;
			}
			else{
				ret += '0';
			}//else
			tmp /= 2;
		}//while
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.doubleBinary(0.75) << endl;

	system("pause");
	return 0;
}