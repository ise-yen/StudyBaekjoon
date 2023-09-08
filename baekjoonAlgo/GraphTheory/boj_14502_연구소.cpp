// 연구소

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 8;
int map[MAX][MAX];
int copyMap[MAX][MAX];
bool isVisit[MAX][MAX];
bool isDFSVisit[MAX][MAX];

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int res{};

bool isInMap(int r, int c, int N, int M) {
	if (r < 0 || c < 0 || r >= N || c >= M) return false;
	return true;
}

void BFS(int r, int c, int N, int M) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	isVisit[r][c] = true;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		copyMap[r][c] = 2;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];

			if (!isInMap(nr, nc, N, M) || isVisit[nr][nc] || copyMap[nr][nc] != 0) continue;
			isVisit[nr][nc] = true;
			q.push(make_pair(nr, nc));
		}
	}
}

// DFS
void MakeWall(int N, int M, int cnt) {
	if (cnt == 3) {
		// 옯기기
		copy(&map[0][0], &map[0][0] + MAX * MAX, &copyMap[0][0]);

		//cout << "\nberore BFS\n";
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		cout << copyMap[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;

		///1. 바이러스 확산 시키기
		// 방문 초기화
		fill(&isVisit[0][0], &isVisit[MAX-1][MAX-1], false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copyMap[i][j] == 2 && !isVisit[i][j]) {
					BFS(i, j, N, M);
				}
			}
		}

		///2. 안전지역 개수 세기
		int safe{};
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copyMap[i][j] == 0) safe++;
			}
		}

		///3. res 최대 개수
		res = res > safe ? res : safe;
		return;
	}

	// 벽 세우기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				MakeWall(N, M, cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	int N{}, M{};
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	// 벽은 3개만 세우기
	MakeWall(N, M, 0);

	// 안전 영역 크기의 최댓값
	cout << res;
}
