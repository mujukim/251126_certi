// 251126_certi.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#define MAX_N 100
int _map[MAX_N][MAX_N];
int _N, _M;

int cvtGrade2int(char Grade[]);

void init(int N, int M, char mGrade[][][])
{
	memset(map, 0x00, sizeof(int) * MAX_N * MAX_N);
	_N = N;
	_M = M;
	for (int i = 0; i < _N; i++)
	{
		for (int j = 0; j < _N; j++)
		{
			_map[i][j] = cvtGrade2int(mGrade[i][j]);
		}
	}

}

int cvtGrade2int(char Grade[])
{
	int len = strlen(Grade);
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret = Grade[i] - 'A' + (26 * ret);
		// A = 0 AA = 0 B = 1 AB = 1 --> 그래서 길이가 길수록 약하게 만들어야함
	}
	ret = ret + 10000 * len;
	return ret; // A = 0, A = 20000 B = 1, AB =20001

}

void change(int mRow, int mCol, int mDir, int mLength, char mGrade[])
{
	int dx = 0, dy = 0;
	for (int i = 0; i < mLength; i++)
	{
		if (mDir == 0) dy = i;
		if (mDir == 1) dx = i;
		map[mRow + dy][mCol + dx] = cvtGrade2int(mGrade);
	}
}

char* calculrate(int L, int sRow, int sCol, int eRow, int eCol)
{

}