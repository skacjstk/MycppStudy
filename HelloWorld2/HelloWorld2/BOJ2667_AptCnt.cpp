#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>	//queue
#include <utility>	//pair
#include <vector>
#include <algorithm>	//sort

static int apt[25][25];
static bool visited[25][25] = { false, };	//방문체크

std::vector<int> aptCnt;

bool visitedCheck(const int y, const int x) {
	bool answer = false;
	if (!visited[y][x] && apt[y][x] == 1)
		answer = true;

	return answer;
}

void BFS(int y, int x, int map) {
	static const int step[4][2] = { {-1,0} , {0,1} , {1,0} ,{ 0, -1} };	//상 우 하 좌  
	int aptBFSCnt = 1;	//자기 자신을 포함.

	std::queue<std::pair<int, int>> q;
	visited[y][x] = true; //방문 했음 
	q.push(std::make_pair(y, x));

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int newy = y + step[i][0]; //탐색할 새 좌표
			int newx = x + step[i][1];

			// newx,newy 의 값이  지도 범위내 (0보다 같거나 크게)
			if (newy >= 0 && newx >= 0)	// -1 좌표 탐색 방지
			{
				//newy, newx 값이 목표지점바깥을 벗어나지 못하게
				if (newy < map && newx < map) {
					// 방문한 적이 없으며, maze가 갈수 있는 길일 때,
					if (visited[newy][newx] == false && apt[newy][newx] == 1)
					{
						visited[newy][newx] = true; //이제 탐색했음(할꺼임)
						q.push(std::make_pair(newy, newx));
						++aptBFSCnt;
					}
				}
			}//endif	
		}//endfor
	}
	aptCnt.push_back(aptBFSCnt);
}

int main() {
	int map;	//5~25 
	std::cin >> map;
	//실제 지도와 그 지도의 방문검사지도 , 2개의 2차원 배열을 만들어야 함.

	for (int i = 0; i < map; ++i) {
		for (int j = 0; j < map; ++j) {
			scanf("%1d", &apt[i][j]);
		}
	}

	int aptSet = 0;
	for (int i = 0; i < map; i++) {
		for (int j = 0; j < map; j++) {
			if (visitedCheck(i, j))
			{
				++aptSet;
				BFS(i, j,map);
			}
		}
	} //endfor

	std::sort(aptCnt.begin(), aptCnt.end(),std::less<int>()); 
	printf("%d\n", aptSet);
	for (int i = 0; i < aptSet; ++i) {
		printf("%d\n", aptCnt[i]);
	}
	return 0;
}