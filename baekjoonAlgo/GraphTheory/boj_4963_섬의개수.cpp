#include<iostream>
#include<queue>

using namespace std;

const int MAX = 51;

int map[MAX][MAX]{};
bool isVisit[MAX][MAX]{};

int dir[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };

bool isInMap(int r, int c, int N, int M) {
	if (r < 0 || c < 0 || r >= N || c >= M) return false;
	return true;
}

void dfs(int r, int c, int N, int M) {
	isVisit[r][c] = true;
	for (int i = 0; i < sizeof(dir)/sizeof(dir[0]); i++) {
		int nr = r + dir[i][0];
		int nc = c + dir[i][1];
		if (!isInMap(nr, nc, N, M)) continue;
		if (isVisit[nr][nc]) continue;
		if (map[nr][nc] == 1) {
			dfs(nr, nc, N, M);
		}
	}
}

int main() {
	int w = -1, h = -1; // 테스트케이스, 열, 행

	while (w != 0 || h != 0) {
		cin >> w >> h;

		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0;
				isVisit[i][j] = false;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		int cnt{};
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (isVisit[i][j] || map[i][j] == 0) continue;
				dfs(i, j, h, w);
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}