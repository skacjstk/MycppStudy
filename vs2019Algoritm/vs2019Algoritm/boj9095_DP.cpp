#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int n = 11;

int dp[n];

int main(void)
{
	int testCase;
	int num;
	cin >> testCase;
	vector<int> answer(testCase);
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	

	for (int i = 0; i < testCase; ++i) {
		cin >> num;
		for(int j=3; j<num;++j){
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		answer[i] = dp[num - 1];
	}
	
	for (auto it : answer) {
		cout << it << "\n";
	}

	return 0;
}
//전형적인 DP문제, 점화식을 찾고, 적용하는 게 제일 중요함
//이 문제의 점화식은 dp[n] = dp[n-1] + dp[n-2] + dp[n-3] 임