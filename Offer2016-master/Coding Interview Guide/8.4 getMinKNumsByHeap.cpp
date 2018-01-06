/*
8.4 �ҵ�������������С��k������
��Ŀ������һ���������������arr���ҵ�������С��k������

Ҫ���������arr�ĳ���ΪN������֮����Ȼ���Եõ���С��k��������ʱʱ�临�Ӷ��������ʱ�临�Ӷ���ͬ��
��ΪO(nlogn)������Ҫ�����ʵ��ʱ�临�Ӷ�ΪO(nlogk)��O(n)���㷨��
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*��������*/
void swap2(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/*���Ѻ���*/
void heapInsert(vector<int> &arr, int val, int idx)
{
	arr[idx] = val;
	while (idx != 0)
	{
		int parent = (idx - 1) / 2;
		if (arr[parent] < arr[idx])
		{
			swap2(arr[parent], arr[idx]);
			idx = parent;
		}//if
		else
			break;
	}//while
}

/*�ѵ�������*/
void heapify(vector<int> kHeap, int idx, int heapSize)
{
	/*��õ���Ŀ��ڵ�����Һ���*/
	int lhs = 2 * idx + 1, rhs = 2 * idx + 2;
	int largest = idx;

	/*�ҵ���ǰ�ڵ��������Һ��������ֵ�ڵ�*/
	while (lhs < heapSize)
	{
		if (kHeap[lhs] > kHeap[idx])
			largest = lhs;
		if (rhs < heapSize && kHeap[rhs] > kHeap[largest])
			largest = rhs;

		if (largest != idx)
		{
			swap2(kHeap[largest], kHeap[idx]);
		}//if
		else
		{
			break;
		}//else

		/*�Ե����ϵ���*/
		idx = largest;
		lhs = 2 * idx + 1;
		rhs = 2 * idx + 2;
	}//while
}

/*ʹ�ö�����ʵ��*/
vector<int> getMinKNumsByHeap(vector<int> arr , int k)
{
	if (arr.empty() || k <= 0)
		return vector<int>();
	int len = arr.size();
	if (len <= k)
		return arr;

	/*����*/
	vector<int> kHeap(k, 0);
	for (int i = 0; i < k; ++i)
	{
		heapInsert(kHeap, arr[i], i);
	}//for

	/*����ʣ��Ԫ�أ�����СԪ�ص�kHeap*/
	for (int i = k; i < len; ++i)
	{
		if (arr[i] < kHeap[0])
		{
			kHeap[0] = arr[i];
			/*���Ƶ���*/
			heapify(kHeap, 0, k);
		}//if
	}//for
	return kHeap;
}

int main()
{
	vector<int> v = { 2, 3, 5, 23, 56, 2, 6, 8, 9, 9, 10, 34, 54 };
	vector<int> kV = getMinKNumsByHeap(v, 3);

	for (unsigned int i = 0; i < kV.size(); ++i)
		cout << kV[i] << "\t";

	cout << endl;
	system("pause");
	return 0;
}