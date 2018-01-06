/*
���ƺ����ָ��ڵ������
һ�����������ڵ���������
struct ListNode{
	int val;
	ListNode *next;
	ListNode *rand;
	ListNode(int v):val(v),next(NULL),rand(NULL){}
����randָ�����ָ�������е�����ڵ㣬Ҳ����ָ��null

����һ����ListNode�ڵ�������ɵ��޻��������ͷ�ڵ�head��ʵ�ֺ����������
���������нṹ�ĸ��ƣ������ظ��Ƶ��������ͷ�ڵ㡣

���ף������ö�������ݽṹ��ֻ�����޼�������������ʱ�临�Ӷ�ΪO(N)�����ԭ���⣻
*/

#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode *rand;
	ListNode(int v) :val(v), next(NULL), rand(NULL){}
};

ListNode *insert(ListNode *head, int val)
{
	if (!head)
		head = new ListNode(val);
	else{
		ListNode *p = head;
		while (p->next)
			p = p->next;
		p->next = new ListNode(val);
	}//else
	return head;
}

void display(ListNode *head)
{
	if (!head)
		cout << endl;
	else{
		ListNode *p = head;
		while (p->next)
		{
			cout << p->val << "��>";
			p = p->next;
		}//while
		cout << p->val << endl;
	}//else
}

/*����һ������map�������ݽṹ*/
ListNode *copyListWithRand1(ListNode *head)
{
	if (!head)
		return head;

	map<ListNode *, ListNode*> nodeMap;
	ListNode *p = head;
	while (p)
	{
		nodeMap[p] = new ListNode(p->val);
		p = p->next;
	}//while

	/*�������ӹ�ϵ*/
	for (auto iter = nodeMap.begin(); iter != nodeMap.end(); ++iter)
	{
		iter->second->next = nodeMap[iter->first->next];
		
		iter->second->rand = iter->first->rand ? nodeMap[iter->first->rand] : NULL;
	}//for
	return nodeMap[head];
}

/*�����������������ݽṹ*/
ListNode *copyListWithRand2(ListNode *head)
{
	if (!head)
		return head;
	ListNode *p = head;
	while (p)
	{
		ListNode *r = p->next;
		ListNode *node = new ListNode(p->val);
		/*������������뵱ǰ���ʽڵ�����̽ڵ�֮��*/
		node->next = r;
		p->next = node;

		p = r;
	}//while

	p = head;
	ListNode *q = head->next, *rHead = q;
	while (p && q)
	{
		/*������һ��Ԫ����ڵ�*/
		ListNode *rp = q->next;
		/*������һ�����ƽڵ�*/
		ListNode *rq = rp ? rp->next : NULL;
		
		q->next = rq;
		if (p->rand)
			q->rand = p->rand->next;
		else
			q->rand = NULL;
		p->next = rp;

		p = rp;
		q = rq;
	}//while
	return rHead;
}

int main()
{
	ListNode *head = NULL;
	head = insert(head, 9);
	head = insert(head, 0);
	head = insert(head, 4);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 1);

	display(head);

	ListNode *rHead = copyListWithRand1(head);
	display(rHead);

	ListNode *rHead2 = copyListWithRand2(head);
	display(rHead2);

	system("pause");
	return 0;
}