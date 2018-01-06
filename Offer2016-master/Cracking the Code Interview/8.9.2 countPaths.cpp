/*
* ������8.9.2 ��������·������
* �����и�����������X*Y��������Ͻǣ�ֻ�����ҡ������ƶ��������˴�(0,0)��(x,y)�ж������߷���
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution{
public:
	//����һ���ݹ�ʵ�֣����ܱȽϲ�
	int countPaths1(int x, int y)
	{
		if (x == 0 && y == 0)
			return 0;
		if (x == 0 || y == 0)
			return 1;
		else
			return countPaths1(x - 1, y) + countPaths1(x, y - 1);
	}

	//������������ʽ�Ƶ����Ϊ(x+y)!/x!y!
	int countPaths2(int x, int y)
	{
		if (x == 0 && y == 0)
			return 0;
		if (x == 0 || y == 0)
			return 1;
		else
			return factorial(x + y) / (factorial(x)*factorial(y));
	}
	int factorial(int n)
	{
		int ret = 1;
		while (n)
			ret *= n--;
		return ret;
	}

	//����������̬�滮
	int countPaths(int x, int y)
	{
		if (x == 0 && y == 0)
			return 0;
		vector<vector<int> > paths(x + 1, vector<int>(y + 1, 0));
		for (int i = 1; i <= x; ++i)
			paths[i][0] = 1;
		for (int j = 1; j <= y; ++j)
			paths[0][j] = 1;
		
		for (int i = 1; i <= x; ++i)
		{
			for (int j = 1; j <= y; ++j)
			{
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
			}//for
		}//for
		return paths[x][y];
	}
};

int main()
{
	Solution s;
	cout << s.countPaths1(2, 4) << endl;
	cout << s.countPaths2(2, 4) << endl;
	cout << s.countPaths(2, 4) << endl;

	system("pause");
	return 0;
}