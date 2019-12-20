#pragma once
#include <ctime>
#include "InsertionSort.h"

using namespace std;

// ��arr[l...r]���ֽ���partition����
// ����p��ʹ��arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition2(T arr[], int l, int r) {
	// �����ѡ��һ��Ԫ����Ϊ��Ԫpivot element
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	// arr[l+1...i) <= v; arr(j...r] >= v
	int i = l + 1, j = r; // ��ʼ����������һ���˵���ͬ��ʹ����������Ϊ��
	while (true) {
		while (i <= r && arr[i] < v) i++;
		while (j >= l + 1 && arr[j] > v) j--;
		if (i > j) break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}

// ��arr[l...r]���ֽ��п�������
template <typename T>
void _quickSort2Ways(T arr[], int l, int r) {
	// �Ż�1��С������ʹ�ò�������
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	int p = __partition2(arr, l, r);
	_quickSort2Ways(arr, l, p - 1);
	_quickSort2Ways(arr, p + 1, r);
}

template <typename T>
void quickSort2Ways(T arr[], int n) {
	srand(time(NULL)); // �����������
	_quickSort2Ways(arr, 0, n - 1);
}