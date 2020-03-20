#include <iostream>
//섬의 탐색은 기본적으로 DFS
/*
	0 기준으로 8방을 검사한다
	0,0 번 map부터 검사하면서 index 에 담긴 변수가 1일 경우 섬이 1개 있는걸로 간주,
	반복문으로 검사하면서 재귀함수로 DFS 탐색하여 그 0 기준으로 8방향으로 가지를 뻣어나가듯이 
	탐색하면서 방문했음을 확인한다.
*/
using namespace std;
int vi[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int vj[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void DFS(int map[52][52], int i, int j) {
	if (map[i][j] != 0) {
		map[i][j] = 0;
		for (int m = 0; m < 8; m++)
			DFS(map, i + vi[m], j + vj[m]);
	}
}

int main() {
	int w, h;
	while (scanf("%d %d", &w, &h)) {
		if (w == 0 && h == 0) {
			return 0;
		}
		int map[52][52] = { 0, };	
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				scanf("%d", &map[i][j]);
		}
		int cnt = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == 0)
					continue;
				DFS(map, i, j);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
