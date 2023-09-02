// 백준 1260번 DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool isVisited[1001] = { false, };
int map[1001][1001] = { 0, };

void DFS_1260(int N, int now) {
	cout << now << " "; // 출력
	isVisited[now] = true; // 방문 처리
	
	for (int i = 1; i <= N; i++) {
		if (isVisited[i] || map[now][i] == 0) continue;
		DFS_1260(N, i);
	}
}

void BFS_1260(int N, int now) {
	queue<int> q;
	q.push(now); // 첫번째꺼 넣기
	isVisited[now] = true; // 방문 처리

	// 탐색
	while (!q.empty()) {
		now = q.front();
		cout << now << " ";
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (isVisited[i] || map[now][i] == 0) continue;
			q.push(i);
			isVisited[i] = true;
		}
	}

}

void boj_1260() {
	// 주어진 값 입력
	int N{}, M{}, V{};
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int n1{}, n2{};
		cin >> n1 >> n2;
		map[n1][n2] = 1;
		map[n2][n1] = 1;
	}

	fill_n(isVisited, 1001, false);
	DFS_1260(N, V);
	cout << endl;
	fill_n(isVisited, 1001, false);
	BFS_1260(N, V);
}
