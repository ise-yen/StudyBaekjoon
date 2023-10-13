#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define INF 1e9

using namespace std;

const int MAX = 100001;

// 노드 개수, 간선 개수
int n, m, start{};

// 노드 정보를 담은 배열
vector<pair<int, int>> graph[MAX];

// 최단거리 테이블
int dis[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	// 시작 노드로 가기 위한 최단 경로는 0으로 설정. 큐에 삽입
	pq.push({ 0, start });
	dis[start] = 0;

	while (!pq.empty()) {
		// 가장 최단 거리가 짧은 노드 꺼내기
		int nowCost = -pq.top().first; // 현재 노드까지의 비용 (최소힙으로 동작하려면 음수(-)로 넣어야함)
		int nowNode = pq.top().second; // 현재 노드
		pq.pop();

		// 현재 노드가 이미 처리된 거면 무시
		if (dis[nowNode] < nowCost) continue;

		// 현재 노드와 연결된 다른 인접 노드들 확인
		for (int i = 0; i < graph[nowNode].size(); i++) {
			// 현재 노드를 거쳐서 갈 때의 비용
			int cost = nowCost + graph[nowNode][i].second;

			// cost가 더 최단 거리라면 업데이트
			int nextNode = graph[nowNode][i].first;
			if (cost < dis[nextNode]) {
				dis[nextNode] = cost;
				pq.push(make_pair(-cost, graph[nowNode][i].first)); // (최소힙으로 동작하려면 음수(-)로 넣어야함)
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;

	// 모든 간선 정보를 입력받기
	for (int i = 0; i < m; i++) {
		int nowNode, nextNode, cost;
		cin >> nowNode >> nextNode >> cost;
		graph[nowNode].push_back({ nextNode, cost });
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill(dis, dis + MAX, INF);

	// 다익스트라
	dijkstra(start);

	// 모든 노드로 가기 위한 최단 거리 출력
	for (int i = 1; i <= n; i++) {
		// 도달 못하면 INF 출력
		if (dis[i] == INF) cout << "INF\n";
		else cout << dis[i];
	}

}