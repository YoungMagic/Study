/*
4.8 ������Ӵ�
���������ַ���str1��str2�����������ַ�����������Ӵ���

������str1=��1AB2345CD����str2="12345EF"�����ء�2345��
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
	// write your code here
	if (A.empty() || B.empty())
	{
		return vector<vector<int>>();
	}//if

	int aLen = A.size(), bLen = B.size();
	/*��̬�滮��ʱ�临�Ӷ�O(mn) �ռ临�Ӷ�O(mn��
	dp[i][j]��ʾ�����A[i]��B[j]��Ϊ�����Ӵ������һ���ַ�ʱ���Ӵ���󳤶�*/
	vector<vector<int>> dp(aLen, vector<int>(bLen, 0));
	dp[0][0] = A[0] == B[0] ? 1 : 0;

	for (int i = 1; i<aLen; ++i)
	{
		dp[i][0] = A[i] == B[0] ? 1 : 0;
	}//for

	for (int j = 1; j<bLen; ++j)
	{
		dp[0][j] = A[0] == B[j] ? 1 : 0;
	}//for


	for (int i = 1; i<aLen; ++i)
	{
		for (int j = 1; j<bLen; ++j)
		{
			if (A[i] == B[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}//if
			else {
				dp[i][j] = 0;
			}//if
		}//for
	}//for
	/*��ʱ������Ӵ��ĳ��ȼ�Ϊ����dp�е����ֵ*/
	return dp;
}

/*����һ�����䶯̬�滮 ʱ�临�Ӷ�O(m*n) �ռ临�Ӷ�O(m*n)*/
string longestCommonSubstring(string str1, string str2)
{
	if (str1.empty() || str2.empty())
	{
		return "";
	}//if

	/*�õ�������Ӵ����ȵĶ�̬�滮���Ⱦ���*/
	vector<vector<int>> dp = getDp(str1, str2);

	int m = str1.length(), n = str2.length(), maxLen = 0, end = 0;
	/*�ҵ�������Ӵ��ĳ��ȣ�������str1�еĽ���λ��*/
	for(int i = 0 ; i < m ; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (dp[i][j] > maxLen)
			{
				maxLen = dp[i][j];
				end = i;
			}//if
		}//for
	}//for

	return str1.substr(end - maxLen + 1, maxLen);
}


/*���������Ż��㷨 �ռ临�Ӷ�O(1)*/
string longestCommonSubstring2(string str1, string str2)
{
	if (str1.empty() || str2.empty())
	{
		return "";
	}//if

	/*б�߿�ʼ���к���*/
	int row = 0, col = str2.length() - 1;
	/*�����Ӵ���󳤶ȣ���str1�еĽ���λ��*/
	int maxLen = 0, end = 0;
	while (row < str1.length())
	{
		int i = row, j = col, len = 0;
		/*��(i,j)��ʼ�����·�����*/
		while (i < str1.length() && j < str2.length())
		{
			if (str1[i] != str2[j])
			{
				len = 0;
			}//if
			else {
				++len;
			}//else

			/*��¼���ֵ�Լ������ַ���λ��*/
			if (maxLen < len)
			{
				maxLen = len;
				end = i;
			}//if

			++i;
			++j;
		}//while

		/*б�߿�ʼλ�õ����������ƶ�*/
		if (col > 0)
		{
			--col;
		}//if
		/*���ƶ��������Ժ��������ƶ�*/
		else {
			++row;
		}//else
	}//while
	return str1.substr(end - maxLen + 1, maxLen);
}

int main()
{
	string str1 = "1AB2345CD", str2 = "12345EF";
	cout << longestCommonSubstring2(str1, str2) << endl;

	system("pause");
	return 0;
}