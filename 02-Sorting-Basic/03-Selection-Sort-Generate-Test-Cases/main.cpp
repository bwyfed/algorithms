#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
using namespace std;

// ����Ϊģ�庯��
template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		// Ѱ��[i, n)���������Сֵ
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}
int main() {
	int n = 10000; //������Ԫ�صĸ���
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	selectionSort(arr, n);
	SortTestHelper::printArray(arr, n);

	delete[] arr; // �ͷ�����ĵ�ַ�ռ�

	return 0;
}