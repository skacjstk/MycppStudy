#include <iostream>
int number = 50000;
int arr[50000 + 1];

void primeNumber() {
	for (int i = 2; i <= number; ++i)
		arr[i] = i;
	for (int i = 2; i <= number; ++i) {
		if (arr[i] == 0)
			continue;
		for (int j = i+i; j <= number; j +=i) {
			arr[j] = 0;
		}
	}
	
	for (int i = 2; i <= number; ++i) {
		if (arr[i] != 0) printf("%d ", arr[i]);
	}
}
int main(void)
{
	primeNumber();
}