/*
���������������������

����������ÿһ���ڵ��ֵ����0~9֮�䣬��ô��������Ϳ��Դ���һ������(��λ��ǰ��λ�ں�)��
���� 9��>3��>7����937
�����������������ͷ���head1��head2,�����ɴ��������������ֵ�Ľ������

���� 9��>3��>7 + 6��>3 = 1��>0��>0��>0
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode *rand;
	ListNode(int v) :val(v), next(NULL), rand(NULL){}
};

ListNode *insert(ListNode *head, int val)
{
	if (!head)
		head = new ListNode(val);
	else{
		ListNode *p = head;
		while (p->next)
			p = p->next;
		p->next = new ListNode(val);
	}//else
	return head;
}


void display(ListNode *head)
{
	if (!head)
		cout << endl;
	else{
		ListNode *p = head;
		while (p->next)
		{
			cout << p->val << "��>";
			p = p->next;
		}//while
		cout << p->val << endl;
	}//else
}

/*����һ������ջ��Ϊ�����ṹ*/
ListNode *addList1(ListNode *head1, ListNode *head2)
{
	if (!head1)
		return head2;
	else if (!head2)
		return head1;

	stack<int> stk1, stk2;
	ListNode *p = head1;
	while (p)
	{
		stk1.push(p->val);
		p = p->next;
	}//while

	p = head2;
	while (p)
	{
		stk2.push(p->val);
		p = p->next;
	}//while

	/*��ͺ��������ͷ*/
	ListNode *rHead = NULL;
	/*�洢��λ*/
	int carry = 0;
	while (!stk1.empty() && !stk2.empty())
	{
		int sum = stk1.top() + stk2.top() + carry;
		stk1.pop();
		stk2.pop();

		ListNode *node = new ListNode(sum % 10);
		carry = sum / 10;
		if (!rHead)
		{
			rHead = node;
			rHead->next = NULL;
		}
		/*ͷ�巨*/
		else{
			node->next = rHead;
			rHead = node;
		}//else
	}//while

	while (!stk1.empty())
	{
		int sum = stk1.top() + carry;
		stk1.pop();
		ListNode *node = new ListNode(sum % 10);
		carry = sum / 10;
		if (!rHead)
		{
			rHead = node;
			rHead->next = NULL;
		}
		/*ͷ�巨*/
		else{
			node->next = rHead;
			rHead = node;
		}//else
	}//while
	while (!stk2.empty())
	{
		int sum = stk2.top() + carry;
		stk2.pop();
		ListNode *node = new ListNode(sum % 10);
		carry = sum / 10;
		if (!rHead)
		{
			rHead = node;
			rHead->next = NULL;
		}
		/*ͷ�巨*/
		else{
			node->next = rHead;
			rHead = node;
		}//else
	}//while

	if (carry != 0)
	{
		ListNode *node = new ListNode(carry);
		if (!rHead)
		{
			rHead = node;
			rHead->next = NULL;
		}
		/*ͷ�巨*/
		else{
			node->next = rHead;
			rHead = node;
		}//else
	}//if
	return rHead;
}

/*��������ͷ�巨����������ͣ����򴴽��������*/
ListNode *addList2(ListNode *head1, ListNode *head2)
{
	if (!head1)
		return head2;
	else if (!head2)
		return head1;
	ListNode *p = head1->next;
	head1->next = NULL;
	while (p)
	{
		ListNode *r = p->next;
		p->next = head1;
		head1 = p;

		p = r;
	}//while

	p = head2->next;
	head2->next = NULL;
	while (p)
	{
		ListNode *r = p->next;
		p->next = head2;
		head2 = p;

		p = r;
	}//while

	ListNode *rHead = NULL;
	int carry = 0;
	while (head1 && head2)
	{
		int sum = head1->val + head2->val + carry;
		ListNode *node = new ListNode(sum % 10);
		carry = sum / 10;

		if (!rHead)
		{
			rHead = node;
			rHead->next = NULL;
		}
		else{
			node->next = rHead;
			rHead = node;
		}//else

		head1 = head1->next;
		head2 = head2->next;
	}//while

	while (head1)
	{
		int sum = head1->val + carry;
		ListNode *node = new ListNode(sum % 10);
		carry = sum / 10;

		if (!rHead)
		{
			rHead = node;
			rHead->next = NULL;
		}
		else{
			node->next = rHead;
			rHead = node;
		}//else

		head1 = head1->next;
	}//while

	while (head2)
	{
		int sum = head2->val + carry;
		ListNode *node = new ListNode(sum % 10);
		carry = sum / 10;

		if (!rHead)
		{
			rHead = node;
			rHead->next = NULL;
		}
		else{
			node->next = rHead;
			rHead = node;
		}//else

		head2 = head2->next;
	}//while

	if (carry != 0)
	{
		ListNode *node = new ListNode(carry);
		if (!rHead)
		{
			rHead = node;
			rHead->next = NULL;
		}
		else{
			node->next = rHead;
			rHead = node;
		}//else
	}//if

	return rHead;
}

int main()
{
	ListNode *head = NULL;
	head = insert(head, 9);
	head = insert(head, 0);
	head = insert(head, 4);
	ListNode *head2 = NULL;
	head2 = insert(head2, 4);
	head2 = insert(head2, 5);
	head2 = insert(head2, 1);

	display(head);
	cout << "+" << endl;
	display(head2);
	cout << "=" << endl;
	display(addList1(head, head2));

	cout << endl;
	display(head);
	cout << "+" << endl;
	display(head2);
	cout << "=" << endl;
	display(addList2(head, head2));

	system("pause");
	return 0;

}
