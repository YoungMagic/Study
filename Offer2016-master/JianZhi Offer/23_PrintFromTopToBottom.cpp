///*
// * �������´�ӡ������	
// * ��Ŀ����
// * �������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
// */
//
//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
///*
//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};*/
//
//struct TreeNode
//{
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL){}
//};
//
//class Solution {
//public:
//	vector<int> PrintFromTopToBottom(TreeNode *root) {
//		if (!root)
//			return vector<int>();
//
//		vector<int> ret;
//
//		queue<TreeNode *> parent;
//		parent.push(root);
//
//		while (!parent.empty())
//		{
//			queue<TreeNode *> child;
//			while (!parent.empty())
//			{
//				ret.push_back(parent.front()->val);
//				if (parent.front()->left)
//					child.push(parent.front()->left);
//				if (parent.front()->right)
//					child.push(parent.front()->right);
//				//�������㵱ǰ�ڵ�
//				parent.pop();
//			}
//			parent = child;
//		}//while
//		return ret;
//	}
//};
//
//const int flag = INT_MIN;
//
//TreeNode *generateTree(vector<int> &nums)
//{
//	if (nums.empty())
//		return NULL;
//
//	TreeNode *root = new TreeNode(nums[0]);
//	queue<TreeNode *> que;
//	que.push(root);
//	//�������Ԫ�ظ�������Ӧ����������ڵ����
//	int size = nums.size();
//	for (int i = 1; i < size; i += 2)
//	{
//		//������׽ڵ����������
//		TreeNode *tmp = que.front();
//		TreeNode *left = NULL, *right = NULL;
//		//����ǿ�������
//		if (nums[i] != flag)
//		{
//			left = new TreeNode(nums[i]);
//			que.push(left);
//		}
//
//		//����ǿ�������
//		if (i + 1 < size && nums[i + 1] != flag)
//		{
//			right = new TreeNode(nums[i + 1]);
//			que.push(right);
//		}
//
//		tmp->left = left;
//		tmp->right = right;
//		//������ǰ����Ľڵ�
//		que.pop();
//	}
//	return root;
//}
//
//int main()
//{
//	Solution s;
//
//	vector<int> v1 = { 8, flag, 9, 3, 2 };
//
//	TreeNode *root1 = generateTree(v1);
//	vector<int> ret = s.PrintFromTopToBottom(root1);
//	for (size_t i = 0; i < ret.size(); ++i)
//		cout << ret[i] << "\t";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}