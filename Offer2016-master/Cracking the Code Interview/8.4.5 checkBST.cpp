/*
��Ŀ����

��ʵ��һ�����������һ�ö������Ƿ�Ϊ�����������
�������ĸ����ָ��TreeNode* root���뷵��һ��bool����������Ƿ�Ϊ�����������
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

/*�������ڵ����ݽṹ*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

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

class Checker {
public:
	/*����һ�����ö���������������Ϊ����Ĺ���*/
	int lastVal = INT_MIN;
	bool checkBST1(TreeNode* root) {
		// write code here
		if (!root)
			return true;

		/*�ݹ���������*/
		if (!checkBST1(root->left))
			return false;

		/*�Ƚϵ�ǰ�ڵ㣬�������ѱ����ڵ�����ֵ*/
		if (root->val <= lastVal)
			return false;
		lastVal = root->val;

		/*�ݹ���������*/
		if (!checkBST1(root->right))
			return false;
		return true;
	}

	/*�������������Сֵ��*/
	bool checkBST(TreeNode* root) {
		// write code here
		if (!root)
			return true;
		return checkBST2(root, INT_MAX, INT_MIN);
	}
	bool checkBST2(TreeNode *root, int maxVal, int minVal)
	{
		if (!root)
			return true;
		if (root->val < minVal || root->val >= maxVal)
			return false;
		if (!checkBST2(root->left, root->val, minVal) || !checkBST2(root->right, maxVal, root->val))
			return false;
		return true;
	}
};

int main()
{
	vector<int> v = { 7, 6, flag, 4, flag, 2, 5, 1, 3, flag, flag, flag, flag, flag, flag };
	TreeNode *root = generateTree(v);

	Checker c;
	bool ret = c.checkBST(root);

	cout << ret << endl;

	system("pause");
	return 0;
}