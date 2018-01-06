/*������9.3 N!��0�ĸ���*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*��ͨ����1~N�к��ж��ٸ�����5*/
int zeroNum1(int n)
{
	int count = 0;
	for (int i = 5; i <= n; i += 5)
	{
		int tmp = i;
		while (tmp % 5 == 0)
		{
			++count;
			tmp /= 5;
		}//while
	}//for
	return count;
}

/*���Ž� count = n/5 + n/(5^2) + n/5^3 + ... + n/5^i  iһֱ������֪��5^i > N*/
int zeroNum2(int n)
{
	int count = 0;
	while (n)
	{
		count += n / 5;
		n /= 5;
	}//while
	return count;
}
//int main()
//{
//	cout << zeroNum1(6) << endl;
//	cout << zeroNum2(6) << endl;
//
//	system("pause");
//	return 0;
//}