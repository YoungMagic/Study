/*
* ������8.3.2 ���һ��ջ������push��pop��������֧��min�������ɷ���ջ�е���Сֵ��push��pop��min����ʱ�临�ӶȾ�������O(1)
* ������ʵ�ַ�ʽ��
* ��1������һ���������浱ǰջ����СԪ�أ�push��pop�����£���ʱpop��ʱ�临�Ӷ�Ϊ���ԣ�
* ��2������һ������ջ����ÿ��ʱ��ջ����СԪ�أ���ʱ����Ҫ����ռ䣻
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

class StackWithMin{
public:
	void push(int val)
	{		
		if (s.empty() || val < minVal)
			minVal = val;
		s.push(val);
	}

	int top()
	{
		return s.top();
	}

	int minV()
	{
		if (s.empty())
			return INT_MAX;
		return minVal;
	}

	int pop()
	{
		int ret = s.top();
		s.pop();

		//��ǰջ��Ԫ�ؼ�����СԪ�أ�������СԪ��
		if (ret == minVal)
		{
			vector<int> v;
			while (!s.empty())
			{
				v.push_back(s.top());
				s.pop();
			}//while

			//������СԪ��
			int len = v.size();
			minVal = v[0];
			for (int i = 0; i < len; ++i)
			{
				if (v[i] < minVal)
					minVal = v[i];
			}

			//��ԭջ��Ԫ��
			for (int i = 0; i < len; ++i)
			{
				s.push(v[i]);
			}//for
		}
		
		return ret;
	}
private:
	stack<int> s;
	int minVal;
};

class StackWithMin2{
public:
	void push(int val)
	{
		//������СԪ��
		if (nums.empty())
		{		
			minV.push(val);
		}
		else if (nums.top() > val)
		{
			minV.push(val);
		}
		else{
			minV.push(nums.top());
		}
		nums.push(val);
	}

	int pop()
	{
		int ret = nums.top();
		nums.pop();
		minV.pop();
		return ret;
	}

	int top()
	{
		return nums.top();
	}

	int min()
	{
		return minV.top();
	}

private:
	stack<int> nums;
	stack<int> minV;
};

int main()
{
	StackWithMin2 s;

	s.push(2);
	cout << s.min() << endl;
	s.push(1);
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;

	system("pause");
	return 0;

}