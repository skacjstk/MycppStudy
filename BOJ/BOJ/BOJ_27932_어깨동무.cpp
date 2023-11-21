#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

#define INT_MAX       2147483647
using namespace std;

vector<int> Students;
unsigned int N, K;
int SolveResult = INT_MAX;
int CheckTired(int H)
{
	int Result = 0;
	if (N >= 2)
	{
		int current = Students[0];
		int after = Students[1];
		if (abs(current - after) > H)
			++Result;
	}

	for (unsigned int i = 1; i < N; ++i)
	{
		int before = Students[i - 1];
		int current = Students[i];
		int after = Students[i + 1];

		if (abs(current - before) > H || abs(current - after) > H)
			++Result;
	}

	return Result;
}

void BSearch(int low, int high)
{
	if (low > high)
		return;

	int mid = (low + high) / 2;	// H를 대변하는 값, 현재 계산하는 H를 의미
	// 가장 낮은 mid를 찾기.
	int count = CheckTired(mid);

	// 여유가 됨, H 키워보기
	if (K < count)
		BSearch(mid + 1, high);
	else
	{
		// 지친 사람 초과, H 줄여보기
		SolveResult = min(SolveResult, mid);
		BSearch(low, mid - 1);
	}
	// 사실상 0 ~ 21억을 다 찾을 수 없으니 H 값만 반으로 잘라가며 비교하는 것
}

int Solve()
{	
	BSearch(0, INT_MAX);
	return SolveResult;
}
int main()
{
	cin >> N >> K;	// 학생수, 지친 사람수
	Students.resize(N + 1);
	for (int i = 0; i < N; ++i)
	{
		cin >> Students[i];
	}
	Students[N] = Students[N - 1];	// 끝 학생 계산 편하게 하기 위한 더미값

	cout << Solve();
}