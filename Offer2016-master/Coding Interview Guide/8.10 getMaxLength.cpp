/*
8.10 δ���������������ۼӺ�Ϊ����ֵ��������鳤��
��Ŀ��
����һ������arr�����������򣬵�ÿ��ֵ��Ϊ�������ٸ���һ������k��
��arr������������������Ԫ����Ӻ�Ϊk��������鳤�ȡ�
���磺arr=[1,2,1,1,1] k=3
�ۼӺ�Ϊ3��������鳤��Ϊ1 1 1 ����3
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int getMaxLen(vector<int> &arr, int k)
{
	if (arr.empty() || k <= 0)
		return 0;

	int lhs = 0, rhs = 0, len = 0, sum = arr[0];
	while (rhs < arr.size())
	{
		if (sum == k)
		{
			/*���µ���ָ����Сk�������鳤��*/
			len = (rhs - lhs + 1) > len ? (rhs - lhs + 1) : len;
			/*�����lhs֮��ʼ��������*/
			sum -= arr[lhs++];
		}//if
		else if (sum < k)
		{
			++rhs;
			if (rhs >= arr.size())
				break;
			sum += arr[rhs];
		}//elif
		else
		{
			sum -= arr[lhs++];
		}//else
	}//while
	return len;
}

int main()
{
	vector<int> arr = { 1, 2, 1, 1, 1 };
	cout << getMaxLen(arr, 3) << endl;

	system("pause");
	return 0;
}