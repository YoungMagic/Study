/*
* ������8.2.5 ���������������ʾ��������ÿ���ڵ����һ����λ����Щ��λ�Ƿ����ŵģ�Ҳ���Ǹ�λ���������ײ���
* ��д�����������������ʾ��������ͣ�����������ʽ���ؽ����
*
* ���ף�����λ������ʱ������ʵ��һ�顣
*/

#include <iostream>
#include <cstdlib>

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

//���������
class PartialSum{
public:
	ListNode *sum = NULL;
	int carry = 0;
};

class Solution{
public:
	/* ���ף���λ��������,�������ʵ�֣�����һ����������ͷ�巨��������ת��Ȼ��������溯��ʵ�֣�
	* ����ʹ������һ�ַ���ʵ�֣�
	*/
	ListNode *addLists2(ListNode *head1, ListNode *head2)
	{
		if (head1 == NULL)
			return head2;
		else if (head2 == NULL)
			return head1;

		//����������ĳ���
		int len1 = 0, len2 = 0;
		ListNode *p = head1, *q = head2;
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

		//��0Ԫ�ؽڵ����϶�������ײ�
		if (len1 < len2)
		{
			head1 = padList(head1, len2 - len1);
		}
		else{
			head2 = padList(head2, len1 - len2);
		}//else
		
		//�������������
		PartialSum *sum = addListHelper(head1, head2);

		//����н�λ����������ײ������޽�λ��ֱ�ӷ���
		if (sum->carry == 0)
			return sum->sum;
		else{
			ListNode *result = insertBefore(sum->sum, sum->carry);
			return result;
		}//else
		
	}

	PartialSum *addListHelper(ListNode *head1, ListNode *head2)
	{
		if (head1 == NULL && head2 == NULL)
		{
			PartialSum *sum = new PartialSum();
			return sum;
		}

		//�Խ�С���ֵݹ����
		PartialSum *sum = addListHelper(head1->next, head2->next);

		//����λ�͵�ǰ�������
		int val = sum->carry + head1->val + head2->val;

		//���뵱ǰ��ͽ��
		ListNode *full_result = insertBefore(sum->sum, val % 10);

		//������ͽ���ͽ�λֵ
		sum->sum = full_result;
		sum->carry = val / 10;

		return sum;
	}

	//����Ԫ�ؽڵ㵽�����ײ�
	ListNode *insertBefore(ListNode *head, int data)
	{
		ListNode *node = new ListNode(data);
		node->next = head;
		head = node;

		return head;
	}
	//������head���ײ������len��ֵΪ0�Ľڵ�
	ListNode* padList(ListNode *head, int len)
	{
		for (int i = 0; i < len; ++i)
		{
			ListNode *node = new ListNode(0);
			if (head == NULL)
				head = node;
			else{
				node->next = head;
				head = node;
			}
		}//for
		return head;
	}
};

int main()
{
	ListNode *head1 = NULL, *head2 = NULL, *head = NULL;

	head1 = insert(head1, 6);
	head1 = insert(head1, 1);
	head1 = insert(head1, 7);

	display(head1);
	head2 = insert(head2, 2);
	head2 = insert(head2, 9);
	head2 = insert(head2, 5);

	display(head2);

	Solution s;
	head = s.addLists2(head1, head2);

	display(head);

	system("pause");
	return 0;
}