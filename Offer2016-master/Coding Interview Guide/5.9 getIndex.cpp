/*
5.9 �����򵫺��пո�������в����ַ���
��Ŀ��
����һ���ַ�������strs[]����strs����Щλ��Ϊnull�����ڲ�Ϊnull��λ���ϣ�
���ַ����ǰ��ֵ�˳����С�������γ��ֵġ��ٸ���һ���ַ���str���뷵��str��
strs�г��ֵ������λ�á�
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int getIndex(vector<string> strs, string str)
{
	if (strs.empty())
		return -1;
	int lhs = 0, rhs = strs.size() - 1;
	/*�洢�±���*/
	int pos = -1;
	while (lhs <= rhs)
	{
		int mid = (lhs + rhs) / 2;
		if (!strs[mid].empty())
		{
			if (strs[mid] == str)
			{
				pos = mid;
				rhs = mid - 1;
			}//if
			else if (strs[mid] < str)
			{
				lhs = mid + 1;
			}//if
			else
				rhs = mid - 1;
		}//if
		else
		{
			int i = mid;
			while (strs[i].empty() && --i >= lhs)
				;
			if (i < lhs || strs[i] < str)
				lhs = mid + 1;
			else
			{
				pos = strs[i] == str ? i : pos;
				rhs = i - 1;
			}//else
		}//else
	}
	return pos;
}

int main()
{
	vector<string> v = { "a", "a", string(), string(), "a", "b", string(), "c" };

	cout << getIndex(v, "a") << endl;

	system("pause");
	return 0;
}