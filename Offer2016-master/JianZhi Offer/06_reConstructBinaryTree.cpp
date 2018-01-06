/*
 *
 * ��Ŀ: 06 �ؽ�������
 * ����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
 * ���������ǰ���������������Ľ���ж������ظ������֡�
 * ��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> preOrder, vector<int> inOrder) {
		if (preOrder.empty() && inOrder.empty())
			return NULL;

		return reConstructBinaryTree(preOrder.begin(), preOrder.end(), inOrder.begin(), inOrder.end());
	}

	TreeNode *reConstructBinaryTree(vector<int>::iterator preBeg, vector<int>::iterator preEnd,
		vector<int>::iterator inBeg, vector<int>::iterator inEnd)
	{
		if (preBeg == preEnd && inBeg == inEnd)
			return NULL;

		/*�������ڵ�*/
		TreeNode *root = new TreeNode(*preBeg);

		int leftLen = 0;
		for (auto iter = inBeg; iter != inEnd; ++iter)
		{
			if (*iter == *preBeg)
				break;
			++leftLen;
		}//for

		root->left = reConstructBinaryTree(preBeg + 1, preBeg + leftLen + 1, inBeg, inBeg + leftLen);
		root->right = reConstructBinaryTree(preBeg + leftLen + 1, preEnd, inBeg + leftLen + 1, inEnd);

		return root;
	}
};

int main()
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 },
		inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Solution s;
	TreeNode *root = s.reConstructBinaryTree(preOrder, inOrder);

	system("pause");
	return 0;
}