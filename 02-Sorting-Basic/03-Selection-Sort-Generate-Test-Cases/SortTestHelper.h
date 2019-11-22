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
}
