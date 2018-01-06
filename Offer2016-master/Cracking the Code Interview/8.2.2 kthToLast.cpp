/*
 * 8.2.2 ʵ��һ���㷨�ҳ��������е�����k���ڵ�
 */

#include <iostream>
#include <cstdlib>
#include <unordered_set>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;

	ListNode(int x) :val(x), next(NULL){}
};

class IntWrapper{
public:
	int val = 0;
};

class Solution{
public:
	//����һ���ݹ�ʵ�֣�ʹ��ֵ����
	ListNode *kthToLast1(ListNode *head, int k, int &i)
	{
		if (k <= 0 || head == NULL)
			return NULL;

		ListNode *node = kthToLast1(head->next, k, i);
		++i;
		if (i == k)
		{
			return head;
		}
		return node;
	}

	//������������������
	ListNode *kthToLast2(ListNode *head, int k, IntWrapper &i)
	{
		if (k <= 0 || head == NULL)
			return NULL;

		ListNode *node = kthToLast2(head->next, k, i);
		i.val = i.val + 1;
		if (i.val == k)
			return head;
		return node;
	}

	//������������ָ��
	ListNode *kthToLast(ListNode *head, int k)
	{
		if (k <= 0 || head == NULL)
			return NULL;

		int i = 1;
		ListNode *p = head;
		while (p && i < k)
		{
			p = p->next;
			++i;
		}//while

		if (!p)
			return NULL;

		ListNode *q = p;
		p = head;
		while (q->next)
		{
			p = p->next;
			q = q->next;
		}//while
		return p;
	}

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

int main()
{
	ListNode *head = NULL;

	for (int i = 1; i <= 6; ++i)
		head = insert(head, i);

	display(head);

	Solution s;
	int i = 0;
	IntWrapper iw;
	ListNode *node = s.kthToLast2(head, 3,iw);

	cout << node->val << endl;

	system("pause");
	return 0;
}