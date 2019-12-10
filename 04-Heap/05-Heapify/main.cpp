#include <iostream>
#include "Heap.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void heapSort1(T arr[], int n) {
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
		maxheap.insert(arr[i]);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}
int main() {
	int n = 1000000;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	// ≤‚ ‘1: “ª∞„–‘≤‚ ‘
	cout << "Test for Random Array, size = " << n << ", random range[0, " << n << "]" << endl;
	SortTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);

	delete[] arr1;

	cout << endl;
	return 0;
}