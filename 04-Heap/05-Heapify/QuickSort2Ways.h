#pragma once
#include <ctime>
#include "InsertionSort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition2(T arr[], int l, int r) {
	// 随机的选择一个元素作为主元pivot element
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	// arr[l+1...i) <= v; arr(j...r] >= v
	int i = l + 1, j = r; // 初始化和区间另一个端点相同，使得两个区间为空
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

// 对arr[l...r]部分进行快速排序
template <typename T>
void _quickSort2Ways(T arr[], int l, int r) {
	// 优化1：小数据量使用插入排序
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
	srand(time(NULL)); // 设置随机种子
	_quickSort2Ways(arr, 0, n - 1);
}