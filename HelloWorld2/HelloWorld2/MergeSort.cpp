#include "Sort.h"

int sortedArray[MAX_ARRAY] = { 0, };


void Merge (int* data, int start, int middle, int end) {
	int i = start , j = middle+1;
	int arrPointer = start;
	while (i <= middle && j <= end)
	{
		if (data[i] < data[j])	//data j가 더 크다면 
		{
			sortedArray[arrPointer] = data[i];	//data[i]의 값 넣고 	(작은 값부터)	
			++i;
		} else {
			sortedArray[arrPointer] = data[j];
			++j;
		} //endif
		++arrPointer; //남은 데이터를 넣을때마다 같이 증가시켜줌
	}
	if (i > middle) {
		for (int p = j; p <= end; ++p) {
			sortedArray[arrPointer] = data[p];
			++arrPointer;	
		}
	}
	else {	//if j > end
		for (int p = i; p <= middle; ++p) {
			sortedArray[arrPointer] = data[p];
			++arrPointer;
		}
	}//endif
	for (int p = start; p <= end; ++p) {	//단순히 sorted는 임시버퍼인 셈이니까...
		data[p]	= sortedArray[p];
	}	
}
void MergeSort(int* data, int start, int end) {
	//크기가 1개면
	if (start < end) {
		int middle = (start + end) / 2;
		MergeSort(data, start, middle);
		MergeSort(data, middle + 1, end);
		Merge(data, start, middle, end);
	}
}


int main(void)
{
	randomInputData(array, 1, 20);
	dataShow(array);
	MergeSort(array, 0, MAX_ARRAY - 1);
	dataShow(array);
}