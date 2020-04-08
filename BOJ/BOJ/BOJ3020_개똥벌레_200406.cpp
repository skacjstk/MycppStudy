#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <algorithm>


int main(void)
{
	int n, h;

	scanf("%d %d", &n, &h);
	std::vector<int> height(h); //0~ h-1Ãþ

}

/*
int main(void)
{
	int n, h;

	scanf("%d %d", &n, &h);
	std::vector<int> height(h); //0~ h-1Ãþ

	for (int i = 1; i <= n; ++i)
	{
		int fence;
		scanf("%d", &fence);

		if (i % 2 != 0)  //È¦¼ö¶ó¸é
		{
			for (int j = 0; j < fence; ++j) {
				++height[j];
			}
		}
		else {
			for (int k = 1; k <= fence; ++k) {

				++height[height.size() - k];
			}
		}
	}

	std::sort(height.begin(), height.end());

	int cnt=1;

	for (int u = 1;;++u) {
		if (height[0] == height[u])
			++cnt;
		else break;
	}
	
	printf("%d %d", height[0], cnt);
	return 0;
}
*/