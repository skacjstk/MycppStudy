#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>

#define INT_MAX       2147483647

bool IsNearer(int Amid, int Nearest, int find)
{
	if (abs(Amid - find) < abs(Nearest - find)) 
		return true;
	return false;
}

int BSearch_Near(const std::vector<int>& A, int find) {
	int left = 0;
	int right = A.size()-1;
	int mid = (left + right) / 2;

	int Nearest = A[mid];

	while (left <= right) {
		mid = (left + right) / 2;
		if (A[mid] == find)
			return find;

		if (A[mid] < find) {
			left = mid + 1;
		}
		else if (A[mid] > find) {
			right = mid - 1;
		}
		if (IsNearer(A[mid], Nearest, find))
			Nearest = A[mid];
	}
	return Nearest;
}	


int main(void)
{
	int Anum, Bnum, Cnum;

	std::vector<int> APlayer, BPlayer, CPlayer;

	std::cin >> Anum >> Bnum >> Cnum;
	APlayer.resize(Anum);
	BPlayer.resize(Bnum);
	CPlayer.resize(Cnum);

	for (int i = 0; i < Anum; ++i)	
		std::cin >> APlayer[i];
	
	for (int i = 0; i < Bnum; ++i)	
		std::cin >> BPlayer[i];
	
	for (int i = 0; i < Cnum; ++i)	
		std::cin >> CPlayer[i];
	
	std::sort(APlayer.begin(), APlayer.end());
	std::sort(BPlayer.begin(), BPlayer.end());
	std::sort(CPlayer.begin(), CPlayer.end());

	int SelectNum[3];

	int SelectNumDiff;

	int CompareNum1, CompareNum2;
	
	int Result = INT_MAX;
	for (int i = 0; i < APlayer.size(); ++i)
	{
		SelectNum[0] = APlayer[i];
		SelectNum[1] = BSearch_Near(BPlayer, SelectNum[0]);	// 첫번째
		SelectNum[2] = BSearch_Near(CPlayer, SelectNum[0]);	// 첫번째
		SelectNumDiff = BSearch_Near(CPlayer, SelectNum[1]); // 두번째

		CompareNum1 = std::max(std::max( SelectNum[0], SelectNum[1]), SelectNum[2]) 
			- std::min(std::min(SelectNum[0], SelectNum[1]), SelectNum[2]);

		CompareNum2 = std::max(std::max(SelectNum[0], SelectNum[1]), SelectNumDiff)
			- std::min(std::min(SelectNum[0], SelectNum[1]), SelectNumDiff);

		Result = std::min(std::min(CompareNum1, CompareNum2), Result);
	}

	std::cout << Result;
	return 0;
}