#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> ques[32001];
std::priority_queue<int> pq;

int main(void) {

	int n, m; //학생 수와 키를 비교한 횟수 

	scanf("%d %d", &n, &m);
	std::vector<int> count(n + 1, 0);// 계수용
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		++count[b];
		ques[a].push_back(b);
	}

	for (int j = 1; j <= n; ++j) {
		if (count[j] == 0)
			pq.push(-j);
	}

	while (!pq.empty()) {
		int nowNode = -pq.top();
		pq.pop();
		printf("%d ", nowNode);

		for (int element : ques[nowNode]) {
			--count[element];
			if (count[element] == 0)
				pq.push(-element);
		}
	}

	return 0;
}