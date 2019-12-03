#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

int main() {
	int n1 = 8000, n2 = 9000, n3 = 10000;
	int *arr1 = SortTestHelper::generateRandomArray(n1, 0, n1);
	int *arr2 = SortTestHelper::generateRandomArray(n2, 0, n2);
	int *arr3 = SortTestHelper::generateRandomArray(n3, 0, n3);

	SortTestHelper::testSort("Bubble Sort1", bubbleSort, arr1, n1);
	SortTestHelper::testSort("Bubble Sort1", bubbleSort, arr2, n2);
	SortTestHelper::testSort("Bubble Sort1", bubbleSort, arr3, n3);

	delete[] arr1;
}