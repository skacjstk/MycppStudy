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

    //������ �ֱ�

    for (int i = 0; i < n; ++i) {
        number[i] = i+1;
    }

    //������ ��ü ����ϱ�
    do {
        //������ &, const�� ���Ἲ ����
        for (const int& it : number) {
            cout << it <<" ";
        }
        /*  
        for (int i = 0; i < n; ++i) {
            cout << number[i] << " ";
        } */
        cout << "\n";
    }    
    while (next_permutation(number.begin(), number.end()));


 //   else
    //    cout << "-1";

    return 0;
}