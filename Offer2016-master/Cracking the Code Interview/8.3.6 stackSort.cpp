/*
* ������8.3.6 ��ջʵ����������
* ���ֻ��ʹ��һ�������ջ�����ʱ���ݣ����ǲ��ý�Ԫ�ظ��Ƶ�������ݽṹ�У������飩��
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Solution{
public:
	stack<int> stackSort(stack<int> s)
	{
		if (s.empty())
			return s;

		stack<int> ret;
		while (!s.empty())
		{
			int tmp = s.top();
			s.pop();

			//�ҵ�tmp��retջ��Ӧ�ò����λ��
			while (!ret.empty() && ret.top() > tmp)
			{
				s.push(ret.top());
				ret.pop();
			}//while
			ret.push(tmp);
		}//while
		return ret;			
	}
};

int main()
{
	Solution s;

	stack<int> st;
	st.push(3);
	st.push(4);
	st.push(2);
	st.push(1);

	stack<int> ret = s.stackSort(st);
	while (!ret.empty())
	{
		cout << ret.top() << "\t";
		ret.pop();
	}//while
	cout << endl;

	system("pause");
	return 0;
}