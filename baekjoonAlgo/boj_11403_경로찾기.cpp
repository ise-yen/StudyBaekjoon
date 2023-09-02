// 백준 11403번 경로찾기
#include <iostream>

using namespace std;

const int MAX = 100;
int N{};
int map[MAX][MAX]{};
bool visited[MAX] = { false };
int res[MAX][MAX]{};

/// <summary>
/// 경로 찾는 알고리즘
/// </summary>
/// <param name="start">경로 시작 지점</param>
/// <param name="now">현재 탐색 시작 지점</param>
/// <param name="end">경로 종료 지점</param>
void DFS_11403(int start, int now, int end) {
	// 종료 지점에 도착하면 탐색 종료
	// visited[end] : DFS(0, 0) 같은 경우 배제하기 위한 조건
	if (visited[end] && now == end) {
		res[start][end] = 1;
		return;
	}

	for (int i = 0; i < N; i++) {
		// 경로가 있고 방문한 적 없을 때
		if (map[now][i] == 1 && !visited[i]) {
			visited[i] = true; // 방문 체크
			DFS_11403(start, i, end);
			if (res[start][end] == 1) return; // 추가 탐색하지 않게 경로 찾았으면 탐색 완전 종료
		} 
	}
}

void boj_11403() {
	// 입력
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	// 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) res[i][j] = 1; // 간선이 있으면 바로 등록
			else {
				// 간선 없으면 탐색
				DFS_11403(i, i, j);
				// 방문 체크 초기화
				fill_n(visited, MAX, false);
			}
		}
	}

	// 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}