#include <iostream>
#include <queue>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL); // �� �� ������ �ð��ʰ�

	std::priority_queue<int, std::vector<int>, std::greater<int> > PQ;
	int N = 0;
	std::cin >> N;

	int n;
	for (int i = 0; i < N * N; ++i)
	{
		std::cin >> n;
		PQ.push(n);
		if (PQ.size() > N)		
			PQ.pop();
		
	}
	std::cout << PQ.top();
	return 0;
}