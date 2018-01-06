/* 
 * ��������15 �������е�����k�����
 * ����һ����������������е�����k����㡣
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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (!pListHead || k <= 0)
			return NULL;

		int len = 0;
		ListNode *p = pListHead;
		while (p)
		{
			++len;
			p = p->next;
		}//while

		if (k > len)
			return NULL;

		//��������
		k = len - k + 1;
		p = pListHead;
		int i = 1;
		while (p && i < k)
		{
			p = p->next;
			++i;
		}
		return p;
	}

	/*ֻ��Ҫ����һ�εĸ�Ч�㷨*/
	ListNode *FindKthToTail2(ListNode* pListHead, unsigned int k)
	{
		if (pListHead == NULL || k == 0)
			return NULL;

		ListNode *pAhead = pListHead, *pBehind = pListHead;
		for (int i = 0; i < k - 1; ++i)
		{
			if (pAhead->next != NULL)
				pAhead = pAhead->next;
			/*˵�������ܳ���С��k*/
			else
				return NULL;
		}//for

		while (pAhead->next)
		{
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}//while

		return pBehind;
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
	ListNode *r = s.FindKthToTail(head , 2);
	cout << r->val << endl;
	
	ListNode *r2 = s.FindKthToTail2(head, 2);
	cout << r2->val << endl;
	system("pause");
	return 0;
}