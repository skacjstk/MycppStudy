#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> seq;
std::unordered_map<int, bool> answer;
int N;
void Solution(int startIdx, int sum)
{
	// 배열 끝에 도달할 경우
	if (startIdx == N)
	{
		answer[sum] = true;
		return;
	}
	Solution(startIdx + 1, sum + seq[startIdx]);	// 더했을 경우
	Solution(startIdx + 1, sum);	//더하지 않았을 경우
}

int main(void)
{
	int S, range;
	std::cin >> N;
	seq.reserve(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> S;
		seq.push_back(S);
	}
	Solution(0, 0);	// 시작은 0에서 시작

	range = 0;
//	std::cout << "맵 크기: " << answer.size() << std::endl;
	while (1)
	{
		if (answer[range] == false) {
			std::cout << range << "\n";
			break;
		}
		else
			++range;
	}

	return 0;
}