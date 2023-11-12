#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string IDCode, CompareSubstr;
int RegionCount;
vector<int> RegionCodes;	// IDCode���� stoi�� ��ȯ

bool CheckDay(int year, int month, int day)
{
	// ���⿡ ���� 28,29,30,31 ����
	// �ش� day �� ��ȿ�ϴٸ� true ��ȯ
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
	case 2:	// ����� ����
	{
		bool IsLeapYear = false;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
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

	// ���� ���Ἲ
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

	// ���� ���Ἲ 
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

	// üũ�� �ڵ� ���Ἲ
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

	// ���� 
	CompareSubstr = IDCode.substr(14, 3);
	if (CompareSubstr == "000")
		return Result;

	int OriginSex = stoi(CompareSubstr);
	if (OriginSex % 2 == 0)
		Result = "F";	// ¦������
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