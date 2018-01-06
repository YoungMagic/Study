/*
��Ŀ����дһ���࣬������ջʵ�ֶ��У�֧�ֶ��еĻ�������
ע�⣺
	1. ���stackPushҪ��stackPop��ѹ�����ݣ���ô����һ���԰�stackPush�е�����ȫ��ѹ�룻
	2. ���stackPop��Ϊ�գ�stackPush���Բ�����stackPop��ѹ������
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <cassert>

using namespace std;

class MyQueue{
private:
	stack<int> stackPush;
	stack<int> stackPop;

public:
	MyQueue(){}

	void push(int val)
	{
		stackPush.push(val);
	}

	void pop()
	{
		assert(!(stackPush.empty() && stackPop.empty()));
		if (stackPop.empty())
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}//while
		}
		else
		{
			stackPop.pop();
		}
	}

	int top()
	{
		assert(!(stackPush.empty() && stackPop.empty()));
		if (stackPop.empty())
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}//while
		}
		return stackPop.top();
	}
};

int main()
{
	MyQueue mq;

	mq.push(1);
	mq.push(2);
	cout << mq.top() << endl;
	mq.pop();

	cout << mq.top() << endl;

	mq.push(3);
	mq.push(4);
	cout << mq.top() << endl;
	mq.pop();

	cout << mq.top() << endl;
	system("pause");
	return 0;
}