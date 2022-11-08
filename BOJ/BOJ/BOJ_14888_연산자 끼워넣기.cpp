#include <iostream>
#include <algorithm>

int operatorCount[4] = { 0, };	// + - * / 순서

int N;	// 숫자의 갯수이자 DFS의 깊이 (N - 1) 
int nums[11] = { 0, };	// 문제 조건이 1~100 사이임

int maxResult = -1000000000;	// 최소값을 넣어야 
int minResult = 1000000000;		// 최대값을 넣어야

void DFS(int depth, int currentValue, int useOp)
{
	// 연산자에 따라 연산
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
		printf("버그상황: useOp 는 0~3만 허용합니다.\n");
	}
	// 반환 조건: depth 끝까지 도달
	if (depth == N - 1) {
		maxResult = std::max(maxResult, currentValue);
		minResult = std::min(minResult, currentValue);
	}

	// 인접 노드 탐색
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
	if (operatorCount[3] > 0) {	// 나누기
		--operatorCount[3];
		DFS(depth + 1, currentValue, 3);
		++operatorCount[3];
	}

}

int main(void)
{
	std::cin >> N;

	// N 개의 숫자 입력	
	for (int i = 0; i < N; ++i) {
		std::cin >> nums[i];
	}

	// 각 연산자들의 갯수 읽기
	std::cin >> operatorCount[0] >> operatorCount[1] >> operatorCount[2] >> operatorCount[3];

	// 탐색 시작
	DFS(0, 0, 0);
	std::cout << maxResult << std::endl << minResult;

	return 0;
}