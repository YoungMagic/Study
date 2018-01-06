/*
* ��Ŀ����ת����
* ����һ��������ת�����������������Ԫ�ء�
*/

#include <iostream>
#include <cstdlib>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (!pHead || !pHead->next)
			return pHead;

		int len = 0;
		ListNode *p = pHead;
		while (p)
		{
			++len;
			p = p->next;
		}//while
		//�����нڵ��������һ��
		p = pHead ->next;
		pHead->next = NULL;
		while (p)
		{
			//����p�ĺ����ڵ�
			ListNode *r = p->next;
			p->next = pHead;
			pHead = p;
			p = r;
		}
		return pHead;
	}
};

ListNode *insert(ListNode *head, int val)
{
	if (head == NULL)
	{
		head = new ListNode(val);
		return head;
	}

	ListNode *p = head;
	while (p && p->next)
	{
		p = p->next;
	}

	ListNode *q = new ListNode(val);
	p->next = q;

	return head;
}

int main()
{
	ListNode *head = NULL;

	for (int i = 0; i < 5; ++i)
		head = insert(head, i);

	Solution s;
	head = s.ReverseList(head);



	system("pause");
	return 0;
}