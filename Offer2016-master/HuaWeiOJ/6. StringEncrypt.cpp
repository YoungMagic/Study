/************************************************************************/
/*
����
��Ŀ����
1����������ַ������мӽ��ܣ��������
2���ܷ���Ϊ��
��������Ӣ����ĸʱ���ø�Ӣ����ĸ�ĺ�һ����ĸ�滻��ͬʱ��ĸ�任��Сд,����ĸaʱ���滻ΪB����ĸZʱ���滻Ϊa��
������������ʱ��Ѹ����ּ�1����0�滻1��1�滻2��9�滻0��
�����ַ������仯��
3�����ܷ���Ϊ���ܵ�����̡�

�ӿ�������
ʵ�ֽӿڣ�ÿ���ӿ�ʵ��1������������
void Encrypt (char aucPassword[], char aucResult[])���ڸú�����ʵ���ַ������ܲ����
˵����
1���ַ�����\0��β��
2���ַ����100���ַ���

int unEncrypt (char result[], char password[])���ڸú�����ʵ���ַ������ܲ����
˵����
1���ַ�����\0��β��
2���ַ����100���ַ���
֪ʶ��	�ַ���
����ʱ������	10M
�ڴ�����	128
����
����˵��
����һ��Ҫ���ܵ�����
����һ���ӹ��ܵ�����
���
���˵��
������ܺ���ַ�
������ܺ���ַ�
��������	abcdefg BCDEFGH
�������	BCDEFGH abcdefg
*/
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*���ܺ���*/
void Encrypt(char aucPassword[], char aucResult[])
{
	int len = strlen(aucPassword);
	for (int i = 0; i < len; ++i)
	{
		char c = aucPassword[i];
		if (c >= '0' && c <= '9')
		{
			if (c == '9')
				aucResult[i] = '0';
			else
				aucResult[i] = c + 1;
		}//if
		else if (c >= 'A' && c <= 'Z')
		{
			if (c == 'Z')
				aucResult[i] = 'a';
			else
				aucResult[i] = c - 'A' + 'b';
		}//elif
		else if (c >= 'a' && c <= 'z')
		{
			if (c == 'z')
				aucResult[i] = 'A';
			else
				aucResult[i] = c - 'a' + 'B';
		}//elif
		else
			aucResult[i] = c;
	}//for
	aucResult[len] = '\0';
}

/*���ܺ���*/
void unEncrypt(char result[], char password[])
{
	int len = strlen(result);
	for (int i = 0; i < len; ++i)
	{
		char c = result[i];
		if (c >= '0' && c <= '9')
		{
			if (c == '0')
				password[i] = '9';
			else
				password[i] = c - 1;
		}//if
		else if (c >= 'A' && c <= 'Z')
		{
			if (c == 'A')
				password[i] = 'z';
			else
				password[i] = c - 'B' + 'a';
		}//elif
		else if (c >= 'a' && c <= 'z')
		{
			if (c == 'a')
				password[i] = 'Z';
			else
				password[i] = c - 'b' + 'A';
		}//elif
		else
			password[i] = c;
	}//for
	password[len] = '\0';
}

int main()
{
	char str[100], password[100];
	
	/*��������*/
	cin >> str;
	cin >> password;
	char strRet[128], pwdRet[128];
	Encrypt(str, strRet);
	unEncrypt(password, pwdRet);
	
	/*������ܽ��ܺ�Ľ��*/
	cout << strRet << endl;
	cout << pwdRet << endl;

	system("pause");
	return 0;
}