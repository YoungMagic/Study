/*
* ��Ŀ��������25 ��������Ϊĳһֵ��·��
* ����������һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
* ·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return vector<vector<int>>();

		vector<vector<int> > paths;
		vector<int> path;

		findPaths(root, expectNumber, path, 0, paths);

		return paths;
	}

	void findPaths(TreeNode *root, int expectNumber, vector<int> path, int curNumber, vector<vector<int>> &paths)
	{
		//����ǰ�ڵ�ֵ�����浽��ǰ����·��
		path.push_back(root->val);
		curNumber += root->val;

		//����Ҷ�ڵ���·����ΪĿ��ֵ���򱣴浱ǰ·��
		if (root->left == NULL && root->right == NULL && curNumber == expectNumber)
		{
			paths.push_back(path);
		}

		if (root->left)
			findPaths(root->left, expectNumber, path, curNumber, paths);

		if (root->right)
			findPaths(root->right, expectNumber,path, curNumber, paths);

		//���򣬵�����ǰ�ڵ㣬���ظ��ڵ�
		path.pop_back();
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
	vector<int> v = { 10, 5, 12, 4, 7 };
	TreeNode *root = generateTree(v);

	Solution  s;
	vector<vector<int> > ret = s.FindPath(root , 22);

	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cout << ret[i][j] << "\t";
		}//for
		cout << endl;
	}//for

	system("pause");
	return 0;
}