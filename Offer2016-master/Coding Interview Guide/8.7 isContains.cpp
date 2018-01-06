/*
8.7 �����ж��ź���ľ���������
����һ����N*M�����;���matrix��һ������k��matrix��ÿһ�У�ÿһ�ж����ź���ġ�
ʵ��һ���������ж�k�Ƿ���matrix�С�
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

bool isContains(const vector<vector<int>> &matrix, const int &k)
{
	if (matrix.empty())
		return false;
	int m = matrix.size(), n = matrix[0].size();
	int row = 0, col = n - 1;
	while (row < m&& col >= 0)
	{
		if (k == matrix[row][col])
			return true;
		else if (k > matrix[row][col])
			++row;
		else
			--col;
	}//while
	return false;
}

int main()
{
	vector<vector<int>> matrix = { { 0, 1, 2, 5 }, { 2, 3, 4, 7 }, { 4, 4, 4, 8 }, { 5, 7, 7, 9 } };

	bool ret = isContains(matrix, 7);

	cout << ret << endl;

	system("pause");
	return 0;
}