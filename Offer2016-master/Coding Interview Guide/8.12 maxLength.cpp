/*
������8.12 δ�����������ۼӺ�С�ڻ���ڸ���ֵ��������鳤��
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int firstIdx(vector<int> v, int target)
{
	if (v.empty())
		return -1;

	int l = 0, r = v.size() - 1, pos = -1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (v[mid] >= target)
		{
			pos = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}//else
	}//while
	return pos;
}

/*�㷨ԭ�ͣ�������������ۼӺ�<=k����������С*/
int maxLength(vector<int> v, int k)
{
	if (v.empty())
		return 0;

	int n = v.size();
	vector<int> helpSum(n + 1, 0);

	/*ͬʱ���������鹹��Ϊ��������*/
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
		helpSum[i + 1] = max(sum, helpSum[i]);
	}//for

	 /*����i��β�ģ��ۼӺ�<=k��������飬�ȼ��ڴ�ǰ���ҵ���һ���ۼӺʹ��ڵ���sum-k������*/
	sum = 0;

	int pos = -1;
	int len = 0, maxLen = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
		pos = firstIdx(helpSum, sum - k);
		if (pos == -1)
		{
			len = 0;
		}
		else {
			len = i - pos + 1;
		}
		maxLen = max(maxLen, len);
	}
	return maxLen;
}
