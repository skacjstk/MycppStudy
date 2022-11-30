#include <iostream>
#include <vector>

std::vector<std::vector<char>> arr;	// 이중 벡터(배열, 종이 크기) 
std::vector<std::vector<bool>> visited;	// 방문 검사할 -> 필요 없나?

int N, M;

int dx[] = { -1,1,0,0 };		// x축 왼쪽, 오른쪽
int dy[] = { 0,0,-1,1 };		// y축 위, 아래

int maxDepth = 10;

// 필요 할까??
// 코인의 y 좌표
int coinY[2];
// 코인의 x 좌표
int coinX[2];




int result = 9999;	// 최대값을 넣야아 함


// 동전 떨어진 갯수, 깊이
void DFS(int fallCoinNum, int depth)
{
	// 이쪽은 실패한거임 10번 초과 시도하거나, 한번에 두개가 떨어졌으니까
	if (depth >= maxDepth || fallCoinNum == 2) {
		return;
	}
	else if (fallCoinNum == 1) {
		result = std::min(result, depth);
	}
	// 실질적인 DFS 수행 부
	else {

		// 코인 이전 위치( 여기 들어왔을 때 위치 )
		int beforeX[2];
		int beforeY[2];

		// 이전 위치 기록 (무조건 해야 함)
		beforeX[0] = coinX[0];
		beforeY[0] = coinY[0];

		beforeX[1] = coinX[1];
		beforeY[1] = coinY[1];

		// 4방향으로 이동 시도
		for (int i = 0; i < 4; ++i) {
			// 검사용 코인 위치
			int newX;
			int newY;

			// 확정된 새 코인 위치
			int newCoinY[2];
			int newCoinX[2];

			// k번 코인의 새 위치
			for (int k = 0; k < 2; ++k) {
				newX = coinX[k] + dx[i];
				newY = coinY[k] + dy[i];
				

				// 떨어진 경우
				if (newX < 0 || newX >= M || newY < 0 || newY >= N) {
					++fallCoinNum;	// 떨어진 코인 수 증가
					continue;
				}
				else if (arr[newY][newX] == '#')
					continue;
				// 성공: 2가지 경우의 수 검사
				else
				{
					// 코인 새 위치 기록
					newCoinX[k] = newX;
					newCoinY[k] = newY;

					// 코인 새 위치 반영 ( 범위 벗어나도 상관없다 {위험하긴 하다} )
					coinX[k] = newX;
					coinY[k] = newY;
				}//endif


			} //end for


			// 새 위치로 옮기기는 했음.
			DFS(fallCoinNum, depth + 1);
			coinX[0] = beforeX[0];
			coinY[0] = beforeY[0];

			coinX[1] = beforeX[1];
			coinY[1] = beforeY[1];
		}//endfor
	}//endif
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
	char pin;
	int coinNum = 0;
	// y축
	for (int i = 0; i < N; ++i) {
		// x축
		for (int j = 0; j < M; ++j) {

			std::cin >> arr[i][j];

			// 코인 위치 기록
			if (arr[i][j] == 'o') {
				coinY[coinNum] = i;
				coinX[coinNum] = j;
				coinNum++;
			}
		}
	}

	// 입력 다받았으면 동전 각 Move에 따른 동전의 위치를 계산해야 한다.

	DFS(0, 0);	// 10번 초과니까 첫 시도를 0로 해 10번째에서 시도조차 못하게 걸러야 함
	
	// 어떤 경우도 성공하지 못한다면 -1로 바꿈
	if (result == 9999)
		result = -1;

	std::cout << result;

	return 0;
}