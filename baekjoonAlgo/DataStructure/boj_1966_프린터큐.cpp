// 프린터 큐

#include <iostream>
#include <queue>

using namespace std;

int main() {
	int T{}; // 테스트 케이스
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N{}, M{};
		queue<pair<int, int>> q;
		
		cin >> N >> M;

		int max{}, mimpt{};
		
		// 중요도 입력
		for (int n = 0; n < N; n++) {
			int impt{}; // 중요도
			cin >> impt;
			q.push({ impt, n });

			// 가장 앞의 중요도가 max
			if (n == 0) max = impt;
			
			// 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있는지 확인
			if (max < impt) {
				max = impt;
			}
		}

		// 출력 순서 조절
		int pcnt{}; // 인쇄 순서
		while (!q.empty()) {
			int f = q.front().first;
			int order = q.front().second;
			q.pop();

			// 더 중요도 높은 문서가 나올때까지 후순위로 밀림
			if (f < max) q.push({ f, order });
			else {
				pcnt++;
				// 찾던거면 끝내기
				if (order == M) {
					cout << pcnt << endl;
					break;
				}
				// max 재탐색
				max = 0;
				for (int i = 0; i < q.size(); i++) {
					f = q.front().first;
					order = q.front().second;
					max = max < f ? f : max;
					q.pop();
					q.push({ f, order });
				}
			}
		}
	}
}