/*
8.14 ��Ȼ���������
��Ŀ������һ������ΪN����������arr��������N��������ȵ���Ȼ��1~N��
��ʵ��arr������
Ҫ��ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(1)
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*����һ������һ����ʱ��������Ծ��䷽ʽ*/
void sort1(vector<int> &arr)
{
	if (arr.empty())
		return;

	int len = arr.size();
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == (i+1))
			continue;
		else{
			/*��iλ�õ���ֵtmp������Ӧ�ڵ�λ��tmp-1*/
			int tmp = arr[i];
			while (arr[i] != (i + 1))
			{
				/*����tmp-1λ�ô����洢��ֵ����һѭ���������Ӧ���ڵ�λ��*/
				int next = arr[tmp - 1];
				arr[tmp - 1] = tmp;
				tmp = next;
			}//while
		}//else
	}//for
}

/*�������������滻�ķ�ʽ*/
void sort2(vector<int> &arr)
{
	if (arr.empty())
		return;

	int len = arr.size();
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == (i+1))
			continue;
		else{			
			while (arr[i] != (i + 1))
			{
				int tmp = arr[i];
				arr[i] = arr[tmp - 1];
				arr[tmp - 1] = tmp;
			}//while
		}//else
	}//for
}

int main()
{
	vector<int> v = { 2, 3, 1, 5, 4 };
	sort2(v);

	system("pause");
	return 0;
}