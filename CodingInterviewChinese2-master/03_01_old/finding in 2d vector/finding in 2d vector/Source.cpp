/*
* 二维数组中的查找：
*
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
* 每一列都按照从上到下递增的顺序排序。请完成一个函数，
* 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/


//先从第一排的最后一位开始比较。
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