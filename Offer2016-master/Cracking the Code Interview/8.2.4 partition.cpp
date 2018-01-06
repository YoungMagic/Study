/*
 * ������8.2.4 ��д���룬�Ը���ֵxΪ��׼������ָ�������֣�
 * ����С��x�Ľڵ����ڴ��ڵ���x�Ľڵ�֮ǰ��
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
	/*����һ��������������һ��������С��x��Ԫ�أ���һ����Ŵ���x��Ԫ�ء��������ʣ�����x����Ԫ�أ�*/
	ListNode *partition(ListNode *node, int x)
	{
		ListNode *lessHead = NULL, *bigHead = NULL;
		ListNode *lessEnd = NULL, *bigEnd = NULL;

		while (node)
		{
			//��������ڵ�
			ListNode *rear = node->next;
			node->next = NULL;

			if (node->val < x)
			{
				if (lessHead == NULL)
				{
					lessHead = node;
					lessEnd = lessHead;
				}//if
				else{
					lessEnd->next = node;
					lessEnd = node;
				}//else
			}//if
			else{
				if (bigHead == NULL)
				{
					bigHead = node;
					bigEnd = bigHead;
				}//if
				else{
					bigEnd->next = node;
					bigEnd = node;
				}//else
			}//else
			node = rear;
		}//while

		if (lessHead == NULL)
			return bigHead;

		/*�ϲ�*/
		lessEnd->next = bigHead;
		return lessHead;
	}

	/*��������ͬ�����������������ǲ���ͷ�巨����ԭʼ����ڵ�Ԫ��*/
	ListNode *partition2(ListNode *node, int x)
	{
		ListNode *lessHead = NULL, *bigHead = NULL;
		while (node)
		{
			ListNode *rear = node->next;

			if (node->val < x)
			{
				node->next = lessHead;
				lessHead = node;
			}
			else{
				node->next = bigHead;
				bigHead = node;
			}//else
			node = rear;
		}//while

		if (lessHead == NULL)
			return bigHead;

		/*��λ��lessHead��β�����ϲ���������*/
		ListNode *p = lessHead;
		while (p->next)
		{
			p = p->next;
		}//while
		p->next = bigHead;

		return lessHead;
	}

};

int main()
{
	ListNode *head = NULL;	
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 3);
	for (int i = 1; i <= 3; ++i)
		head = insert(head, i);

	display(head);

	Solution s;
	head = s.partition2(head, 4);
	display(head);
	

	system("pause");
	return 0;
}