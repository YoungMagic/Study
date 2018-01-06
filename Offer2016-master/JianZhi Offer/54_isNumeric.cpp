/*
������54�� ��ʾ��ֵ���ַ���

��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isExponential(string &str, int &idx)
{
	if (idx > str.size() || !(str[idx] == 'e' || str[idx] == 'E'))
	{
		return false;
	}

	++idx;
	if (str[idx] == '+' || str[idx] == '-')
		++idx;
	if (idx >= str.size())
		return false;
	/*�ҵ���һ�������ֵ��ַ�*/
	while (idx < str.size() && str[idx] >= '0' && str[idx] <= '9')
		++idx;
	return idx == str.size();

}
bool isNumeric(string str)
{
	if (str.empty())
		return false;

	int idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
		++idx;

	if (idx == str.size())
		return false;

	bool ret = true;
	/*�ҵ���һ�������ֵ��ַ�*/
	while (idx < str.size() && str[idx] >= '0' && str[idx] <= '9')
		++idx;

	if (idx < str.size())
	{
		if (str[idx] == '.')
		{
			++idx;
			/*�ҵ���һ�������ֵ��ַ�*/
			while (idx < str.size() && str[idx] >= '0' && str[idx] <= '9')
				++idx;
			if (idx == str.size())
				return true;
			else if (str[idx] == 'e' || str[idx] == 'E')
				return isExponential(str, idx);
			else
				return false;
		}
		else if (str[idx] == 'e' || str[idx] == 'E')
			return isExponential(str, idx);
		else
			return false;
	}
	else {
		if (idx == str.size())
			return true;
		return false;
	}
}

int main()
{
	cout << isNumeric("+100") << endl;
	cout << isNumeric("5e2") << endl;
	cout << isNumeric("-123") << endl;
	cout << isNumeric("1a3.14") << endl;

	system("pause");
	return 0;
}