#include <iostream>
#include <vector>
#include <queue>

const int nodeNum = 6;
int INF = 9000000;

std::vector<std::pair<int, int> > node[nodeNum+1];
std::vector<int> dist(nodeNum + 1);

void dijkstra(int start) {
	dist[start] = 0;
	std::priority_queue<std::pair<int, int> > pq;
	pq.push(std::make_pair(start, 0)); //�ڱ��ڽ��� ����ġ 0

	while (!pq.empty()) {
		int current = pq.top().first;
		//���� �ε���
		int distance = -pq.top().second;
		//����ġ
		pq.pop();

		if (dist[current] < distance) continue;
		for (std::pair<int, int> element : node){ 
			int next = element.first;
			int nextDistance = distance + element.second;
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push(std::make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void)
{
	for (int i = i; i <= nodeNum; ++i)
		dist[i] = INF;

	printf("first: ������, second: ����ġ");
	int x, y;

//	scanf("%d %d", &x, &y);
//	node[1].push_back(std::make_pair(x, y));

	node[1].push_back(std::make_pair(2, 2));
	node[1].push_back(std::make_pair(3, 5));
	node[1].push_back(std::make_pair(4, 1));


	node[2].push_back(std::make_pair(1, 2));
	node[2].push_back(std::make_pair(3, 3));
	node[2].push_back(std::make_pair(4, 2));


	node[3].push_back(std::make_pair(1, 2));

	dijkstra(1);

	for (int i = 1; i <= nodeNum; ++i) {
		printf("%d ", dist[i]);
	}
	return 0;
}