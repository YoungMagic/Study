/*
5.1 �ж������ַ����Ƿ�Ϊ���δ�
��Ŀ�����������ַ���str1��str2�����str1��str2�г��ֵ��ַ�����һ������ÿ���ַ����ֵĴ���һ����
��ôstr1��str2��Ϊ���δʡ���ʵ�ֺ����ж������ַ����Ƿ�Ϊ���δʡ�
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*����һ������*/
bool isDeformation(string str1, string str2)
{
	int len1 = str1.length(), len2 = str2.length();

	if (len1 != len2)
		return false;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	return str1 == str2;
}

/*����������ϣ�������ַ���ӦASCII�� 0~255*/
bool isDeformation2(string str1, string str2)
{
	if (str1.size() != str2.size())
		return false;

	vector<int> v(256, 0);
	for (auto &c : str1)
	{
		++v[c];
	}//for

	for (auto &c : str2)
	{
		--v[c];
		if (v[c] < 0)
			return false;
	}//for
	return true;
}

int main()
{
	string s1 = "124", s2 = "241";
	cout << isDeformation(s1, s2) << endl;
	cout << isDeformation2(s1, s2) << endl;

	system("pause");
	return 0;
}

