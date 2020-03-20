#include <iostream>
//���� Ž���� �⺻������ DFS
/*
	0 �������� 8���� �˻��Ѵ�
	0,0 �� map���� �˻��ϸ鼭 index �� ��� ������ 1�� ��� ���� 1�� �ִ°ɷ� ����,
	�ݺ������� �˻��ϸ鼭 ����Լ��� DFS Ž���Ͽ� �� 0 �������� 8�������� ������ ��������� 
	Ž���ϸ鼭 �湮������ Ȯ���Ѵ�.
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
