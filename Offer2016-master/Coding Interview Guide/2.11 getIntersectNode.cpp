/*
���������ཻ��һϵ������
�ڱ����У�����������л���Ҳ�����޻������������������ͷ���head1��head2������������
�����ཻ��Ҳ���ܲ��ཻ��ʵ��һ��������������������ཻ���뷵���ཻ�ĵ�һ���ڵ㣬���
���ཻ������null���ɡ�
Ҫ��
�������1�ĳ���ΪN������2�ĳ���ΪM����ʱ�临�Ӷ���ﵽO(N+M)���ռ临�Ӷ���ﵽO(1)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
public:
	int value;
	Node *next;

	Node(int val) :value(val), next(NULL){}
};

/*���ҵ�������뻷�ڵ㣬�����򷵻�NULL*/
Node *getLoopNode(Node *head)
{
	if (!head || head->next == NULL || head->next->next == NULL)
		return NULL;

	Node *slow = head->next;
	Node *fast = head->next->next;

	while (slow != fast)
	{
		if (fast->next == NULL || fast->next->next == NULL)
			return NULL;
		slow = slow->next;
		fast = fast->next->next;
	}//while

	/*slow��fast�ཻ����ʱ��fast����ָ��head�ڵ�*/
	fast = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}//while
	return slow;
}

/*�����޻�������ཻ�ڵ㣬�޽����򷵻�NULL*/
Node *getNoLoopIntersectNode(Node *head1, Node *head2)
{
	if (!head1 || !head2)
		return NULL;

	Node *p = head1, *q = head2;
	int len1 = 0, len2 = 0, len = 0;

	while (p)
	{
		++len1;
		p = p->next;
	}//while

	while (q)
	{
		++len2;
		q = q->next;
	}//while

	/*����1���ȴ�������2*/
	if (len1 > len2)
	{
		p = head1;
		q = head2;
		len = len1 - len2;
	}
	else{
		p = head2;
		q = head1;
		len = len2 - len1;
	}//else

	while (len > 0)
	{
		p = p->next;
		--len;
	}//while

	while (p != q)
	{
		p = p->next;
		q = q->next;
	}//while
	return p;
}

/*���������л�������ཻ�ڵ�*/
Node *getLoopIntersectNode(Node *head1, Node *loop1, Node *head2, Node *loop2)
{
	Node *cur1 = NULL, *cur2 = NULL;
	if (loop1 == loop2)
	{
		cur1 = head1;
		cur2 = head2;
		int n = 0;
		while (cur1 != loop1)
		{
			++n;
			cur1 = cur1->next;
		}//while

		while (cur2 != loop2)
		{
			--n;
			cur2 = cur2->next;
		}//while

		cur1 = n > 0 ? head1 : head2;
		cur2 = cur1 == head1 ? head2 : head1;

		n = n > 0 ? n : -n;
		while (n > 0)
		{
			cur1 = cur1->next;
			--n;
		}//while
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}//while
		return cur1;
	}//if
	else{
		cur1 = loop1->next;
		while (cur1 != loop1)
		{
			if (cur1 == loop2)
			{
				return loop1;
			}//if
			cur1 = cur1->next;
		}//while
		return NULL;
	}
}

/*���ҽ���ڵ�������*/
Node *getIntersectNode(Node *head1, Node *head2)
{
	/*�����������ཻ�ڵ�Ϊ��*/
	if (!head1 && !head2)
		return NULL;

	Node *loop1 = getLoopNode(head1);
	Node *loop2 = getLoopNode(head2);

	if (loop1 == NULL && loop2 == NULL)
		return getNoLoopIntersectNode(head1, head2);
	else if (loop1 != NULL && loop2 != NULL)
		return getLoopIntersectNode(head1, loop1, head2, loop2);
	else
		return NULL;
}

int main()
{

}