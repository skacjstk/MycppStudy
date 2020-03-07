#include <iostream>
#include <algorithm>
constexpr auto MAX_ARRAY = 10001;

/*
BOJ 10989번, countingSort 를 이용해 푸는 문제
https://www.acmicpc.net/board/view/21880
cin 대신 scanf
cout대신 printf
endl 대신 "\n"
https://stackoverflow.com/questions/1042110/using-scanf-in-c-programs-is-faster-than-using-cin
*/
int main(void)
{
	int size;
	int array[MAX_ARRAY] = { 0, };	//최대 10000개
	int  max=0;
	int num;
	//std::cin >> size;
	scanf_s("%d", &size);
	for (int i = 0; i < size; ++i) {
		//std::cin >> num;
		scanf_s("%d", &num);
		++array[num];	
		max = std::max(num, max);
	//	std::cout<<"\t" << num << " 번 index ++ \n";
	}
	for (int i = 0; i < max+1; ++i) {
		while (array[i] != 0) {
			printf("%d\n", i);
			--array[i];
		}
	} 
	return 0;
}


//백준 10989번 제출 버전
/*
#include <iostream>
#include <algorithm>


int main(void)
{
	int size;
	int array[10001] = { 0, };	//최대 10000개
	int  max=0;
	int num;
	//std::cin >> size;
	scanf("%d", &size);
	for (int i = 0; i < size; ++i) {
		//std::cin >> num;
		scanf("%d", &num);
		++array[num];
		max = std::max(num, max);
	//	std::cout<<"\t" << num << " 번 index ++ \n";
	}
	for (int i = 0; i < max+1; ++i) {
		while (array[i] != 0) {
			printf("%d\n", i);
			--array[i];
		}
	}
	return 0;
}


*/