#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> tall[32001];
std::queue<int> q;

int main(void) {

	int n, m; //학생 수와 키를 비교한 횟수 

	scanf("%d %d", &n, &m);
	std::vector<int> count(n + 1,0);// 계수용
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		++count[b];
		tall[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i) {
		if (!count[i])
			q.push(i);
	}

	while (!q.empty()) {
		int output = q.front();
		q.pop();
		printf("%d ", output);

		for (const int &i : tall[output]) {
			--count[i];
			if (!count[i]) q.push(i);
		}
	}
	return 0;
}