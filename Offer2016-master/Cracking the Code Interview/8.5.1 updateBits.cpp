/*
* ������8.5.1 ��������32λ������N��M���Լ���ʾ����λ�õ�i��j����дһ����������M����N��
* ʹ��M��N�ĵ�jλ��ʼ������iλ�������ٶ��ӵ�jλ����iλ��������M��Ҳ����M=10011����ôj��i֮��
* ���ٿ�������5��λ�����磬�����ܳ���j=3��i=2���������Ϊ��3λ�͵�2λ֮��Ų���M��
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
	
	int updateBits(int n, int m, int j, int i)
	{
		/*��һ������n�ĵ�jλ����iλ���㣬���δ������������Ҳ�*/
		//�õ�һ����1
		int tmp = ~0;
		//��λ��j֮ǰ��λ��Ϊ1
		int left = tmp << (j + 1);

		//��λ��i֮���λ��Ϊ1
		int right = (1 << i) - 1;

		//�õ�����i��jλΪ0������λΪ1
		int mask = left | right;

		/*�ڶ��������n�ĵ�i��jλ֮���ֵ*/
		n &= mask;

		/*�����������m */
		m <<= i;

		return n | m;
	}
};

int main()
{
	Solution s;
	int n = 10000000000, m = 10011, i = 2, j = 6;

	cout << s.updateBits(n, m, j, i) << endl;

	system("pause");
	return 0;

}