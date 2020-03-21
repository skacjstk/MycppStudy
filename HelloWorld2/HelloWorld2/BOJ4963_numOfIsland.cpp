#include <iostream>
#include <vector>
//���� Ž���� �⺻������ DFS
/*
	0 �������� 8���� �˻��Ѵ�
	0,0 �� map���� �˻��ϸ鼭 index �� ��� ������ 1�� ��� ���� 1�� �ִ°ɷ� ����,
	�ݺ������� �˻��ϸ鼭 ����Լ��� DFS Ž���Ͽ� �� 0 �������� 8�������� ������ ��������� 
	Ž���ϸ鼭 �湮������ Ȯ���Ѵ�.
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
			std::cout<<"���̳� �ʺ� 50�� �ʰ��߽��ϴ�.";
			continue;
		}
		std::vector<std::vector<int>> map(w + 2, std::vector<int>(h + 2, 0));
		//w+2, h+2 ĭ�� 0�ʱ�ȭ 2�������� �̸�: map

		//std::vector<std::vector<int>> visited(w + 2, std::vector<int>(h + 2));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				scanf_s("%d", &map[i][j]);
		} 
		std::vector<std::vector<int>> visited(map);	//map�� ������ visited �߰�(�������� ����� �갡 ��)
		//������ �ջ��� ���� ���� visited ���� �߰�.
		int cnt = 0;	//���� ����
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
