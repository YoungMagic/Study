/*
5.7 �ַ�����ͳ���ַ���

��Ŀ������һ���ַ���str������str��ͳ���ַ��������磬��aaabbadddffc��
��ͳ���ַ���Ϊa3b2a1d3f2c1

������Ŀ������һ���ַ�����ͳ���ַ���cstr���ٸ���һ������index������cstr������
��ԭʼ�ַ����ĵ�index���ַ���
����a_1_b_100�������ԭʼ�ַ����ϵ�0���ַ�Ϊ'a'����50���ַ�Ϊ'b'
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*������Ŀ*/
string countStr(const string str)
{
	if (str.empty())
		return NULL;

	string res;
	res += str[0];
	int len = str.length(), count = 1;
	for (int i = 1; i < len; ++i)
	{
		if (str[i] == str[i - 1])
			++count;
		else{
			char c = count + '0';
			res = res + '_' + c + '_' + str[i];
			count = 1;
		}//else
	}//for
	char c = count + '0';
	res = res + '_' + c;

	return res;
}

/*������Ŀ*/
char getChar(const string str, int idx)
{
	if (str.empty())
		return '\0';

	/*�����ͳ���ַ����ĳ��ȣ��ж��Ƿ�Խ��*/
	int len = str.length();
	if (idx < 0 || idx >= len)
		return '\0';

	/*flag����ǰ�ַ�״̬��Ϊtrue����Ϊ��ĸ��Ϊfalse����Ϊͳ������*/
	bool flag = true;
	/*count��¼Դ���ĵ�ǰ�ַ�����*/
	int sum = 0, count = 0;
	char pre = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '_')
		{
			flag = !flag;
			continue;
		}//if
		/*��ǰ����ĸ*/
		else if (flag)
		{
			sum += count;
			if (sum > idx)
				return pre;
			else{
				/*���浱ǰ�ַ�*/
				pre = str[i];
				count = 0;
			}//else
		}//elif
		else{
			/*���µ�ǰ�ַ���ͳ������*/
			count = count * 10 + str[i] - '0';
		}//else
	}//for

	if (sum + count > idx)
		return pre;
	return 0;
}

//int main()
//{
//	cout << countStr("aaabbadddffc") << endl;
//
//	cout << getChar("a_3_b_2_a_1_d_3_f_2_c_1", 6) << endl;
//	system("pause");
//	return 0;
//}