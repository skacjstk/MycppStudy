#include <iostream>
#include <vector>

std::vector<std::vector<char>> arr;	// ���� ����(�迭, ���� ũ��) 
// �湮�˻� ���: ���ѹݺ��� depth 10���� ����

int N, M;

int dx[] = { -1,1,0,0 };		// x�� ����, ������
int dy[] = { 0,0,-1,1 };		// y�� ��, �Ʒ�

int maxDepth = 10;
std::vector<std::pair<int, int>> coinDir;

int result = 9999;	// �ִ밪�� �־߾� ��

// 
bool IsCoinFall(int &x, int &y) {

	if (x < 0 || x >= M || y < 0 || y >= N) return true;
	return false;
}

// 0 = �������� ��ġ, 1 = ���ŷ ��ġ, 2 = ���� �̵� ����
int IsBlocking(int& x, int& y) {
	if (IsCoinFall(x, y))
		return 0;

	else if (arr[y][x] == '#') return 1;
	return 2;
}

// 1������ ��ǥ, 2������ ��ǥ, ���� ����
void DFS(int x1, int y1, int x2, int y2, int depth)
{
	// ���� �ʰ� 10������ �������� 11������ �ȵ� (index 0 ~ 9)
	if (depth >= maxDepth)
		return;
	else
	{		
		int coinFall = 0;
		if (IsCoinFall(x1, y1))
		{
			++coinFall;
		}
		if (IsCoinFall(x2, y2))
		{
			++coinFall;
		}

		// �� �� �������ٸ� ����
		switch(coinFall)
		{
			case 2: // �� ���͵� ����
				return;
			case 1:	// �ڽ��� depth�� result�� ����� �� return
				result = std::min(result, depth);
				return;
				// ������ �ϳ��� �ȶ������ٸ�
			case 0:
				// ���⼭ ���ο� 4�� DFS �� ����

				for (int i = 0; i < 4; ++i) {
					int nX = x1 + dx[i];
					int nY = y1 + dy[i];


					// 0 = �������� ��ġ, 1 = ���ŷ ��ġ, 2 = ���� �̵� ����

					switch (IsBlocking(nX, nY)) {
					case 1:
						nX = x1;
						nY = y1;
						break;
					}

					int nnX = x2 + dx[i];
					int nnY = y2 + dy[i]; 

					switch (IsBlocking(nnX, nnY)) {
					case 1:
						nnX = x2;
						nnY = y2;
						break;
					}

					// ���������� ������ ���� ��ġ�� �����ϱ�
					DFS(nX, nY, nnX, nnY, depth + 1);	
					// 



				}//endfor
				break;
		}//end switch
	}
}

int main(void)
{
	std::cin >> N >> M;

	arr.resize(N);
	for (int i = 0; i < N; ++i) {
		arr[i].resize(M);
	}
	// 2���� �迭 ũ���Ҵ�
	char pin;
	int coinNum = 0;
	// y��
	for (int i = 0; i < N; ++i) {
		// x��
		for (int j = 0; j < M; ++j) {

			std::cin >> arr[i][j];

			// ���� ��ġ ���
			if (arr[i][j] == 'o') {
				coinDir.push_back(std::make_pair(j,i));
			}
		}
	}

	DFS(coinDir[0].first, 
		coinDir[0].second,
		coinDir[1].first,
		coinDir[1].second,
		0);
	
	// � ��쵵 �������� ���Ѵٸ� -1�� �ٲ�
	if (result == 9999)
		result = -1;

	std::cout << result;

	return 0;
}