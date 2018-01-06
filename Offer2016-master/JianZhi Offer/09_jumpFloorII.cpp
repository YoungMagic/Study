/*
* ��Ŀ: ��̨��
* ����:
* һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int jumpFloorII(int number) {
		
		vector<int> ways(number + 1, 0);
		//ֻ��һ��̨��ʱ��һ�ַ�ʽ
		ways[1] = 1;
		for (int i = 2; i <= number; ++i)
		{
			//����һ����
			ways[i] += 1;
			//�����
			for (int j = 1; j < i; ++j)
			{
				ways[i] += ways[j];
			}
		}
		return ways[number];
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.jumpFloorII(4) << endl;
//
//	system("pause");
//	return 0;
//}