/*

���ɴ������ֵ����
��һ����������arr��һ����СΪw�Ĵ��ڣ������������߻������ұߣ�����ÿ�����ұ߻�һ��λ�á�
���磬����Ϊ[4,3,5,4,3,3,6,7]�����ڴ�СΪ3ʱ�����ɵĴ������ֵ����Ϊ[5,5,5,4,6,7]
������鳤��Ϊn�����ڴ�СΪw����һ������n-w+1�����ڵ����ֵ��
*/

#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>

using namespace std;

vector<int> getMaxWindow(vector<int> arr, int w)
{
	if (arr.empty() || w < 1 || arr.size() < w)
		return vector<int>();

	deque<int> qmax;
	vector<int> ret(arr.size() - w + 1, 0);
	int idx = 0 , len = arr.size();
	for (int i = 0; i < len; ++i)
	{
		while (!qmax.empty() && arr[qmax.back()] <= arr[i])
		{
			qmax.pop_back();
		}//while
		qmax.push_back(i);
		if (qmax.front() == i - w)
		{
			qmax.pop_front();
		}//if

		if (i >= w - 1)
		{
			ret[idx++] = arr[qmax.front()];
		}//if
	}//for
	return ret;
}

//int main()
//{
//	vector<int> v = { 4, 3, 5, 4, 3, 3, 6, 7 };
//	vector<int> maxWindow = getMaxWindow(v, 3);
//
//	for (unsigned i = 0; i < maxWindow.size(); ++i)
//	{
//		cout << maxWindow[i] << "\t";
//	}//for
//	cout << endl;
//
//	system("pause");
//	return 0;
//}