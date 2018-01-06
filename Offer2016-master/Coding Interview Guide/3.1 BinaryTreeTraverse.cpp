/*
3.1 �ֱ��õݹ�ͷǵݹ�ķ�ʽʵ�ֶ������������򡢺������
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int v) :val(v), left(NULL), right(NULL){}
};

/*�ݹ��������*/
void preOrderRecur(TreeNode *tree)
{
	if (!tree)
		return;

	cout << tree->val << "\t";
	preOrderRecur(tree->left);
	preOrderRecur(tree->right);
}

/*�ǵݹ�ʵ���������*/
void preOrderUnRecur(TreeNode *tree)
{
	if (!tree)
		return;

	stack<TreeNode *> stk;
	/*ѹ����ڵ�*/
	stk.push(tree);
	while (!stk.empty())
	{
		TreeNode *tmp = stk.top();
		cout << tmp->val << "\t";
		stk.pop();

		/*��ѹ��ջ�������ڵ㣬��ѹ��ջ�������ڵ�*/
		if (tmp->right)
			stk.push(tmp->right);
		if (tmp->left)
			stk.push(tmp->left);
	}//while
}

/*�ݹ�ʵ���������*/
void inOrderRecur(TreeNode *tree)
{
	if (!tree)
		return;

	inOrderRecur(tree->left);
	cout << tree->val << "\t";
	inOrderRecur(tree->right);
}

/*�ǵݹ�ʵ���������*/
void inOrderUnRecur(TreeNode *tree)
{
	if (!tree)
		return;

	stack<TreeNode *> stk;
	TreeNode *cur = tree;
	while (!stk.empty() || cur)
	{
		if (cur)
		{
			stk.push(cur);
			cur = cur->left;
		}//if
		else{
			cur = stk.top();
			stk.pop();
			cout << cur->val << "\t";
			cur = cur->right;
		}//else
	}//while
}

/*�ݹ�ʵ�ֺ������*/
void postOrderRecur(TreeNode *tree)
{
	if (!tree)
		return;

	postOrderRecur(tree->left);
	postOrderRecur(tree->right);
	cout << tree->val << "\t";
}

/*�ǵݹ�ʵ�ֺ������1*/
void postOrderRecur1(TreeNode *tree)
{
	if (!tree)
		return;

	/*��������ջ*/
	stack<TreeNode *> stk1;
	stack<TreeNode *> stk2;

	stk1.push(tree);
	while (!stk1.empty())
	{
		TreeNode *tmp = stk1.top();
		stk2.push(tmp);
		stk1.pop();
		if (tmp->left)
			stk1.push(tmp->left);
		if (tmp->right)
			stk1.push(tmp->right);		
	}//while

	while (!stk2.empty())
	{
		cout << stk2.top()->val << "\t";
		stk2.pop();
	}//while
}

/*�ǵݹ�ʵ�ֺ������2*/
void postOrderRecur2(TreeNode *h)
{
	if (!h)
		return;

	/*ʵ�ֹ����У�h�������һ�ε�������ӡ�Ľڵ�*/
	stack<TreeNode *> stk;
	stk.push(h);
	TreeNode *tmp;
	while (!stk.empty())
	{
		/*tmp����ջ���ڵ�*/
		tmp = stk.top();
		if (tmp->left && h != tmp->left && h != tmp->right)
		{
			stk.push(tmp->left);
		}//else
		else if (tmp->right && h != tmp->right)
		{
			stk.push(tmp->right);
		}//elif
		else
		{
			cout << tmp->val << "\t";
			stk.pop();
			h = tmp;
		}//else
	}//while
}

const int flag = INT_MAX;
TreeNode *generateTree(vector<int> &nums)
{
	if (nums.empty())
		return NULL;

	TreeNode *root = new TreeNode(nums[0]);
	queue<TreeNode *> que;
	que.push(root);
	//�������Ԫ�ظ�������Ӧ����������ڵ����
	int size = nums.size();
	for (int i = 1; i < size; i += 2)
	{
		//������׽ڵ����������
		TreeNode *tmp = que.front();
		TreeNode *left = NULL, *right = NULL;
		//����ǿ�������
		if (nums[i] != flag)
		{
			left = new TreeNode(nums[i]);
			que.push(left);
		}

		//����ǿ�������
		if (i + 1 < size && nums[i + 1] != flag)
		{
			right = new TreeNode(nums[i + 1]);
			que.push(right);
		}

		tmp->left = left;
		tmp->right = right;
		//������ǰ����Ľڵ�
		que.pop();
	}
	return root;
}

int main()
{
	vector<int> v = { 7, 6, flag, 4, flag, 2, 5, 1, 3, flag, flag, flag, flag, flag, flag };
	TreeNode *root = generateTree(v);

	cout << "���������" << endl;
	cout << "\t��  �飺\t";
	preOrderRecur(root);
	cout << endl;
	cout << "\t�ǵݹ飺\t";
	preOrderUnRecur(root);
	cout << endl;

	cout << "���������" << endl;
	cout << "\t��  �飺\t";
	inOrderRecur(root);
	cout << endl;
	cout << "\t�ǵݹ飺\t";
	inOrderUnRecur(root);
	cout << endl;

	cout << "���������" << endl;
	cout << "\t��   �飺\t";
	postOrderRecur(root);
	cout << endl;
	cout << "\t�ǵݹ�1��\t";
	postOrderRecur1(root);
	cout << endl;

	cout << "\t�ǵݹ�2��\t";
	postOrderRecur2(root);
	cout << endl;

	system("pause");
	return 0;

}
