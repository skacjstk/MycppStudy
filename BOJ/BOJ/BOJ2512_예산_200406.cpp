#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> region;
int bSearch(int useBudget, int maxBudget) {
	int left = 0;
	int right = maxBudget;
	int mid;
	long long comBudget = 0;
	int answer = 0;

	while (left <= right)
	{
		comBudget = 0;
		mid = (left + right) / 2;
		//      printf("%d\t", mid);

		for (int bud : region) {
			comBudget += std::min(bud, mid);
		}
		//      printf("%lld\n",comBudget);
		if (comBudget <= useBudget) {
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return answer;
}

int main()
{
	int regionNum;		//3~10,000
	scanf("%d", &regionNum);
	region.resize(regionNum);
	int maxBudget = 0;
	for (int i = 0; i < regionNum; ++i) {
		scanf("%d", &region[i]);

		//-->이 경우, maxBudget 값을 comBudget과 비교할 때, 
		//예산이 터무니없이 많이 들어올 때, mid 값이 정상적인 측정이 안됨(사실 당연한거)
   //     maxBudget += region[i];
		maxBudget = std::max(maxBudget, region[i]);
	}
	int useBudget;
	scanf("%d", &useBudget);
	std::sort(region.begin(), region.end());

	printf("%d", bSearch(useBudget, maxBudget));
	return 0;
}
