//https://sihyungyou.github.io/baekjoon-2178/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <utility>



static int xExit, yExit;
static int maze[100][100];
static int away[100][100] = { 0, }; //방문한 위치의 시작지점으로부터의 거리 -->이거 만들어야 언제든지 위치탐색 가능 

void BFS(int y, int x) {
	static const int step[4][2] = { {-1,0} , {0,1} , {1,0} ,{ 0, -1} };	//상 우 하 좌  
	static bool visited[100][100] = { false, };	//방문체크
	std::queue<std::pair<int, int>> q;
	visited[y][x] = true; //방문 했음 

	q.push(std::make_pair(y, x));
	while (!q.empty()) {	
		y = q.front().first;
		x = q.front().second;		
		q.pop();
//		printf("함수 호출: y:%d x:%d\n", y, x);
	
		for (int i = 0; i < 4;++i) {
			int newy = y + step[i][0]; //탐색할 새 좌표
			int newx = x + step[i][1];

			// newx,newy 의 값이  지도 범위내 (0보다 같거나 크게)
			if (newy >= 0 && newx >= 0)	// -1 좌표 탐색 방지
			{
				//newy, newx 값이 목표지점바깥을 벗어나지 못하게
				if (newy < yExit && newx < xExit) {
					// 방문한 적이 없으며, maze가 갈수 있는 길일 때,
					if (visited[newy][newx] == false && maze[newy][newx] == 1)
					{
						visited[newy][newx] = true; //이제 탐색했음(할꺼임)
						away[newy][newx] = away[y][x] + 1;
						q.push(std::make_pair(newy, newx));
						printf("새 좌표 y:%d-->%d, x:%d-->%d 진입\n", y,newy, x,newx);
					}
				}
			}//endif	
		}//endfor
	} 
}

int main() {
	scanf("%d %d", &yExit, &xExit);
	for (int i = 0; i < yExit; ++i) {
		for (int j = 0; j < xExit; ++j) {
			scanf("%1d", &maze[i][j]);	//1 아니면 0
		}
	} //endfor
	BFS(0, 0); //시작지점에서 출발

	printf("%d\n", away[yExit - 1][xExit - 1] +1 );
	return 0;
}