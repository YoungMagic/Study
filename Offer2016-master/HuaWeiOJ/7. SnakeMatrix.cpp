/************************************************************************/
/* 
��Ŀ˵��
���ξ�������1��ʼ����Ȼ���������гɵ�һ�������������Ρ�

��������
5
�������
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11
�ӿ�˵��
ԭ��
void GetResult(int Num, char * pResult);
���������
int Num�������������N
���������
int * pResult��ָ�������ξ�����ַ���ָ��
ָ��ָ����ڴ�����֤��Ч
����ֵ��
void

֪ʶ��	����
����ʱ������	10M
�ڴ�����	128
����
����������N��N������100��

���
���һ��N�е����ξ���

��������	4
�������	1 3 6 10 2 5 9 4 8 7
*/
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


void GetResult(int Num, int *pResult)
{
	vector<vector<int>> ret(Num, vector<int>(Num, 0));
	for (int i = 0, tmp = 1; i < Num; ++i)
	{
		for (int row = i, col = 0; col <= i &&row >= 0; --row, ++col)
		{
			ret[row][col] = tmp;
			++tmp;
		}		
	}//for

	for (int i = 0, k = 0; i < Num; ++i)
	{
		for (int j = 0; j < Num && ret[i][j] != 0; ++j)
		{
			pResult[k++] = ret[i][j];
		}//for
	}//for
}

int main()
{
	int N;
	cin >> N;
	int *ret = new int[(N*(N + 1)) / 2];
	GetResult(N, ret);
	
	/*��ʼ�е���ʼλ��*/
	int beg = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - i; ++j)
		{
			if (j == N - i - 1)
			{
				cout << ret[beg + N - i - 1] <<endl;
			}
			else{
				cout << ret[beg + j] << " ";
			}//else			
		}//for
		/*������һ����ʼλ��*/
		beg += (N - i);
	}//for
	
	system("pause");
	return 0;
}