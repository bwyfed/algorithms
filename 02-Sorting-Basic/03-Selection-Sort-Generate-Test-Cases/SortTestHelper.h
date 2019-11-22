#pragma once
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper {
	// ������n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR); // ����ʹ�ú�������׳
		int *arr = new int[n];
		srand(time(NULL)); // ʹ�õ�ǰ��ʱ���������������
		// ����n�������
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		return arr;
	}

	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
}
