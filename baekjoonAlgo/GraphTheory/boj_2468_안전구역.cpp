#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100;
int map[MAX][MAX]{};
bool isVisit[MAX][MAX]{};

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N{};

bool isInMap(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= N) return false;
	else return true;
}

int cnt{};

void bfs(int r, int c, int level) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	isVisit[r][c] = true;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];

			if (!isInMap(nr, nc)) continue;
			if (isVisit[nr][nc]) continue;
			if (map[nr][nc] >= level) {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
			}
		}
	}
	cnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int max{};
	for (int level = 1; level <= 100; level++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(map[i][j] >= level && !isVisit[i][j])
					bfs(i, j, level);
			}
		}
		max = max > cnt ? max : cnt;
		fill(&isVisit[0][0], &isVisit[MAX-1][MAX], false);
		cnt = 0;
	}

	cout << max;
}