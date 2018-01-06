/*
������13 ��O(1)��ʱ��ɾ������ڵ�
��Ŀ���������������ͷָ���һ���ڵ�ָ�룬����һ��������O(1)ʱ��ɾ���ýڵ㡣
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL){}

	bool operator==(ListNode *node)
	{
		return this->val == node->val;
	}

	bool operator!=(ListNode *node)
	{
		return !(this == node);
	}
};

void deleteNode(ListNode **head, ListNode *node)
{
	if (!head || !node)
		return ;
	/*��Ҫɾ����Ŀ�Ľڵ㲻��β�ڵ�*/
	else if (node->next != NULL)
	{
		ListNode *tmp = node->next;
		node->val = node->next->val;

		node->next = node->next->next;
		delete tmp;
		tmp = NULL;
	}//elif
	/*��Ҫɾ��β�ڵ���������ֻ��һ���ڵ�*/
	else if (*head == node)
	{
		delete *head;
		*head = NULL;
	}
	/*ɾ��������β�ڵ㣬����˳��������ҵ�β�ڵ��ǰ��*/
	else{
		ListNode *p = *head;
		while (p->next != node)
		{
			p = p->next;
		}//while

		p->next = NULL;
		delete node;
		node = NULL;
	}//else
}

void insert(ListNode **head, ListNode *node)
{
	if (node == NULL)
		return;
	else if (head == NULL || (*head) == NULL)
	{
		*head = node;
		return;
	}//elif
	else{
		ListNode *p = *head;
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}//else
}

void display(ListNode *head)
{
	ListNode *p = head;
	while (p)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	ListNode *head = NULL;
	
	ListNode *p = new ListNode(2);
	insert(&head, p);

	ListNode *q = new ListNode(3);
	insert(&head, q);

	ListNode *r = new ListNode(4);
	insert(&head, r);


	display(head);

	deleteNode(&head,q);

	display(head);

	/*��ʱrָ���ѱ�ɾ��������ֵ������q*/
	deleteNode(&head,q);

	display(head);

	deleteNode(&head, p);

	display(head);

	system("pause");
	return 0;

}