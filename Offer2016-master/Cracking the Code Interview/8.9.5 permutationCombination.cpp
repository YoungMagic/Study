/*
* ������8.9.5 ��дһ������ȷ��ĳ�ַ���������������ϣ�
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> permutations(string s)
	{
		vector<string> ret = vector<string>();
		if (s.empty())
			return ret;
		int len = s.length();
		if (len == 1)
		{
			ret.push_back(s);
		}//else
		else{
			/*�õ���β��ĸ����Ӵ���ȫ������*/
			vector<string> tmp = permutations(s.substr(0, len - 1));

			auto iter = tmp.begin();
			for (; iter != tmp.end(); ++iter)
			{
				/*ÿ���Ӵ������г���Ϊlen-1,����len���տɹ�β��ĸ����*/
				for (int j = 0; j <= len - 1; ++j)
				{
					/*��ò���ÿ����϶���õ���ȫ����һ������*/
					string str = (*iter).substr(0, j) + s[len - 1] + (*iter).substr(j, len - j);
					ret.push_back(str);
				}//for
			}//for
		}//else
		return ret;	
	}
};

int main()
{
	Solution s;
	vector<string> ret = s.permutations("abcd");
	
	for (unsigned i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}//for

	system("pause");
	return 0;
}