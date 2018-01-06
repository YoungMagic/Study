/*
* ������8.3.3 ������һ�����ӣ���̫�߿��ܻᵹ�¡��������ʵ�����У����Ӷѵ�һ���߶�ʱ�����Ǿͻ������һ�����ӡ�
* ��ʵ�����ݽṹSetOfStacks��ģ��������Ϊ��SetOfStacksӦ���ɶ��ջ��ɣ�������ǰһ��ջ����ʱ���½�һ��ջ�����⣬push��pop����
* Ӧ������ͨջ��ͬ��
* ���ף�ʵ��һ��popAt(int index)����������ָ������ջ��ִ��pop������
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

const int MAXSIZE = 2;

class SetOfStacks{
public:
	void push(int val)
	{
		//ѹ�����һ���ǿ�ջ
		if (stacks.empty())
		{
			stack<int> s;
			s.push(val);
			stacks.push_back(s);
		}
		else{
			//�ҵ����һ���ǿ�ջ
			int idx = stacks.size() - 1;
			while (idx != 0 && stacks[idx].empty())
			{
				--idx;
			}
			//ģ�����һ��ջ��
			if (stacks[idx].size() == MAXSIZE)
			{
				//�ж��Ƿ���Ҫ��ջ
				if (idx == stacks.size() - 1)
				{
					stack<int> s;
					s.push(val);
					stacks.push_back(s);
				}
				//����Ҫ��ջ
				else{
					stacks[idx + 1].push(val);
				}
				
			}
			else{
				stacks[idx].push(val);
			}
		}
	}

	void pop()
	{
		//�ҵ����һ���ǿ�ջ
		int i = 0;
		while (i < stacks.size() && !stacks[i].empty())
		{
			++i;
		}
		stacks[i - 1].pop();
	}

	int top()
	{
		//�ҵ����һ���ǿ�ջ
		int i = 0;
		while (i < stacks.size() && !stacks[i].empty())
		{
			++i;
		}
		return stacks[i - 1].top();
	}
private:
	vector<stack<int> > stacks;
};

int main()
{
	SetOfStacks stacks;

	for (int i = 0; i < 4; ++i)
		stacks.push(i);
	cout << stacks.top() << endl;

	stacks.pop();
	cout << stacks.top() << endl;

	stacks.pop();
	cout << stacks.top() << endl;

	stacks.pop();
	cout << stacks.top() << endl;

	stacks.push(5);
	cout << stacks.top() << endl;

	stacks.push(6);
	cout << stacks.top() << endl;

	system("pause");
	return 0;



}