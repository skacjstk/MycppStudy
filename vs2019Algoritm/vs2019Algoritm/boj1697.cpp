#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> nodes;
bool visited[100001]; //10만 (main함수에 넣으면 스택 16384 바이트 오버
int extract;

bool validCheck(const int& num) {
	if (num > 100000 || num < 0 || visited[num])
		return false;
	return true;
}

void bfs(const int& k) {
	while (!nodes.empty()) {
		int num = nodes.front().first;
		int time = nodes.front().second;
		nodes.pop();
		visited[num] = true;
		
		//어차피 중복검사 하고나서, spendTime을 넣기에, 중복된 값이 다시 들어갈 염려는 없으며, 먼저 호출된 놈이 가장 작은 값이기에 걱정 없다.
		if (num == k) { //위치와 같은가?
			extract = time;
			break;
		}
		else {
			if (validCheck(num + 1)){
				nodes.push({ num + 1,time + 1 });
			}
			if (validCheck(num - 1)){
				nodes.push({ num - 1,time + 1 });
			}
			if (validCheck(num * 2)){
				nodes.push({ num * 2,time + 1 });
			}//end if
		}//end if
	}//end while
}

int main(void)
{
	int n, k;	
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	nodes.push({ n,0 });
	visited[n] = true;	//n은 방문했음

	bfs(k);


	cout << extract;

	/*
	for (int i = 0; i < 100; ++i) {
		if (i % 10 == 0 && i > 0)
			cout << "\n";

		cout << spendTime[i] <<" ";

	}
	*/
	return 0;
}
/*
1차수정: pair로 교체, 기존 spendTime 개별배열은 뭔가 숫자가 더해짐
2차수정: validCheck 조건을 visited를 먼저 보지 말고, num의 유효성을 먼저 검사하면 된다.
*/