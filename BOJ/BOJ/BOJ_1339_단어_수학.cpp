#include <iostream>
#include <algorithm>
#include <cmath>

bool compare(int a, int b) { return a > b; }
int main(void)
{
	int N = 0, result = 0;
	int digit = 0;
	std::string word;
	int alphabet[26] = { 0, };
	int idx; // 문자열 번호추출 임시저장용

	std::cin >> N;

	//전체 단어 들 처리중
	for (int i = 0; i < N; ++i) {
		std::cin >> word;

		digit = pow(10, word.size() - 1);	// 글자 길이가 5개면, 10000부터 시작하듯이...어쨋든 사이즈를 1 빼줘야

		// 한 단어 처리중
		for (int k = 0; k < word.size(); ++k) {
			idx = word[k] - 'A';
			alphabet[idx] += digit;

			digit = (int)(digit * 0.1f);	// 이제 자릿수를 10 나눠줌
		}
	}

	// 알파벳을 크기순으로 정렬하고, 거기에 0~9까지를 결정해줌
	std::sort(alphabet, alphabet + 26, compare);

	// 최대값 9 ~ 0 까지 알파벳의 수를 곱했던 값을 넣어주기
	for (int i = 9; i >= 0; --i) {
		int idxAlpha = 9 - i;

		result += alphabet[idxAlpha] * i;
	}

	std::cout << result;
	return 0;
}

// 참고: https://excited-hyun.tistory.com/145 ( 풀이 부분 수학만 봤음 )