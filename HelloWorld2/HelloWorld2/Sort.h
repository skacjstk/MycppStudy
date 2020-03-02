#pragma once 
#include <iostream>
#include <cstdlib>		//랜덤 함수 생성 용
#include <ctime>	//시간 시드용
#include <algorithm>	//swap() 함수 사용 


#define MAX_ARRAY 10

extern int array[MAX_ARRAY];

void dataShow(const int *data);
void quickSort(int *data, int start, int end);

void dataShow(const int *data);
void randomInputData(int *data);
void randomInputData(int *data, int start, int end);
