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
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1,0);
}
//base�� 15649��
/*
���������� �ٽ���. Ʈ��ŷ�ϴ� �ڽ� index ���� ū index�� Ž���ϸ� �ȴٴ� ��
*/