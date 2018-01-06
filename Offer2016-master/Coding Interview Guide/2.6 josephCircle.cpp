/*
Լɪ�����⣺
���룺һ�����������ͷ���head�ͱ�������ֵm
���أ�������������Ľڵ㣬������ڵ��Լ���ɻ��ε������������ڵ㶼ɾ����

���ף�
�������ڵ���ΪN������ʱ�临�Ӷ�ΪO(N)ʱ�����ԭ�����Ҫ�����ʵ�֣�
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
	{
		head = new ListNode(val);
		head->next = head;
	}
	else{
		ListNode *p = head;
		while (p->next != head)
			p = p->next;
		p->next = new ListNode(val);
		p->next->next = head;
	}//else
	return head;
}

void display(ListNode *head)
{
	if (!head)
		cout << endl;
	else{
		ListNode *p = head;
		while (p->next != head)
		{
			cout << p->val << "��>";
			p = p->next;
		}//while
		cout << p->val << endl;
	}//else
}

ListNode *josephCircle(ListNode *head, int m)
{
	if (!head || !head->next || m < 1)
		return head;
	ListNode *last = head;
	/*Ѱ������β�ڵ�*/
	while (last->next != head)
		last = last->next;

	/*��������*/
	int count = 0;
	while (head != last)
	{
		if (++count == m)
		{
			last->next = head->next;
			count = 0;
		}
		else{
			last = last->next;
		}//else
		head = last->next;
	}//while
	return head;
}

/*�������Ľڵ���*/
int getLive(int i, int m)
{
	if (i == 1)
		return 1;
	return (getLive(i - 1, m) + m - 1) % i + 1;
}
/*Լɪ�򻷽�������*/
ListNode *josephCircle2(ListNode *head, int m)
{
	if (!head || !head->next || m < 1)
		return head;
	ListNode *node = head->next;
	int len = 1;
	while (node != head)
	{
		++len;
		node = node->next;
	}//while

	int lastLive = getLive(len, m);
	while (--lastLive != 0)
		head = head->next;
	head->next = head;
	return head;
}


int main()
{
	ListNode *head = NULL;
	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	head = josephCircle(head, 3);
	display(head);

	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	head = josephCircle2(head, 3);
	display(head);

	system("pause");
	return 0;
}