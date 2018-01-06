/*
������28 �ַ���������

��Ŀ��
����һ���ַ�������ӡ�����ַ������ַ����������С�
*/

#include <iostream>
#include <cstdlib>

using namespace std;


void Permutation(char *pStr, char *pBeg)
{
	/*�����ַ�*/
	if (*pBeg == '\0')
		cout << pStr << endl;
	else {
		for (char *pCh = pBeg; *pCh != '\0'; ++pCh)
		{
			char tmp = *pCh;
			*pCh = *pBeg;
			*pBeg = tmp;

			Permutation(pStr, pBeg + 1);

			tmp = *pCh;
			*pCh = *pBeg;
			*pBeg = tmp;
		}//for
	}//else
}

/*�ַ������к���*/
void Permutation(char *pStr)
{
	if (pStr == NULL)
		return;

	Permutation(pStr, pStr);
}

int main()
{
	/*�����ַ�������*/
	char str[] = "abc";
	Permutation(str);

	system("pause"); return 0;
}