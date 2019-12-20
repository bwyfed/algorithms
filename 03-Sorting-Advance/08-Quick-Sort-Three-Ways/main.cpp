#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

// ��·���������� arr[l...r]
// ��arr[l...r]��Ϊ <v; ==v; >v ������
// ֮��ݹ�� < v; >v�����ּ���������·��������
template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	// partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	int lt = l; // arr[l+1...lt] < v
	int gt = r + 1; // arr[gt...r] > v
	int i = l + 1; // arr[lt+1...i) == v ���ڿ����Ԫ��
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
//			i++; // i����Ҫ++����ʱ����ָ��δ�����Ԫ��
		}
		else { // arr[i] == v
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	__quickSort3Ways(arr, l, lt - 1); // �����䲻��l-1������l�����������
	__quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n) {
	srand(time(NULL));
	__quickSort3Ways(arr, 0, n - 1);
}

int main() {
	int n = 1000000;
	// ����1�������������
	cout << "Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << endl;

	// ����2: ���Խ������������
	int swapTimes = 100;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << endl;
	// ����3: �����д����ظ����ݵ�����
	cout << "Test for Random Array, size = " << n << ", random range [0, 10]" << endl;
	arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << endl;

	return 0;
}