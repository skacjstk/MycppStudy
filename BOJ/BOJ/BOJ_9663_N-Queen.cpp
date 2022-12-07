#include <iostream>
#include <vector>

std::vector<int> arr;	// 1���� ����
// �� �����غ���, ������ ���� ������ ������ ������, ������ ������ �������� �ܼ� if�� �˻��� �� �ִ�
// �츮���� �ʿ��Ѱ� �밢���� ���� ��ġ����


int N;
int maxDepth = 14;

int result = 0;	// ����� �� �˻��̶� 0���� 

// 
bool Possibility(int& depth) {
	// ���� ���̸� �ȵǰ�, �밢���� �־�� �� �ȴ�.
	for (int i = 0; i < depth; i++) {
		// ���� ���̸鿩�⼭ true�� ���� || ���� �Ѹ���� ����� ���� ��. �� ���� ������, ���Ⱑ �������̴� ����
		if (arr[depth] == arr[i] || depth - i == abs(arr[depth] - arr[i])) {
			return false;
		}
	}
	return true;

}


void DFS(int depth)
{
	// ���� ���޽� ��� �ڸ��� ���� ���� �� ����.
	if (depth >= maxDepth) {
		++result;	// ���� ������ �´� ���̱⿡ ����� �� �߰�
		return;
	}
	else
	{
		for (int i = 0; i < N; ++i) {
			arr[depth] = i;	// depth ��° ���� i ��° �࿡ Queen�� �ִ´�.
			if (Possibility(depth)) {	
				DFS(depth + 1);
			}
		}
	}
}

int main(void)
{
	std::cin >> N;
	maxDepth = N;	// ���� ���� N���� ����
	arr.resize(N);
	DFS(0);

	std::cout << result;

	return 0;
}