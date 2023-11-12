#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string IDCode, CompareSubstr;
int RegionCount;
vector<int> RegionCodes;	// IDCode에서 stoi로 변환

bool CheckDay(int year, int month, int day)
{
	// 윤년에 따른 28,29,30,31 구분
	// 해당 day 가 유효하다면 true 반환
	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
			return day <= 30;
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
			return day <= 31;
		break;
	case 2:	// 대망의 윤년
	{
		bool IsLeapYear = false;
		if (year % 400 == 0 && year % 100 != 0 && year % 4 == 0)
			IsLeapYear = true;

		if (IsLeapYear == true)
			return day <= 29;
		else
			return day <= 28;
	}
	default:
		return false;
		break;
	}
}

string Solve()
{
	string Result = "I";
	bool RegionCheck = false;

	// 지역 무결성
	CompareSubstr = IDCode.substr(0, 6);
	int OriginCode = stoi(CompareSubstr);
	for (int Code : RegionCodes)
	{
		if (Code == OriginCode)
		{
			RegionCheck = true;
			break;
		}
	}
	
	if (RegionCheck == false)
		return Result;

	// 생일 무결성 
	CompareSubstr = IDCode.substr(6, 4);
	int OriginYear = stoi(CompareSubstr);
	CompareSubstr = IDCode.substr(10, 2);
	int OriginMonth = stoi(CompareSubstr);
	CompareSubstr = IDCode.substr(12, 2);
	int OriginDay = stoi(CompareSubstr);

	if (OriginYear < 1900 || OriginYear > 2011)
		return Result;
	else if (OriginMonth < 1 || OriginMonth > 12)
		return Result;
	else if (OriginDay < 1 || !CheckDay(OriginYear, OriginMonth, OriginDay))
		return Result;

	// 체크섬 코드 무결성
	CompareSubstr = IDCode.substr(17, 1);

	int CheckSumCode;
	if (CompareSubstr == "X")
		CheckSumCode = 10;
	else
		CheckSumCode = stoi(CompareSubstr);

	int CheckSumVarifyCode = CheckSumCode;
	for (int i = 17; i >= 1 ; --i)	 // 1 ~ 17
	{
		CheckSumVarifyCode += stoi(IDCode.substr(17 - i, 1)) * pow(2, i);
		CheckSumVarifyCode %= 11;
	}
	if (CheckSumVarifyCode % 11 != 1)
		return Result;

	// 성별 
	CompareSubstr = IDCode.substr(14, 3);
	if (CompareSubstr == "000")
		return Result;

	int OriginSex = stoi(CompareSubstr);
	if (OriginSex % 2 == 0)
		Result = "F";	// 짝수여자
	else
		Result = "M";
	return Result;
}

int main(void)
{
	cin >> IDCode;
	cin >> RegionCount;
	RegionCodes.resize(RegionCount);

	for (int i = 0; i < RegionCount; ++i)
	{
		cin >> RegionCodes[i];
	}

	cout << Solve();
	return 0;
}