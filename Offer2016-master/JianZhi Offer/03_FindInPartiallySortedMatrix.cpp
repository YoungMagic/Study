/*
 * ��ά�����еĲ��ң�
 *
 * ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
 * ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
 * ����������һ����ά�����һ���������ж��������Ƿ��и�������
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	bool Find(vector<vector<int> > array, int target) {
		if (array.empty())
			return false;
		//���ά���������������
		int rows = array.size(), cols = array[0].size();

		int r = 0, c = cols - 1;
		while (r < rows && c >= 0)
		{
			if (array[r][c] == target)
				return true;
			//��Ŀ��Ԫ��ֻ����λ�����²��Ӿ���
			else if (array[r][c] > target)
			{
				c--;
			}
			//��Ŀ��Ԫ��ֻ����λ�����²��Ӿ���
			else{
				++r;
			}
		}//while
		return false;
	}
};

int main()
{
	vector<vector<int> > arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	Solution s;

	bool ret = s.Find(arr, 9);

	cout << ret << endl;
	system("pause");
	return 0;
}
