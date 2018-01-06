/************************************************************************/
/*
����
���7�й����ֵĸ���������7�ı��������а���7�����֣���17��27��37...70��71��72��73...���ĸ���
֪ʶ��	ѭ��
����ʱ������	0M
�ڴ�����	0
����
һ��������N��(N������30000)
���
������N����7�йص����ָ�������������20����7�йص����ְ���7,14,17.
��������	20
�������	3                                                                    
*/
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAX = 30000;

bool isConnect(int num)
{
	if (num <7 || num > MAX)
		return false;
	else if (num % 7 == 0)
		return true;
	else{
		while (num > 0)
		{
			if (num % 10 == 7)
				return true;
			else
				num /= 10;
		}//while
		return false;
	}

}
int main()
{
	int num;
	cin >> num;
	int count = 0;
	for (int i = 7; i <= num;++i)
		if (isConnect(i))
			++count;
	cout << count << endl;
	system("pause");
	return 0;
}