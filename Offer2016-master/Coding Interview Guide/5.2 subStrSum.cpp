/*
5.2 �ַ����������Ӵ������

��Ŀ������һ���ַ���str��������ȫ�����ִ������������֮�ͣ�
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*�ַ����������Ӵ������*/
int subStrSum(string str)
{
	if (str.empty())
		return 0;

	int res = 0, num = 0, cur = 0;
	bool flag = true;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		cur = str[i] - '0';
		if (cur<0 || cur>9)
		{
			res += num;
			num = 0;
			/*��������*/
			if (str[i] == '-')
			{
				if (i > 0 && str[i - 1] == '-')
					flag = !flag;
				else
					flag = false;
			}//if
			else{
				flag = true;
			}//else
		}//if
		else{
			num = num * 10 + (flag ? cur : -cur);
		}//else
	}//for

	/*�������һ�������Ӵ�ֵ����ĩβ���������Ӵ�num=0*/
	res += num;
	return res;
}

int main()
{
	string str = "A-1BC--12";
	cout << subStrSum(str) << endl;

	system("pause");
	return 0;
}