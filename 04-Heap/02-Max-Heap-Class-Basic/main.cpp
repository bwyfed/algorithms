#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

template<typename Item>
class MaxHeap {
private:
	Item *data;
	int count; // �����ж��ٸ�Ԫ��
	int capacity;

public:
	// ���캯��, ����һ���ն�, ������capacity��Ԫ��
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	~MaxHeap() {
		delete[] data;
	}
	// ���ض��е�Ԫ�ظ���
	int size() {
		return count;
	}
	// ����һ������ֵ, ��ʾ�����Ƿ�Ϊ��
	bool isEmpty() {
		return count == 0;
	}
	void insert(Item item) {
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		shiftUp(count);
	}
};
int main() {
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout << maxheap.size() << endl;

	return 0;
}