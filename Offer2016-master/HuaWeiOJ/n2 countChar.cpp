/*
��Ŀ����
д��һ�����򣬽���һ������ĸ�������Լ��ո���ɵ��ַ�������һ���ַ���Ȼ����������ַ����к��и��ַ��ĸ����������ִ�Сд��

��������:
����һ������ĸ�������Լ��ո���ɵ��ַ�������һ���ַ���

�������:
��������ַ����к��и��ַ��ĸ�����

��������:
ABCDEF
A

�������:
1
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int countC(string str, char c)
{
	int ret = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (c == str[i])
			++ret;
	}//for
	return ret;
}

//int main()
//{
//	string str; 
//	char c;
//	getline(cin, str);
//	cin >> c;
//	cout << countC(str, c) << endl;
//
//	system("pause");
//	return 0;
//}