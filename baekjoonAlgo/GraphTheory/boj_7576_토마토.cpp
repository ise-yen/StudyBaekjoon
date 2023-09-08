// 토마토

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;
int map[MAX][MAX]{};
int check[MAX][MAX]{};

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isInMap(int r, int c, int N, int M) {
	if (r < 0 || c < 0 || r >= N || c >= M) return false;
	else return true;
}

queue<pair<int, int>> q;
void BFS(int N, int M) {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		map[r][c] = 1;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];

			if (!isInMap(nr, nc, N, M) || check[nr][nc] != 0 || map[nr][nc] != 0) continue;
			q.push(make_pair(nr, nc));
			check[nr][nc] = check[r][c] + 1;
		}
	}
}

int main() {
	int N{}, M{};

	cin >> M >> N;
	
	int cntTomato{}, cntNotTomato{};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tomato{};
			cin >> tomato;
			map[i][j] = tomato;
			if (tomato == 1) cntTomato++;
			else cntNotTomato++;
		}
	}

	// 처음부터 전부 익었으면 0
	if (cntTomato == N * M) {
		cout << 0;
		return 0;
	}
	// 처음부터 전부 안 익은 상태면 -1
	else if (cntNotTomato == N * M) {
		cout << -1;
		return 0;
	}
	else {
		// 아닐 경우에는 익히기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// 시간에 따라 토마토가 동시에 익어야하므로, 이미 익은 토마토들의 모든 위치 넣어주기
				if (map[i][j] == 1) q.push(make_pair(i, j));
			}
		}

		// 탐색
		BFS(N, M);
	}
	
	int res{}; // 최종 결과 값. 모두 익는 최소 일수

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 만약 익지 않은 토마토가 하나라도 있으면 -1
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
			
			// check에서 가장 큰 값
			res = res < check[i][j] ? check[i][j] : res;
		}
	}

	cout << res;

}