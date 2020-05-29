#include <iostream>

using namespace std;

void findString(string parent, string pattern) {
	int parentSize = parent.size(); // ��ü �� �� ������ 
	int patternSize = pattern.size(); // ã�ƾ��ϴ� �κ� ���ڿ� ������ 

	int parentHash = 0, patternHash = 0; // ���� hash �� �ʱ�ȭ
	int power = 1; // �������� �ǹ�(ó���� 2��0��)

	for (int i = 0; i <= parentSize - patternSize; i++) {
		// ���� ó�� �ʱ�ȭ 
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;

				// ���� ���ڿ��� ������ ���� j�� �۴ٸ� 2�� �����ֶ�� �� 
				if (j < patternSize - 1) {
					power *= 2;
					//power *= 403; // MOD(������ ����)
				}
			}
		} //endif		���ڿ��� ���� ù �ؽð� �ϼ� 
		else {
			// �� �� �ؽð� = 2 * (���� �� �� �ؽð� - ���� ���� ��) + ���� �߰��� ������ �ؽð�
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];

			// MOD(����������)
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
				printf("%d�� °���� �߰��߽��ϴ�\n", i + 1);
			}
		}
		//printf("�ؽ� �� ��: %d %d\n", parentHash, patternHash);
	}
}

int main(void) {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";

	findString(parent, pattern);

	return 0;
}