#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::string;

string ModifyString;
string OriginString;

int Modify[26] = { 0, };
int Origin[26] = { 0, };


void ClearVariable()
{
	std::fill_n(Modify, 26, 0);
	std::fill_n(Origin, 26, 0);
}

bool CheckArray()
{
	for (int i = 0; i < 26; ++i)
	{
		if (Origin[i] != Modify[i])	// 서로의 갯수가 동일한지
			return false;
		else
			continue;
	}
	return true;
}

bool CheckVarify()
{
	ClearVariable();
	int index = 0;
	int OriginLength = 0;
	int ModifySum = 0;
	int OriginSum = 0;

	OriginLength = OriginString.length();
	for (int i = 0; i < OriginLength; ++i)
	{
		index = OriginString[i] - 'a';
		Origin[index] += 1;
		OriginSum = OriginSum + index + 1;	// 합치는 값은 변별을 위해 1 ~ n으로 

		// 슬라이딩 윈도우, 첫 값 설정을 위한 부분
		index = ModifyString[i] - 'a';
		Modify[index] += 1;
		ModifySum = ModifySum + index + 1;
	}

	unsigned int First;
	for (unsigned int Last = OriginLength; Last < ModifyString.length(); ++Last)
	{
		if (ModifySum == OriginSum)
		{
			if (CheckArray() == true)
				return true;
		}
		First = Last - OriginLength;
		index = ModifyString[First] - 'a';
		Modify[index] -= 1;
		ModifySum = ModifySum - index - 1;

		index = ModifyString[Last] - 'a';
		Modify[index] += 1;
		ModifySum = ModifySum + index + 1;		
	}

	if (ModifySum == OriginSum)
	{
		if (CheckArray() == true)
			return true;
	}
	return false;

}

int main()
{
	int N;
	vector<bool> Answers;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> ModifyString;
		cin >> OriginString;
		Answers.push_back(CheckVarify());
	}

	for (bool answer : Answers)
	{
		if (answer == true)
			cout << "YES" << std::endl;
		else
			cout << "NO" << std::endl;
	}
	return 0;
}