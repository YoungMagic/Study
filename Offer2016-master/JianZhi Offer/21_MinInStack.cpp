/*
 * ����min������ջ
 * ��Ŀ����
 * ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min����
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Solution {
public:
	void push(int value) {
		m_data.push(value);

		if (m_min.empty() || m_min.top() > value)
			m_min.push(value);
		else
			m_min.push(m_min.top());

	}
	void pop() {
		m_data.pop();
		m_min.pop();
	}

	int top() {
		return m_data.top();
	}
	int min() {
		return m_min.top();
	}
private:
	stack<int> m_data;	//����ջ
	stack<int> m_min;	//����ջ���洢��ǰ����ջ������Ԫ�ص���Сֵ
};

//int main()
//{
//	Solution s;
//	s.push(1);
//	cout << s.min() << endl;
//	s.push(3);
//	cout << s.min() << endl;
//	s.push(2);
//	cout << s.min() << endl;
//
//	system("pause");
//	return 0;
//}