#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

template <typename T>
void mergeSortBU(T arr[], int n) {
	for (int sz = 1; sz <= n; sz += sz)
		for (int i = 0; i + sz < n; i += sz + sz) // i+sz<n保证第2部分的存在
			if(arr[i+sz-1] > arr[i+sz]) // 这里是对算法进行优化
				// 对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并
				__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n-1));
}

int main() {
	int n = 1000000;
	// 测试1：一般性测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Merge Sort Buttom Up", mergeSortBU, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;
	// 测试2:测试近乎有序的数组
	int swapTimes = 100;
	cout << "Test for nearly orderly array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Merge Sort Buttom Up", mergeSortBU, arr2, n);

	delete[] arr1;
	delete[] arr2;

	return 0;
}