#include "Sort.h"

// 이 자료구조 Heap은 root 노드의 index 가 0 이다. 
void heapify(int* data, int size, int mid);
void buildMaxHeap(int* data, int size);
void heapSort(int* data, int size) {
	// 중간에서 시작( index가 10이면 5에서 시작) 그러나 시작이 0이니까 4 
	buildMaxHeap(data, size);
	while (size > 1) {
		std::swap(data[0], data[size - 1]);
		--size;
		heapify(data, size, 0);
	}
}
void buildMaxHeap(int* data, int size) {
	int mid = size / 2 - 1;

	for (mid; mid >= 0; --mid) {
		heapify(data, size, mid);
	}
}


void heapify(int* data, int size, int mid) {
	int parent = mid;
	int left = parent * 2 + 1;	//만약 1에서 시작이라면 *2 *2+1 임.
	int right = parent * 2 + 2;
	int largest = parent;	//현재 비교노드중 가장 큰 노드

	if (left < size && data[left] > data[largest]) {
		largest = left;
	}
	// Check if right child exists && compare the value
	if (right < size && data[right] > data[largest]) {
		largest = right;
	}
	// Swap
	if (parent != largest) {	//조건 만족(부모노드가 더 작다면)	
		std::swap(data[largest], data[parent]);	//이쪽 largest는 rightOrleft
		// swap 발생시, heapify 재귀
		heapify(data, size, largest);
	}
}

int main(void)
{	
	randomInputData(array, 1, 20);
	dataShow(array);
	heapSort(array, MAX_ARRAY);
	dataShow(array);	
	//왜지? 범위 밖 숫자가 0으로 출력된다.
}