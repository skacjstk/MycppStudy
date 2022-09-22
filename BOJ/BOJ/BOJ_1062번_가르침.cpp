#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool alphabet[26] = { false, };
std::vector<std::string> words;

int N, K;	// N은 단어 갯수, K는 알파벳을를 읽을 수 있는 수
int answer = 0;

// 한 문자열에서 한글자씩 단어를 읽어내는 함수
// currentReadAlphabet: 현재까지 읽은 알파벳의 수를 의미합니다. K보다 클 수 없습니다.
// currentReadWord: 현재까지 읽은 단어의 수, 마지막 단어를 읽고나면 
// depth: DFS 깊이를 의미합니다. 현재는 words 벡터의 index로 사용됩니다.
void DFS(int currentReadAlphabet, int currentReadWord, int depth)
{

	if (depth >= N)	// 같아지면 다 읽은 것
	{
		answer = std::max(currentReadWord, answer);	// 자신이 읽은 Read수를 넘기고 끝낸다.
		return;
	}
	// 단어 읽기
	std::vector<int> readableAlphabetIndex;	// 한꺼번에 읽게 하기
	bool successRead = true;	// 읽기 성공했는지 확인하는 flag 변수
	for (int i = 0; i < words[depth].size(); ++i) {		
		// bool 비트를 마스킹했을 때, 뭐가 나오면 새로배우는 단어
		bool newBet = alphabet[words[depth][i] - 'a'] & true;
		if (newBet == false)	//AND 연산으로 false가 나오면 배운적 없는 단어
		{
			// 1. 나중에 true 변화시킬 index를 가져오기
			readableAlphabetIndex.push_back((int)(words[depth][i] - 'a'));
			alphabet[words[depth][i] - 'a'] = true;	// 이거 실패시 false로 바꿔줘야 함.
			// 2. currentReadAlphabet을 1 더하기, 알파벳을 하나 더 읽은 것
			++currentReadAlphabet;
			// 3. 읽을 수 있는 단어의 갯수를 초과하면, 단어 읽기 실패, 반복문 중단
			if (currentReadAlphabet > K)
			{
				successRead = false;	// 이 단어는 읽기 실패한 것
				break;
			}
		}
	}	// endfor

	//단어 읽기 성공시: 성공수 + 1 로 깊게
	if (successRead == true)
	{
		for (int& it : readableAlphabetIndex) {
			alphabet[it] = true;	// 단어를 읽은 것
		}
		DFS(currentReadAlphabet, currentReadWord + 1, depth + 1);
	}//endif

	// 단어 읽기 실패시: 성공수 + 0으로 깊게
	// 얘가 antatica를 지워버릴 수 있나?
	for (int& it : readableAlphabetIndex) {
		alphabet[it] = false;	// 이제 단어 안읽은거임
	}
	DFS(currentReadAlphabet, currentReadWord, depth + 1);
}

void Solution() {
	// anta tica 는 기본적으로 true 바꿔놓기
	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	K = K - 5;	// 이미 5개를 읽은 상태
	DFS(0, 0, 0);
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