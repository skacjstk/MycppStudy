#pragma once 
#include <iostream>
#include <cstdlib>		//���� �Լ� ���� ��
#include <ctime>	//�ð� �õ��


#define MAX_ARRAY 10

extern int array[MAX_ARRAY];

void dataShow(const int *data);
void quickSort(int *data, int start, int end);

void dataShow(const int *data);
void randomInputData(int *data);
void randomInputData(int *data, int start, int end);
