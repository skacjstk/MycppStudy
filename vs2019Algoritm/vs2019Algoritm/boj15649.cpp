#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
 //           cout <<"depth " << cnt << " <- " << i << "삽입\t";
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0);
}
//https://cryptosalamander.tistory.com/54
//출처. 
/*
dfs 호출 순서
0 - 1 - 2 - 3
    2   4
    3

    이런느낌. 
    그 중간에 방문여부 판단이 있기 때문에
    방문 했음 -> 안했음 에서 수많은 안했음이 분리됨. (그래서 중복이 방지됨)

*/