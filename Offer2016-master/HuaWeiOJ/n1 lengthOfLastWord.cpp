/*
��Ŀ����
�����ַ������һ�����ʵĳ��ȣ������Կո������

��������:
һ���ַ�����

�������:
����N�����һ�����ʵĳ��ȡ�

��������:
hello world

�������:
5
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int lengthOfLastWord(string str)
{
	int length = str.length();
	int pos = str.find_last_of(" ");
	return length - pos - 1;
}

//int main()
//{
//	string str;
//	while (getline(std::cin, str))
//	{
//		cout << lengthOfLastWord(str) << endl;
//	}//while
//
//	system("pause");
//	return 0;
//}