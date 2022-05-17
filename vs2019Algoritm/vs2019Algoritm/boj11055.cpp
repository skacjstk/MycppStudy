#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> seq;
vector<int> answer;

void test2(int& index);

void test(int& index) {

	answer.push_back(seq[index]);	
	test2(index);
}
void test2(int& index) {

	int flag = 0;

	for (int i = 0; i < index; ++i) {
		if (flag < seq[i] && seq[i] < seq[index])	//���� �������� �ΰ���
		{
			flag = seq[i];
			answer[index] += seq[i];
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

//	seq.resize(n);
//	answer.resize(n);
	int num;

	for (int i = 0; i < n; ++i) {
		cin >> num;
		seq.push_back(num);
		test(i);
	}

	cout << *max_element(answer.begin(), answer.end());

	return 0;
}


//���� ���� ����
//DP�� Ǯ�� �� ��������, �̰� ���� Ž�����ε� Ǯ �� ���� �� �˾Ҵµ� DP������ ������ �ִ�.

//����: ���� num���� ū ���� �ִ� ���� ����� �ε����� ���� num���� �ٲٱ�
//���� ����ؾ��Ұ� ���� ���� ū���� ���̰� ��� �ƴϾ���...
/* ���� ���� �ο��ٿ�� �ڵ�� �Ⱦ���
* void inputCheck(const int& num) {
	if (seq.empty() || seq.back() < num) {
		seq.push_back(num);
	}
	else if (seq.back() > num) {
		CustomLowerbound(num);
	}
}
void CustomLowerbound(int num) {
	int left = 0;
	int right = seq.size() - 1;
	int mid = right;

	while (right - left > 0) {
		mid = (left + right) / 2;
		if (seq[mid] < num) {

			left = mid + 1;
		}
		else right = mid;

	}
	seq[right] = num;
}
*/