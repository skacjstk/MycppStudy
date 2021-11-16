#include <iostream>

using namespace std;

int dp[1001] = { 0, };
void Tilling(int num) {
	int answer;
	for (int i = 3; i <= num; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; 
		//숫자가 너무 커서 틀리다고 나온다. 어차피 나머지계산 할 운명이었으므로 미리 해놓고 저장해도 괜찮다
	}
	
	answer = dp[num];
	cout << answer;
}


int main(void)
{
	int num;

	dp[1] = 1;
	dp[2] = 2;
	//dp[3] = 3; dp[4] = 5;
	//점화식 dp[n] = dp[n-1] + dp[n-2];

	cin >> num;

	switch (num){
	case 1:
		cout << "1";
		break;
	case 2:
		cout << "2";		
		break;
	default:
		Tilling(num);
	}

	return 0;
}