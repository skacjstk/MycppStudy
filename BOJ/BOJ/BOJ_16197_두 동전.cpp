#include <iostream>
#include <vector>

std::vector<std::vector<char>> arr;	// ���� ����(�迭, ���� ũ��) 
std::vector<std::vector<bool>> visited;	// �湮 �˻��� -> �ʿ� ����?

int N, M;

int dx[] = { -1,1,0,0 };		// x�� ����, ������
int dy[] = { 0,0,-1,1 };		// y�� ��, �Ʒ�

int maxDepth = 10;

// �ʿ� �ұ�??
// ������ y ��ǥ
int coinY[2];
// ������ x ��ǥ
int coinX[2];




int result = 9999;	// �ִ밪�� �־߾� ��


// ���� ������ ����, ����
void DFS(int fallCoinNum, int depth)
{
	// ������ �����Ѱ��� 10�� �ʰ� �õ��ϰų�, �ѹ��� �ΰ��� ���������ϱ�
	if (depth >= maxDepth || fallCoinNum == 2) {
		return;
	}
	else if (fallCoinNum == 1) {
		result = std::min(result, depth);
	}
	// �������� DFS ���� ��
	else {

		// ���� ���� ��ġ( ���� ������ �� ��ġ )
		int beforeX[2];
		int beforeY[2];

		// ���� ��ġ ��� (������ �ؾ� ��)
		beforeX[0] = coinX[0];
		beforeY[0] = coinY[0];

		beforeX[1] = coinX[1];
		beforeY[1] = coinY[1];

		// 4�������� �̵� �õ�
		for (int i = 0; i < 4; ++i) {
			// �˻�� ���� ��ġ
			int newX;
			int newY;

			// Ȯ���� �� ���� ��ġ
			int newCoinY[2];
			int newCoinX[2];

			// k�� ������ �� ��ġ
			for (int k = 0; k < 2; ++k) {
				newX = coinX[k] + dx[i];
				newY = coinY[k] + dy[i];
				

				// ������ ���
				if (newX < 0 || newX >= M || newY < 0 || newY >= N) {
					++fallCoinNum;	// ������ ���� �� ����
					continue;
				}
				else if (arr[newY][newX] == '#')
					continue;
				// ����: 2���� ����� �� �˻�
				else
				{
					// ���� �� ��ġ ���
					newCoinX[k] = newX;
					newCoinY[k] = newY;

					// ���� �� ��ġ �ݿ� ( ���� ����� ������� {�����ϱ� �ϴ�} )
					coinX[k] = newX;
					coinY[k] = newY;
				}//endif


			} //end for


			// �� ��ġ�� �ű��� ����.
			DFS(fallCoinNum, depth + 1);
			coinX[0] = beforeX[0];
			coinY[0] = beforeY[0];

			coinX[1] = beforeX[1];
			coinY[1] = beforeY[1];
		}//endfor
	}//endif
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
	char pin;
	int coinNum = 0;
	// y��
	for (int i = 0; i < N; ++i) {
		// x��
		for (int j = 0; j < M; ++j) {

			std::cin >> arr[i][j];

			// ���� ��ġ ���
			if (arr[i][j] == 'o') {
				coinY[coinNum] = i;
				coinX[coinNum] = j;
				coinNum++;
			}
		}
	}

	// �Է� �ٹ޾����� ���� �� Move�� ���� ������ ��ġ�� ����ؾ� �Ѵ�.

	DFS(0, 0);	// 10�� �ʰ��ϱ� ù �õ��� 0�� �� 10��°���� �õ����� ���ϰ� �ɷ��� ��
	
	// � ��쵵 �������� ���Ѵٸ� -1�� �ٲ�
	if (result == 9999)
		result = -1;

	std::cout << result;

	return 0;
}