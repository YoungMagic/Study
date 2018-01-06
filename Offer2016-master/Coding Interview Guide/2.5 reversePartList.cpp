/*
��Ŀ����ת���ֵ�������
Ҫ��
	����һ�����������ͷ���head���Լ���������from��to���ڵ��������ϰѵ�from
	���ڵ㵽��to���ڵ���һ���ֽ��з�ת
	�磺
	1->2->3->4->5->null  from = 2, to = 4 ��ת��
	1->4->3->2->5->null
	���磺
	1->2->3->null  from = 1, to = 3 ��ת��
	3->2->1->null
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL){}
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


/*��ת���ֵ�������*/
ListNode *reversePartList(ListNode *head, int from , int to)
{
	if (!head || from < 1 || from >= to)
		return head;
	ListNode *pre = head, *p = head, *tmpHead = NULL, *tmpEnd = NULL;
	int idx = 1;
	while (idx < from)
	{
		pre = p;
		p = p->next;
		++idx;
	}//while


	if (idx == 1)
	{
		head = NULL;
	}//if
	else{
		while (idx <= to && p)
		{
			ListNode *r = p->next;
			if (!head)
			{
				head = p;
				head->next = NULL;				
			}//if
			else if (idx == from)
			{
				/*��ת���ֵ�ͷ��β*/
				tmpHead = p;
				tmpEnd = p;
				tmpHead->next = NULL;
			}
			else{
				p->next = tmpHead;		
				tmpHead = p;
				pre->next = tmpHead;
			}//else
			p = r;
			++idx;
		}//while
	}//else
	tmpEnd->next = p;
	return head;
}


int main()
{
	ListNode *head = NULL;
	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	head = reversePartList(head, 2, 4);
	display(head);

	
	system("pause");
	return 0;
}