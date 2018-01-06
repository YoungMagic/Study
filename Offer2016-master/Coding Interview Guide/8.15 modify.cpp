/*
8.15 �����±궼����������ż���±궼��ż��

��Ŀ������һ�����Ȳ�С��2������arr��ʵ��һ����������arr��Ҫô�����е�ż���±궼��ż����
Ҫô�����е������±궼��������

Ҫ�����arr�ĳ���ΪN������Ҫ��ʱ�临�Ӷ�ΪO(N)������ռ临�Ӷ�ΪO(1)
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*����Ԫ��ֵ*/
void swap3(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/*��Ҫ���������Ԫ��,���̶ȵı�֤ż���±�洢ż��Ԫ�أ������±�洢����Ԫ��*/
void modify(vector<int> &arr)
{
	if (arr.empty() || arr.size() < 2)
		return;

	int len = arr.size();
	int even = 0, odd = 1, end = len - 1;
	while (even < len && odd < len)
	{
		/*��βԪ��Ϊż��*/
		if ((arr[end] & 0x1) == 0)
		{
			/*������ǰż���±���βԪ��*/
			swap3(arr[end], arr[even]);
			even += 2;
		}//if
		/*βԪ��Ϊ����������*/
		else{
			swap3(arr[end], arr[odd]);
			odd += 2;
		}//else
	}//while
}

int  main()
{
	vector<int> arr = { 1, 3, 4, 2, 5, 7, 21, 48 };
	modify(arr);

	system("pause");
	return 0;

}