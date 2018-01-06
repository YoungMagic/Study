/*
* ������8.9.4 ��дһ������������ĳ���ϵ������Ӽ���
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution{
public:
	/*����һ���ݹ�ʵ��*/
	vector<vector<int>> getSubsets(vector<int> &nums)
	{
		vector<vector<int> > ret;
		/*�ռ���ֻ��һ�����Ӽ�*/
		if (nums.empty())
		{
			ret.push_back(vector<int>());
			return ret;
		}
		/*�õ�[0,len-2]�������е������Ӽ�*/
		vector<vector<int>> tmpSets = getSubsets(vector<int>(nums.begin(), nums.begin() + nums.size() - 1));
		auto iter = tmpSets.begin();
		while (iter != tmpSets.end())
		{
			ret.push_back(*iter);
			(*iter).push_back(nums[nums.size() - 1]);
			ret.push_back(*iter);
			++iter;
		}//while
		return ret;
	}

	/*�����������������ѧ��֪ʶ*/
	vector<vector<int>> getSubsets2(vector<int> &nums)
	{
		vector<vector<int>> ret;
		/*�Ӽ��ϵĸ���*/
		int size = 1 << nums.size();
		
		/*ÿ��ֵ��Ӧ�Ķ��������ж���Ӧ��һ���Ӽ���*/
		for (int i = 0; i < size; ++i)
		{
			vector<int> tmp = convertIntToSet(i, nums);
			ret.push_back(tmp);
		}//for
		return ret;
	}

	vector<int> convertIntToSet(int x, vector<int> &nums)
	{
		vector<int> subset = vector<int>();

		int idx = 0;
		for (int i = x; i > 0; i >>= 1)
		{
			if ((i & 1) == 1)
				subset.push_back(nums[idx]);
			++idx;
		}//for
		return subset;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 2, 3 };

	vector<vector<int>> ret = s.getSubsets2(v);

	for (unsigned i = 0; i < ret.size(); ++i)
	{
		for (unsigned j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << "\t";
		cout << endl;
	}//for

	system("pause");
	return 0;
}