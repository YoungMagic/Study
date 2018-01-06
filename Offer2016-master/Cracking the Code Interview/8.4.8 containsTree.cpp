/*
��Ŀ���������ŷǳ���Ķ�������T1,�м�������ڵ㣻T2�м��ٸ��ڵ㡣
���һ���㷨���ж�T2�Ƿ�ΪT1��������

���T1��һ���ڵ�n����������T2һģһ������T2ΪT1��������Ҳ����˵���ӽڵ�n
���������ϣ��õ�������T2��ȫ��ͬ��
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

class Solution {
public:
	bool containsTree(TreeNode *t1, TreeNode *t2)
	{
		if (t2 == NULL)
			return true;

		return subTree(t1, t2);
	}

	/*�ж�t2�Ƿ�Ϊt1������*/
	bool subTree(TreeNode *t1, TreeNode *t2)
	{
		if (t1 == NULL)
			return false;
		
		if (t1->val == t2->val)
			return matchTree(t1, t2);
		else
			return subTree(t1->left, t2) || subTree(t1->right, t2);
	}

	/*�ж��������Ƿ���ȫһ��*/
	bool matchTree(TreeNode *t1, TreeNode *t2)
	{
		if (t1 == NULL && t2 == NULL)
			return true;
		else if (t1 == NULL || t2 == NULL)
			return false;
		else if (t1->val != t2->val)
			return false;
		else
			return matchTree(t1->left, t2->left) && matchTree(t1->right, t2->right);
	}

};

int main()
{
	vector<int> v1 = { 7, 6, flag, 4, flag, 2, 5, 8, 3, flag, flag, flag, flag, flag, flag };
	TreeNode *t1 = generateTree(v1);

	vector<int> v2 = {2, 8, 3};
	TreeNode *t2 = generateTree(v2);

	cout << Solution().containsTree(t1, t2) << endl;
	system("pause");
	return 0;
}