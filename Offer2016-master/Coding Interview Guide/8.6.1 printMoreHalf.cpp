/*
��Ŀ��8.5.1 ���������ҵ����ִ�������һ�������
Ҫ�󣺸���һ����������arr����ӡ���г��ִ�������һ�������
���û��������������ӡ��ʾ��Ϣ��	
*/

#include <iostream>
#include <cstdlib>

using namespace std;
void printMoreHalf(int arr[] , int N)
{
	if(N <= 0)
		cout<<"The array is empty!"<<endl;
	int cand = arr[N-1],times=0;
	for(int i=0;i<N;++i)
	{
		if (0 == times)
		{
			cand = arr[i];
			times = 1;
		}
		else if(arr[i] == cand)
			++times;
		else
			--times;
	}//for
	
	int count = 0;
	for(int i=0;i<N;++i)
	{
		if(arr[i] == cand)
			++count;
	}//for
	if(count <= N/2)
		cout<<"There is not number!"<<endl;
	else
		cout<<cand<<endl;
}

//int main()
//{
//	int arr[] = {1,2,3,4,4,4,4,4,5};
//	
//	printMoreHalf(arr,9);
//	
//	system("pause");
//	return 0;
//}