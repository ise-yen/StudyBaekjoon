// 연결요소의 개수

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;

int map[MAX][MAX];
bool isVisit[MAX];

void BFS(int r, int N) {
	queue<int> q;
	q.push(r);
	isVisit[r] = true;

	while (!q.empty()) {
		int r = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (map[r][i] == 0 || isVisit[i]) continue;
			q.push(i);
			isVisit[i] = true;
		}
	}
}

void DFS(int r, int N, int cnt) {
	isVisit[r] = true;
	if (cnt == N) return;
	for (int i = 1; i <= N; i++) {
		if (isVisit[i]) continue;
		if (map[r][i] == 1)
			DFS(i, N, ++cnt);
	}
}

int main() {
	int N{}, M{}; // 정점, 간선

	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		int r{}, c{};
		cin >> r >> c;
		map[r][c] = 1;
		map[c][r] = 1;
	}

	int cnt{};
	// BFS
	for (int i = 1; i <= N; i++) {
		if (isVisit[i]) continue;
		BFS(i, N);
		cnt++;
	}

	cnt = 0;
	// DFS
	for (int i = 1; i <= N; i++) {
		if (isVisit[i]) continue;
		DFS(i, N, 1);
		cnt++;
	}
	
	cout << cnt;
}