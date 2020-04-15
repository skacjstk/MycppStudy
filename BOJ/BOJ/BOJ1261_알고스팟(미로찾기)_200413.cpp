#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

const int INF = 110000;


 int wall[101][101];
 int path[101][101];

void dijkstra(int &yExit, int &xExit)
{
//	std::vector<std::vector<bool>> visited(yExit, std::vector<bool>(xExit,true));  //동적할당 row 길이의 int vector 를 stdvectorInt 에 하나씩. 
	static int step[4][2] = { {-1,0} , {0,1} , {1,0} ,{ 0, -1} };	//상 우 하 좌 
	std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
	path[0][0] = wall[0][0];	//만약 시작지점이 1일 수 있다면 바뀌어야 함.
	pq.push({ 0,{0,0}});
	while (!pq.empty()) {
		int pqWall = -pq.top().first;
		int pqCol = pq.top().second.first;
		int pqRow = pq.top().second.second;
		pq.pop();
//		printf("=========시작==========\n");
		if (path[pqCol][pqRow] < pqWall) continue;
		for (int i = 0; i < 4; ++i) {
	//		printf("벽:%d\n", pqWall);
			int newCol = pqCol + step[i][0]; //탐색할 새 좌표
			int newRow = pqRow + step[i][1];
			if (newCol < 0 || newRow < 0 || newCol >= yExit || newRow >= xExit) continue;
			
			int newWall = pqWall + wall[newCol][newRow];

			if (newWall < path[newCol][newRow]) {
	//					printf("[%d][%d]벽:%d ->  ",newCol,newRow, path[newCol][newRow]);
				path[newCol][newRow] = newWall;
	//			printf("%d\n", newWall);
				pq.push({-newWall ,{newCol,newRow }});
			}
		}
	}
}

int main()
{
	int col, row;   //열 행 
	scanf("%d %d", &row, &col);
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			scanf("%1d", &wall[i][j]);   //벽 상태 기록 (bool로 하면 메모리절약 가능)
			path[i][j] = INF;
		}
	}
	dijkstra(col, row);
	printf("%d", path[col - 1][row - 1]);
	return 0;
}


/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

constexpr int INF = 110000;
typedef struct _location {
	int wallNum;
	int col;
	int row;
}loc;

struct compare {
	bool operator()(loc a, loc b) {
		return a.wallNum < b.wallNum;
	}
};

void dijkstra(const std::vector<std::vector<int>> &wall, std::vector<std::vector<int>> &path, const int &yExit, const int &xExit)
{
	//	std::vector<std::vector<bool>> visited(yExit, std::vector<bool>(xExit,true));  //동적할당 row 길이의 int vector 를 stdvectorInt 에 하나씩.
	static const int step[4][2] = { {-1,0} , {0,1} , {1,0} ,{ 0, -1} };	//상 우 하 좌
	std::priority_queue<loc, std::vector<loc>, compare> pq;
	pq.push({ 0,0,0 });    //0개 부숨, 좌표 [0][0];

	while (!pq.empty()) {
		int pqWall = pq.top().wallNum;
		int pqCol = pq.top().col;
		int pqRow = pq.top().row;
		pq.pop();

		if (path[pqCol][pqRow] < pqWall) continue;
		for (int i = 0; i < 4; ++i) {
			int newCol = pqCol + step[i][0]; //탐색할 새 좌표
			int newRow = pqRow + step[i][1];
			if (newCol < 0 || newRow < 0 || newCol >= yExit || newRow >= xExit) continue;

			int newWall = pqWall + wall[newCol][newRow]; //벽 0또는 1

			if (newWall < path[newCol][newRow]) {
				path[newCol][newRow] = newWall;
				pq.push({ newWall, newCol, newRow });
			} //endif

		}
	}

}

int main()
{
	int col, row;   //열 행
	scanf("%d %d", &row, &col);
	std::vector<std::vector<int>> wall(col, std::vector<int>(row));  //동적할당 row 길이의 int vector 를 stdvectorInt 에 하나씩.
				//0부터 시작하니까 언젠가 -1씩 해줘야 할 때가 옴.
	std::vector<std::vector<int>> path(col, std::vector<int>(row, INF)); //지나온대까지 벽을 뚫은 횟    수( 최솟값 필요 )


	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			scanf("%1d", &wall[i][j]);   //벽 상태 기록 (bool로 하면 메모리절약 가능)
		}
	}

	dijkstra(wall, path, col, row);

	printf("%d", path[col - 1][row - 1]);
	return 0;
}

*/