#include <iostream>
using namespace std;

int main(void) {
	int max = 0, idx = 0, arr[26] = { 0, };
	string S;
	const string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		S[i] = toupper(S[i]);
		arr[a.find(S[i])]++;
	}
	for (int j = 0; j < sizeof(arr) / sizeof(int); j++) {
		if (arr[j] == 0)
			continue;
		if (max == arr[j]) {
			idx = 26;
			continue;
		}
		if (max < arr[j]) {
			max = arr[j];
			idx = j;
		}
	}
	cout << a[idx];
}