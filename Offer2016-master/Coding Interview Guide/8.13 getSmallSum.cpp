/*
8.13 ���������С��
��Ŀ��
����С�͵Ķ������£��������� s = [1,3,5,2,4,6] ��s[0]�����С�ڵ���s[0]�����ĺ�Ϊ0��
��s[1]�����С�ڵ���s[1]�����ĺ�Ϊ1...���ι��ɣ��õ�s��С��Ϊ0+1+4+1+6+15=27.
����һ������s��ʵ�ֺ�������s��С�͡�
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*����һ������ѭ��ʵ�֣����Ӷ�O(N^2)*/
int getSmallSum(const vector<int> &arr)
{
	if (arr.empty())
		return 0;

	int sum = 0, len = arr.size();
	/*����ÿ��Ԫ�ص����С��*/
	for (int i = 0; i < len; ++i)
	{
		int tmp = 0;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] <= arr[i])
			{
				tmp += arr[j];
			}//if
		}//for
		sum += tmp;
	}//for

	return sum;
}

/*�����������ù鲢�����˼�룬�õ�ʱ�临�Ӷ�ΪO(nlogn)���ռ临�Ӷ�ΪO(n)���㷨*/
int merge(vector<int> &arr, int left, int mid, int right)
{
	/*����һ����ʱ��̬����*/
	vector<int> tmp(right - left + 1, 0);

	int smallSum = 0, i = left, j = mid + 1, k = -1;
	for (; i <= mid&&j <= right;)
	{
		if (arr[i] < arr[j])
		{
			/*С��*/
			smallSum += arr[i] * (right - j + 1);
			tmp[++k] = arr[i++];
		}//if
		else{
			/*û��С��*/
			tmp[++k] = arr[j++];
		}//else
	}//for

	/*ʣ��*/
	for (; i <= mid || j <= right; ++i, ++j)
	{
		tmp[++k] = i > mid ? arr[j] : arr[i];
	}//for
	
	/*����ԭʼ����*/
	for (int i = 0; i < k; ++i)
	{
		arr[left + i] = tmp[i];
	}//for
	tmp.clear();

	return smallSum;
}

int func(vector<int> &arr, int l, int r)
{
	if (arr.empty() || l >= r)
		return 0;

	int mid = (l + r) / 2;
	return func(arr, l, mid) + func(arr, mid + 1, r) + merge(arr, l, mid, r);
}
int getSmallSum2(vector<int> &arr)
{
	if (arr.empty())
		return 0;

	return func(arr, 0, arr.size() - 1);
}

int main()
{
	vector<int> v = { 1, 3, 5, 2, 4, 6 };
	cout << getSmallSum(v) << endl;

	cout << getSmallSum2(v) << endl;

	system("pause");
	return 0;
}
