/*
 * ��Ŀ����������1�ĸ���
 * ����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n)
		{
			++count;
			//��һ��������ȥ1 ����ԭ�����������㣬��Ѹ��������ұ�һ��1��Ϊ0
			n = (n - 1) & n;
		}//while

		return count;
	}
};

int main()
{
	Solution s;
	cout << s.NumberOf1(9) << endl;

	
	system("pause");
	return 0;
}