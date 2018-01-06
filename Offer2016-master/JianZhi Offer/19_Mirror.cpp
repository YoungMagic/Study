/*
 * ������20 �� �������ľ���
 * ��Ŀ����
 * ���������Ķ�����������任ΪԴ�������ľ��� 
 */
#include <iostream>
#include <cstdlib>

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

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		//�������ߵ�������ֱ�ӷ���
		if (pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL))
			return;

		TreeNode *tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;

		if (pRoot->left)
			Mirror(pRoot->left);

		if (pRoot->right)
			Mirror(pRoot->right);
	}
};

//int main()
//{
//
//}