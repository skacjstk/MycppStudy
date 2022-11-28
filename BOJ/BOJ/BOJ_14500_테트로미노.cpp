#include <iostream>
#include <vector>

std::vector<std::vector<int>> arr;	// ���� ����(�迭, ���� ũ��) 
std::vector<std::vector<bool>> visited;	// �湮 �˻��� 

int N, M;

int dx[] = { -1,1,0,0 };		// x�� ����, ������
int dy[] = { 0,0,-1,1 };		// y�� ��, �Ʒ�

// �����Ͽ� ��� ���� ��ǥ �ȳ���
// ���� ��ǥ(0�� index)���� �����ǥ �� �� �� �� ����
int ox[4][4] = { {0,1,2,1}, {0,0,0,1}, {0,-1,-2,-1}, {0,0,0,-1} };
int oy[4][4] = { {0,0,0,-1}, {0,1,2,1}, {0,0,0,1}, {0,-1,-2,-1} };

int result = 0;	// �ּҰ��� �־���� ��.

// ��Ʈ�ι̳��� ��� ���� ��� 4��
// �� ���� Ư���� ����� �����ϸ�, �Ϲ����� DFS ����� ���� �� �ִ� ���
// ���� ��� �� ����� �� ����� DFS ���� �� 3��° index���� �ݴ� �������� ������� ���� �� �ִ� ����� �� 
// �׷��� �Ǹ� �����ϰ� ��ġ �Ϲ� DFSó�� ���� ����
void DFS(int x, int y, int sum, int depth)
{

	// 0, 1, 2, 3 Ž���ϰ� 4�Ǹ� ��ȯ
	if (depth >= N) {
//		printf("����:%d \t��: %d %d\n", depth, sum, result);
		result = std::max(result, sum);
		return;
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];

			// ���� ���� �˻� 
			// ���� ����� DFS ����( �� ȸ������ �� ���� �������� ����. )
			if (newX < 0 || newX >= M || newY < 0 || newY >= N ) continue;

			// �̹湮�� ���� ���� Ž��
			if (!visited[newY][newX]) {
				visited[newY][newX] = true;

				sum = sum + arr[newY][newX];	// �ش� ��ġ �����ϱ�
				DFS(newX, newY, sum, depth + 1);
				sum = sum - arr[newY][newX];	// �湮 �ϰ� �����ϱ� ������ 
				visited[newY][newX] = false;
			}//endif
		}//endfor
	}//endif
}


// �� �� ���� Ư�� ó��
// x, y ������ ��, �� , ��, �� ����� ���� �˻��ؼ� result�� std::max ������
void CheckOtherShape(int x, int y)
{
	bool isValid = true;	// �� ��ġ������ ����� ��ȿ����

	// 4�� ���� 
	for(int k = 0; k < 4; ++k){	// ����� ��
		int sum = 0;	// ��
		for (int i = 0; i < 4; ++i) {	// ��
			int newX = x + ox[k][i];
			int newY = y + oy[k][i];

			// ���� ���� �˻� 
			// ���� ����� �ش� ��� ������� ����
			if (newX < 0 || newX >= M || newY < 0 || newY >= N) {
				isValid = false; 
				break;
			}
			// �湮 �˻簡 �ʿ� ����
			sum = sum + arr[newY][newX];	// �����ϱ�

		}//endif
		if(isValid)
			result = std::max(result, sum);	// ������ continue�� ȣ��Ǹ� ����� �ȿ�.
	}
}

int main(void)
{
	std::cin >> N >> M;

	arr.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; ++i) {
		arr[i].resize(M);
		visited[i].resize(M);
	}
	// 2���� �迭 ũ���Ҵ�

	// y��
	for (int i = 0; i < N; ++i) {
		// x��
		for (int j = 0; j < M; ++j) {
			std::cin >> arr[i][j];
		}
	}

	// �Է� �ٹ޾����� ��� ������ ��翡 �ɸ´� DFS�� �����Ѵ�
	for (int i = 0; i < N; ++i) {	// y��
		for (int j = 0; j < M; ++j) {	// x��
			visited[i][j] = true;
			DFS(j, i, arr[i][j], 1);	// �� ���� ��ȿ�ϸ�, depth 1���� �����ؾ� ����
			visited[i][j] = false;

			// �� �� �� �� ���� �˻�
			CheckOtherShape(j, i);

		}
	}
	std::cout << result;

	return 0;
}