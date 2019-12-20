#pragma once
#include <ctime>
#include "InsertionSort.h"
using namespace std;

//----������������---
// ��arr[l...r]���ֽ���partition����
// ����p��ʹ��arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {
	// �����ѡ��һ��Ԫ����Ϊ��Ԫpivot element
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	// arr[l+1...j] < v; arr[j+1...i) > v
	int j = l; // ��ʼ����£���������Ϊ��
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

// ��arr[l...r]���ֽ��п�������
template <typename T>
void __quickSort(T arr[], int l, int r) {
	// �Ż�1��С������ʹ�ò�����������Ż�
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
	srand(time(NULL)); // �����������
	__quickSort(arr, 0, n - 1);
}
