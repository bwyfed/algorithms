#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"

using namespace std;

// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename T>
void __merge(T arr[], int l, int mid, int r) 
{
//	T aux[r-l+1]; // ��ʱ�ռ�
	//* VS��֧�ֶ�̬��������, ������ʹ�� T aux[r-l+1]�ķ�ʽ����aux�Ŀռ�
	//* ʹ��VS��ͬѧ, ��ʹ��new�ķ�ʽ����aux�ռ�
	//* ʹ��new����ռ�, ��Ҫ������__merge���������, delete������Ŀռ�:)
	T *aux = new T[r - l + 1];
	for(int i = l; i <= r; i ++)
		aux[i-l] = arr[i];
		
	int i = l, j = mid + 1;
	for(int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j-l];
			j++;
		} else if (j > r) {
			arr[k] = aux[i-l];
			i++;
		} else if (aux[i-l] < aux[j-l]) {
			arr[k] = aux[i-l];
			i++;
		} else {
			arr[k] = aux[j-l];
			j++;
		}
	}
	delete[] aux;
}

// �ݹ�ʹ�ù鲢���򣬶�arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort(T arr[], int l, int r) {
	// �Թ鲢��������Ż�2������С������ʹ�ò�������
	//if ( l >= r)
	//	return;
	if (r - l <= 15) { // ����16��Ԫ�ص�����
		insertionSort(arr, l, r);
		return;
	}
	int mid = (l + r) / 2; // ����ȡ�� 
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);
	// �Թ鲢��������Ż�1���Խ��������������Ż�
	if (arr[mid] > arr[mid+1]) // arr[mid] <= arr[mid+1]��ʾarr�Ѿ��������
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
	__mergeSort(arr, 0, n-1);
}

int main() {
	int n = 50000;
	// ����1 һ���Բ���
	cout << "Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	
	delete[] arr1;
	delete[] arr2;

	cout << endl;
	// ����2 ���Խ������������
	int swapTimes = 10;
	cout << "Test for Random Nearly Orderly Array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);

	delete[] arr1;
	delete[] arr2;
	return 0; 
}
