#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <queue>
#include <utility>


int rupeeData[125][125] = { 0 };
int cost[125][125];

const short stepSize = 4;

int step[stepSize][2] = { {0,-1},{-1,0},{0,1},{1,0} };

const int INF = 987654321;

int dijkstra(int start, int &squareSize) {
	int end = squareSize;
	cost[start][start] = rupeeData[start][start];
	std::priority_queue<std::pair<int, std::pair<int, int>>> pq;	//가중치, 좌표

	pq.push(std::make_pair(-rupeeData[start][start], std::make_pair(start, start)));	//시작 좌표와 거기 가중치
//	printf("최초위치:");
	while (!pq.empty()) {
		int nowDis = -pq.top().first;
		//		printf("현재위치: %d\n",nowDis);
		int nowCol = pq.top().second.first;
		int nowRow = pq.top().second.second;
		pq.pop();
		if (cost[nowCol][nowRow] < nowDis) continue;
		for (int i = 0; i < stepSize; ++i) {
			int newCol = nowCol + step[i][0];
			int newRow = nowRow + step[i][1];
			if (newCol < 0 || newCol >= squareSize || newRow < 0 || newRow >= squareSize)
				continue;
			int newDis = nowDis + rupeeData[newCol][newRow];
			if (newDis < cost[newCol][newRow]) {
				cost[newCol][newRow] = newDis;
				pq.push(std::make_pair(-newDis, std::make_pair(newCol, newRow)));
			}
		} //다중배열 꺼내기
	}//endwhile

	return cost[squareSize - 1][squareSize - 1];
}
void testCase(int squareSize) {
	static int testCnt = 1;
	for (int i = 0; i < squareSize; ++i) {
		for (int j = 0; j < squareSize; ++j) {
			scanf("%d", &rupeeData[i][j]);
			cost[i][j] = INF;
			//		printf("입력확인[%d][%d]\n",i,j );
		}
	}
	printf("Problem %d: %d\n", testCnt++, dijkstra(0, squareSize));
	//dijkstra(0,squareSize);
}

int main() {

	while (true) {
		int squareSize;
		scanf("%d", &squareSize);

		if (squareSize != 0)
			testCase(squareSize);
		else
			break;
	}
	return 0;

}