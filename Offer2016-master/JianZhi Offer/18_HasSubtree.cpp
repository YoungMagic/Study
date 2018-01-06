/*
 * �����ӽṹ
 * ��Ŀ����
 * �������Ŷ�����A��B���ж�B�ǲ���A���ӽṹ
 */

#include <iostream>
#include <cstdlib>

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

const int flag = INT_MIN;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool ret = false;
		if (pRoot1 && pRoot2)
		{
			if (pRoot1->val == pRoot2->val)
				ret = HasSubtree2(pRoot1, pRoot2);
			if (!ret)
				ret = HasSubtree2(pRoot1->left, pRoot2);
			if (!ret)
				ret = HasSubtree2(pRoot1->right, pRoot2);
		}
		return ret;		
	}

	//�ڶ�����
	bool HasSubtree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL)
			return true;
		
		if (pRoot1 == NULL)
			return false;

		if (pRoot1->val != pRoot2->val)
			return false;
		else
			return HasSubtree2(pRoot1->left, pRoot2->left) && HasSubtree2(pRoot1->right, pRoot2->right);
	}
};

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
	Solution s;

	vector<int> v1 = { 8, flag, 9, 3, 2 };
	vector<int> v2 = {};

	TreeNode *root1 = generateTree(v1);
	TreeNode *root2 = generateTree(v2);
	bool ret = s.HasSubtree(root1, root2);
	cout << ret << endl;

	system("pause");
	return 0;
}