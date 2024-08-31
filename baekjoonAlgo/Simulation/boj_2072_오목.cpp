// N <= 100이므로 단순 시뮬레이션으로 구현

#include<iostream>
#include<vector>

using namespace std;

const int MAX_MAP = 20;
int map[MAX_MAP][MAX_MAP]; // 바둑판

vector<pair<int, int>> dir = { {1, 0}, {0, 1}, {1, 1}, {1, -1} }; // 탐색 방향. + 방향만 세팅(-방향은 Check함수에서 처리)

/// 바둑판(map) 크기를 벗어나는지 체크
bool isInMap(int x, int y) {
	if (x > 0 && x <= MAX_MAP && y > 0 && y <= MAX_MAP) return true;
	else return false;
}

/// 오목 성공인지 체크하는 함수 (target: 바둑돌 색상)
bool Check(int target, int x, int y) {
	for (int i = 0; i < dir.size(); i++) {
		bool isVisit[MAX_MAP][MAX_MAP]{}; // 방문체크
		int cnt{};
		isVisit[x][y] = true;
		cnt++;
		// + 방향으로 탐색
		// 다음 탐색 위치
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;
		while (isInMap(nx, ny)) { // 맵 크기 벗어나면 개수 탐색 중단
			if (isVisit[nx][ny]) break; // 이미 방문한 곳이면 패스

			// 같은 색의 바둑돌인지 확인
			if (map[nx][ny] != target) break;
			cnt++;
			isVisit[nx][ny] = true; // 방문처리
			// 다음 탐색 위치 갱신
			nx += dir[i].first;
			ny += dir[i].second;
		}

		// - 방향으로 탐색
		// 다음 탐색 위치
		nx = x - dir[i].first;
		ny = y - dir[i].second;
		while (isInMap(nx, ny)) { // 맵 크기 벗어나면 개수 탐색 중단
			if (isVisit[nx][ny]) break; // 이미 방문한 곳이면 패스

			// 같은 색의 바둑돌인지 확인
			if (map[nx][ny] != target) break;
			cnt++;
			isVisit[nx][ny] = true; // 방문처리
			// 다음 탐색 위치 갱신
			nx -= dir[i].first;
			ny -= dir[i].second;
		}

		// 오목 성공일 때
		if (cnt == 5) return true;
	}

	// 오목 실패일 때
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	enum Color { NONE = 0, BLACK = 1, WHITE = 2 }; // 바둑알 종류
	int N{};
	cin >> N;

	bool isWin = false;

	for (int i = 1; i <= N; i++) {
		// 입력
		int x{}, y{};
		cin >> x >> y;
		map[x][y] = i % 2 == 1 ? BLACK : WHITE;

		// 바둑돌이 5개 놓일 때부터 매순간 체크
		if (i >= 9) isWin = Check(map[x][y], x, y);

		// 정답 출력
		if (isWin) {
			cout << i;
			return 0;
		}
	}

	// 정답 출력
	cout << -1;

	return 0;
}