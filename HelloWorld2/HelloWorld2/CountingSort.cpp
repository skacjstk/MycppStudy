/*
	계수 정렬: On 의 속도가 나온다.
	- n개의 숫자를 정렬하는데 걸리는 시간은 O(n)
	- 각 숫자가 나온 횟수를 세는데 O(n)
	- 다시 숫자를 정렬된 리스트에 채워넣는데 O(n)
출처: https://www.crocus.co.kr/470 [Crocus]
	정수, 일정한 범위 가 있는 자료에서만 사용 가능.
	개인적으론 배열 2개 + 누적합 배열 1개로 메모리를 많이쓰고 한정적인 배열이라 생각함.
*/
#include "Sort.h"
const int dataRange = 5;	//어쩔수없이 전역변수화 함..

//for문이 4개니까 O(4n) 인데 빅오 표기법은 정수부분을 버리고 표기한다.
void counterDebug(int *counter,int counterSize) {
	for(int i=0; i<counterSize; ++i){
		std::cout << counter[i] << " "; 
	}
	std::cout << "\n";
}
void countingSort(int *data,int size) {
	int sorted[MAX_ARRAY];
/*https://namwhis.tistory.com/entry/C-%EB%B0%B0%EC%97%B4-%EC%B4%88%EA%B8%B0%ED%99%94-stdfill-stdfilln-%EC%A0%95%EB%A6%AC*/
	int counter[dataRange + 1] = { 0, };
	for (int i = 0; i < size; ++i) {
		++counter[data[i]];
	}//endfor
	//누적합 배열화
//	counterDebug(counter, dataRange + 1);
	for (int i = 0; i < dataRange; ++i) {
		counter[i + 1] += counter[i];
	}//endfor 누적합 배열화
	counterDebug(counter, dataRange + 1);
	for (int i = MAX_ARRAY-1; i >= 0; --i) {
		sorted[counter[data[i]]-1] = data[i];
		--counter[data[i]];
	}//endfor
	//정렬부분 설명 이해한거https://sexycoder.tistory.com/31
//	dataShow(sorted);	
	for (int i = 0; i < size; ++i) {
		data[i] = sorted[i];
	}	//배열 자체를 반환하려면 이 배열을 포인터로 선언했어야...
}



int main(void)
{
	randomInputData(array, 1, dataRange);
	dataShow(array);
	countingSort(array,MAX_ARRAY);
	dataShow(array);
}