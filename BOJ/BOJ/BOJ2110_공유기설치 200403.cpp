/******************************************************************************

							  Online C++ Compiler.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> arr;

int bSearch(const int &n, const int &c) {
	int left = 1;
	int right = arr[n - 1] - arr[0];
	int mid, cnt = 1, answer;
	int wayPoint;

	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 1;
		wayPoint = arr[0];

		for (int i = 1; i < n; ++i) {
			if (arr[i] - wayPoint >= mid) {
				++cnt;
				wayPoint = arr[i];
			}
		}

		if (cnt < c) //덜 설치되었음
			right = mid - 1;
		else
		{
			answer = mid;
			left = mid + 1;
		}

	}
	return answer;
}

int main()
{
	int n;
	int c;
	scanf("%d %d", &n, &c);
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);

	}
	std::sort(arr.begin(), arr.end());

	int answer = bSearch(n, c);
	printf("%d", answer);
	return 0;
}
