#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

// ��arr[l...r]���ֽ���partition����
// ����p��ʹ��arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition2(T arr[], int l, int r) {
	// �����ѡ��һ��Ԫ����Ϊ��Ԫpivot element
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	// arr[l+1...i) <= v; arr(j...r] >= v
	int i = l+1, j = r;
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
void __quickSort2(T arr[], int l, int r) {
	// �Ż�1��С������ʹ�ò�������
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	int p = __partition2(arr, l, r);
	__quickSort2(arr, l, p - 1);
	__quickSort2(arr, p + 1, r);
}

template <typename T>
void quickSort2(T arr[], int n) {
	srand(time(NULL));
	__quickSort2(arr, 0, n - 1);
}
int main() {
	int n = 10000;
	// �����д����ظ�ֵ���������
	cout << "Test for Random Array, size = " << n << ", random range [0, 10]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	/*for (int i = 0; i < 100; i++)
		cout << arr1[i] << ",";
	cout << endl;*/
//	for (int i = 0; i < n; i++)
//		cout << arr2[i] << ",";
	cout << endl;
//	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n); // ����ʱջ���
//	SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);
//	for (int i = 0; i < 100; i++)
//		cout << arr2[i] << ",";
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}
int main2() {
	int n = 1000000;

	cout << "Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << endl;

	// ���Խ������������
	int swapTimes = 100;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << endl;
	// �����д����ظ�ֵ���������
	cout << "Test for Random Array, size = " << n << ", random range [0, 10]" << endl;
	arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n); // ����ʱջ���
	SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}