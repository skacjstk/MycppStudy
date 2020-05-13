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

// 문자 -> 숫자 변환
int f(char ch)
{
	return ch - 'A';
}

int main()
{
	int source = f('A'), sink = f('Z');
	scanf("%d", &n);

	// 입력을 받아온다.
	// 주의 사항 : capacity a-> b를 더해줄때, b->a도 더해줘야 한다.
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
		// 경로를 저장
		printf("반복 시작\n");
		int prev[MAX];
		fill_n(&prev[0], MAX, -1);

		// 시작지점 추가
		q.push(source);

		// BFS를 이용하여 경로를 찾는다.
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int k = 0; k < v[cur].size(); k++)
			{
				int next = v[cur][k];

				printf("prev[%d]:%d --> prev[%d]:%d", cur, prev[cur], next, prev[next]);
				printf("    잔여유량:%d", capacity[cur][next] - flow[cur][next]);
				printf("  q.size():%d", q.size());
				if (prev[next] == -1 && capacity[cur][next] - flow[cur][next] > 0)
				{
					prev[next] = cur;
					q.push(next);
					printf(" --> %d", q.size());
					if (next == sink) {
						printf(" [%d] 도달\n", sink);	break;
					}
				}
				printf("\n");
			}
		}
		//	printf("순환: %d\n",prev[sink]);
		if (prev[sink] == -1)
			break;
		// 더 이상 sink로 가는 경로가 존재하지 않는 경우

		int tmp = sink, possible_flow = INF;
		for (int i = sink; i != source; i = prev[i])
			possible_flow = min(possible_flow, capacity[prev[i]][i] - flow[prev[i]][i]);
		// 찾은 경로에서의 흐를 수 있는 최소 유량을 확인한다.

		for (int i = sink; i != source; i = prev[i])
		{
			flow[prev[i]][i] += possible_flow;
			flow[i][prev[i]] -= possible_flow;
		}
		// 찾은 경로에 흐를 수 있는 최소 유량을 더해준다.
		// 주의 사항 : 역방향에 대해서도 추가해 줘야한다.(유량 대칭)
		total += possible_flow;
	}
	printf("%d\n", total);
	return 0;
}