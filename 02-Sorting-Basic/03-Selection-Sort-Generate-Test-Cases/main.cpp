#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
using namespace std;

// 声明为模板函数
template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		// 寻找[i, n)区间里的最小值
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}
int main() {
	int n = 10000; //数组中元素的个数
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	selectionSort(arr, n);
	SortTestHelper::printArray(arr, n);

	delete[] arr; // 释放数组的地址空间

	return 0;
}