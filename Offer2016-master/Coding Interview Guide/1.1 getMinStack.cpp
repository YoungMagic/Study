/*
��Ŀ�����һ����getMin���ܵ�ջ page 1
Ҫ��
	1. pop��push��getMin������ʱ�临�Ӷȶ���O(1)
	2. ��Ƶ�ջ�����ʹ���ֳɵ�ջ�ṹ
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <stack>

using namespace std;

/*����һ*/
class MinStack1{
public:
	void push(int val)
	{
		if (stackMin.empty())
			stackMin.push(val);
		else if (stackMin.top() > val)
			stackMin.push(val);

		stackData.push(val);
	}

	int pop()
	{
		assert(!stackData.empty());

		int ret = stackData.top();
		if (ret == stackMin.top())
			stackMin.pop();

		stackData.pop();

		return ret;
	}

	int getMin()
	{
		assert(!stackMin.empty());
		return stackMin.top();	
	}
private:
	stack<int> stackData;
	stack<int> stackMin;
};
/*����2*/
class MinStack2{
public:
	void push(int val)
	{
		this->values.push(val);
		/*���浱ǰջ�е���СԪ��*/
		if (minVal.empty())
			minVal.push(val);
		else if (val < minVal.top())
			minVal.push(val);
		else
			minVal.push(minVal.top());
	}


	int pop()
	{
		/*���*/
		assert(!values.empty());
		int ret = values.top();
		values.pop();
		minVal.pop();

		return ret;
	}

	int getMin()
	{
		return minVal.top();
	}

	bool isEmpty()
	{
		return values.empty();
	}

	int top()
	{
		return values.top();
	}
private:	
	/*�����ṹ*/
	stack<int> minVal;
	stack<int> values;
};

int main()
{
	MinStack1 stk1;
	MinStack2 stk2;

	for (int i = 8; i > 1; --i)
	{
		stk1.push(i);
		stk2.push(i);
	}//for

	cout << stk1.getMin() << endl;
	cout << stk2.getMin() << endl;

	system("pause");
	return 0;
}