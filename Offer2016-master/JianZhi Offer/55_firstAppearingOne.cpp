/*������55 �ַ����е�һ�����ظ����ַ�

��Ŀ����ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 256;

char firstAppearingOne(string str)
{

	vector<int> pos(N, -1);
	if (str.empty())
		return '\0';
	int n = str.size();
	for (int i = 0; i < n; ++i)
	{
		/*����δ���ֹ���Ԫ�أ���������ֵ�λ��*/
		if (pos[str[i]] == -1)
			pos[str[i]] = i;
		//���ڳ��ֹ���Ԫ�أ���϶����ǽ�������һ�Σ�����ֵ��Ϊ�����-2��
		else
			pos[str[i]] = -2;
	}//for

	int minPos = numeric_limits<int>::max();
	char c;
	for (int i = 0; i < n; ++i)
	{
		if (pos[str[i]] >= 0 && minPos > pos[str[i]])
		{
			c = str[i];
			minPos = pos[str[i]];
		}
	}

	return c;
}

int main()
{
	cout << firstAppearingOne("google") << endl;


	system("pause");
	return 0;
}