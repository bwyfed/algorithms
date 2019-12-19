#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {
	// 随机的选择一个元素作为主元pivot element
	swap(arr[l] , arr[rand() % (r - l + 1) + l]);
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
	srand(time(NULL)); // 设置随机种子
	__quickSort(arr, 0, n - 1);
}
int main() {
	int n = 1000000;

	cout << "Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	// 测试近乎有序的数组
	int swapTimes = 100;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;
	// 测试有大量重复数据的数组
	cout << "Test for Random Array, size = " << n << ", random range [0, 10]" << endl;
	arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;

	return 0;
}