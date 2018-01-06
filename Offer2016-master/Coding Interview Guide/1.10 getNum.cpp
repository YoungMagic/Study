/*
��Ŀ�����ֵ��ȥ��СֵС�ڻ����num������������
��������arr������num���������ж��ٸ��������������������
max(arr[i...j]) - min(arr[i...j]) <= num

max(arr[i...j])��ʾ������arr[i...j]�е����ֵ��min(arr[i...j])��ʾ������arr[i...j]�е���Сֵ��

Ҫ��������鳤��ΪN����ʵ��ʱ�临�Ӷ�ΪO(N)���㷨��
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

using namespace std;

int getNum(vector<int> arr, int num)
{
	if (arr.empty())
		return 0;

	deque<int> qmin, qmax;
	int i = 0, j = 0, ret = 0, len = arr.size();
	while (i < len)
	{
		while (j < len)
		{
			while (!qmin.empty() && arr[qmin.back()] >= arr[j])
				qmin.pop_back();
			qmin.push_back(j);
			while (!qmax.empty() && arr[qmax.back()] <= arr[j])
				qmax.pop_back();
			qmax.push_back(j);

			if (arr[qmax.front()] - arr[qmin.front()] > num)
				break;
			++j;
		}//while
		if (qmin.front() == i)
			qmin.pop_front();
		if (qmax.front() == i)
			qmax.pop_front();

		ret += (j - i);
		++i;
	}//while
	return ret;
}

int main()
{
	vector<int> v = { 4, 3, 5, 4, 3, 3, 6, 7 };
	cout << getNum(v, 2) << endl;

	system("pause");
	return 0;
}