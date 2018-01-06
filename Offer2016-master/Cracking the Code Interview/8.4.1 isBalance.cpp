/*
��Ŀ����

ʵ��һ�����������������Ƿ�ƽ�⣬ƽ��Ķ������£��������е�����һ����㣬
�����������ĸ߶Ȳ����1��
����ָ����������ָ��TreeNode* root���뷵��һ��bool������������Ƿ�ƽ�⡣
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Balance {
public:

	bool isBalance(TreeNode* root) {
		// write code here
		if (!root)
			return true;
		else if (abs(height(root->left) - height(root->right)) > 1)
			return false;
		else
			return isBalance(root->left) && isBalance(root->right);

	}

	int height(TreeNode *root)
	{
		if (!root)
			return 0;
		else
		{
			return max(height(root->left), height(root->right)) + 1;
		}//ekse
	}

	/*�Ľ������㷨,�ռ临�Ӷ�ΪO(H) ʱ�临�Ӷ�ΪO(N)*/
	bool isBalance2(TreeNode *root)
	{
		if (checkHeight(root) == -1)
			return false;
		else
			return true;
	}

	int checkHeight(TreeNode *root)
	{
		/*���ؿ����ĸ߶�Ϊ0*/
		if (root == NULL)
			return 0;

		/*����������Ƿ�ƽ��*/
		int leftHeight = checkHeight(root->left);
		/*������-1��˵��������Ϊ��ƽ����*/
		if (leftHeight == -1)
			return -1;

		int rightHeight = checkHeight(root->right);
		if (rightHeight == -1)
			return -1;

		/*��鵱ǰ�ڵ��Ƿ�ƽ��*/
		int heightDiff = abs(leftHeight - rightHeight);
		if (heightDiff > 1)
			return -1;
		else{
			/*���ظ߶�*/
			return max(leftHeight, rightHeight) + 1;
		}
	}
};

