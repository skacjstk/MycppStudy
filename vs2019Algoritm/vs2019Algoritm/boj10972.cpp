#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
//int arr[MAX] = { 0, };
//bool visited[MAX] = { 0, };
vector<int> number; //인덱스가 담긴 N 들


int main() {
    cin >> n;
    number.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
        //이전 순열은 prev_permutation
    if (next_permutation(number.begin(), number.end())) {
        for (int i = 0; i < n; ++i) {
            cout << number[i] << " ";
        }
    }
    else
        cout << "-1";

    return 0;
}
//다음 순열을 구하는 C++ 함수 라이브러리가 있음
//벡터에 다음 순열이 직접 적용된다.
//반환값은 true, false 이다. 