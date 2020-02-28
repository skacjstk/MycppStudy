/*
	퀵 정렬 예제
	퀵 정렬: 시간복잡도 n*logn 을 자랑하나 최악의 경우(거의 정렬된, 또는 정렬된 배열)
	n*n의 시간복잡도를 보인다.
*/

#include <iostream>
#define MAX_ARRAY 10

int array[MAX_ARRAY] = { 4, 8, 2, 3, 9 ,1 ,6, 10 ,5, 7 };

void quickSort(int *data, int start, int end) {
	if (start >= end)	//원소가 1개(더 안쪼개질 경우) 냅두기
		return;	

	int temp;	//데이터 교환용 임시 버퍼 
	int pivot = start; //pivot 방향 
	int i = start +1; //시작 원소부터 탐색 >(Greater) 탐색
	int j = end;	//끝 원소부터 탐색 <(Less) 탐색

	while(i <= j){	//엇갈릴 때까지 반복
		while (i <= end && data[pivot] >= data[i]) //피벗 값보다 큰 원소 찾기 
			++i;						
		while (j > start && data[pivot] <= data[j])	//피벗 값보다 작은 원소 찾기
			--j;

		if (i > j) {//역전했다면 j값과 pivot 값을 교환
			temp = data[pivot];
			data[pivot] = data[j];
			data[j] = temp;
		}
		else {	//아니라면 i와 j 값을 교환
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j-1);	//j의 위치에 pivot이 왔으니까 j를 기준으로 반갈죽
	quickSort(data, j + 1, end);

}

void dataShow(const int *data) {
	for (int i = 0; i < MAX_ARRAY; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}
/*		
//*data 와 &(data)[10]은 같다. 애초에 포인터니까 당연한거긴 한데 
void dataShow(const int *data, int *test) {
	for (int i = 0; i < MAX_ARRAY; ++i) {
		std::cout << array[i] << " ";
	}
	test[0] = 5;
	std::cout << "\n";
}
*/

int main(void)
{
	dataShow(array);
	quickSort(array, 0, MAX_ARRAY - 1);
	dataShow(array);
	//	int test[1];
	//	test[0] = 1;
	//dataShow(array, test);
	//std::cout << test[0];
}