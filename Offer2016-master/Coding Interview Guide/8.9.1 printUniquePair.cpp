/*
8.9 ���ظ���ӡ������������Ӻ�Ϊ����ֵ�����ж�Ԫ��
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void printUniquePair(const vector<int> &arr, const int &K)
{
	if (arr.empty())
		return;

	/*����ָ��*/
	int left = 0, right = arr.size() - 1;
	while (left < right)
	{
		if (arr[left] + arr[right] == K)
		{
			cout << "{" << arr[left] << ", " << arr[right] << "}" << endl;
			++left;
			--right;
		}//if
		else if (arr[left] + arr[right] < K)
			++left;
		else
			--right;
	}//while
}

int main()
{
	vector<int> arr = { -8, -4, -3, 0, 1, 2, 4, 5, 8, 9 };

	printUniquePair(arr, 10);

	system("pause");
	return 0;
}
