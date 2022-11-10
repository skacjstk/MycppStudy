#include <iostream>
#include <vector>
#include <algorithm>

int matrixNum = 0;	// DFS의 깊이로도 사용할 수 있음
int result = INT32_MAX;
bool visited[20] = { false, };	// (i + 1 번 사람의 방문 여부)

int matrix[20][20] = { 0, };	// 최대값

void DFS(int index, int currentDepth)
{

	// 조건식에 감지되면, 팀 분배가 결정된 것
	// 결산
	if (currentDepth == matrixNum / 2)
	{
		int start = 0;
		int link = 0; // 점수 총합
		std::vector<int> startList;
		std::vector<int> linkList;
		for (int i = 0; i < matrixNum ; i++)
		{
			for (int j = 0; j < matrixNum; j++)
			{
				// 둘이 
				if (visited[i] == true && visited[j] == true) start += matrix[i][j];
				if (visited[i] == false && visited[j] == false) link += matrix[i][j];

			}
		}
		printf("삽입 전 검사: %d\n", result);
		result = std::min(result, std::abs(start - link));	// 최솟값 넣기
		return;
	}

	// 어차피 첫 시도에 N까지 못감(if 조건을 N/2로 할 꺼니까)
	for (int i = index; i < matrixNum; ++i) {
		if (visited[i])	// 얘가 i +  1 기능을 대신하는 셈 
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
	// 1. 가능한 수 구하기
//	std::cin >> matrixNum;
//
//	// 2. 2중 반복문으로 배열 채우기 (행렬구현 귀찮...)
//	for (int i = 0; i < matrixNum; ++i) {
//		for (int k = 0; k < matrixNum; ++k) {
//			std::cin >> matrix[i][k];
//		}
//	}

	// 자동 테스트
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


	// 3. N명중 N/2명을 구하는 조합을 찾고, 팀을 나눴을 때
	DFS(0, 0);

	printf("%d\n", result);

	return 0;
}