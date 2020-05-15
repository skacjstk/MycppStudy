#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#define MAX 1000 

/*
typedef struct _sharkData {
	int Ssize;
	int	speed;
	int	intel;
	
	_sharkData(int _size, int _speed, int _intel) :
	Ssize(_size), speed(_speed), intel(_intel){}

}sharkData;
*/

//std::vector<std::vector<sharkData>> node;	//원소가 담기는 곳

int sharkNode[MAX][3];
std::vector<bool> visited;	//방문검사
int b[MAX +1]; //i번째 작업과 매칭된 b[i]번째 사람.
std::vector<int> node[MAX];

bool dfs(int here) {
	for (int there : node[here]) { .//고정배열이니까 이렇게하면 안됌
		if (visited[there]) //return 0;
			continue;

		visited[there] = true;
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return true;
		}
	}

	return false;

}

int bmatch(const int sharkNum) {
	int ret = sharkNum;

	


	return ret;
}

void testCase() {
	int sharkNum;
	scanf("%d", &sharkNum);
	//상어 메모리 초기화  
	for (int i = 1; i <= sharkNum; ++i) {
		scanf("%d %d %d", &sharkNode[i][0], &sharkNode[i][1], &sharkNode[i][2]); //상어 크기 속도 지능
	}
	//데이터 입력 완료
	printf("%d", bmatch(sharkNum));
}

int main(void)
{
	testCase();
	return 0;

}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#define MAX 1000
std::vector<std::vector<int>> node;	//원소가 담기는 곳
std::vector<bool> visited;	//방문검사
int b[MAX +1]; //i번째 작업과 매칭된 b[i]번째 사람.

bool dfs(int here) {
	for (int there : node[here]) {
		if (visited[there]) //return 0;
			continue;

		visited[there] = true;
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return true;
		}
	}

	return false;

}

int bmatch(const int cow) {
	int ret = 0;
	for (int i = 1; i <= cow; ++i) {
		for (int j = 0; j < 2; ++j) {
			visited.clear();
			visited.resize(MAX + 1, false);	//여길 cow +1 하면 틀린다. 왜지?
			if (dfs(i)) ret++;
		}
	}

	return ret;
}

void testCase() {
	int cow, cage;
	scanf("%d %d", &cow, &cage);

	node.resize(cow + 1, std::vector<int>());

	int wantNum;
	int cageNum;
	for (int n = 1; n <= cow; ++n) {
		scanf("%d", &wantNum);
		for (int i = 0; i < wantNum; ++i) {
			scanf("%d", &cageNum);
			node[n].push_back(cageNum);
		}
	}
	//데이터 입력 완료
	printf("%d", bmatch(cow));
}

int main(void)
{
	testCase();
	return 0;

}
*/