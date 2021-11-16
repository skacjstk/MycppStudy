#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, m;
vector<int> number; //인덱스가 담긴 N 들

int maxValue = 0;

void CalMaxvalue(int& index) {
    int compareValue = 0;
    for (int i = 1; i < index; ++i) {
        //해당 절대값을 삽입
       compareValue += abs(number[i - 1] - number[i]);
    }
    if (maxValue < compareValue)
    {
        maxValue = compareValue;
    }

}
int main() {
    cin >> n;
    number.resize(n);

    //데이터 넣기

    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    //모든 경우 구하기라서 sort 필요
    sort(number.begin(), number.end());


    //데이터 전체 순차하며 최대값 연산하기
    int n_2, n_1;
    do {
        CalMaxvalue(n);

    }     while (next_permutation(number.begin(), number.end()));

    cout << maxValue;

    return 0;
}
