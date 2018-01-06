/*
 * ������51���������ظ�������
 * ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�
 * ����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
 * ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3��
*/

#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	//����һ�����ù�ϣ��˼�룬����STL���unordered_set
	bool duplicate1(int numbers[], int length, int* duplication) {
		if (length <= 0)
			return false;

		unordered_set<int> us;
		for (int i = 0; i < length; ++i)
		{
			if (us.count(numbers[i]) <= 0)
			{
				us.insert(numbers[i]);
				continue;
			}
			else
			{
				*duplication = numbers[i];
				return true;
			}
		}//for
		return false;
	}

	//��������ԭ������ T(n)=O(n) S(n)=O(1)
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length <= 0)
			return false;

		for (int i = 0; i < length; ++i)
		{
			if (numbers[i] < 0 || numbers[i] >= length)
				return false;
		}//for

		for (int i = 0; i < length; ++i)
		{
			//���ڶ�Ӧλ���򽻻�
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				int tmp = numbers[i];
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
			}//while
		}//for
		return false;

	}
};

//int main()
//{
//	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
//	Solution s;
//	int duplication = 0;
//
//	if(s.duplicate(numbers, 7, &duplication))
//		cout << duplication << endl;
//
//	system("pause");
//	return 0;
//
//}
