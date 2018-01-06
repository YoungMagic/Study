/*
8.9.2 ���ظ���ӡ������������Ӻ�Ϊ����ֵ��������Ԫ��
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void printUniquePair(const vector<int> &arr,int idx , int left , int right, const int &K)
{
	if (arr.empty() || left >= right)
		return;

	/*����ָ��*/
	while (left < right)
	{
		if (arr[left] + arr[right] == K)
		{
			cout << "{" << arr[idx] << ", " << arr[left] << ", " << arr[right] << "}" << endl;
			++left;
			--right;
		}//if
		else if (arr[left] + arr[right] < K)
			++left;
		else
			--right;
	}//while
}

void printUniqueTriad(const vector<int> &arr, int K)
{
	if (arr.empty())
		return;

	int len = arr.size();
	for (int i = 0; i < len-2; ++i)
	{
		/*�����ظ�Ԫ��*/
		if (0 == i || arr[i] != arr[i - 1])
		{
			printUniquePair(arr, i, i + 1, len - 1, K - arr[i]);
		}//if
	}//for
}

//int main()
//{
//	vector<int> arr = { -8, -4, -3, 0, 1, 2, 4, 5, 8, 9 };
//
//	printUniqueTriad(arr, 10);
//
//	system("pause");
//	return 0;
//}
