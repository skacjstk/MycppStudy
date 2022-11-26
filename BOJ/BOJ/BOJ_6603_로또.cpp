#include <iostream>
#include <vector>

std::vector<std::pair<int, bool>> visitedNum;
int maxDepth = 6;	// 6개 출력수 

void DFS(int index, int depth)
{

	// 6개 출력하고 리턴하기
	if (depth == maxDepth)	// 6 == 6 이어야 다 선택한 것
	{
		for (int i = 0; i < visitedNum.size(); ++i) {
			if (visitedNum[i].second == true) {
				printf("%d ", visitedNum[i].first);
			}			
		}
		printf("\n");
		return;
	}
	// 6개 안되었으면 깊이 들어가기
	else {
		for (int i = index; i < visitedNum.size(); ++i) {
			visitedNum[i].second = true;
			DFS(i + 1, depth + 1);
			visitedNum[i].second = false;
		}
	}
}

int main(void)
{
	int k = 0;
	std::pair<int, bool> input;

	while (1)
	{
		std::cin >> k;

		if (k == 0)
			break;

		visitedNum.resize(k);
		input.second = false;

		for (int i = 0; i < k; ++i) {

			std::cin >> input.first;
			visitedNum[i] = input;
		}

		DFS(0, 0);
		printf("\n");
	}

	return 0;
}