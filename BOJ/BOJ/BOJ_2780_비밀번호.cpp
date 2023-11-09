#include <iostream>
#include <vector>
// DP
#define DIVNUM 1234567

using namespace std;
vector < vector<int>> dp;

int NextPassword(int N, int current)
{
	if (N == 1)return 1;
	if (dp[N][current] != -1)return dp[N][current];
	
	int result;

    switch (current)
    {
    case 0:
        result = NextPassword(N - 1, 7) % DIVNUM;
        dp[N][current] = result;
        return result;
    case 1:
        result = NextPassword(N - 1, 2) % DIVNUM + NextPassword(N - 1, 4) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    case 2:
        result = NextPassword(N - 1, 1) % DIVNUM + NextPassword(N - 1, 3) % DIVNUM + NextPassword(N - 1, 5) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    case 3:
        result = NextPassword(N - 1, 2) % DIVNUM + NextPassword(N - 1, 6) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    case 4:
        result = NextPassword(N - 1, 1) % DIVNUM + NextPassword(N - 1, 5) % DIVNUM + NextPassword(N - 1, 7) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    case 5:
        result = NextPassword(N - 1, 2) % DIVNUM + NextPassword(N - 1, 4) % DIVNUM + NextPassword(N - 1, 6) % DIVNUM + NextPassword(N - 1, 8) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    case 6:
        result = NextPassword(N - 1, 3) % DIVNUM + NextPassword(N - 1, 5) % DIVNUM + NextPassword(N - 1, 9) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    case 7:
        result = NextPassword(N - 1, 4) % DIVNUM + NextPassword(N - 1, 8) % DIVNUM + NextPassword(N - 1, 0) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    case 8:
        result = NextPassword(N - 1, 5) % DIVNUM + NextPassword(N - 1, 7) % DIVNUM + NextPassword(N - 1, 9) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    case 9:
        result = NextPassword(N - 1, 6) % DIVNUM + NextPassword(N - 1, 8) % DIVNUM;
        dp[N][current] = result % DIVNUM;
        return dp[N][current];
    }
}

int Solve(int N, int i)
{
	return NextPassword(N, i);
}
int main(void)
{
	int T, N;
	cin >> T;
    dp.resize(1001, std::vector<int>(10, -1));

    for (int k = 0; k < T; ++k)
    {
        cin >> N;
        int Result = 0;
        for (int i = 0; i < 10; i++) {
            Result = (Result % DIVNUM + Solve(N, i) % DIVNUM) % DIVNUM;
        }
        cout << Result << '\n';
    }

	return 0;
}