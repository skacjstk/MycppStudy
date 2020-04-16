#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::pair<int, int>> nodeData[801];
const int INF = 987654321;

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
	int pathStartNode, pathEndNode;
	scanf("%d %d", &node, &edge);
	std::vector<int> cost1(node);
	std::vector<int> cost2(node);
	std::vector<int> cost3(node);

	for (int i = 1; i <= edge; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		nodeData[a].push_back(std::make_pair(c, b));
		nodeData[b].push_back(std::make_pair(c, a));
	}
	for (int i = 0; i < node; ++i) {
		cost1[i] = INF;
		cost2[i] = INF;
		cost3[i] = INF;
	}

	scanf("%d %d", &pathStartNode, &pathEndNode);
	dijkstra(1, cost1);
	dijkstra(pathStartNode, cost2);
	dijkstra(pathEndNode, cost3);
	int answer = cost1[pathStartNode - 1] + cost2[pathEndNode - 1] + cost3[node - 1];


	for (int i = 0; i < node; ++i) {
		cost1[i] = INF;
		cost2[i] = INF;
		cost3[i] = INF;
	}
	dijkstra(1, cost1);  //시작부터 어딘가의 거리
	dijkstra(pathEndNode, cost2); // 경로End 노드부터 어딘가의 거리
	dijkstra(pathStartNode, cost3); //경로 start 노드부터 어딘가의 거리

	int compare = cost1[pathEndNode - 1] + cost2[pathStartNode - 1] + cost3[node - 1];

	// a - b - c- d  
	// a - c - b- -d 두가지를 고려해야 함 .
	if (INF < answer)
		answer = -1;
	if (INF < compare)
		compare = -1;

	if (answer < 0)
		answer = -1;
	if (compare < 0)
		compare = -1;

	if (answer == compare)
		printf("%d", answer);
	else if (answer < compare)
		printf("%d", answer);
	else
		printf("%d", compare);

	return 0;

}