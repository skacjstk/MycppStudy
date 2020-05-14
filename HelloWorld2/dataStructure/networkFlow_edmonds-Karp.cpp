
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void)
{
	int repeat;
	scanf("%d", &repeat);


	float total = 0;
	//const int one = 1;

	float mother = 1;
	float div = 0;
	for (int i = 1; i <= repeat; ++i) {
		float son = 0;
		div += i;		
		son += div;
	//	printf("%1f / %1f = %2f\n",mother, son, mother / son);
		total += mother / son;
	//	printf(" %2f \n", total);

	}
	printf("\n%lf", total);
}