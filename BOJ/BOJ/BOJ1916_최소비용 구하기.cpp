#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::pair<int, int>> nodeData[1001];
const int INF = 100000001; //이 문제의 가중치는 100,000, 노드는 1000개니까 가능한 한 최대의 수는 1억, 그보다 크려면 1억+1

void dijkstra(int start, std::vector<int> &cost) {
	cost[start - 1] = 0; //가중치 0
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(0, start));

	//cost 가 first, node가 second
	while (!pq.empty()) {
		int nowCost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (cost[node - 1] < nowCost) continue;
		for (std::pair<int, int> &next : nodeData[node]) {
			int nextNode = next.second;
			int nextCost = nowCost + next.first;
			if (nextCost < cost[nextNode - 1]) {
				cost[nextNode - 1] = nextCost;
				pq.push(std::make_pair(-nextCost, nextNode));
			}
		}
	}//endwhile
}

int main() {
	int node, edge;
	int startNode, endNode;
	//정점 node개(1~20,000) , 간선 edge 개(1~ 300,000)
	scanf("%d", &node);
	scanf("%d", &edge);
	std::vector<int> cost(node);

	for (int i = 1; i <= edge; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		nodeData[a].push_back(std::make_pair(c, b));
	}
	for (int i = 0; i < node; ++i) {
		cost[i] = INF;
	}

	scanf("%d %d", &startNode, &endNode);
	dijkstra(startNode, cost);


	printf("%d", cost[endNode - 1]);

	return 0;

}