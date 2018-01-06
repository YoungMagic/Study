/*
5.8 �ж��ַ��������Ƿ����е��ַ���ֻ���ֹ�һ��

��Ŀ��
����һ���ַ���������chas[]���ж�chas���Ƿ����е��ַ���ֻ���ֹ�һ�Σ�
��������²�ͬ������Ҫ��ʵ������������

Ҫ��
��1��ʵ��ʱ�临�Ӷ�ΪO(N)�ķ���
��2���ڱ�֤����ռ临�Ӷ�O(1)��ǰ���£�ʵ��ʱ�临�ӶȾ����͵��㷨��
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>

using namespace std;

/*Ҫ��1������set�ṹ��Ψһ�Ը���ʵ��*/
bool isUnique(char str[])
{
	if (str == NULL)
		return true;

	unordered_set<char> cSet;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (cSet.find(str[i]) != cSet.end())
			return false;
		cSet.insert(str[i]);
	}//for

	return true;
}

/*Ҫ��2�����ö������㷨���ַ���������Ȼ������ж��ַ���Ψһ��*/
void swap(char str[], int parent, int i)
{
	char tmp = str[parent];
	str[parent] = str[i];
	str[i] = tmp;
}

void heapInsert(char str[], int i)
{
	int parent = 0;
	while (i != 0)
	{
		parent = (i - 1) / 2;
		if (str[parent] < str[i])
		{
			swap(str, parent, i);
			i = parent;
		}//if
		else
		{
			break;
		}
	}//while
}

/*�ѵ���*/
void heapify(char str[], int i, int size)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int largest = i;
	while (left < size)
	{
		if (str[left] > str[i])
			largest = left;

		if (right < size && str[right] > str[largest])
			largest = right;

		if (largest != i)
			swap(str, largest, i);
		else
		{
			break;
		}//else

		i = largest;
		left = 2 * i + 1;
		right = 2 * i + 2;
	}//while
}
void heapSort(char str[])
{
	if (str == NULL)
		return;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		heapInsert(str, i);
	}//for

	for (int i = strlen(str) - 1; i > 0; --i)
	{
		swap(str, 0, i);
		heapify(str, 0, i);
	}//for
}
bool isUnique2(char str[])
{
	if (str == NULL)
		return true;
	heapSort(str);
	for (int i = 1; i < strlen(str); ++i)
	{
		if (str[i] == str[i - 1])
			return false;
	}//for
	return true;
}

//int main()
//{
//	char str[] = "121";
//	cout << isUnique(str) << endl;
//	cout << isUnique2(str) << endl;
//
//	char str2[] = "abc";
//	cout << isUnique(str2) << endl;
//	cout << isUnique2(str2) << endl;
//
//	system("pause");
//	return 0;
//}