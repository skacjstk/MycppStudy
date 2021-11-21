#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 100001
int visited[MAX]; //10만 (main함수에 넣으면 스택 16384 바이트 오버
//int beforePos[100001] = { -1, }; //예를들어 bp[10] = 9 일경우 10의 이전 위치가 9
int extract;

queue<pair<int, int>> nodes;

vector<int> path;

bool validCheck(const int& num) {
	if (num > MAX - 1 || num < 0 || visited[num] != -1)
		return false;
	return true;
}

void bfs(const int& k) {
	while (!nodes.empty()) {
		int num = nodes.front().first;
		int time = nodes.front().second;
		nodes.pop();
		//방문결과 반영 시점을 nodes에 집어넣을 때로 변경

		//어차피 중복검사 하고나서, spendTime을 넣기에, 중복된 값이 다시 들어갈 염려는 없으며, 먼저 호출된 놈이 가장 작은 값이기에 걱정 없다.
		if (num == k) { //위치와 같은가?
			extract = time;
			break;
		}
		else {
			if (validCheck(num + 1)) {
				nodes.push({ num + 1,time + 1 });
				visited[num + 1] = num;	//여기에 값이 들어간다는 것 자체가, 방문했다는 증거
			}
			if (validCheck(num - 1)) {
				nodes.push({ num - 1,time + 1 });
				visited[num - 1] = num;
			}
			if (validCheck(num * 2)) {
				nodes.push({ num * 2,time + 1 });
				visited[num * 2] = num;
			}//end if
		}//end if
	}//end while
}
void InitializeVisited() {
	for (int i = 0; i < MAX; ++i) {
		visited[i] = -1; //0~MAX-1 까지 초기화
	}
}
/// <summary>
/// 수빈이가 동생보다 앞에 있다면, -1밖에 없기 때문에 bfs 할 필요가 없다.
/// </summary>
/// <param name="n">수빈이 위치</param>
/// <param name="k">동생 위치</param>
/// <returns></returns>
bool CalEitherCase(int& n, int& k) {
	if (n >= k) {
		cout << n - k << "\n"; //-1밖에 못하니 시간이 딱 그정도
		for (int i = n; i >= k; --i) {
			cout << i << " ";
		}
		return true;
	}
	return false;
}
int main(void)
{
	//수빈, 동생
	int n, k;
	int beforePoint;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	//수빈이가 순간이동 못할때 (n이 k보다 크거나 같을 때)	
	if (!CalEitherCase(n, k)) {

		nodes.push({ n,0 }); //n 자신과 자신의 time(깊이) 삽입
		visited[n] = n;	//n은 방문했음 (자기 자신이 방문한 걸로 취급)

		InitializeVisited(); // -1로 배열 초기화

		bfs(k); //목적지 k를 주고 bfs 수행
		cout << extract << "\n"; //찾기까지의 time(깊이)
		beforePoint = k;
		while (beforePoint != n) { //목적지가 나올때까지 되돌아가기
			path.push_back(beforePoint);
			//	cout << beforePoint << " ";
			beforePoint = visited[beforePoint];
		}
		path.push_back(n);
		reverse(path.begin(), path.end());
		for (int it : path) {
			cout << it << " ";
		}

	}
	return 0;

	//n < k 일 때

	/*
	for (int i = 0; i < 100; ++i) {
		if (i % 10 == 0 && i > 0)
			cout << "\n";

		cout << spendTime[i] <<" ";

	}
	*/
}
/*
1차수정: pair로 교체, 기존 spendTime 개별배열은 뭔가 숫자가 더해짐
2차수정: validCheck 조건을 visited를 먼저 보지 말고, num의 유효성을 먼저 검사하면 된다.

3차수정: visited를 int형으로 바꾸고, -1로 초기화했다. 이전 방문 위치를 저장한다
*/