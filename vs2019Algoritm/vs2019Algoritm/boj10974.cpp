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

    //데이터 넣기

    for (int i = 0; i < n; ++i) {
        number[i] = i+1;
    }

    //데이터 전체 출력하기
    do {
        //복사비용 &, const로 무결성 보장
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