#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<bool> Selected;	// index가 선택되었는지
vector<int> Star;	// 해당 칸에 무슨 숫자가 들어갔는지
vector<int> RemainIndex;	//채워야 하는 위치
char Map[5][9];
int Line[6][4] = { {1,2,3,4}, {0,2,5,7}, {0,3,6,10}, {7,8,9,10}, {1,5,8,11}, {4,6,9,11} };
bool Result;

bool CheckSuccess()
{
	// 합 26 검사
	for (int i = 0; i < 6; ++i){
		int Sum = 0;
		for (int j = 0; j < 4; ++j){
			Sum += Star[Line[i][j]] + 1;	// Star에 숫자를 0~11로 저장해놔서
		}
		if (Sum != 26)		
			return false;		
	}
	return true;
}

void DFS(int Depth)
{
	if (Result) return;
	if (Depth == RemainIndex.size())
	{
		Result = CheckSuccess();
		return;
	}

	for (int i = 0; i < 12; ++i)
	{
		if (Selected[i] == false)
		{
			Selected[i] = true;
			Star[RemainIndex[Depth]] = i;
			DFS(Depth + 1);
			Selected[i] = false;
			if (Result)  return;
		}
	}
	return;
}

int main(void)
{
	Selected.resize(12, false);
	Star.resize(12, 0);

	for (int i = 0; i< 5; ++i){
		for (int j = 0; j < 9; ++j){
			cin >> Map[i][j];
			if (Map[i][j] >= 'A' && Map[i][j] <= 'Z'){
				int SelectedNum = Map[i][j] - 'A';
				Selected[SelectedNum] = true;
			}
		}
	}
	//Star 0~12 까지 입력
	Star[0] = Map[0][4] - 'A';	
	for (int i = 1; i <= 4; i++)
	{
		Star[i] = Map[1][(i * 2) - 1] - 'A';
		Star[(size_t)i + 6] = Map[3][(i * 2) - 1] - 'A';
	}
	Star[5] = Map[2][2] - 'A';
	Star[6] = Map[2][6] - 'A';
	Star[11] = Map[4][4] - 'A';

	for (int i = 0; i < 12; ++i) {
		if (Star[i] == 'x' - 'A')	// 0 4 5 6 7 8 9 10 11
			RemainIndex.push_back(i);
	}

	DFS(0);
	// Map에 재주입
	Map[0][4] = Star[0] + 'A';
	for (int i = 1; i <= 4; i++)
	{
		Map[1][(i * 2) - 1] = Star[i] + 'A';
		Map[3][(i * 2) - 1] = Star[(size_t)i + 6] + 'A';
	}
	 Map[2][2] = Star[5] + 'A';
	 Map[2][6] = Star[6] + 'A';
	 Map[4][4] = Star[11] + 'A'; 

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << Map[i][j];			
		}
		cout << endl;
	}

	return 0;
}