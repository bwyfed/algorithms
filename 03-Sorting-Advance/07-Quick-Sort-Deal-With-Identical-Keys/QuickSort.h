#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

// ��arr[l...r]���ֽ���partition����
// ����p��ʹ��arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {
	// �����ѡ��һ��Ԫ����Ϊ��Ԫpivot element
	cout << "l=" << l << ",r=" << r << endl;
	int randomNum = rand() % (r - l + 1) + l;
	cout << "randomNum = " << randomNum << ",arr[randomNum]=" << arr[randomNum]<<",";
	swap(arr[l], arr[randomNum]);
	T v = arr[l];
	cout << "v=" << v << ",";
	// arr[l+1...j] < v; arr[j+1...i) > v
	int j = l; // ��ʼ����£���������Ϊ��
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[l], arr[j]);
	cout << "j=" << j << endl;
	return j;
}

// ��arr[l...r]���ֽ��п�������
template <typename T>
void __quickSort(T arr[], int l, int r) {
	//if (l >= r)
	//	return;
	// �Ż�1��С������ʹ�ò�������
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
	srand(time(NULL));
//	cout << "quickSort:"<<endl;
//	for (int i = 0; i < 100; i++)
//		cout << arr[i] << ",";
	__quickSort(arr, 0, n - 1);
}