#include <iostream>
#include <string>
#include "SortTestHelper.h"
#include "SelectionSort.h"
using namespace std;

// 插入排序
template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		// 寻找当前元素arr[i]合适的插入位置
		// 内层循环可以提前结束
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			swap(arr[j], arr[j - 1]);
		}
		/*for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}*/
	}
}
int main() {
	int n = 10000; //数组中元素的个数
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

	delete[] arr; // 释放数组的地址空间
	delete[] arr2;

	return 0;
}