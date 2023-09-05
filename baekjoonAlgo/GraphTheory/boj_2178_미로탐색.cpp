// ¹Ì·Î Å½»ö
#include <iostream>
#include <string>
#include <queue>

using namespace std;
const int MAX = 100;
char map[MAX][MAX]{};
int check[MAX][MAX] = { {0}, {0} };
bool isVisit[MAX][MAX]{};

bool isInMap_2178(int r, int c, int N, int M) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	else return true;
}

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void BFS_2178(int r, int c, int N, int M) {
	isVisit[r][c] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (!isInMap_2178(nr, nc, N, M)) continue;

			if (!isVisit[nr][nc] && map[nr][nc] == '1' && check[nr][nc] == 0) {
				check[nr][nc] = check[r][c] + 1;
				isVisit[nr][nc] = true;
				q.push(pair<int, int>(nr, nc));
			}
		}
	}
}

void boj_2178_¹Ì·ÎÅ½»ö() {
	// ÀÔ·Â
	int N{}, M{};
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str{};
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];
		}
	}

	BFS_2178(0, 0, N, M);

	if(N > 0 && M > 0)
		cout << check[N-1][M-1] + 1;
}