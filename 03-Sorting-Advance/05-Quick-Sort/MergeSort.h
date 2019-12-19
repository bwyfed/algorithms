#pragma once
#include <iostream>
#include "InsertionSort.h"

using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	//	T aux[r-l+1]; // 临时空间
		//* VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
		//* 使用VS的同学, 请使用new的方式申请aux空间
		//* 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
	// 对归并排序进行优化2：对于小数量，使用插入排序
	//if ( l >= r)
	//	return;
	if (r - l <= 15) { // 处理16个元素的排序
		insertionSort(arr, l, r);
		return;
	}
	int mid = (l + r) / 2; // 向下取整 
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	// 对归并排序进行优化1：对近乎有序的数组的优化
	if (arr[mid] > arr[mid + 1]) // arr[mid] <= arr[mid+1]表示arr已经是有序的
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
	__mergeSort(arr, 0, n - 1);
}
