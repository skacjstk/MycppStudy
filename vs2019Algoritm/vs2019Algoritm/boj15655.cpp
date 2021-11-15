#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
//int arr[MAX] = { 0, };
//bool visited[MAX] = { 0, };
vector<int> number; //인덱스가 담긴 N 들
vector<int> arr;
vector<bool> visited;

void dfs(int index, int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = index; i < n; i++)
    {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = number[i];
            //          cout << "depth " << depth << " <- " << number[i] << "삽입\t";
            dfs(i, depth + 1);
            visited[i] = false;

        }

    }
}

int main() {
    cin >> n >> m;
    arr.resize(m); //얘는 m크기
    number.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    sort(number.begin(), number.end());
    //재대로 입력됨.

    dfs(0, 0);
    return 0;

}
//base 15655번