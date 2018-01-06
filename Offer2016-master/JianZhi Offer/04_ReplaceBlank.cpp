#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

/*
 * �滻�ո�
 * ��Ŀ����
 * ��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
 * ���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
 */
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (length <= 0 || str == NULL)
			return;
		
		int blankCount = 0 , len = 0;

		//�����ַ����еĿո����,�Լ�Դ������
		for (int i = 0; str[i] != '\0'; ++i)
		{
			if (' ' == str[i])
				++blankCount;
			++len;
		}//for

		//�滻֮����ַ�������
		int newLen = len + 2 * blankCount;

		//����������
		if (newLen > length)
			return;

		str[newLen] = '\0';

		for (int i = newLen - 1, j = len - 1; i >= 0 && j >= 0; --j)
		{
			if (str[j] != ' ')
			{
				str[i] = str[j];
				--i;
			}//if
			else{
				str[i] = '0';
				str[--i] = '2';
				str[--i] = '%';
				--i;
			}//else
		}//for

	}
};

int main()
{
	Solution s;

	char *str = new char[50];

	gets(str);

	s.replaceSpace(str, 50);

	cout << str << endl;

	system("pause");
	return 0;
}