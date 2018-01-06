/*
* ������8.9.1 n��¥������
* �и�С��������¥�ݣ�¥����n��̨�ף�С��һ�ο�����1��2��3�ף�ʵ��һ������������С���ж�������¥�ݵķ�ʽ��
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution{
public:
	//����һ���ݹ�ʵ�֣�ʱ�临�Ӷ�O(3^n)
	int countSteps1(int n)
	{
		if (n <= 0)
			return 0;
		else if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else if (n == 3)
			return countSteps1(1) + countSteps1(2) + 1;
		else
		{
			return countSteps1(n - 1) + countSteps1(n - 2) + countSteps1(n - 3);
		}//else
	}

	//�������������м仺�棬���ö�̬�滮��˼�룬�Ż�����
	int countSteps(int n)
	{
		if (0 == n)
			return 0;
		vector<int> nums(n + 1, 0);
		nums[1] = 1;
		nums[2] = 2;
		nums[3] = nums[1] + nums[2] + 1;

		for (int i = 4; i <= n; ++i)
		{
			nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3];
		}//for
		return nums[n];
	}
};

int main()
{
	Solution s;
	cout << s.countSteps1(6) << endl;
	cout << s.countSteps(6) << endl;
	system("pause");
	return 0;
}