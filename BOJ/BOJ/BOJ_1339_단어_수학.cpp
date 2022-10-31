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
	int idx; // ���ڿ� ��ȣ���� �ӽ������

	std::cin >> N;

	//��ü �ܾ� �� ó����
	for (int i = 0; i < N; ++i) {
		std::cin >> word;

		digit = pow(10, word.size() - 1);	// ���� ���̰� 5����, 10000���� �����ϵ���...��¶�� ����� 1 �����

		// �� �ܾ� ó����
		for (int k = 0; k < word.size(); ++k) {
			idx = word[k] - 'A';
			alphabet[idx] += digit;

			digit = (int)(digit * 0.1f);	// ���� �ڸ����� 10 ������
		}
	}

	// ���ĺ��� ũ������� �����ϰ�, �ű⿡ 0~9������ ��������
	std::sort(alphabet, alphabet + 26, compare);

	// �ִ밪 9 ~ 0 ���� ���ĺ��� ���� ���ߴ� ���� �־��ֱ�
	for (int i = 9; i >= 0; --i) {
		int idxAlpha = 9 - i;

		result += alphabet[idxAlpha] * i;
	}

	std::cout << result;
	return 0;
}

// ����: https://excited-hyun.tistory.com/145 ( Ǯ�� �κ� ���и� ���� )