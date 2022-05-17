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
		if (flag < seq[i] && seq[i] < seq[index])	//수열 만족조건 두가지
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


//최장 증가 수열
//DP로 풀라 한 문제지만, 이건 이진 탐색으로도 풀 수 있을 줄 알았는데 DP문제인 이유가 있다.

//목적: 인자 num보다 큰 수가 있는 가장 가까운 인덱스의 값을 num으로 바꾸기
//내가 계산해야할게 합이 제일 큰거지 길이가 긴게 아니었다...
/* 따라서 기존 로워바운드 코드는 안쓴다
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