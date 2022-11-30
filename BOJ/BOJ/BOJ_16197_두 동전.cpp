#include <iostream>
#include <vector>

std::vector<std::vector<char>> arr;	// 이중 벡터(배열, 종이 크기) 
// 방문검사 취소: 무한반복도 depth 10에서 끝남

int N, M;

int dx[] = { -1,1,0,0 };		// x축 왼쪽, 오른쪽
int dy[] = { 0,0,-1,1 };		// y축 위, 아래

int maxDepth = 10;
std::vector<std::pair<int, int>> coinDir;

int result = 9999;	// 최대값을 넣야아 함

// 
bool IsCoinFall(int &x, int &y) {

	if (x < 0 || x >= M || y < 0 || y >= N) return true;
	return false;
}

// 0 = 떨어지는 위치, 1 = 블로킹 위치, 2 = 정상 이동 가능
int IsBlocking(int& x, int& y) {
	if (IsCoinFall(x, y))
		return 0;

	else if (arr[y][x] == '#') return 1;
	return 2;
}

// 1번동전 좌표, 2번동전 좌표, 현재 깊이
void DFS(int x1, int y1, int x2, int y2, int depth)
{
	// 깊이 초과 10번까진 괜찮은데 11번부터 안돼 (index 0 ~ 9)
	if (depth >= maxDepth)
		return;
	else
	{	
		for (int i = 0; i < 4; ++i) {
			int nX = x1 + dx[i];
			int nY = y1 + dy[i];

			int coinFall = 0;

			// 다음 진행 위치에 대한 예측
			// 0 = 떨어지는 위치, 1 = 블로킹 위치, 2 = 정상 이동 가능
			switch (IsBlocking(nX, nY)) {
			case 0:
				coinFall++;
				break;
			case 1:
				nX = x1;
				nY = y1;
				break;
			}

			int nnX = x2 + dx[i];
			int nnY = y2 + dy[i];

			switch (IsBlocking(nnX, nnY)) {
			case 0:
				coinFall++;
				break;
			case 1:
				nnX = x2;
				nnY = y2;
				break;
			}

			// 둘다 떨어지면 이 경우의 수 폐기
			switch (coinFall)
			{
			case 0:
				break;
			case 1:
				result = std::min(result, depth + 1);
				continue;
			case 2:
				continue;
			}
			if (coinFall == 2) {
				continue;
			}

			// 결정된 새 위치로 DFS 수행하기
			DFS(nX, nY, nnX, nnY, depth + 1);
		}
	}
}

int main(void)
{
	std::cin >> N >> M;

	arr.resize(N);
	for (int i = 0; i < N; ++i) {
		arr[i].resize(M);
	}
	// 2차원 배열 크기할당
	char pin;
	int coinNum = 0;
	// y축
	for (int i = 0; i < N; ++i) {
		// x축
		for (int j = 0; j < M; ++j) {

			std::cin >> arr[i][j];

			// 코인 위치 기록
			if (arr[i][j] == 'o') {
				coinDir.push_back(std::make_pair(j,i));
			}
		}
	}

	DFS(coinDir[0].first, 
		coinDir[0].second,
		coinDir[1].first,
		coinDir[1].second,
		0);
	
	// 어떤 경우도 성공하지 못한다면 -1로 바꿈
	if (result == 9999)
		result = -1;

	std::cout << result;

	return 0;
}