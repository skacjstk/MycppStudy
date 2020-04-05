#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void)
{
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);

	int length = (v - a);
	int step = a - b;
	int result = length / step;
	if (length % step != 0)
		++result;

	printf("%d", ++result);	// 시작은 1일이니까
	return 0;
}