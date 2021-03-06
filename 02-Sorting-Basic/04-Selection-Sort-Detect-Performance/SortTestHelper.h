#pragma once
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper {
	// 生成有n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR); // 断言使得函数更健壮
		int *arr = new int[n];
		srand(time(NULL)); // 使用当前的时间来设置随机种子
		// 设置n个随机数
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
	// 测试排序算法的正确性:判断此数组是否排序成功
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;
		return true;
	}
	// 测试排序算法
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		// 验证数组是否有序
		assert(isSorted(arr, n));
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
}
