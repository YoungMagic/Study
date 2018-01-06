/*
4.5 �����������
����һ����������arr������ΪN���ҵ�����������У�LIS��������LIS�ĳ��ȡ�

������
���� [5,4,1,2,3]��LIS �� [1,2,3]������ 3
���� [4,2,4,5,3,7]��LIS �� [4,4,5,7]������ 4
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//O(n^2)�ĸ��Ӷ�
vector<int> getDp1(vector<int> &nums)
{
	if (nums.empty())
	{
		return vector<int>();
	}//if

	int len = nums.size();
	vector<int> dp(len, 0);
	for (int i = 0; i < len; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] >= nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}//if
		}//for
	}//for

	return dp;
}

//O(nlogn)�ĸ��Ӷȣ���Բ����ظ�Ԫ�ص�����������У�
vector<int> getDp2(vector<int> &nums)
{
	if (nums.empty())
	{
		return vector<int>();
	}//if

	int len = nums.size();
	vector<int> dp(len, 0), ends(len, 0);
	dp[0] = 1;
	ends[0] = nums[0];

	int right = 0;

	int l = 0, r = 0, m = 0;
	for (int i = 1; i < len; ++i)
	{
		l = 0;
		r = right;
		/*���ö��ֵ�˼�룬���͸��Ӷ�*/
		while (l <= r)
		{
			m = (l + r) / 2;
			if (nums[i] < ends[m])
			{
				l = m + 1;
			}//if
			else {
				r = m - 1;
			}//else
		}//while

		right = max(right, l);
		ends[l] = nums[i];
		dp[i] = l + 1;
	}//for

	return dp;
}

//��̬�滮
int longestIncreasingSubsequence(vector<int> nums) {
	// write your code here
	if (nums.empty())
	{
		return 0;
	}//if

	vector<int> dp = getDp1(nums);
	int maxLen = 0, len = dp.size();
	for (int i = 0; i < len; ++i)
	{
		if (dp[i] > maxLen)
		{
			maxLen = dp[i];
		}//if
	}//for

	return maxLen;
}


int main()
{
	vector<int> v = { 5,4,1,2,3 };
	cout << longestIncreasingSubsequence(v) << endl;

	system("pause");
	return 0;
}