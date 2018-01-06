/*
������8����ת�������С����
��Ŀ����һ��������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
���磬����{3��4��5��1��2}Ϊ����{1��2��3��4��5}��һ����ת�����������СֵΪ1��
*/

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

/*˳�����*/
int minNumber(int *arr, int beg, int end)
{
	int minRet = arr[beg];
	for (int i = beg; i <= end; ++i)
	{
		if (arr[i] < minRet)
			minRet = arr[i];
	}//for
	return minRet;
}

/*���ö��ֵ�˼�����*/
int minNumber(int *arr, int len)
{
	assert((arr != NULL) && (len > 0));

	int beg = 0, end = len - 1;
	int mid = beg;
	while (arr[beg] >= arr[end])
	{
		if (end - beg == 1)
		{
			mid = end;
			break;
		}//if

		mid = (beg + end) / 2;

		if (arr[beg] == arr[mid] && arr[mid] == arr[end])
			return minNumber(arr, beg, end);

		else if (arr[mid] >= arr[beg])
		{
			beg = mid;
		}
		else
		{
			end = mid;
		}//elif
	}//while
	return arr[mid];
}

int main()
{
	int arr[] = { 1, 0, 1, 1, 1 };
	int arr2[] = { 1, 1, 1, 0, 1 };
	int arr3[] = { 3, 4, 5, 1, 2 };

	cout << minNumber(arr, 5) << endl;
	cout << minNumber(arr2, 5) << endl;
	cout << minNumber(arr3, 5) << endl;

	system("pause");
	return 0;
}