/*
8.3 "֮"���δ�ӡ����
����һ������matrix�����ա�֮�����εķ�ʽ��ӡ����������磺
1	2	3	4
5	6	7	8
9	10	11	12
13	14	15	16
֮���δ�ӡ���Ϊ��1 2 5 9 6 3 4 7 10 13 14 11 8 12 15 16

Ҫ�󣺶���ռ临�Ӷ�ΪO(1)
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void zigzagPrintMatrix(vector<vector<int>> &matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int tR = 0, tC = 0, dR = 0, dC = 0;

	int endR = m - 1, endC = n - 1;

	/*������Ʊ���*/
	bool fromUp = false;
	while (tR != endR + 1)
	{
		if (fromUp)
		{
			int curR = tR, curC = tC;
			while (curR != dR + 1)
			{
				cout << matrix[curR++][curC--] << "\t";
			}//while
		}
		else{
			int curR = dR, curC = dC;
			while (curR != tR - 1)
			{
				cout << matrix[curR--][curC++] << "\t";
			}//while
		}//else

		tR = tC == endC ? tR + 1 : tR;
		tC = tC == endC ? tC : tC + 1;
		dC = dR == endR ? dC + 1 : dC;
		dR = dR == endR ? dR : dR + 1;

		fromUp = !fromUp;
	}//while
	cout << endl;
}

int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	zigzagPrintMatrix(matrix);

	system("pause");
	return 0;
}