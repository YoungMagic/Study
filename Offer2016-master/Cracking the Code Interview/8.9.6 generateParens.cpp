/*
* ������8.9.6 ʵ��һ���㷨����ӡn�����ŵ�ȫ����Ч��ϡ�
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution{
public:
	/*����һ���ݹ������ѵõ�n-1�����ŵĺϷ���ϣ�����ÿһ���Ϸ����
	 * ��1���ڵ�һ��������֮�����һ������
	 * ��2���ڵڶ���������֮�����һ������
	 * ��3�����ַ�����ͷ����һ������
	 */
	vector<string> generateParens1(int n)
	{
		unordered_set<string> us;
		if (0 == n)
			us.insert("");
		else
		{
			vector<string> tmp = generateParens1(n - 1);
			auto iter = tmp.begin();
			for (; iter != tmp.end(); ++iter)
			{
				/*����n-1��������*/
				int len = (*iter).length();
				for (int i = 0; i < len; ++i)
				{
					if ((*iter)[i] == '(')
					{
						/*��i֮�����һ������*/
						string str = (*iter).substr(0, i + 1) + "()" + (*iter).substr(i + 1, len - i - 1);
						us.insert(str);
					}//if
				}//for
				/*���ַ�����ͷ���루��*/
				string str = "()" + (*iter);
				us.insert(str);
			}//for	
		}//else
		return vector<string>(us.begin(), us.end());
	}
	/*
	* ����������ͷ��ʼ�����ַ������Ӷ���������ظ�������������У���һ���������Ż��������ţ�ֻҪ�ַ�����Ȼ��Ч��
	* �ж���Ч����1��ֻҪ�����Ż�û���꣬�Ϳ��Բ��������ţ���2��ֻ�кϷ���Ҳ���������Ÿ���С�ڵ��������žͿ��Բ��������š�
	*/
	vector<string> generateParens(int n)
	{
		vector<string> ret;
		string str(2*n,' ');
		addParen(ret, n, n, str, 0);

		return ret;
	}
	void addParen(vector<string> &ret, int leftRem, int rightRem, string str, int count)
	{
		//����������������С��0 ���߿������������С��������˵��Ŀǰ������ַ����Ƿ�
		if (leftRem < 0 || rightRem < leftRem)
			return;

		/*�����ſ���ӣ��õ�һ���Ϸ����*/
		if (leftRem == 0 && rightRem == 0)
		{
			ret.push_back(str);
		}//else
		else{
			/*���������ſ��ã�����һ��������*/
			if (leftRem > 0)
			{
				str[count] = '(';
				addParen(ret, leftRem - 1, rightRem, str, count + 1);
			}//if
			/*���ַ�����Ч������һ��������*/
			if (rightRem > leftRem)
			{
				str[count] = ')';
				addParen(ret, leftRem, rightRem - 1, str, count + 1);
			}//if
		}//else
	}	
};

int main()
{
	Solution s;
	vector<string> ret = s.generateParens(3);
	
	for (unsigned i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}//for

	system("pause");
	return 0;
}