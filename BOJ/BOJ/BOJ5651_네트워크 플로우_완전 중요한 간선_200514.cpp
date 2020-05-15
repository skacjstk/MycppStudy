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
//n은 vertex 
//std::vector<int> v[MAX];


/*
void ClearQueue(std::queue<int> &someQueue)
{
std::queue<int> empty;
std::swap(someQueue, empty);
}
출처: https://kindtis.tistory.com/574 [Game Programmer Life]
*/

//목적: 완전 중요한 간선 찾기 https://www.acmicpc.net/problem/5651
//완전 중요한 간선?: 용량(capacity)를 1 줄였을 때, 최대 용량이 1 감소하는 간선 
int netWorkFlow(int source, int sink, std::vector<std::vector<int>> &capacity, std::vector<std::vector<int>> &flow, std::vector<std::vector<int>> &v, std::vector<std::pair<int, int>> &vc) {
	while (1) {
		int prev[MAX];	//vertex 의 이전위치 표시 겸 방문검사
		std::fill_n(&prev[0], MAX, -1);
		std::queue<int> q;
		// 시작지점 추가
		q.push(source);		//큐는 초기화 필요한가?  (10:48 = 어차피 큐 다빠져야 반복이 끝나는게 bfs인데 필요없을거같다)
		// BFS를 이용하여 경로를 찾는다.
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : v[cur]) {
				//잔여 유량이 남으면서 이전위치 표시가 없다면  
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

	// 더 이상 sink로 가는 경로가 존재하지 않는 경우( 코드상으론 나가는 길이 없을 경우 )
		if (prev[sink] == -1)
			break;
		int tmp = sink, possible_flow = INF;
		for (int i = sink; i != source; i = prev[i]) {
			possible_flow = std::min(possible_flow, capacity[prev[i]][i] - flow[prev[i]][i]);
			//		printf("[%d][%d] 의 possible_flow : %d \n",prev[i],i,possible_flow);
		}
		// 찾은 경로에서의 흐를 수 있는 최소 유량을 확인한다.

		for (int i = sink; i != source; i = prev[i])
		{
			flow[prev[i]][i] += possible_flow;
			flow[i][prev[i]] -= possible_flow;
		}
		// 찾은 경로에 흐를 수 있는 최소 유량을 더해준다.
		// 주의 사항 : 역방향에 대해서도 추가해 줘야한다.(유량 대칭)
		total += possible_flow;
	}//endwhile(1)
//	return total;

	int answer = 0;
	for (auto here : vc) {
		int s = here.first; // 시작
		int t = here.second; //도착 
		int prev[MAX];	//vertex 의 이전위치 표시 겸 방문검사
		std::fill_n(&prev[0], MAX, -1);
		std::queue<int> q;
		// 시작지점 추가
		q.push(s);		//큐는 초기화 필요한가?  (10:48 = 어차피 큐 다빠져야 반복이 끝나는게 bfs인데 필요없을거같다)
		// BFS를 이용하여 경로를 찾는다.
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : v[cur]) {
				//잔여 유량이 남으면서 이전위치 표시가 없다면  
				if (prev[next] == -1 && capacity[cur][next] - flow[cur][next] > 0)
				{
					prev[next] = cur;	//이전에 계속 개고생 했던 이유 prev[cur] = next;  이런식으로 반대로 넣어서 
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
초기화 해야할 것
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
	//source 는 1 , sink 는 vertex 
	int source = 1, sink = vertex;
	//정점, 간선과 용량 입력 
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
	int s = here.first; //시작
	int t = here.second; // 끝
	printf("[%d] [%d] \n",s,t);
	int prev[MAX];
	std::fill_n(&prev[0],MAX, -1);

	std::queue<int> q2;
	q2.push(s);
	while(!q2.empty()){ //큐가 비었거나 prev[t] 가 흘렀거나
//	printf("진입");
		int cur = q2.front();
		q2.pop();
		for(int next : v[cur]){

			if(prev[next] != -1) {continue;}

		printf("c[%d][%d] = %d, f[%d][%d] = %d\n",cur,next,capacity[cur][next] ,cur,next, flow[cur][next]);

			if(capacity[cur][next] - flow[cur][next] > 0 ){ //양수면 흐를 수 있단 소리지
				printf("당첨\n");
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
