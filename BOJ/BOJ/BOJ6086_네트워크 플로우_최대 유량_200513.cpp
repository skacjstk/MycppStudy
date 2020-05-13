#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAX 1005
#define INF 987654321
#define MOD 31991
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, c, total = 0, flow[MAX][MAX], capacity[MAX][MAX];

char a, b;
vector<int> v[MAX];
queue<int> q;
bool visit[MAX][MAX];

// ���� -> ���� ��ȯ
int f(char ch)
{
	return ch - 'A';
}

int main()
{
	int source = f('A'), sink = f('Z');
	scanf("%d", &n);

	// �Է��� �޾ƿ´�.
	// ���� ���� : capacity a-> b�� �����ٶ�, b->a�� ������� �Ѵ�.
	for (int i = 0; i < n; i++)
	{
		scanf(" %c %c %d", &a, &b, &c);
		int q = f(a), w = f(b);
		capacity[q][w] += c;
		capacity[w][q] += c;
		v[f(a)].push_back(f(b));
		v[f(b)].push_back(f(a));
	}

	while (1)
	{
		// ��θ� ����
		printf("�ݺ� ����\n");
		int prev[MAX];
		fill_n(&prev[0], MAX, -1);

		// �������� �߰�
		q.push(source);

		// BFS�� �̿��Ͽ� ��θ� ã�´�.
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int k = 0; k < v[cur].size(); k++)
			{
				int next = v[cur][k];

				printf("prev[%d]:%d --> prev[%d]:%d", cur, prev[cur], next, prev[next]);
				printf("    �ܿ�����:%d", capacity[cur][next] - flow[cur][next]);
				printf("  q.size():%d", q.size());
				if (prev[next] == -1 && capacity[cur][next] - flow[cur][next] > 0)
				{
					prev[next] = cur;
					q.push(next);
					printf(" --> %d", q.size());
					if (next == sink) {
						printf(" [%d] ����\n", sink);	break;
					}
				}
				printf("\n");
			}
		}
		//	printf("��ȯ: %d\n",prev[sink]);
		if (prev[sink] == -1)
			break;
		// �� �̻� sink�� ���� ��ΰ� �������� �ʴ� ���

		int tmp = sink, possible_flow = INF;
		for (int i = sink; i != source; i = prev[i])
			possible_flow = min(possible_flow, capacity[prev[i]][i] - flow[prev[i]][i]);
		// ã�� ��ο����� �带 �� �ִ� �ּ� ������ Ȯ���Ѵ�.

		for (int i = sink; i != source; i = prev[i])
		{
			flow[prev[i]][i] += possible_flow;
			flow[i][prev[i]] -= possible_flow;
		}
		// ã�� ��ο� �带 �� �ִ� �ּ� ������ �����ش�.
		// ���� ���� : �����⿡ ���ؼ��� �߰��� ����Ѵ�.(���� ��Ī)
		total += possible_flow;
	}
	printf("%d\n", total);
	return 0;
}