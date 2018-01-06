/*
* ������8.9.3 ������A[0...n-1]�У�����ν��ħ����������������A[i]=i��
* ����һ�������������飬Ԫ��ֵ������ͬ����дһ��������������A���ҳ�һ��ħ�������������ڵĻ���
* ����������������ظ�Ԫ�أ��ָ���δ���
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
	/*����һ����������� O(n)*/
	int magicIndex(vector<int> &nums)
	{
		if (nums.empty())
			return INT_MAX;

		/*���г���*/
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == i)
				return i;
		}//for
		return INT_MIN;
	}

	/*�����������ַ����*/
	int magicIndex2(vector<int> &nums)
	{
		if (nums.empty())
			return INT_MIN;
		
		/*��������*/
		int lhs = 0, rhs = nums.size() - 1;
		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (mid == nums[mid])
				return mid;
			else if (mid < nums[mid])
				rhs = mid - 1;
			else
				lhs = mid + 1;
		}//while
		return INT_MIN;
	}

	/*�������������ظ�Ԫ�أ��ݹ�ʵ��*/
	int magicIndex(vector<int> &nums, int beg, int end)
	{
		if (nums.empty() || beg > end || beg < 0 || end > nums.size())
			return INT_MIN;

		int mid = (beg + end) / 2;

		if (mid == nums[mid])
			return mid;

		/*������벿��*/
		int leftIndex = magicIndex(nums, beg, min(mid - 1, nums[mid]));
		if (leftIndex != INT_MIN)
			return leftIndex;

		/*�����Ұ벿��*/
		int rightIndex = magicIndex(nums, max(mid + 1, nums[mid]), end);
		if (rightIndex != INT_MIN)
			return rightIndex;
		
		/*������*/
		return INT_MIN;
	}

};


int main()
{
	Solution s;
	vector<int> v = { 1, 2, 3, 3, 4, 5, 6 };
	cout << s.magicIndex(v) << endl;

	cout << s.magicIndex(v, 0, v.size() - 1) << endl;

	system("pause");
	return 0;
}