/*
 * ������8.2.7 ��дһ����������������Ƿ�Ϊ���ġ�
 */


#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;

	ListNode(int x) :val(x), next(NULL){}
};

//β�巨
ListNode *insert(ListNode *head, int val)
{
	ListNode *node = new ListNode(val);

	if (head == NULL)
	{
		head = node;
		return head;
	}
	else{
		ListNode *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}//while
		p->next = node;
	}
	return head;
}

void display(ListNode *head)
{
	if (head)
	{
		cout << head->val;
	}
	ListNode *p = head->next;
	while (p)
	{
		cout << "��>" << p->val;
		p = p->next;
	}//while
	cout << endl;
}

class Solution{
public:
	//����һ�������������鱣��Ԫ�أ�ֱ���ж������Ƿ�Ϊ��������
	bool isPalindrome1(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return true;

		vector<int> v;
		ListNode *p = head;
		while (p)
		{
			v.push_back(p->val);
			p = p->next;
		}//while

		int lhs = 0, rhs = v.size() - 1;
		while (lhs < rhs)
		{
			if (v[lhs++] != v[rhs--])
				return false;
		}//while

		return true;
	}

	//����������תԭʼ�����Ա���������ԭʼ�����Ƿ���ͬ
	bool isPalindrome2(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return true;

		ListNode *rHead = NULL;
		ListNode *p = head;
		while (p)
		{
			ListNode *node = new ListNode(p->val);
			node->next = rHead;
			rHead = node;

			p = p->next;
		}//while

		p = head;
		ListNode *q = rHead;
		while (p && q)
		{
			if (p->val != q->val)
				return false;
			p = p->next;
			q = q->next;
		}//while
		return true;
	}
	
	//����������������Ҫ̽�������ǰ�벿���Ƿ�Ϊ��벿�ַ�ת���ɣ�ֻ��Ҫ��ǰ�벿������ת������ջʵ�֡�
	bool isPalindrome2(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return true;

		ListNode *slow = head, *fast = head;
		stack<int> st;
		/*�������ǰ�벿����ջ����fastָ�루�ƶ��ٶ�Ϊ����ָ�����������������β��ʱ������ָ�뵽���м�λ��*/
		while (slow && fast->next)
		{
			st.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}//while

		//��Ϊ������Ԫ��ʱ�������м�Ԫ��
		if (fast)
		{
			slow = slow->next;
		}//if

		while (slow)
		{
			if (slow->val != st.top())
				return false;
			slow = slow->next;
			st.pop();
		}//while

		return true;
	}


};

int main()
{
	ListNode *head = NULL;

	for (int i = 1; i <= 3; ++i)
		head = insert(head, i);
	for (int i = 3; i > 0; --i)
		head = insert(head, i);

	display(head);

	Solution s;
	cout << s.isPalindrome1(head) << endl;
	cout << s.isPalindrome2(head) << endl;

	system("pause");
	return 0;
}