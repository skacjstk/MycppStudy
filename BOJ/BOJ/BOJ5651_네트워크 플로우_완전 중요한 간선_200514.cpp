#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define MAX 301
#define INF 987654321
#pragma warning(disable:4996)

int
total = 0;
//int flow[MAX][MAX], capacity[MAX][MAX];
//n�� vertex 
//std::vector<int> v[MAX];


/*
void ClearQueue(std::queue<int> &someQueue)
{
std::queue<int> empty;
std::swap(someQueue, empty);
}
��ó: https://kindtis.tistory.com/574 [Game Programmer Life]
*/

//����: ���� �߿��� ���� ã�� https://www.acmicpc.net/problem/5651
//���� �߿��� ����?: �뷮(capacity)�� 1 �ٿ��� ��, �ִ� �뷮�� 1 �����ϴ� ���� 
int netWorkFlow(int source, int sink, std::vector<std::vector<int>> &capacity, std::vector<std::vector<int>> &flow, std::vector<std::vector<int>> &v, std::vector<std::pair<int, int>> &vc) {
	while (1) {
		int prev[MAX];	//vertex �� ������ġ ǥ�� �� �湮�˻�
		std::fill_n(&prev[0], MAX, -1);
		std::queue<int> q;
		// �������� �߰�
		q.push(source);		//ť�� �ʱ�ȭ �ʿ��Ѱ�?  (10:48 = ������ ť �ٺ����� �ݺ��� �����°� bfs�ε� �ʿ�����Ű���)
		// BFS�� �̿��Ͽ� ��θ� ã�´�.
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : v[cur]) {
				//�ܿ� ������ �����鼭 ������ġ ǥ�ð� ���ٸ�  
				if (prev[next] == -1 && capacity[cur][next] - flow[cur][next] > 0)
				{
					prev[next] = cur;
					q.push(next);
					if (next == sink) {
						break;
					}
				}//endif
			}//endfor
		}//endwhile(!q.empty())

	// �� �̻� sink�� ���� ��ΰ� �������� �ʴ� ���( �ڵ������ ������ ���� ���� ��� )
		if (prev[sink] == -1)
			break;
		int tmp = sink, possible_flow = INF;
		for (int i = sink; i != source; i = prev[i]) {
			possible_flow = std::min(possible_flow, capacity[prev[i]][i] - flow[prev[i]][i]);
			//		printf("[%d][%d] �� possible_flow : %d \n",prev[i],i,possible_flow);
		}
		// ã�� ��ο����� �带 �� �ִ� �ּ� ������ Ȯ���Ѵ�.

		for (int i = sink; i != source; i = prev[i])
		{
			flow[prev[i]][i] += possible_flow;
			flow[i][prev[i]] -= possible_flow;
		}
		// ã�� ��ο� �带 �� �ִ� �ּ� ������ �����ش�.
		// ���� ���� : �����⿡ ���ؼ��� �߰��� ����Ѵ�.(���� ��Ī)
		total += possible_flow;
	}//endwhile(1)
//	return total;

	int answer = 0;
	for (auto here : vc) {
		int s = here.first; // ����
		int t = here.second; //���� 
		int prev[MAX];	//vertex �� ������ġ ǥ�� �� �湮�˻�
		std::fill_n(&prev[0], MAX, -1);
		std::queue<int> q;
		// �������� �߰�
		q.push(s);		//ť�� �ʱ�ȭ �ʿ��Ѱ�?  (10:48 = ������ ť �ٺ����� �ݺ��� �����°� bfs�ε� �ʿ�����Ű���)
		// BFS�� �̿��Ͽ� ��θ� ã�´�.
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : v[cur]) {
				//�ܿ� ������ �����鼭 ������ġ ǥ�ð� ���ٸ�  
				if (prev[next] == -1 && capacity[cur][next] - flow[cur][next] > 0)
				{
					prev[next] = cur;	//������ ��� ����� �ߴ� ���� prev[cur] = next;  �̷������� �ݴ�� �־ 
					q.push(next);
					//		if (next == t){
					//			break;
					//		}
				}//endif
			}//endfor
		}//endwhile(!q.empty())

		if (prev[t] == -1)
			answer++;
	}


	return answer;
}
/*
�ʱ�ȭ �ؾ��� ��
v
void q

*/
void testCase() {
	total = 0;
	std::vector<std::vector<int>> capacity(MAX, std::vector<int>(MAX, 0));
	std::vector<std::vector<int>> flow(MAX, std::vector<int>(MAX, 0));
	std::vector<std::vector<int>> v(MAX);
	std::vector<std::pair<int, int>> vc;
	vc.clear();
	int vertex, edge;
	scanf("%d %d", &vertex, &edge);
	//source �� 1 , sink �� vertex 
	int source = 1, sink = vertex;
	//����, ������ �뷮 �Է� 
	for (int i = 0; i < edge; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		capacity[a][b] += c;
		v[a].push_back(b);
		v[b].push_back(a);
		vc.push_back(std::make_pair(a, b));

	} //endfor
	printf("%d\n", netWorkFlow(source, sink, capacity, flow, v, vc));
}

int main()
{
	int source = 1, sink = -1;
	int repeatNum;

	scanf("%d", &repeatNum);
	while (repeatNum) {
		testCase();
		--repeatNum;
	}

	return 0;
}



/*
int answer = 0;
for(std::pair<int,int> here : vc){
	int s = here.first; //����
	int t = here.second; // ��
	printf("[%d] [%d] \n",s,t);
	int prev[MAX];
	std::fill_n(&prev[0],MAX, -1);

	std::queue<int> q2;
	q2.push(s);
	while(!q2.empty()){ //ť�� ����ų� prev[t] �� �귶�ų�
//	printf("����");
		int cur = q2.front();
		q2.pop();
		for(int next : v[cur]){

			if(prev[next] != -1) {continue;}

		printf("c[%d][%d] = %d, f[%d][%d] = %d\n",cur,next,capacity[cur][next] ,cur,next, flow[cur][next]);

			if(capacity[cur][next] - flow[cur][next] > 0 ){ //����� �带 �� �ִ� �Ҹ���
				printf("��÷\n");
				q2.push(next);
				prev[cur] = next;
			}
		}
	}
	if(prev[t] == -1)
		{++answer;}
} //end forpair
return answer;
*/
