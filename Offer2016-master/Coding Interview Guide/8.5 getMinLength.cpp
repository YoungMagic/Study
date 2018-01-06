/*
��Ŀ��8.5  ��Ҫ�������������鳤��
����һ����������arr�������Ҫ�������������鳤�ȡ�
���磺arr={1��5��3��4��2��6��7}����4��
ֻ��{5��3��4��2}����Ҫ����
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int getMinLength(int arr[], int n)
{
	if (n <= 0)
		return 0;
	
	int minNum = arr[n - 1];
	int noMinIdx = -1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (arr[i] > minNum)
		{
			noMinIdx = i;
		}
		else{
			minNum = arr[i];
		}//else
	}//for

	if (-1 == noMinIdx)
		return 0;

	int maxNum = arr[0], noMaxIdx = -1;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < maxNum)
		{
			noMaxIdx = i;
		}
		else{
			maxNum = arr[i];
		}//else
	}//for

	if (-1 == noMaxIdx)
		return 0;

	return noMaxIdx - noMinIdx + 1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

	int len = getMinLength(arr, 7);

	cout << len << endl;

	system("pause");
	return 0;
}
