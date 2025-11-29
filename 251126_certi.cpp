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

static char retStr[5]; // 최대 3글자 + '\0'

bool bfsCheck(int limit, int L, int sRow, int sCol, int eRow, int eCol) {
    queue<pair<int, int>> q;
    static int dist[MAX_N][MAX_N];
    memset(dist, -1, sizeof(dist));

    q.push({ sRow, sCol });
    dist[sRow][sCol] = 0;

    int dr[4] = { -1,1,0,0 };
    int dc[4] = { 0,0,-1,1 };

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == eRow && c == eCol) return true;
        if (dist[r][c] >= L) continue;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= _N || nc < 0 || nc >= _N) continue;
            if (dist[nr][nc] != -1) continue;
            if (_map[nr][nc] < limit) continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({ nr,nc });
        }
    }
    return false;
}

char* calculrate(int L, int sRow, int sCol, int eRow, int eCol)
{
    vector<int> levels;
    levels.reserve(_N * _N);
    for (int r = 0; r < _N; r++)
        for (int c = 0; c < _N; c++)
            levels.push_back(_map[r][c]);

    sort(levels.begin(), levels.end());
    levels.erase(unique(levels.begin(), levels.end()), levels.end());

    int lo = 0, hi = levels.size() - 1, best = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (bfsCheck(levels[mid], L, sRow, sCol, eRow, eCol)) {
            best = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    if (best == -1) {
        strcpy(retStr, "Zzz"); // 이동 불가 시 규칙 요청
        return retStr;
    }

    // int → 문자열 다시 변환 (필요하면 구현, 아니면 등급 int도 OK)
    // 여기서는 테스트 편하게 int를 연출 문자열로 반환
    sprintf(retStr, "%d", levels[best]);
    return retStr;
}
