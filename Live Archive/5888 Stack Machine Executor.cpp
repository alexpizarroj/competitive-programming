#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

/*
-------------------------
Instruction abbreviations
-------------------------
NUM N
POP P
INV I
ADD A
SUB S
DIV D
MOD M
--------------------------
Special Inst. abbreviations
--------------------------
DUP U
SWP W
MUL Q
*/

bool run(const int initialValue, const int nInst,
	const char* inst, const int* instParam, int stk[])
{
	const int cstMaxValue = 1000000000;
	int res; long long longres;

	int pStk = 0;
	stk[pStk++] = initialValue;
	for(int i = 0; i < nInst; i++)
	{
		switch (inst[i])
		{
			case 'N':
				stk[pStk] = instParam[i];
				++pStk;
				break;

			case 'P':
				if (pStk < 1) return false;
				--pStk;
				break;

			case 'I':
				if (pStk < 1) return false;
				stk[pStk-1] *= -1;
				break;

			case 'U':
				if (pStk < 1) return false;
				stk[pStk] = stk[pStk-1];
				++pStk;
				break;

			case 'W':
				if (pStk < 2) return false;
				swap(stk[pStk-2], stk[pStk-1]);
				break;

			case 'A':
				if (pStk < 2) return false;
				res = stk[pStk-2] + stk[pStk-1];
				if (abs(res) > cstMaxValue) return false;

				stk[pStk-2] = res;
				--pStk;
				break;

			case 'S':
				if (pStk < 2) return false;
				res = stk[pStk-2] - stk[pStk-1];
				if (abs(res) > cstMaxValue) return false;

				stk[pStk-2] = res;
				--pStk;
				break;

			case 'Q':
				if (pStk < 2) return false;
				longres = (long long)stk[pStk-2] * stk[pStk-1];
				if (abs(longres) > cstMaxValue) return false;

				stk[pStk-2] = (int)longres;
				--pStk;
				break;

			case 'D':
				if (pStk < 2 || stk[pStk-1] == 0) return false;
				res = stk[pStk-2] / stk[pStk-1];

				stk[pStk-2] = res;
				--pStk;
				break;

			case 'M':
				if (pStk < 2 || stk[pStk-1] == 0) return false;
				res = abs(stk[pStk-2]) % abs(stk[pStk-1]);
				if (stk[pStk-2] < 0) res *= -1;

				stk[pStk-2] = res;
				--pStk;
				break;

			default:
				assert("This should not happen");
		}
	}

	if (pStk != 1) return false;
	printf("%d\n", stk[0]);
	return true;
}

int main()
{   
	int nInst, stk[1005];
	char inst[100005], tmp[15];
	int *instParam = new int[100005];
	
	while (true)
	{
		scanf("%s", tmp);
		if (tmp[0] == 'Q')
			break;

		nInst = 0;
		while (tmp[0] != 'E')
		{
			// Instruction recognition
			char instruction = tmp[0];
			if (strncmp("DU", tmp, 2) == 0)
				instruction = 'U';
			else if (strncmp("SW", tmp, 2) == 0)
				instruction = 'W';
			else if (strncmp("MU", tmp, 2) == 0)
				instruction = 'Q';
			inst[nInst] = instruction;

			// Do we have a parameter?
			if (instruction == 'N')
			{
				int param;
				scanf("%d", &param);
				instParam[nInst] = param;
			}

			// Next instruction, please!
			++nInst;
			scanf("%s", tmp);
		}

		int nQueries;
		scanf("%d", &nQueries);
		for(int q = 1; q <= nQueries; q++)
		{
			int initialValue;
			scanf("%d", &initialValue);
			if (!run(initialValue, nInst, inst, instParam, stk))
				puts("ERROR");
		}
		puts("");
	}
	
	delete[] instParam;
	return 0;
}
