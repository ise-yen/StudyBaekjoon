#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define INF 1e9

using namespace std;

const int MAX = 20001;

vector<pair<int, int>> graph[MAX];

int dis[MAX]{};
int V{}, E{}, K{}; // 정점, 간선, 시작 노드 번호

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq; // 1. 비용, 2. 다음 노드 번호
	// 비용이 먼저인 이유 : 비용을 기준으로 우선순위큐 안에서 정렬되게 하기 위해

	pq.push({ 0, start});
	dis[start] = 0;

	while (!pq.empty()) {
		// 비용에 마이너스를 붙이는 이유 : C++의 우선순위 큐=최대힙
		/* ex) 비용
		기본: 10, 9, 8, 7 : 비용값이 클수록 1번
		음수: -7, -8, -9, -10  : 비용이 작을수록 1번(최소힙처럼 보이게 됨)
		*/
		int nowCost = -pq.top().first; // 현재까지의 비용
		int nowNode = pq.top().second; // 현재 노드 번호
		pq.pop();

		// 이미 방문된 노드는 패스
		if (dis[nowNode] < nowCost) continue;

		// 현재 노드에서 갈 수 있는 노드들
		for (int i = 0; i < graph[nowNode].size(); i++) {
			int cost = nowCost + graph[nowNode][i].second;

			// cost가 더 최단 거리라면 업데이트
			int nextNode = graph[nowNode][i].first;
			if (cost < dis[nextNode]) {
				dis[nextNode] = cost;
				pq.push(make_pair(-cost, nextNode));
			}
		}
	}
}

int main() {
	cin >> V >> E;

	cin >> K;

	for (int i = 0; i < E; i++) {
		int u{}, v{}, w{}; // 시작 노드, 도착 노드, 비용
		cin >> u >> v >> w;
	
		graph[u].push_back({ v, w }); // (출발) u 노드 → (도착) v 노드 : (비용=w)
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill(dis, dis + MAX, INF);

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF) cout << "INF\n";
		else cout << dis[i] << "\n";
	}

}