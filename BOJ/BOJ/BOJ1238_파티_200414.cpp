#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 0xfffffff;

//std::vector<std::pair<int,std::pair<int,int>>> map;		//가중치 와 first -> second 관계
// first.first = 가중치 (우선순위 큐에 최솟값 배정 예정 {음수저장}
// second.first -> second.second  

int map[1001][1001] = { 0 };
//int dist[1000][1000] = {0};

int floyd_warshall(int numHuman, int numRoad,int dest ) {
	for (int k = 1; k <= numHuman; k++)
	{
		// x에서
		for (int i = 1; i <= numHuman; i++)
		{
			// y로 갈때
			for (int j = 1; j <= numHuman; j++)
			{
				// 최단거리면 업데이트 해준다.
				if (map[i][k] + map[k][j] < map[i][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	int answer = -1;
	for (int u = 1; u <= numHuman; ++u) {
		answer = std::max(answer, map[u][dest] + map[dest][u]);
	}
	return answer;
}

int main(void)
{
	int numHuman, numRoad, dest; //사람수(max 1,000), 도로 수(단방향{max10,000}), 목적지(마을)
	scanf("%d %d %d", &numHuman, &numRoad, &dest);
	
	for (int i = 1; i <= numHuman; ++i) {
		for (int j = 1; j <= numHuman; ++j) {	
			if (i == j)
				map[i][j] = 0;
			else
			map[i][j] =	 INF;			
		}
	}	//백만개 감당 가능한가? 
	for (int i = 0; i < numRoad; ++i) {
		int from, to, dis;
		scanf("%d %d %d", &from, &to, &dis);
		map[from][to] = dis;	
	}

	printf("%d\n", floyd_warshall(numHuman, numRoad, dest));


	return 0;
}