#include <iostream>
#include <vector>
#define TETROSIZE maxDepth 

std::vector<std::vector<int>> arr;	// 이중 벡터(배열, 종이 크기) 
std::vector<std::vector<bool>> visited;	// 방문 검사할 

int N, M;

int maxDepth = 4;

int dx[] = { -1,1,0,0 };		// x축 왼쪽, 오른쪽
int dy[] = { 0,0,-1,1 };		// y축 위, 아래

// 상좌하우 모양 방향 좌표 안내용
// 시작 좌표(0번 index)기준 상대좌표 ㅗ ㅏ ㅜ ㅓ 순서
int ox[4][4] = { {0,1,2,1}, {0,0,0,1}, {0,-1,-2,-1}, {0,0,0,-1} };
int oy[4][4] = { {0,0,0,-1}, {0,1,2,1}, {0,0,0,1}, {0,-1,-2,-1} };

int result = 0;	// 최소값을 넣어놔야 함.

// 테트로미노의 블록 수가 모두 4개
// ㅗ 같은 특이한 모양을 제외하면, 일반적인 DFS 수행시 나올 수 있는 모양
// 예를 들어 ㄱ 블록은 ㅣ 블록의 DFS 수행 중 3번째 index에서 반대 방향으로 뻗어나가면 생길 수 있는 경우의 수 
// 그래서 ㅗ를 제외하고 마치 일반 DFS처럼 수행 가능
void DFS(int x, int y, int sum, int depth)
{

	// 0, 1, 2, 3 탐색하고 4되면 반환
	if (depth >= TETROSIZE) {
//		printf("깊이:%d \t값: %d %d\n", depth, sum, result);
		result = std::max(result, sum);
		return;
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];

			// 지도 범위 검사 
			// 범위 벗어나면 DFS 생략( 이 회전에서 이 값을 상정하지 않음. )
			if (newX < 0 || newX >= M || newY < 0 || newY >= N ) continue;

			// 미방문시 다음 영역 탐색
			if (!visited[newY][newX]) {
				visited[newY][newX] = true;

				//	덧셈이 이 for 내부에서 저장되는걸 막기 위해 인자로 같이 전달
				DFS(newX, newY, sum + arr[newY][newX], depth + 1);
				visited[newY][newX] = false;
			}//endif
		}//endfor
	}//endif
}


// ㅗ 를 위한 특수 처리
// x, y 에서의 ㅗ, ㅏ , ㅜ, ㅓ 모양을 각각 검사해서 result에 std::max 대입함
void CheckOtherShape(int x, int y)
{
	bool isValid = true;	// 이 위치에서의 모양이 유효한지

	// 4번 돌때 
	for(int k = 0; k < 4; ++k){	// 경우의 수
		isValid = true;	// 이게 유지되면 유효한 범위
		int sum = 0;	// 합
		for (int i = 0; i < 4; ++i) {	// 값
			int newX = x + ox[k][i];
			int newY = y + oy[k][i];

			// 지도 범위 검사 
			// 범위 벗어나면 해당 모양 사용하지 않음
			if (newX < 0 || newX >= M || newY < 0 || newY >= N) {
				isValid = false; 
				break;
			}
			// 방문 검사가 필요 없음
			sum = sum + arr[newY][newX];	// 덧셈하기

		}//endif
		if(isValid)
			result = std::max(result, sum);	// 위에서 continue가 호출되면 얘까지 안옴.
	}
}

int main(void)
{
	std::cin >> N >> M;

	arr.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; ++i) {
		arr[i].resize(M);
		visited[i].resize(M);
	}
	// 2차원 배열 크기할당

	// y축
	for (int i = 0; i < N; ++i) {
		// x축
		for (int j = 0; j < M; ++j) {
			std::cin >> arr[i][j];
		}
	}

	// 입력 다받았으면 모든 점에서 모양에 걸맞는 DFS를 수행한다
	for (int i = 0; i < N; ++i) {	// y축
		for (int j = 0; j < M; ++j) {	// x축
			visited[i][j] = true;
			DFS(j, i, arr[i][j], 1);	// 이 값이 유효하면, depth 1에서 시작해야 맞음
			visited[i][j] = false;

			// ㅗ ㅏ ㅜ ㅓ 전용 검사
			CheckOtherShape(j, i);

		}
	}
	std::cout << result;

	return 0;
}