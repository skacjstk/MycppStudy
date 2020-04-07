
#include <iostream>
#include <vector>
#include <algorithm>

int bSearch(const std::vector<int> &tree, long long wantWood) {
	int left = 0;
	int right = tree[tree.size() - 1];
	int mid = 0;
	int answer = 0;
	while (left <= right) {
		long long cut = 0;
		mid = (left + right) / 2;
		for (int treeHigh : tree) {
			if (treeHigh > mid)
				cut += treeHigh - mid;
		}

		if (cut >= wantWood)  //너무 많이잘랐으면  덜 잘라야 한다.
		{
			answer = mid;
			left = mid + 1;
		}
		else if (cut < wantWood) //양이 부족하면 더 많이 잘라야 한다.
			right = mid - 1;
	}

	return answer;
}


int main()
{
	int treeNum;
	long long wantWood;
	scanf("%d %lld", &treeNum, &wantWood);
	std::vector<int> tree(treeNum);
	for (int i = 0; i < treeNum; ++i) {
		scanf("%d", &tree[i]);
	}
	std::sort(tree.begin(), tree.end());

	printf("%d", bSearch(tree, wantWood));

	return 0;
}
