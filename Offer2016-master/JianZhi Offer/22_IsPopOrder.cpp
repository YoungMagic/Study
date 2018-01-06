/*
 * ջ��ѹ�롢��������
 * ��Ŀ����
 * ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
 * ����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
 * ����4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <stack>

using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		//�������
		if (pushV.size() != popV.size() || pushV.empty() || popV.empty())
			return false;

		bool ret = false;
		//��Ԫ�����и���
		int len = pushV.size();
		vector<int>::iterator pNextPush = pushV.begin(),
			pNextPop = popV.begin();

		stack<int> s;

		while (pNextPop != popV.end())
		{
			while (s.empty() || s.top() != *pNextPop)
			{
				if (pNextPush == pushV.end())
					break;

				s.push(*pNextPush);
				pNextPush++;
			}
			if (s.top() != *pNextPop)
				break;
			s.pop();
			pNextPop++;
		}//while
		if (s.empty() && pNextPop == popV.end())
			ret = true;
		return ret;
	}
};

//int main()
//{
//	vector<int> pushV = { 1, 2, 3, 4, 5 }, popV = { 4, 5, 3, 1, 2 };
//	Solution s;
//	cout << s.IsPopOrder(pushV, popV) << endl;
//
//	system("pause");
//	return 0;
//}