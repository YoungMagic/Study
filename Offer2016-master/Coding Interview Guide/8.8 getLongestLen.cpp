/*
8.8 ������������鳤��
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>

using namespace std;

int getLongestLen(const vector<int> &arr)
{
	if (arr.empty())
		return 0;

	int size = arr.size(), maxLen = 0;
	unordered_set<int> subArr;
	/*��֤����������*/
	for (int i = 0; i < size; ++i)
	{
		subArr.clear();
		int maxNum = INT_MIN, minNum = INT_MAX;
		for (int j = i; j < size; ++j)
		{
			/*�������ظ�Ԫ�أ���������鲻�����ϣ�������һѭ��*/
			if (subArr.count(arr[j]))
				continue;
		
			subArr.insert(arr[j]);
			/*���¸�������������Сֵ*/
			if (maxNum < arr[j])
				maxNum = arr[j];
			else if (minNum > arr[j])
				minNum = arr[j];

			/*��֤���������Ƿ�Ϊ����������:���ֵ-��Сֵ+1���������鳤��*/
			if (maxNum - minNum == j - i)
				maxLen = maxLen > (j - i + 1) ? maxLen : (j - i + 1);
		}//for
		return maxLen;
	}
}

int main()
{
	vector<int> arr = { 5, 5, 3, 2, 6, 4, 3 };
	cout << getLongestLen(arr) << endl;

	system("pause");
	return 0;
}