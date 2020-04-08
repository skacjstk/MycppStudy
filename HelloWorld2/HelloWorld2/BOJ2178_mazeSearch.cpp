//https://sihyungyou.github.io/baekjoon-2178/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <utility>



static int xExit, yExit;
static int maze[100][100];
static int away[100][100] = { 0, }; //�湮�� ��ġ�� �����������κ����� �Ÿ� -->�̰� ������ �������� ��ġŽ�� ���� 

void BFS(int y, int x) {
	static const int step[4][2] = { {-1,0} , {0,1} , {1,0} ,{ 0, -1} };	//�� �� �� ��  
	static bool visited[100][100] = { false, };	//�湮üũ
	std::queue<std::pair<int, int>> q;
	visited[y][x] = true; //�湮 ���� 

	q.push(std::make_pair(y, x));
	while (!q.empty()) {	
		y = q.front().first;
		x = q.front().second;		
		q.pop();
//		printf("�Լ� ȣ��: y:%d x:%d\n", y, x);
	
		for (int i = 0; i < 4;++i) {
			int newy = y + step[i][0]; //Ž���� �� ��ǥ
			int newx = x + step[i][1];

			// newx,newy �� ����  ���� ������ (0���� ���ų� ũ��)
			if (newy >= 0 && newx >= 0)	// -1 ��ǥ Ž�� ����
			{
				//newy, newx ���� ��ǥ�����ٱ��� ����� ���ϰ�
				if (newy < yExit && newx < xExit) {
					// �湮�� ���� ������, maze�� ���� �ִ� ���� ��,
					if (visited[newy][newx] == false && maze[newy][newx] == 1)
					{
						visited[newy][newx] = true; //���� Ž������(�Ҳ���)
						away[newy][newx] = away[y][x] + 1;
						q.push(std::make_pair(newy, newx));
//						printf("�� ��ǥ y:%d-->%d, x:%d-->%d ����\n", y,newy, x,newx);
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
			scanf("%1d", &maze[i][j]);	//1 �ƴϸ� 0
		}
	} //endfor
	BFS(0, 0); //������������ ���

	printf("%d\n", away[yExit - 1][xExit - 1] +1 );
	return 0;
}