// 적록색약

#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 101;

char map[MAX][MAX]{};
bool visit[MAX][MAX]{};

bool isInMap(int r, int c, int N) {
	if (r >= 0 && c >= 0 && r < N && c < N) return true;
	else return false;
}


int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };


void BFS(int r, int c, int N, bool isBlind) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	char area = map[r][c];
	visit[r][c] = true;
	
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (!isInMap(nr, nc, N) || visit[nr][nc]) continue;
			if (!isBlind) {
				if (map[nr][nc] == area) {
					q.push({ nr, nc });
					visit[nr][nc] = true;
				}
			}
			else {
				if (area == 'B'){
					if (map[nr][nc] == 'B') {
						q.push({ nr, nc });
						visit[nr][nc] = true;
					}
					else continue;
				}
				else if(area == 'G' || area == 'R'){
					if (map[nr][nc] == 'G' || map[nr][nc] == 'R') {
						q.push({ nr, nc });
						visit[nr][nc] = true;
					}
					else continue;
				}
			}

		}
		
	}
}

int main() {
	int N{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str{};
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j];
		}
	}

	int cnt{};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				BFS(i, j, N, false);
				cnt++;
			}
		}
	}
	cout << cnt << " ";

	//memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}

	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				BFS(i, j, N, true);
				cnt++;
			}
		}
	}
	cout << cnt;

}