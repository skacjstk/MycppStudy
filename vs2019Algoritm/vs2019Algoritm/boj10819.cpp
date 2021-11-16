#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, m;
vector<int> number; //�ε����� ��� N ��

int maxValue = 0;

void CalMaxvalue(int& index) {
    int compareValue = 0;
    for (int i = 1; i < index; ++i) {
        //�ش� ���밪�� ����
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

    //������ �ֱ�

    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    //��� ��� ���ϱ�� sort �ʿ�
    sort(number.begin(), number.end());


    //������ ��ü �����ϸ� �ִ밪 �����ϱ�
    int n_2, n_1;
    do {
        CalMaxvalue(n);

    }     while (next_permutation(number.begin(), number.end()));

    cout << maxValue;

    return 0;
}
