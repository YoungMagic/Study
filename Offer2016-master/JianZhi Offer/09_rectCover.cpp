/*
* ��Ŀ: ���θ���
* ����:
* ���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
* ������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;

		int fminus1 = 2, fminus2 = 1 , fn;
		for (int i = 3; i <= number; ++i)
		{
			fn = fminus1 + fminus2;
			fminus2 = fminus1;
			fminus1 = fn;
		}//for

		return fn;
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.rectCover(4) << endl;
//
//	system("pause");
//
//	return 0;
//}