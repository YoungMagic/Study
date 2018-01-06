/*
4.7 �����������

���������ַ���str1��str2�����������ַ���������������С�
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*���㶯̬�滮����*/
vector<vector<int>> getDp(string A, string B)
{
	if (A.empty() || B.empty())
	{
		return vector<vector<int>>();
	}//if

	int aLen = A.size(), bLen = B.size();

	/*����dp[i][j]�ĺ������ַ���A[0...i]���ַ���B[0...j]������������г��ȣ������ң����ϵ��¼������dp*/
	vector<vector<int>> dp(aLen, vector<int>(bLen, 0));
	dp[0][0] = A[0] == B[0] ? 1 : 0;
	for (int i = 1; i < aLen; ++i)
	{
		dp[i][0] = max(dp[i - 1][0], A[i] == B[0] ? 1 : 0);
	}//for

	for (int j = 1; j < bLen; ++j)
	{
		dp[0][j] = max(dp[0][j], A[0] == B[j] ? 1 : 0);
	}//for

	for (int i = 1; i < aLen; ++i)
	{
		for (int j = 1; j < bLen; ++j)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if (A[i] == B[j])
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}//if
		}//for
	}//for

	/*��ʱdp[aLen-1][bLen-1]��������������еĳ���*/
	return dp;
}

/*�������������*/
string longestCommonSubsequence(string str1, string str2)
{
	if (str1.empty() || str2.empty())
	{
		return "";
	}//if

	/*�õ�����������г��ȵĶ�̬�滮���Ⱦ���*/
	vector<vector<int>> dp = getDp(str1, str2);

	int m = str1.length() - 1, n = str2.length() - 1, len = dp[m][n];
	/*����������г���Ϊlen����ʼ��һ������ַ���*/
	string ret(len,'0');
	/*�����½Ǳ�������*/
	for (int idx = len - 1; idx >= 0; )
	{
		if (n > 0 && dp[m][n] == dp[m][n - 1])
		{
			/*��ѡstr1[m] �� str2[n] �����ƶ�*/
			--n;
		}//if
		else if (m > 0 && dp[m][n] == dp[m - 1][n])
		{
			/*��ѡstr1[m] �� str2[n] �����ƶ�*/
			--m;
		}//elif
		else {
			/*ѡ��ǰ�ַ��������Ϸ��ƶ�*/
			ret[idx--] = str1[m];
			--m;
			--n;
		}//else
	}//for

	return ret;
}

int main()
{
	string str1 = "1A2C3D4B56", str2 = "B1D23CA45B6A";
	cout << longestCommonSubsequence(str1, str2) << endl;

	system("pause");
	return 0;
}