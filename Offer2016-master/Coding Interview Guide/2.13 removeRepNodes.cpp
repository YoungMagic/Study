/*
2.13 ɾ������������ֵ�ظ����ֵĽڵ�

��Ŀ
����һ�����������ͷ���head��ɾ������ֵ�ظ����ֵĽڵ㡣
����һ�����������ΪN��ʱ�临�Ӷ�ΪO(N)
������������ռ临�Ӷ�ΪO(1)
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

/*����һ�����ù�ϣ��˼�룬����ռ临�Ӷ�ΪO(n)*/
ListNode *removeRep1(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	unordered_set<int> us;
	us.insert(head->val);

	ListNode *pre = head,*p = pre->next;
	while (p)
	{
		if (us.find(p->val) != us.end())
		{
			ListNode *tmp = p;
			pre->next = p->next;
			p = p->next;
			delete tmp;
			tmp = NULL;
		}//if
		else
		{
			us.insert(p->val);
			pre = pre->next;
			p = p->next;
		}//else
	}//while

	return head;
}

/*���������ռ临�Ӷ�ΪO(1)*/
ListNode *removeRep2(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *p = head;
	while (p)
	{
		/*p�ڵ��ֵΪp->val�Ľڵ�ȫ��ɾ��*/
		ListNode *pre = p,*q = p->next;
		while (pre && q)
		{
			if (q->val == p->val)
			{
				ListNode *tmp = q;
				q = q->next;
				pre->next = q;

				delete tmp;
				tmp = NULL;
			}//if
			else
			{
				pre = pre->next;
				q = q->next;
			}//else
		}//while
		p = p->next;
	}//while
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
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 4);
	head = insert(head, 2);
	head = insert(head, 1);

	display(head);

	head = removeRep2(head);
	display(head);

	deleteNodes(head);
	system("pause");
	return 0;
}
