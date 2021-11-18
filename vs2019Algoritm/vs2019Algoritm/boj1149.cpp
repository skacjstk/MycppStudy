#include <iostream>
#include <algorithm>
using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

//RGB 거리 (집 색칠하기)
int main(void)
{
	int n;
	int r, g, b;
	int dp[1001][3] = { 0, };
	cin >> n;


	for (int i = 1; i <= n; ++i) {

		cin >> r >> g >> b;

		dp[i][RED] = min(dp[i-1][GREEN], dp[i - 1][BLUE]) + r;
		dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + g;
		dp[i][BLUE] = min(dp[i - 1][GREEN], dp[i - 1][RED]) + b;

	}

	cout << min(dp[n][BLUE], min(dp[n][RED], dp[n][GREEN]));


	return 0;
}