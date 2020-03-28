#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>	//queue
#include <utility>	//pair
#include <vector>
#include <algorithm>	//sort

static int apt[25][25];
static bool visited[25][25] = { false, };	//�湮üũ

std::vector<int> aptCnt;

bool visitedCheck(const int y, const int x) {
	bool answer = false;
	if (!visited[y][x] && apt[y][x] == 1)
		answer = true;

	return answer;
}

void BFS(int y, int x, int map) {
	static const int step[4][2] = { {-1,0} , {0,1} , {1,0} ,{ 0, -1} };	//�� �� �� ��  
	int aptBFSCnt = 1;	//�ڱ� �ڽ��� ����.

	std::queue<std::pair<int, int>> q;
	visited[y][x] = true; //�湮 ���� 
	q.push(std::make_pair(y, x));

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int newy = y + step[i][0]; //Ž���� �� ��ǥ
			int newx = x + step[i][1];

			// newx,newy �� ����  ���� ������ (0���� ���ų� ũ��)
			if (newy >= 0 && newx >= 0)	// -1 ��ǥ Ž�� ����
			{
				//newy, newx ���� ��ǥ�����ٱ��� ����� ���ϰ�
				if (newy < map && newx < map) {
					// �湮�� ���� ������, maze�� ���� �ִ� ���� ��,
					if (visited[newy][newx] == false && apt[newy][newx] == 1)
					{
						visited[newy][newx] = true; //���� Ž������(�Ҳ���)
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
	//���� ������ �� ������ �湮�˻����� , 2���� 2���� �迭�� ������ ��.

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