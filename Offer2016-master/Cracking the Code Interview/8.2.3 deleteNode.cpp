/*
 * ������8.2.3 ɾ���������е�ĳ���ڵ㣬�ٶ�ֻ�ܷ��ʸýڵ㡣
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;

	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	/* ����������У��޷�����������׽ڵ㣬ֻ�ܷ����Ǹ���ɾ���Ľڵ㡣�ⷨ�ܼ򵥣�ֱ�ӽ���̽ڵ�����ݸ��Ƶ�
	 * ��ǰ�ڵ㣬Ȼ��ɾ�������̽ڵ㣻������Ҫע����ǣ������ɾ���Ľڵ�Ϊ�����β�ڵ㣬�����Ŀ�޽⡣
	 * ����ֻ��Ҫ�����Թ�ָ����һ�㼴�ɡ�
	 */
	bool deleteNode(ListNode *node)
	{
		if (!node || !node->next)
			return false;

		int tmp = node->next->val;
		node->next->val = node->val;
		node->val = tmp;

		ListNode *p = node->next;
		node->next = node->next->next;

		delete p;
		p = NULL;
		return true;
	}
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
		cout << head->val ;
	}
	ListNode *p = head->next;
	while (p)
	{
		cout << "��>" << p->val;
		p = p->next;
	}//while
	cout << endl;
}

int main()
{
	ListNode *head = NULL;
	head = insert(head, 1);
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 3);
	display(head);

	Solution s;
	s.deleteNode(head);

	display(head);

	system("pause");
	return 0;

}