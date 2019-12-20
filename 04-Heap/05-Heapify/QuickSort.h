#pragma once
#include <ctime>
#include "InsertionSort.h"
using namespace std;

//----基本快速排序---
// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {
	// 随机的选择一个元素作为主元pivot element
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	// arr[l+1...j] < v; arr[j+1...i) > v
	int j = l; // 初始情况下，两个区间为空
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {
	// 优化1：小数据量使用插入排序进行优化
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
	srand(time(NULL)); // 设置随机种子
	__quickSort(arr, 0, n - 1);
}
