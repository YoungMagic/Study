/*������50 ���������ڵ����͹�������*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;






/*��1�����1���ڶ������������ҽڵ�p��q����͹�������*/
/*�����������ڵ�ṹ*/
typedef struct BSTNode {
	int val;
	BSTNode *left;
	BSTNode *right;

	BSTNode(int val) :val(val), left(NULL), right(NULL) {}
};

BSTNode *getLastCommonParent1(BSTNode *root, BSTNode *p, BSTNode *q)
{
	if (root == NULL)
		return NULL;

	BSTNode *ret = root;

	while (ret != NULL)
	{
		//��������ڵ�p,q��ֵ�ȸ��ڵ�ret��������͹���������������
		if (ret->val < p->val && ret->val < q->val)
		{
			ret = ret->right;
		}
		//��������ڵ�p,q��ֵ�ȸ��ڵ�ret��С������͹���������������
		else if (ret->val > p->val && ret->val > q->val) {
			ret = ret->left;
		}
		//���ret��ֵ��p��q���м䣬��ret����p��q����͹�������
		else {
			break;
		}
	}//while
	return ret;
}

/*��2�����2���Ƕ�����������ֻ����ͨ�Ķ�����������ÿ���ڵ����ָ�򸸽ڵ��ָ��
��ʱ�������ڵ�p��q����һ��ָ����ڵ�root����������Ŀ����ת��Ϊ��������ĵ�һ�������ڵ㡣
*/
/*���и��ڵ�ָ�����ͨ�������ڵ�ṹ*/
typedef struct TPNode {
	int val;
	TPNode *left;
	TPNode *right;
	TPNode *parent;

	TPNode(int val) :val(val), left(NULL), right(NULL), parent(NULL) {}
};

TPNode *getLastCommonParent2(TPNode *root, TPNode *p, TPNode *q)
{
	if (root == NULL)
		return NULL;

	int pLen = 0, qLen = 0;
	TPNode *pTmp = p;
	while (pTmp != NULL)
	{
		++pLen;
		pTmp = pTmp->parent;
	}

	TPNode *qTmp = q;
	while (qTmp != NULL)
	{
		++qLen;
		qTmp = qTmp->parent;
	}

	pTmp = p;
	qTmp = q;
	if (pLen > qLen)
	{
		int diff = pLen - qLen;
		while (diff > 0)
		{
			pTmp = pTmp->parent;
		}//while
	}
	else {
		int diff = qLen - pLen;
		while (diff > 0)
		{
			qTmp = qTmp->parent;
		}
	}//else

	while (pTmp != qTmp)
	{
		pTmp = pTmp->parent;
		qTmp = qTmp->parent;
	}

	return pTmp;
}

/*��3�����3���Ƕ�����������ֻ����ͨ�Ķ�������������ÿ���ڵ㲻����ָ�򸸽ڵ��ָ��
��ʱ��˳��һ��p��q����ͬһ�ߵ����ӣ�Ҳ����˵�����p��q����ĳ�ڵ����ߣ��͵���������ȥ
���ҹ������ȣ���������ұ߾�ȥ������ȥ���ҹ������ȡ�Ҫ��p��q����ͬһ�ߣ���ô�ͱ�ʾ�Ѿ��ҵ���һ���������ȡ�
*/
/*�������ڵ�ָ�����ͨ�������ڵ�ṹ*/
typedef struct BTNode {
	int val;
	BTNode *left;
	BTNode *right;

	BTNode(int val) :val(val), left(NULL), right(NULL) {}
};

bool judge(BTNode *root, BTNode *p)
{
	//�ж϶�����root���Ƿ��нڵ�p
	if (root == NULL)
		return false;
	if (root == p)
		return true;

	return judge(root->left, p) || judge(root->right, p);
}
BTNode *getLastCommonParent3(BTNode *root, BTNode *p, BTNode *q)
{
	if (root == NULL || !judge(root,p) || !judge(root,q))
		return NULL;

	if (root == p || root == q)
		return root;

	/*p��q����root��ͬһ�ߣ�˵��root�������ǵ���͹�������*/
	bool isPOnLeft = judge(root->left, p);
	bool isQOnLeft = judge(root->left, q);

	/*���p��q����root�����*/
	if (isPOnLeft && isQOnLeft)
	{
		return getLastCommonParent3(root->left, p, q);
	}
	//�������p��q����root���ұ�
	else if(!isPOnLeft && !isQOnLeft){
		return getLastCommonParent3(root->right, p, q);
	}
	//����˵��p��q����ͬһ�ߣ���ʱ���ҵ�������͹�������
	else {
		return root;
	}
}

/*��4�����4���Ƕ�������ֻ����ͨ�Ķ������������ÿ���ڵ㲻����ָ�򸸽ڵ��ָ��
��ʱ������ôӸ��ڵ㵽p��q��·����ת��Ϊ����������һ�������ӽڵ㡣
*/

/*���и��ڵ�ָ�����ͨ�������ڵ�ṹ*/
typedef struct TreeNode {
	int val;
	TreeNode *left;
	vector<TreeNode *> m_vChildren;

	TreeNode(int val) :val(val), m_vChildren(vector<TreeNode*>()) {}
};

//��ȡnode�ڵ�����root�е�·��
bool getNodePath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
{
	if (root == node)
		return true;

	path.push_back(root);
	bool found = false;
	vector<TreeNode *>::iterator iter = root->m_vChildren.begin();
	while (!found && iter < root->m_vChildren.end())
	{
		found = getNodePath(*iter, node, path);
		++iter;
	}//while

	if (!found)
		path.pop_back();

	return found;
}

TreeNode *getLastCommonNode(vector<TreeNode *> pV, vector<TreeNode *> qV)
{
	if (pV.empty() && qV.empty())
		return NULL;
	vector<TreeNode *>::iterator pIter = pV.begin(), qIter = qV.begin();

	TreeNode *ret = NULL;
	while (pIter != pV.end() && qIter != qV.end())
	{
		if (*pIter == *qIter)
			ret = *pIter;
		++pIter;
		++qIter;
	}//while
	return ret;

}

TreeNode *getLastCommonParent4(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == NULL)
		return NULL;

	vector<TreeNode *> pV, qV;
	getNodePath(root, p, pV);
	getNodePath(root, q, qV);

	return getLastCommonNode(pV, qV);
}
