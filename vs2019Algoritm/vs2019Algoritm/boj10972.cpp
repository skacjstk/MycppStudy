#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
//int arr[MAX] = { 0, };
//bool visited[MAX] = { 0, };
vector<int> number; //�ε����� ��� N ��


int main() {
    cin >> n;
    number.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }

    if (next_permutation(number.begin(), number.end())) {
        for (int i = 0; i < n; ++i) {
            cout << number[i] << " ";
        }
    }
    else
        cout << "-1";

    return 0;
}
//���� ������ ���ϴ� C++ �Լ� ���̺귯���� ����
//���Ϳ� ���� ������ ���� ����ȴ�.
//��ȯ���� true, false �̴�. 