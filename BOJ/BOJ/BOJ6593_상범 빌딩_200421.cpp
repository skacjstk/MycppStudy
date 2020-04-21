#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

char buildingData[30][30][30] = {};	//29700�� ... 
int  cost[30][30][30];

int start[3] = { 0 };
int end[3] = { 0 };

static int floor = -1, row = -1, col = -1;

const short stepSize = 6; //�����̴� ����

int step[stepSize][3] = { {0, 0,-1},{0, -1,0},{0, 0,1},{0, 1,0},{-1,0,0}, {1,0,0} };	//z x y , �� �� �� �Ʒ� �� ��

struct a {
	int cost, floor, row, col;

};
typedef struct a buildingSize;

struct compare {	//�� �񱳰��� false �� ��� swap �̳�, queue�� FIFO �ڷᱸ���̱⿡ 
	bool operator()(buildingSize &a, buildingSize &b) {
		return a.cost > b.cost;
	}
};

const int INF = 987654321;


int dijkstra() {
	//����ü �켱���� ť�� z x y �� cost�� ���� pair ���� 
	cost[start[0]][start[1]][start[2]] = 0;
	std::priority_queue<buildingSize, std::vector<buildingSize>, compare> pq;
	pq.push({ 0,start[0],start[1],start[2] }); //����ġ 0, z x y ��ǥ 
	while (!pq.empty()) {
		int nowCost = pq.top().cost;
		int nowFloor = pq.top().floor;
		int nowRow = pq.top().row;
		int nowCol = pq.top().col;
		pq.pop();
		//		printf("%d %d %d %d\n",nowCost, nowFloor, nowRow, nowCol);

			//	printf("nowCost: %d : %d cost[%d][%d][%d]\n",nowCost,cost[nowFloor][nowRow][nowCol], nowFloor,nowRow,nowCol);
			//	if(cost[nowFloor][nowRow][nowCol] < nowCost) continue;
		for (int i = 0; i < stepSize; ++i) {
			int newFloor = nowFloor + step[i][0];
			int newRow = nowRow + step[i][1];
			int newCol = nowCol + step[i][2];

			if (newFloor < 0 || newRow < 0 || newCol < 0)
				continue;
			if (newFloor >= floor || newRow >= row || newCol >= col) //3x3x3 �ϰ�� 0~2�����ϱ� 
				continue;

			//		printf("%d %d %d\n", newFloor, newRow, newCol);	
			if (buildingData[newFloor][newRow][newCol] != '#') {
				int newCost = nowCost + 1;
				cost[newFloor][newRow][newCol] = newCost;
				//			printf("cost:%d [%d] [%d] [%d]\n",nowCost+1, newFloor, newRow, newCol);
							//ť�� �ִ°� ���� ������... ���µ� BFS�� ���� �ٲ� 
				pq.push({ newCost,newFloor,newRow,newCol });
				buildingData[newFloor][newRow][newCol] = '#';
			}//endif
		}
	}//end while
	return cost[end[0]][end[1]][end[2]];

	//cost [floor][row][col] ��ȯ 
}
bool inputBuildingData() {

	scanf("%d %d %d", &floor, &row, &col);
	if (floor == 0 && floor == row && floor == col)
		return false;
	for (int i = floor - 1; i >= 0; --i) {
		//		getchar();
		for (int j = 0; j < row; ++j) {
			//			getchar();
			for (int k = 0; k < col; ++k) {
				std::cin >> buildingData[i][j][k];
				//				printf("%c",buildingData[i][j][k]);
				cost[i][j][k] = INF;
				if (buildingData[i][j][k] == 'S') {
					start[0] = i;
					start[1] = j;
					start[2] = k;
				}
				else if (buildingData[i][j][k] == 'E') {
					end[0] = i;
					end[1] = j;
					end[2] = k;
				}
			}//end for(1/3)
//			getchar();
		}//end for(2/3)
//		getchar();
	}//end for(3/3) 

	return true;
}

bool testCase() {

	if (inputBuildingData())	// 0, 0, 0 �Է� �� false ��ȯ 
	{
		int answer = dijkstra();
		if (answer != INF)
			printf("Escaped in %d minute(s).\n", answer);
		else
			printf("Trapped!\n");
		return true;
	}
	else return false;
}
int main() {

	while (testCase());

	return 0;

}