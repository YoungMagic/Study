/*
��Ŀ����

�����һ���㷨��Ѱ�Ҷ�������ָ��������һ����㣨����������ĺ�̣���
�������ĸ����ָ��TreeNode* root�ͽ���ֵint p���뷵��ֵΪp�Ľ��ĺ�
�̽���ֵ����֤����ֵ���ڵ�����С�ڵ���100000��û���ظ�ֵ���������ں�̷���-1��
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

/*��������*/
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
		}//if

		//����ǿ�������
		if (i + 1 < size && nums[i + 1] != flag)
		{
			right = new TreeNode(nums[i + 1]);
			que.push(right);
		}//if

		tmp->left = left;
		tmp->right = right;
		//������ǰ����Ľڵ�
		que.pop();
	}//for
	return root;
}

class Successor {
public:
	/*����һ���õ������������*/
	int findSucc(TreeNode* root, int p) {
		// write code here
		vector<int> inOrderVals;
		inOrder(inOrderVals, root);
		auto iter = find(inOrderVals.begin(), inOrderVals.end(), p);
		if (++iter != inOrderVals.end())
			return *iter;
		return -1;
	}

	/*�������������*/
	void inOrder(vector<int> &vals, TreeNode *root)
	{
		if (!root)
			return;
		inOrder(vals, root->left);
		vals.push_back(root->val);
		inOrder(vals, root->right);
	}

	///*���������������Ľṹ���죬������Ҫ���а���ָ�򸸽ڵ��ָ��*/
	//int findSucc2(TreeNode* root, int p) {
	//	// write code here
	//	/*��һ�����ҵ�ֵΪp�Ķ������ڵ�*/
	//	TreeNode *node = findTreeNode(root, p);
	//	if (!node)
	//		return -1;
	//	else{
	//		int ret = -1;
	//		/*��1������ýڵ���������������������������ڵ��������*/
	//		if (node->right)
	//		{
	//			node = node->right;
	//			while (node)
	//			{
	//				ret = node->val;
	//				node = node->left;
	//			}//while
	//			return ret;
	//		}//if
	//		else{
	//			/*���ϵ������ҵ�node�ĵ�һ��δ��������*/
	//			TreeNode *p = node->parent;
	//			while (node && p->left != node)
	//			{
	//				node = p;
	//				p = p->parent;
	//			}//while
	//			ret = p->val;
	//			return ret;
	//		}//else
	//		return -1;
	//	}
	//}

	//TreeNode *findTreeNode(TreeNode *root, int p)
	//{
	//	if (!root)
	//		return NULL;
	//	if (root->val == p)
	//		return root;
	//	else{
	//		TreeNode *node = findTreeNode(root->left, p);
	//		if (node != NULL)
	//			return node;
	//		else
	//			return findTreeNode(root->right, p);
	//	}//else		
	//}
};

int main()
{
	vector<int> v = { 7, 6, flag, 4, flag, 2, 5, 1, 3, flag, flag, flag, flag, flag, flag };
	TreeNode *root = generateTree(v);
	Successor s;
	cout << s.findSucc(root, 5) << endl;

	system("pause");
	return 0;
}
