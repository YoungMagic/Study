/*
* ��Ŀ: ��̨��
* ����:
* һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;



class Solution {
public:
	int jumpFloor(int number) {
		if (number < 1)
			return 0;
		else if (number == 1)
			return 1;
		else if (number == 2)
			return 2;
		else{
			int fminus2 = 1, fminus1 = 2 , fn = 0;
			for (int i = 3; i <= number; ++i)
			{
				fn = fminus1 + fminus2;
				fminus2 = fminus1;
				fminus1 = fn;
			}//for
			return fn;
		}//else
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.jumpFloor(4) << endl;
//
//	system("pause");
//	return 0;
//}