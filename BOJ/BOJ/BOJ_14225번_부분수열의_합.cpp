#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> seq;
std::unordered_map<int, bool> answer;
int N;
void Solution(int startIdx, int sum)
{
	// �迭 ���� ������ ���
	if (startIdx == N)
	{
		answer[sum] = true;
		return;
	}
	Solution(startIdx + 1, sum + seq[startIdx]);	// ������ ���
	Solution(startIdx + 1, sum);	//������ �ʾ��� ���
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
	Solution(0, 0);	// ������ 0���� ����

	range = 0;
//	std::cout << "�� ũ��: " << answer.size() << std::endl;
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