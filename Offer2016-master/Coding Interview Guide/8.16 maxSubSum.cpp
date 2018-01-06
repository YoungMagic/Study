/*
8.16 �����������ۼӺ�

��Ŀ��
����һ������arr�����������������ۼӺ͡�
���磬arr={1,-2,3,5,-2,6,-1};���е��������У�[3,5,-2,6]�����ۼӳ����ĺ�12��
���Է���12��
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int maxSubSum(vector<int> arr)
{
	if (arr.empty())
		return 0;
	int len = arr.size(), maxSum = 0, tmpSum = 0, beg = 0, end = -1;
	for (int i = 0; i < len; ++i)
	{
		tmpSum += arr[i];
		if (tmpSum > maxSum)
		{
			maxSum = tmpSum;
			end = i;
		}//if
		else if (tmpSum < 0)
		{
			tmpSum = 0;
			beg = i+1;
		}
		else
			continue;
	}//for
	if (end>beg)
		cout << "����ֶκ���ʼλ�ã�" << beg << ", " << end << endl;
	return maxSum;
}

int main()
{
	vector<int> v = { 1, -2, 3, 5, -2, 6, -1 };

	cout << maxSubSum(v) << endl;

	system("pause");
	return 0;
}