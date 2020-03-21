#include <iostream>
#include <vector>
//섬의 탐색은 기본적으로 DFS
/*
	0 기준으로 8방을 검사한다
	0,0 번 map부터 검사하면서 index 에 담긴 변수가 1일 경우 섬이 1개 있는걸로 간주,
	반복문으로 검사하면서 재귀함수로 DFS 탐색하여 그 0 기준으로 8방향으로 가지를 뻣어나가듯이 
	탐색하면서 방문했음을 확인한다.
*/


int vi[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int vj[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void DFS(std::vector<std::vector<int>> &visited, int i, int j) {
	if (visited[i][j] != 0) {
		visited[i][j] = 0;
		for (int m = 0; m < 8; m++)
			DFS(visited, i + vi[m], j + vj[m]);
	}
}

int main() {
	int w, h;
	while (scanf_s("%d %d", &w, &h)) {
		if (w == 0 && h == 0) {
			return 0;
		}	
		if (50 < w && 50 < h) {
			std::cout<<"높이나 너비가 50을 초과했습니다.";
			continue;
		}
		std::vector<std::vector<int>> map(w + 2, std::vector<int>(h + 2, 0));
		//w+2, h+2 칸의 0초기화 2차원벡터 이름: map

		//std::vector<std::vector<int>> visited(w + 2, std::vector<int>(h + 2));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				scanf_s("%d", &map[i][j]);
		} 
		std::vector<std::vector<int>> visited(map);	//map을 복제한 visited 추가(실질적인 계산은 얘가 함)
		//원본의 손상을 막기 위한 visited 벡터 추가.
		int cnt = 0;	//섬의 갯수
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (visited[i][j] == 0)
					continue;
				DFS(visited, i, j);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
