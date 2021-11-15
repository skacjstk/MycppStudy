#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int index, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = index; i <= n; i++)
    {

        arr[cnt] = i;
        dfs(i, cnt + 1);

    }
}

int main() {
    cin >> n >> m;
    dfs(1,0);
}
//base 15649번
//중복 방지를 위한 visited 제거, 및 50번에 index 전달로 비 내림차순 구현