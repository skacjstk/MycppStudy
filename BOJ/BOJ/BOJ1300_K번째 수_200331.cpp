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