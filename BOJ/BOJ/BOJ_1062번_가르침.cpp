#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool alphabet[26] = { false, };
std::vector<std::string> words;

int N, K;	// N은 단어 갯수, K는 알파벳을를 읽을 수 있는 수
int answer = 0;

int NumOfReadWords()
{
	bool successReadWord = false;		// 단어 읽기 성공 파악용
	bool successReadAlphabet = false;	// 알파벳 읽기 성공 파악용
	int readalphaBet = 0;				// 읽은 단어의 수를 반환하는 변수

	// 단어 순회하며 배울 수 있는 단어의 수 반환하기 갯수 구하기
	for (int j = 0; j < words.size(); ++j) {
		successReadWord = true;
		for (int i = 0; i < words[j].size(); ++i) {
			successReadAlphabet = alphabet[words[j][i] - 'a'] & true;
			// AND 연산으로 false 반환시, 배운적 없는 알파벳의 단어, 즉 단어읽기 실패
			if (successReadAlphabet == false) {
				successReadWord = false;
				break;	// 다음 알파벳을 볼 필요도 없다.
			}
		}	// endfor
		if (successReadWord == true) {
			++readalphaBet;
		}
	} // endfor
	return readalphaBet;	// 함수 끝
}
/// <summary>
/// DFS
/// </summary>
/// <param name="numOfReadAlphabet"> 읽은 알파벳의 갯수(K-5).</param>
/// <param name="index">DFS 깊이 인덱스, 반복문에서 i를 받아 재귀하게 된다.</param>
void DFS(int numOfReadAlphabet, int index)
{

	if (numOfReadAlphabet == K)	// 배울 수 있는만큼 알파벳을 배웠을 때
	{
		answer = std::max(NumOfReadWords(), answer);	// 그 상태에서 읽을 수 있는 단어의 수를 파악한다.
		return;
	}
	// 알파벳 배우기
	for (int i = index; i < 26; ++i) {
		if (alphabet[i] == true) continue;
		alphabet[i] = true;
		DFS(numOfReadAlphabet + 1, i);	// false 였으면 배운거니까, 배운 알파벳 갯수를 + 1 하고, i를 넘겨 다음 분기로
		alphabet[i] = false;
	}
}

void Solution() {
	// anta tica 는 기본적으로 true 바꿔놓기
	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	K = K - 5;	// 이미 5개를 읽은 상태
	DFS(0, 0);
	std::cout << answer << "\n";	// answer을 출력하고 탈출
}

int main(void)
{
	std::cin >> N >> K;
	words.resize(N);

	for (int i = 0; i < N; ++i) {
		// 단어 자체를 잘라서 저장하는게 최적화하기 좋은데 나중에 하자.
		std::cin >> words[i];	// resize를 해놔서 직접 접근 가능.
	}
	// K가 5보다 작으면 하나도 못읽는거임.
	if (K < 5)
		std::cout << 0 << "\n";	// 0을 출력하고 탈출
	// K가 26이면 모두 배울 수 있는거임
	else if (K == 26)
	{
		std::cout << N << "\n";
	}
	// 본격적인 단어탐색 수행
	else 
		Solution();	

	return 0;
}