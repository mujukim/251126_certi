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
	int ret = 0;
	for (int i = 0; i < _M; i++)
	{
		ret += Grade[0] - 65 + (28 * i);
	}
	return ret;
}

void change(int mRow, int mCol, int mDir, int mLength, char mGrade[])
{
	int dx = 0, dy = 0;
	for (int i = 0; i < mLength; i++)
	{
		if (mDir == 0) dy++;
		if (mDir == 1) dx++;
		map[mRow + dy][mCol + dx] = cvtGrade2int(mGrade);
	}
}

char* calculrate(int L, int sRow, int sCol, int eRow, int eCol)
{

}