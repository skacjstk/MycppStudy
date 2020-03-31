#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>


int bSearch(int n,int k) {
	int left = 1;
	int right = k;
	int mid = (left + right) / 2;
	long long compare = 0;
	int answer = 0;

	while (left <= right) {
		compare = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= n; ++i) {
			compare += std::min(n,mid/i);
			/*
				mid/i 의 각 행에서 k보다 작은 수를 구해 더하는 셈.
			*/
		}
		if (compare < k) {
			left = mid + 1;
		}
		else {
			answer = mid;
			/*
			1. 어떤 수 x가 있을 때, x-1 이하의 수의 개수가 K개 미만이고 x 이하의 수의 개수가 K개 이상인 경우
			우리가 찾는 K번째 수는 x 이다.
			2. 즉,  x는 x 이하의 수의 개수가 K개 이상이면서 가장 작은 수이다.

			출처: https://stack07142.tistory.com/298 [Hello World]
			예를 들어 3*3에서 7번쨰 수 x의 값은 6인데
			123
			246
			369
			6이하의 수는 8개로 7개보다 많고
			5이하의 수는 6개로 7개보다 적다
			6은 위 조건을 만족하면서 가장 작은 수이기 때문에 7번째 값은 6이다.
			*/
			right = mid - 1;
		}
	} //endwhile
	return answer;
}

int main(void)
{
	int n=-1;
	int k=-1;
	scanf("%d", &n);
	scanf("%d", &k);
	printf("%d", bSearch(n,k));	
	return 0;
}