/*
2.20 �������Ұ����ķ�ʽ�����������
��Ŀ
����һ���������ͷ���ڵ�head��������ΪN�����NΪż������ôǰN/2���ڵ������������
��N/2���ڵ������Ұ��������NΪ��������ôǰN/2���ڵ��������������N/2+1���ڵ������Ұ�����
�����������������L1->L2->...�Ұ���������������R1->R2->R3->...���뽫�������Ϊ
L1->R1->L2->R2->...����ʽ��
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

ListNode *relocate(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	/*���ÿ���ָ�룬�ҵ�ǰ�벿�ֵ�β����벿�ֵ�ͷ*/
	ListNode *lEnd = head, *rHead = head->next;
	while (rHead->next && rHead->next->next)
	{
		lEnd = lEnd->next;
		rHead = rHead->next->next;
	}//while

	/*�Ұ�����ͷ���*/
	rHead = lEnd->next;
	/*�������β�ڵ�*/
	lEnd->next = NULL;
	

	/*�ϲ�*/
	ListNode *lp = head, *rp = rHead, *rNext=NULL;
	while (lp->next)
	{
		rNext = rp->next;
		rp->next = lp->next;
		lp->next = rp;

		lp = rp->next;
		rp = rNext;
	}//while
	lp->next = rNext;

	return head;
}

ListNode *insert(ListNode *head, int val)
{
	ListNode *node = new ListNode(val);
	if (head == NULL)
	{
		head = node;
		return head;
	}//if

	ListNode *p = head;
	while (p->next)
		p = p->next;
	p->next = node;
	return head;
}

void display(ListNode *head)
{
	if (head == NULL)
		return;

	cout << head->val;
	ListNode *p = head->next;
	while (p)
	{
		cout << "��>" << p->val;
		p = p->next;
	}//while
	cout << endl;
}

void deleteNodes(ListNode *head)
{
	if (head == NULL)
		return;

	while (head)
	{
		ListNode *p = head;
		head = head->next;
		delete p;
		p = NULL;
	}//while
}

int main()
{
	ListNode *head = NULL;
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);

	display(head);

	head = relocate(head);
	display(head);

	deleteNodes(head);
	system("pause");
	return 0;
}