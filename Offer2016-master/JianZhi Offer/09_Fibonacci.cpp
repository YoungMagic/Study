/*
* ��Ŀ: 쳲���������
* ����:
* ��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


class Solution {
public:
	int Fibonacci(int n) {
		//�洢쳲���������
		vector<int> v(n+1, 0);
		v[0] = 0;
		v[1] = 1;

		for (int i = 2; i <= n; ++i)
			v[i] = v[i - 1] + v[i - 2];

		return v[n];
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.Fibonacci(3) << endl;
//
//	system("pause");
//	return 0;
//}