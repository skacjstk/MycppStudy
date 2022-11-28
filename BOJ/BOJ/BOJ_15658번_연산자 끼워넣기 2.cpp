#include <iostream>
#include <algorithm>

int operatorCount[4] = { 0, };	// + - * / ����

int N;	// ������ �������� DFS�� ���� (N - 1) 
int nums[11] = { 0, };	// ���� ������ 1~100 ������

int maxResult = -1000000000;	// �ּҰ��� �־�� 
int minResult = 1000000000;		// �ִ밪�� �־��

void DFS(int depth, int currentValue, int useOp)
{
	// �����ڿ� ���� ����
	switch (useOp)
	{
	case 0:
		currentValue = currentValue + nums[depth];
		break;
	case 1:
		currentValue = currentValue - nums[depth];
		break;
	case 2:
		currentValue = currentValue * nums[depth];
		break;
	case 3:
		currentValue = currentValue / nums[depth];
		break;
	default:
		printf("���׻�Ȳ: useOp �� 0~3�� ����մϴ�.\n");
	}
	// ��ȯ ����: depth ������ ����
	if (depth == N - 1) {
		maxResult = std::max(maxResult, currentValue);
		minResult = std::min(minResult, currentValue);
		return;
	}

	// ���� ��� Ž��
	if (operatorCount[0] > 0) {	// +
		--operatorCount[0];
		DFS(depth + 1, currentValue, 0);
		++operatorCount[0];
	}
	if (operatorCount[1] > 0) {	// -
		--operatorCount[1];
		DFS(depth + 1, currentValue, 1);
		++operatorCount[1];

	}
	if (operatorCount[2] > 0) {	// *
		--operatorCount[2];
		DFS(depth + 1, currentValue, 2);
		++operatorCount[2];
	}
	if (operatorCount[3] > 0) {	// ������
		--operatorCount[3];
		DFS(depth + 1, currentValue, 3);
		++operatorCount[3];
	}

}

int main(void)
{
	std::cin >> N;

	// N ���� ���� �Է�	
	for (int i = 0; i < N; ++i) {
		std::cin >> nums[i];
	}

	// �� �����ڵ��� ���� �б�
	std::cin >> operatorCount[0] >> operatorCount[1] >> operatorCount[2] >> operatorCount[3];

	// Ž�� ����
	DFS(0, 0, 0);	// �̰� �Ǵ� ����: depth�� 0������ (depth 1�� �������� Ž��)
					// �׸��� �̴� ù��° ���ڸ� ��ġ�ϴ� �Ͱ� ����
	std::cout << maxResult << std::endl << minResult;

	return 0;
}