#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 100001
int visited[MAX]; //10�� (main�Լ��� ������ ���� 16384 ����Ʈ ����
//int beforePos[100001] = { -1, }; //������� bp[10] = 9 �ϰ�� 10�� ���� ��ġ�� 9
int extract;

queue<pair<int, int>> nodes;

vector<int> path;

bool validCheck(const int& num) {
	if (num > MAX-1 || num < 0 || visited[num] != -1 )
		return false;
	return true;
}

void bfs(const int& k) {
	while (!nodes.empty()) {
		int num = nodes.front().first;
		int time = nodes.front().second;
		nodes.pop();
		//�湮��� �ݿ� ������ nodes�� ������� ���� ����

		//������ �ߺ��˻� �ϰ���, spendTime�� �ֱ⿡, �ߺ��� ���� �ٽ� �� ������ ������, ���� ȣ��� ���� ���� ���� ���̱⿡ ���� ����.
		if (num == k) { //��ġ�� ������?
			extract = time;
			break;
		}
		else {
			if (validCheck(num + 1)) {
				nodes.push({ num + 1,time + 1 });
				visited[num + 1] = num;	//���⿡ ���� ���ٴ� �� ��ü��, �湮�ߴٴ� ����
			}
			if (validCheck(num - 1)) {
				nodes.push({ num - 1,time + 1 });
				visited[num - 1] = num;
			}
			if (validCheck(num * 2)) {
				nodes.push({ num * 2,time + 1 });
				visited[num * 2] = num;
			}//end if
		}//end if
	}//end while
}
void InitializeVisited() {
	for (int i = 0; i < MAX; ++i) {
		visited[i] = -1; //0~MAX-1 ���� �ʱ�ȭ
	}
}
/// <summary>
/// �����̰� �������� �տ� �ִٸ�, -1�ۿ� ���� ������ bfs �� �ʿ䰡 ����.
/// </summary>
/// <param name="n">������ ��ġ</param>
/// <param name="k">���� ��ġ</param>
/// <returns></returns>
bool CalEitherCase(int& n, int& k) {
	if (n >= k) {
		cout << n - k << "\n"; //-1�ۿ� ���ϴ� �ð��� �� ������
		for (int i = n; i >= k; --i) {
			cout << i << " ";
		}
		return true;
	}
	return false;
}
int main(void)
{
	//����, ����
	int n, k;
	int beforePoint;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	//�����̰� �����̵� ���Ҷ� (n�� k���� ũ�ų� ���� ��)	
	if (!CalEitherCase(n, k)) {

		nodes.push({ n,0 }); //n �ڽŰ� �ڽ��� time(����) ����
		visited[n] = n;	//n�� �湮���� (�ڱ� �ڽ��� �湮�� �ɷ� ���)

		InitializeVisited(); // -1�� �迭 �ʱ�ȭ

		bfs(k); //������ k�� �ְ� bfs ����
		cout << extract << "\n"; //ã������� time(����)
		beforePoint = k;
		while (beforePoint != n) { //�������� ���ö����� �ǵ��ư���
			path.push_back(beforePoint);
			//	cout << beforePoint << " ";
			beforePoint = visited[beforePoint];
		}
		path.push_back(n);
		reverse(path.begin(), path.end());
		for (int it : path) {
			cout << it << " ";
		}

	}
	return 0;

	//n < k �� ��

	/*
	for (int i = 0; i < 100; ++i) {
		if (i % 10 == 0 && i > 0)
			cout << "\n";

		cout << spendTime[i] <<" ";

	}
	*/
}
/*
1������: pair�� ��ü, ���� spendTime �����迭�� ���� ���ڰ� ������
2������: validCheck ������ visited�� ���� ���� ����, num�� ��ȿ���� ���� �˻��ϸ� �ȴ�.

3������: visited�� int������ �ٲٰ�, -1�� �ʱ�ȭ�ߴ�. 
*/