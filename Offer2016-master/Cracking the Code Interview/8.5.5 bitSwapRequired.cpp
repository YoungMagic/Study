/*
* ������8.5.5 ��дһ��������ȷ����Ҫ�ı伸��λ���ܽ�����Aת��Ϊ����B
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
	int bitSwapRequired(int A, int B)
	{
		//��AB��������ӵ͵��������жϵ�ǰλ�Ƿ�Ϊ1
		int c = A^B, count = 0;
		for (; c != 0; c >>= 1)
		{
			count += c & 1;
		}//for
		return count;
	}

	//������
	int bitSwapRequired2(int a, int b)
	{
		int c = a ^ b, count = 0;
		//��ab����������η�ת�����Чλ
		for (; c != 0; c = c&(c - 1))
		{
			++count;
		}//for
		return count;
	}

};

int main()
{
	Solution s;

	cout << s.bitSwapRequired(7, 8) << endl;
	cout << s.bitSwapRequired2(7, 8) << endl;

	system("pause");
	return 0;
}