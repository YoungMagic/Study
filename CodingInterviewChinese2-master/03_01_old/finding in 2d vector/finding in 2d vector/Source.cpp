/*
* ��ά�����еĲ��ң�
*
* ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
* ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
* ����������һ����ά�����һ���������ж��������Ƿ��и�������
*/


//�ȴӵ�һ�ŵ����һλ��ʼ�Ƚϡ�
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	bool find(vector<vector<int>> arr, int target) {
		if (arr.empty())
			return false;
		int rows = arr.size();
		int cols = arr[0].size();
		int r = 0, c = cols - 1;
		while (r < cols && c >= 0)
		{
			if (arr[r][c] == target)
				return true;
			else if (arr[r][c] < target)
				r++;
			else
				c--;
		}
		return false;
	}
};
int main()
{
	vector<vector<int> > arr = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };

	Solution s;

	bool ret = s.find(arr, 9);
	ret = false;
	cout << ret <<"1"<< endl;
	system("pause");
	return 0;
}