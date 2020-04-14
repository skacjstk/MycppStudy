#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 0xfffffff;

//std::vector<std::pair<int,std::pair<int,int>>> map;		//����ġ �� first -> second ����
// first.first = ����ġ (�켱���� ť�� �ּڰ� ���� ���� {��������}
// second.first -> second.second  

int map[1001][1001] = { 0 };
//int dist[1000][1000] = {0};

int floyd_warshall(int numHuman, int numRoad,int dest ) {
	for (int k = 1; k <= numHuman; k++)
	{
		// x����
		for (int i = 1; i <= numHuman; i++)
		{
			// y�� ����
			for (int j = 1; j <= numHuman; j++)
			{
				// �ִܰŸ��� ������Ʈ ���ش�.
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
	int numHuman, numRoad, dest; //�����(max 1,000), ���� ��(�ܹ���{max10,000}), ������(����)
	scanf("%d %d %d", &numHuman, &numRoad, &dest);
	
	for (int i = 1; i <= numHuman; ++i) {
		for (int j = 1; j <= numHuman; ++j) {	
			if (i == j)
				map[i][j] = 0;
			else
			map[i][j] =	 INF;			
		}
	}	//�鸸�� ���� �����Ѱ�? 
	for (int i = 0; i < numRoad; ++i) {
		int from, to, dis;
		scanf("%d %d %d", &from, &to, &dis);
		map[from][to] = dis;	
	}

	printf("%d\n", floyd_warshall(numHuman, numRoad, dest));


	return 0;
}