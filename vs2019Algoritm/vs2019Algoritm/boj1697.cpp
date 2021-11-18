#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> nodes;
bool visited[100001]; //10�� (main�Լ��� ������ ���� 16384 ����Ʈ ����
int extract;

bool validCheck(const int& num) {
	if (num > 100000 || num < 0 || visited[num])
		return false;
	return true;
}

void bfs(const int& k) {
	while (!nodes.empty()) {
		int num = nodes.front().first;
		int time = nodes.front().second;
		nodes.pop();
		visited[num] = true;
		
		//������ �ߺ��˻� �ϰ���, spendTime�� �ֱ⿡, �ߺ��� ���� �ٽ� �� ������ ������, ���� ȣ��� ���� ���� ���� ���̱⿡ ���� ����.
		if (num == k) { //��ġ�� ������?
			extract = time;
			break;
		}
		else {
			if (validCheck(num + 1)){
				nodes.push({ num + 1,time + 1 });
			}
			if (validCheck(num - 1)){
				nodes.push({ num - 1,time + 1 });
			}
			if (validCheck(num * 2)){
				nodes.push({ num * 2,time + 1 });
			}//end if
		}//end if
	}//end while
}

int main(void)
{
	int n, k;	
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	nodes.push({ n,0 });
	visited[n] = true;	//n�� �湮����

	bfs(k);


	cout << extract;

	/*
	for (int i = 0; i < 100; ++i) {
		if (i % 10 == 0 && i > 0)
			cout << "\n";

		cout << spendTime[i] <<" ";

	}
	*/
	return 0;
}
/*
1������: pair�� ��ü, ���� spendTime �����迭�� ���� ���ڰ� ������
2������: validCheck ������ visited�� ���� ���� ����, num�� ��ȿ���� ���� �˻��ϸ� �ȴ�.
*/