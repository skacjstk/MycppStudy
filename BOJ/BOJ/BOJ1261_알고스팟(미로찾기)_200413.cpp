#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

const int INF = 110000;


 int wall[101][101];
 int path[101][101];

void dijkstra(int &yExit, int &xExit)
{
//	std::vector<std::vector<bool>> visited(yExit, std::vector<bool>(xExit,true));  //�����Ҵ� row ������ int vector �� stdvectorInt �� �ϳ���. 
	static int step[4][2] = { {-1,0} , {0,1} , {1,0} ,{ 0, -1} };	//�� �� �� �� 
	std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
	path[0][0] = wall[0][0];	//���� ���������� 1�� �� �ִٸ� �ٲ��� ��.
	pq.push({ 0,{0,0}});
	while (!pq.empty()) {
		int pqWall = -pq.top().first;
		int pqCol = pq.top().second.first;
		int pqRow = pq.top().second.second;
		pq.pop();
//		printf("=========����==========\n");
		if (path[pqCol][pqRow] < pqWall) continue;
		for (int i = 0; i < 4; ++i) {
	//		printf("��:%d\n", pqWall);
			int newCol = pqCol + step[i][0]; //Ž���� �� ��ǥ
			int newRow = pqRow + step[i][1];
			if (newCol < 0 || newRow < 0 || newCol >= yExit || newRow >= xExit) continue;
			
			int newWall = pqWall + wall[newCol][newRow];

			if (newWall < path[newCol][newRow]) {
	//					printf("[%d][%d]��:%d ->  ",newCol,newRow, path[newCol][newRow]);
				path[newCol][newRow] = newWall;
	//			printf("%d\n", newWall);
				pq.push({-newWall ,{newCol,newRow }});
			}
		}
	}
}

int main()
{
	int col, row;   //�� �� 
	scanf("%d %d", &row, &col);
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			scanf("%1d", &wall[i][j]);   //�� ���� ��� (bool�� �ϸ� �޸����� ����)
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
	//	std::vector<std::vector<bool>> visited(yExit, std::vector<bool>(xExit,true));  //�����Ҵ� row ������ int vector �� stdvectorInt �� �ϳ���.
	static const int step[4][2] = { {-1,0} , {0,1} , {1,0} ,{ 0, -1} };	//�� �� �� ��
	std::priority_queue<loc, std::vector<loc>, compare> pq;
	pq.push({ 0,0,0 });    //0�� �μ�, ��ǥ [0][0];

	while (!pq.empty()) {
		int pqWall = pq.top().wallNum;
		int pqCol = pq.top().col;
		int pqRow = pq.top().row;
		pq.pop();

		if (path[pqCol][pqRow] < pqWall) continue;
		for (int i = 0; i < 4; ++i) {
			int newCol = pqCol + step[i][0]; //Ž���� �� ��ǥ
			int newRow = pqRow + step[i][1];
			if (newCol < 0 || newRow < 0 || newCol >= yExit || newRow >= xExit) continue;

			int newWall = pqWall + wall[newCol][newRow]; //�� 0�Ǵ� 1

			if (newWall < path[newCol][newRow]) {
				path[newCol][newRow] = newWall;
				pq.push({ newWall, newCol, newRow });
			} //endif

		}
	}

}

int main()
{
	int col, row;   //�� ��
	scanf("%d %d", &row, &col);
	std::vector<std::vector<int>> wall(col, std::vector<int>(row));  //�����Ҵ� row ������ int vector �� stdvectorInt �� �ϳ���.
				//0���� �����ϴϱ� ������ -1�� ����� �� ���� ��.
	std::vector<std::vector<int>> path(col, std::vector<int>(row, INF)); //�����´���� ���� ���� Ƚ    ��( �ּڰ� �ʿ� )


	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			scanf("%1d", &wall[i][j]);   //�� ���� ��� (bool�� �ϸ� �޸����� ����)
		}
	}

	dijkstra(wall, path, col, row);

	printf("%d", path[col - 1][row - 1]);
	return 0;
}

*/