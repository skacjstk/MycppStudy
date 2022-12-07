#include <iostream>
#include <vector>

std::vector<int> arr;	// 1차원 벡터
// 잘 생각해보면, 어차피 행이 같으면 무조건 못놓고, 열또한 같으면 못놓으니 단순 if로 검사할 수 있다
// 우리에게 필요한건 대각선을 위한 위치정보


int N;
int maxDepth = 14;

int result = 0;	// 경우의 수 검색이라 0부터 

// 
bool Possibility(int& depth) {
	// 같은 열이면 안되고, 대각선상에 있어서도 안 된다.
	for (int i = 0; i < depth; i++) {
		// 같은 열이면여기서 true가 나옴 || 여긴 한마디로 기울기라 보면 됨. 이 값이 같으면, 기울기가 같은것이니 못씀
		if (arr[depth] == arr[i] || depth - i == abs(arr[depth] - arr[i])) {
			return false;
		}
	}
	return true;

}


void DFS(int depth)
{
	// 깊이 도달시 모든 자리에 퀸을 놓을 수 있음.
	if (depth >= maxDepth) {
		++result;	// 도달 성공시 맞는 것이기에 경우의 수 추가
		return;
	}
	else
	{
		for (int i = 0; i < N; ++i) {
			arr[depth] = i;	// depth 번째 열에 i 번째 행에 Queen을 넣는다.
			if (Possibility(depth)) {	
				DFS(depth + 1);
			}
		}
	}
}

int main(void)
{
	std::cin >> N;
	maxDepth = N;	// 깊이 또한 N으로 설정
	arr.resize(N);
	DFS(0);

	std::cout << result;

	return 0;
}