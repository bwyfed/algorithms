#include <iostream>
#include <string>
#include "Student.h"
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
	// 整型数组
	int a[10] = { 12, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	selectionSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	// 浮点数数组
	float b[4] = { 4.4, 3.3, 2.2, 1.1 };
	selectionSort(b, 4);
	for (int i = 0; i < 4; i++)
		cout << b[i] << " ";
	cout << endl;
	// 字符串数组
	string c[4] = { "D", "C", "B", "A" };
	selectionSort(c, 4);
	for (int i = 0; i < 4; i++)
		cout << c[i] << " ";
	cout << endl;
	// 自定义学生类
	Student d[4] = { {"D", 90}, {"C", 100}, {"B", 95}, {"A", 95} };
	selectionSort(d, 4);
	for (int i = 0; i < 4; i++)
		cout << d[i] << " ";
	cout << endl;
	return 0;
}