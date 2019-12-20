#include <iostream>
#include "Heap.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort3Ways.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void __shiftDown(T arr[], int n, int k) {
	while (2 * k + 1 < n) { // �ж��Ƿ�������
		int j = 2 * k + 1; // �ڴ���ѭ���У�arr[k]��arr[j]����λ��
		if (j + 1 < n && arr[j + 1] > arr[j]) // �ж��Һ��Ӻ����ӵĴ�С��ϵ
			j += 1;
		if (arr[k] >= arr[j])
			break;
		swap(arr[k], arr[j]);
		k = j;
	}
}

template<typename T>
void heapSort(T arr[], int n) {
	// heapify
	for (int i = (n - 1) / 2; i >= 0; i--)
		__shiftDown(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}
int main() {
	int n = 1000000;
	// ����1 һ���Բ��ԣ��������
	cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);
	int* arr4 = SortTestHelper::copyIntArray(arr1, n);
	int* arr5 = SortTestHelper::copyIntArray(arr1, n);
	int* arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);
	SortTestHelper::testSort("Heap Sort 3", heapSort, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	cout << endl;

	// ����2: ���Խ������������
	int swapTimes = 100;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);
	SortTestHelper::testSort("Heap Sort 3", heapSort, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	cout << endl;
	// ����3: �����д����ظ����ݵ�����
	cout << "Test for Random Array, size = " << n << ", random range [0, 10]" << endl;
	arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);
	arr5 = SortTestHelper::copyIntArray(arr1, n);
	arr6 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
	SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
	SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);
	SortTestHelper::testSort("Heap Sort 3", heapSort, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	return 0;
}