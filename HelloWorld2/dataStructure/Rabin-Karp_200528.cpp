#include <iostream>

using namespace std;

void findString(string parent, string pattern) {
	int parentSize = parent.size(); // 전체 긴 글 사이즈 
	int patternSize = pattern.size(); // 찾아야하는 부분 문자열 사이즈 

	int parentHash = 0, patternHash = 0; // 각각 hash 값 초기화
	int power = 1; // 제곱수를 의미(처음은 2의0승)

	for (int i = 0; i <= parentSize - patternSize; i++) {
		// 제일 처음 초기화 
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;

				// 패턴 문자열의 사이즈 보다 j가 작다면 2씩 곱해주라는 뜻 
				if (j < patternSize - 1) {
					power *= 2;
					//power *= 403; // MOD(나머지 연산)
				}
			}
		} //endif		문자열에 대한 첫 해시값 완성 
		else {
			// 긴 글 해시값 = 2 * (이전 긴 글 해시값 - 가장 앞의 수) + 새로 추가된 문자의 해시값
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];

			// MOD(나머지연산)
			// parentHash = 403 * (parentHash - parent[i-1] * power) + parent[patternSize - 1 + i];
		}

		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
					break;
				}
			}
			if (finded) {
				printf("%d번 째에서 발견했습니다\n", i + 1);
			}
		}
		//printf("해시 값 비교: %d %d\n", parentHash, patternHash);
	}
}

int main(void) {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";

	findString(parent, pattern);

	return 0;
}