/*
 * �����������ĺ����������	
 * ��Ŀ����
 * ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
 * ����������Yes,�������No���������������������������ֶ�������ͬ��
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		int size = sequence.size();

		vector<int> left_sequence , right_sequence;
		//�����ú������У�С��β�ڵ��Ԫ��Ϊ������������β�ڵ��Ԫ��Ϊ������
		int i;
		for (i = 0; i < size && sequence[i] < sequence[size - 1]; ++i)
			left_sequence.push_back(sequence[i]);

		while (i < size - 1)
		{
			if (sequence[i] < sequence[size - 1])
				return false;
			right_sequence.push_back(sequence[i]);
			++i;
		}

		//������������Ϊ��
		bool l = true, r = true;
		if (!left_sequence.empty())
			l = VerifySquenceOfBST(left_sequence);
		if (!right_sequence.empty())
			r = VerifySquenceOfBST(right_sequence);
		return l && r;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> v = { 4, 8, 6, 12, 16, 14, 10 };
//
//	cout << s.VerifySquenceOfBST(v) << endl;
//
//	system("pause");
//	return 0;
//}