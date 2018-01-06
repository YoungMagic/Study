/*
��Ŀ����

����һ��Ԫ�ظ�����ͬ�Ұ��������е��������У����дһ���㷨������һ�ø߶���С�Ķ����������
����һ����������int[] vals,�뷵�ش����Ķ���������ĸ߶ȡ�
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class MinimalBST {
public:
	int buildMinimalBST(vector<int> vals) {
		// write code here
		if (vals.empty())
			return 0;
		int height = 0;
		createMinimalBST(vals, height);
		return height;
	}

	/*�ݹ���߶�*/
	int getHeight(TreeNode *root)
	{
		if (!root)
			return 0;
		else
			return max(getHeight(root->left), getHeight(root->right)) + 1;
	}

	/*�������������ͬʱ���¸߶�*/
	TreeNode *createMinimalBST(vector<int> vals, int &height)
	{
		if (vals.empty())
		{
			height = 0;
			return NULL;
		}
		int lhs = 0, rhs = vals.size();
		TreeNode *root = new TreeNode(vals[(lhs + rhs) / 2]);
		int leftHeight, rightHeight;
		root->left = createMinimalBST(vector<int>(vals.begin(), vals.begin() + ((lhs + rhs) / 2)), leftHeight);
		root->right = createMinimalBST(vector<int>(vals.begin() + ((lhs + rhs) / 2 + 1), vals.end()), rightHeight);

		height = max(leftHeight, rightHeight) + 1;
		return root;
	}
};

int main()
{
	MinimalBST m;
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	int height = 0;
	TreeNode *root = m.createMinimalBST(v, height);

	system("pause");
	return 0;
}
