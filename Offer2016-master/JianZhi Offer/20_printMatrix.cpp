/*
 * ��Ŀ����
 * ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
 * ���磬����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if (matrix.empty())
			return vector<int>();

		vector<int> ret;
		//����þ��������������
		int m = matrix.size(), n = matrix[0].size();
		//��ǰ�����������ʼ����������
		int r = 0, c = 0;

		for (int r = 0, c = 0; r < m&&c < n; ++r, ++c)
		{
			//�������������
			for (int j = c; j < n; ++j)
				ret.push_back(matrix[r][j]);

			//���������β��
			for (int i = r + 1; i < m; ++i)
				ret.push_back(matrix[i][n-1]);

			//���������β��
			for (int j = n - 2; j >= c && r != m-1; --j)
				ret.push_back(matrix[m - 1][j]);

			//�������������
			for (int i = m - 2; i > r && c != n-1; --i)
				ret.push_back(matrix[i][c]);

			//������һ����
			--m;
			--n;
		}//while
		return ret;
	}
};

int main()
{
	vector<vector<int> > v = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<vector<int> > v2 = { { 1 }, { 2 }, { 3 }, { 4 } ,{ 5 } };
	Solution s;
	vector<int> ret = s.printMatrix(v);

	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << "\t";
	cout << endl;

	system("pause");
	return 0;
}