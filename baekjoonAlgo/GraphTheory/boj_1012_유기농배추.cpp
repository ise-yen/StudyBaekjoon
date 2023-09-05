// ����� ����

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50;
int map[MAX][MAX]{};
bool isVisit[MAX][MAX]{};

// �����¿�
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isInMap(int r, int c, int N, int M) {
	if (r < 0 || c < 0 || r >= N || c >= M) return false;
	else return true;
}

void BFS(int r, int c, int N, int M) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	isVisit[r][c] = true;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			
			if (!isInMap(nr, nc, N, M) || isVisit[nr][nc] || map[nr][nc] == 0) continue;
			q.push(make_pair(nr, nc));
			isVisit[nr][nc] = true;
		}
	}
}

int main() {
	int T{}, N{}, M{}, K{}, X{}, Y{};
	cin >> T; // �׽�Ʈ ���̽� �Է�

	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K; // ��, ��, ���� ��ġ ����

		// ���� ��ġ �Է�
		for (int k = 0; k < K; k++) {
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		int cnt{};

		// bfs
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && !isVisit[i][j]) {
					BFS(i, j, N, M);
					cnt++;
				}
			}
		}

		cout << cnt << endl;

		// �� �ʱ�ȭ
		fill(map[0], map[MAX-1], 0);
		
		// �湮ó�� �ʱ�ȭ
		fill(isVisit[0], isVisit[MAX - 1], false);
	}
}