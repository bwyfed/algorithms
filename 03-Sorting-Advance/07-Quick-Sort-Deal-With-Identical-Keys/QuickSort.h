#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {
	// 随机的选择一个元素作为主元pivot element
	cout << "l=" << l << ",r=" << r << endl;
	int randomNum = rand() % (r - l + 1) + l;
	cout << "randomNum = " << randomNum << ",arr[randomNum]=" << arr[randomNum]<<",";
	swap(arr[l], arr[randomNum]);
	T v = arr[l];
	cout << "v=" << v << ",";
	// arr[l+1...j] < v; arr[j+1...i) > v
	int j = l; // 初始情况下，两个区间为空
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[l], arr[j]);
	cout << "j=" << j << endl;
	return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {
	//if (l >= r)
	//	return;
	// 优化1：小数据量使用插入排序
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
	srand(time(NULL));
//	cout << "quickSort:"<<endl;
//	for (int i = 0; i < 100; i++)
//		cout << arr[i] << ",";
	__quickSort(arr, 0, n - 1);
}