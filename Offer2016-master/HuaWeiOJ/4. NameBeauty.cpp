/*
����
����һ�����֣���������26���ַ�����ɣ���������ַ����ġ�Ư���ȡ�����������ĸ��Ư���ȡ����ܺ͡�
ÿ����ĸ����һ����Ư���ȡ�����Χ��1��26֮�䡣û���κ�������ĸӵ����ͬ�ġ�Ư���ȡ�����ĸ���Դ�Сд��
����������֣�����ÿ�����������ܵġ�Ư���ȡ���
֪ʶ��	�ַ���
����ʱ������	0M
�ڴ�����	0
����
����N������N������
N���ַ�����ÿ����ʾһ������

���
ÿ�����ƿ��ܵ����Ư���̶�
��������	2 zhangsan lisi
�������	192 101
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**/
int cmp(const int &a, const int &b)
{
	if (a > b)
		return 1;
	else
		return 0;
}

/*���ù�ϣ��˼�룬����ÿ���ַ����ֵĴ���*/
const int N = 256;
int maxBeautyValue(string name)
{
	if (name.empty())
		return 0;

	int ret = 0;
	vector<int> letters(N, 0);
	int len = name.length();
	for (int i = 0; i < len; ++i)
	{
		if (name[i] >= 'A' && name[i] <= 'Z')
			++letters[name[i] - 'A' + 'a' - '0'];
		else if (name[i] >= 'a' && name[i] <= 'z')
			++letters[name[i] - '0'];
		else
		{
			cout << "wrong input name!" << endl;
			return -1;
		}
	}//for
	/*�����ַ�������������*/
	sort(letters.begin() , letters.end() , cmp);
	for (int i = 0, tmp = 26; i < len; ++i)
	{
		if (letters[i] > 0)
		{
			ret += (letters[i] * tmp);
			--tmp;
		}//if
	}//for
	return ret;
}

int main()
{
	int N;
	cin >> N;
	char name[1024];
	int beautyValue = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> name;
		cout << maxBeautyValue(name) << endl;
	}//for

	system("pause");
}