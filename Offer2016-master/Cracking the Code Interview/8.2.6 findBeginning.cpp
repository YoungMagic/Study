/*
 * ������8.2.6 ����һ���л�����ʵ��һ���㷨���ػ�·�Ŀ�ͷ���
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
	//����һ�����������ṹ������δ����
	ListNode *findBegginning(ListNode *head)
	{
		if (head == NULL)
			return NULL;

		unordered_set<int> us;

		ListNode *p = head;
		while (true)
		{
			if (p->next)
			{
				unordered_set<int>::iterator iter = us.find(p->next->val);
				if (iter != us.end())
				{
					ListNode *q = head;
					while (q->val != *iter)
					{
						q = q->next;
					}//while
					return q;
				}
				else{
					us.insert(p->val);
					p = p->next;
				}
			}
			else{
				return NULL;
			}//else
		}//while
	}

	//������������ָ��ʵ��
	/*
	 * (1) ��������ָ�룺FastPointer �� SlowPointer
	 * (2) ����ָ��ÿ��һ��������ָ�����������
	 * (3) ��������һ��ʱ���ı�����ָ���ָ��SlowPointerָ��head������ָ��FastPointer���䣻
	 * (4) ����ͬ�ٶ��ƶ�SlowPointer��FastPointer��һ��һ����Ȼ�󷵻��µ���ײ����
	 */
	ListNode *findBegginning2(ListNode *head)
	{
		ListNode *slow = head, *fast = head;
		/*�ҳ���ײ��*/
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next;

			/*��ײ*/
			if (slow == fast)
			{
				break;
			}//if
		}//while

		/*������*/
		if (fast == NULL || fast->next == NULL)
		{
			return NULL;
		}//if

		/*�ı�slowָ��*/
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}//while

		/*��ʱ�����߾�ָ��·��ʼ��*/
		return fast;
	}
};

int main()
{
	ListNode *head = NULL;

	for (int i = 1; i <= 3; ++i)
		head = insert(head, i);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 3);

	display(head);

	Solution s;
	ListNode *node = s.findBegginning(head);
	if (node)
		cout << node->val << endl;

	system("pause");
	return 0;
}