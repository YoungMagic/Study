/*
5.3 ȥ���ַ�������������K��0���Ӵ���
��Ŀ��
����һ���ַ���str��һ������k�����str��������������k��0�ַ�����ʱ��
��k��������'0'�ַ�ȥ�������ش������ַ�����
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string removeKZeros(string &str,int k)
{
	if (str.empty())
		return NULL;

	int beg = -1, count = 0, len = str.size();
	for (int i = 0; i<len; ++i)
	{
		if (str[i] != '0')
		{
			if (count == k)
			{
				str = beg == -1 ? str.substr(count + 1) : str.substr(0, beg) + str.substr(beg + count);
				return str;
			}//if
			else{
				beg = -1;
				count = 0;
			}//else
		}//if
		else{
			if (-1 == beg)
				beg = i;
			++count;
		}//else
	}//for

	/*�ж��Ƿ�����k��0�������ַ���ĩβ*/
	if (count == k)
	{
		str = beg == -1 ? str.substr(count + 1) : str.substr(0, beg) + str.substr(beg + count);
	}//if

	return str;
}

int  main()
{
	string str = "A0000B000";
	cout << removeKZeros(str, 3) << endl;

	system("pause");
	return 0;

}