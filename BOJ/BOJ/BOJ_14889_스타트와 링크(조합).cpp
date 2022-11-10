#include <iostream>
#include <vector>
#include <algorithm>

int matrixNum = 0;	// DFS�� ���̷ε� ����� �� ����
int result = INT32_MAX;
bool visited[20] = { false, };	// (i + 1 �� ����� �湮 ����)

int matrix[20][20] = { 0, };	// �ִ밪

void DFS(int index, int currentDepth)
{

	// ���ǽĿ� �����Ǹ�, �� �й谡 ������ ��
	// ���
	if (currentDepth == matrixNum / 2)
	{
		int start = 0;
		int link = 0; // ���� ����
		 
		for (int i = 0; i < matrixNum ; i++)
		{
			for (int j = 0; j < matrixNum; j++)
			{
				// ���� ���� ���� ������ ��, �߰������� �޴´� ( �ݺ��� �� ij ji �� �ѹ��� ����Ǵ� �� )
				if (visited[i] == true && visited[j] == true) start += matrix[i][j];
				if (visited[i] == false && visited[j] == false) link += matrix[i][j];

			}
		}
		printf("���� �� �˻�: %d\n", result);
		result = std::min(result, std::abs(start - link));	// �ּڰ� �ֱ�
		return;
	}

	// ������ ù �õ��� N���� ����(if ������ N/2�� �� ���ϱ�)
	for (int i = index; i < matrixNum; ++i) {
		if (visited[i])	// �갡 i +  1 ����� ����ϴ� �� 
			continue;
		else
		{
			visited[i] = true;
			DFS(i, currentDepth + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{	
	// 1. ������ �� ���ϱ�
	std::cin >> matrixNum;

	// 2. 2�� �ݺ������� �迭 ä��� (��ı��� ����...)
	for (int i = 0; i < matrixNum; ++i) {
		for (int k = 0; k < matrixNum; ++k) {
			std::cin >> matrix[i][k];
		}
	}

	// �ڵ� �׽�Ʈ
	matrixNum = 4;
	int test[16] = { 0, 1, 2, 3,
					4, 0, 5, 6,
					7, 1, 0, 2,
					3, 4, 5, 0 };

	int testIndex = 0;
	for (int i = 0; i < matrixNum; ++i) {
		for (int k = 0; k < matrixNum; ++k) {
			matrix[i][k] = test[testIndex++];
		}
	}


	// 3. N���� N/2���� ���ϴ� ������ ã��, ���� ������ ��
	DFS(0, 0);

	printf("%d\n", result);

	return 0;
}